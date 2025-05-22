#include "kernel/yosys.h"
#include "kernel/celltypes.h"
#include "kernel/sigtools.h"

USING_YOSYS_NAMESPACE
PRIVATE_NAMESPACE_BEGIN

static bool noff = false;
static bool summary = false;

struct MaxLvlWorker
{
	RTLIL::Design *design;
	RTLIL::Module *module;
	SigMap sigmap;

	dict<SigBit, tuple<int, SigBit, Cell*>> bits;

	dict<SigBit, dict<SigBit, Cell*>> bit2bits;

	dict<SigBit, tuple<SigBit, Cell*>> bit2ff;

	int maxlvl;
	SigBit maxbit;
	pool<SigBit> busy;

	void setup_internals_zeroasic_ff_Z1000(CellTypes& ff_celltypes)
	{
          // Simply list the DFF cells names is enough as cut points
	  //
          ff_celltypes.setup_type(ID(dff), {}, {});
          ff_celltypes.setup_type(ID(dffe), {}, {});
          ff_celltypes.setup_type(ID(dffr), {}, {});
          ff_celltypes.setup_type(ID(dffer), {}, {});
          ff_celltypes.setup_type(ID(dffs), {}, {});
          ff_celltypes.setup_type(ID(dffrs), {}, {});
          ff_celltypes.setup_type(ID(dffes), {}, {});
          ff_celltypes.setup_type(ID(dffers), {}, {});
	}

	void setup_internals_xilinx_ff_xc4v(CellTypes& ff_celltypes)
	{
          // Simply list the DFF cells names is enough as cut points
	  //
          ff_celltypes.setup_type(ID(FDCE), {}, {});
          ff_celltypes.setup_type(ID(FDPE), {}, {});
          ff_celltypes.setup_type(ID(FDRE), {}, {});
          ff_celltypes.setup_type(ID(FDRE_1), {}, {});
          ff_celltypes.setup_type(ID(FDSE), {}, {});
	}

	void setup_internals_lattice_ff_xo2(CellTypes& ff_celltypes)
	{
          // Simply list the DFF cells names is enough as cut points
	  //
          ff_celltypes.setup_type(ID(TRELLIS_FF), {}, {});
	}

	MaxLvlWorker(RTLIL::Module *module) : design(module->design), module(module), 
	                                      sigmap(module)
	{
		CellTypes ff_celltypes;

		if (noff) {

                   ff_celltypes.setup_internals_mem();
                   ff_celltypes.setup_stdcells_mem();

		   // Specify technology related DFF cutpoints for -noff option
		   //
	           setup_internals_zeroasic_ff_Z1000(ff_celltypes);

	           setup_internals_xilinx_ff_xc4v(ff_celltypes);

	           setup_internals_lattice_ff_xo2(ff_celltypes);
		}

		for (auto wire : module->selected_wires())
			for (auto bit : sigmap(wire))
				bits[bit] = tuple<int, SigBit, Cell*>(-1, State::Sx, nullptr);

		for (auto cell : module->selected_cells())
		{
			pool<SigBit> src_bits, dst_bits;

			for (auto &conn : cell->connections()) {

				for (auto bit : sigmap(conn.second)) {
					if (cell->input(conn.first))
						src_bits.insert(bit);
					if (cell->output(conn.first))
						dst_bits.insert(bit);
				}
			}

			if (noff && ff_celltypes.cell_known(cell->type)) {
				for (auto s : src_bits)
					for (auto d : dst_bits) {
						bit2ff[s] = tuple<SigBit, Cell*>(d, cell);
						break;
					}
				continue;
			}

			for (auto s : src_bits)
				for (auto d : dst_bits)
					bit2bits[s][d] = cell;
		}

		maxlvl = -1;
		maxbit = State::Sx;
	}

	void runner(SigBit bit, int level, SigBit from, Cell *via)
	{
		auto &bitinfo = bits.at(bit);

		if (get<0>(bitinfo) >= level)
			return;

		if (busy.count(bit) > 0) {
			log_warning("Detected loop at %s in %s\n", log_signal(bit), log_id(module));
			return;
		}

		busy.insert(bit);
		get<0>(bitinfo) = level;
		get<1>(bitinfo) = from;
		get<2>(bitinfo) = via;

		if (level > maxlvl) {
			maxlvl = level;
			maxbit = bit;
		}

		if (bit2bits.count(bit)) {
			for (auto &it : bit2bits.at(bit))
				runner(it.first, level+1, bit, it.second);
		}

		busy.erase(bit);
	}

	void printpath(SigBit bit)
	{
		auto &bitinfo = bits.at(bit);
		if (get<2>(bitinfo)) {
			printpath(get<1>(bitinfo));
			Cell* cell = get<2>(bitinfo); 
			log("%5d: %s (via %s)\n", get<0>(bitinfo), log_signal(bit), log_id(cell->type));
			//log("%5d: %s (via %s)\n", get<0>(bitinfo), log_signal(bit), log_id(get<2>(bitinfo)));
		} else {
			log("%5d: %s\n", get<0>(bitinfo), log_signal(bit));
		}
	}

	void run()
	{
		for (auto &it : bits)
			if (get<0>(it.second) < 0)
				runner(it.first, 0, State::Sx, nullptr);

		design->scratchpad_set_int("za_max_level", maxlvl);

		if (summary) {
		  log("\n");
		  log("   Max logic level = %d\n", maxlvl);
		} else {
		  log("\n");
		  log("Max logic level in %s (length=%d):\n", log_id(module), maxlvl);

		  if (maxlvl >= 0)
			  printpath(maxbit);

		  if (bit2ff.count(maxbit)) {
			log("%5s: %s (via %s)\n", "ff",
                            log_signal(get<0>(bit2ff.at(maxbit))),
                            log_id(get<1>(bit2ff.at(maxbit))));
		  }

		  log("\n");
		  log("   Max logic level = %d\n", maxlvl);
		}
	}
};

struct MaxLvlPass : public Pass {
	MaxLvlPass() : Pass("max_level", "print max logic level") { }
	void help() override
	{
		//   |---v---|---v---|---v---|---v---|---v---|---v---|---v---|---v---|---v---|---v---|
		log("\n");
		log("    max_level [options] [selection]\n");
		log("\n");
		log("This command prints the max logic levelin the design. (Only considers\n");
		log("paths within a single module, so the design must be flattened.)\n");
		log("\n");
		log("    -noff\n");
		log("        automatically exclude FF cell types\n");
		log("\n");

		log("    -summary\n");
		log("        just print max level number.\n");
		log("\n");
	}

        void clear_flags() override
        {
	  noff = false;
	  summary = false;
	}

	void execute(std::vector<std::string> args, RTLIL::Design *design) override
	{
		log_header(design, "Executing 'max_level' command (find max logic level).\n");
                clear_flags();

		size_t argidx;
		for (argidx = 1; argidx < args.size(); argidx++) {
			if (args[argidx] == "-noff") {
				noff = true;
				continue;
			}
			if (args[argidx] == "-summary") {
				summary = true;
				continue;
			}
			break;
		}

		extra_args(args, argidx, design);

		for (Module *module : design->selected_modules())
		{
			if (module->has_processes_warn())
				continue;

			MaxLvlWorker worker(module);
			worker.run();
		}
	}
} MaxLvlPass;

PRIVATE_NAMESPACE_END
