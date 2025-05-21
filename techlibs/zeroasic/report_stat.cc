/*
 *  yosys -- Yosys Open SYnthesis Suite
 *
 *  Copyright (C) 2012  Claire Xenia Wolf <claire@yosyshq.com>
 *
 *  Permission to use, copy, modify, and/or distribute this software for any
 *  purpose with or without fee is hereby granted, provided that the above
 *  copyright notice and this permission notice appear in all copies.
 *
 *  THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES
 *  WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF
 *  MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR
 *  ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES
 *  WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN
 *  ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF
 *  OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.
 *
 */

#include "kernel/register.h"
#include "kernel/celltypes.h"
#include "kernel/rtlil.h"
#include "kernel/log.h"
#include <chrono>

#define SYNTH_FPGA_VERSION "1.0"

USING_YOSYS_NAMESPACE
PRIVATE_NAMESPACE_BEGIN

struct ReportStatPass : public ScriptPass
{
  // Global data
  //
  RTLIL::Design *G_design = NULL; 

  // Methods
  //
  ReportStatPass() : ScriptPass("report_stat", "Dump flattened netlist stats in file 'stat.csv'") { }

  // -------------------------
  // getNumberOfDffs
  // -------------------------
  int getNumberOfLuts() {

     int nb = 0;

     for (auto cell : G_design->top_module()->cells()) {

         // Generic Luts like for Zero Asic Z1000
         //
         if (cell->type.in(ID($lut))) {
             nb++;
         }

         // Xilinx 'xc4v' Luts
         //
         if (cell->type.in(ID(LUT1), ID(LUT2), ID(LUT3), ID(LUT4), ID(INV))) {
             nb++;
         }
     }

     return nb;
  }

  // -------------------------
  // getNumberOfDffs
  // -------------------------
  int getNumberOfDffs() {

    int nb = 0;

    for (auto cell : G_design->top_module()->cells()) {

        // Zero Asic Z1000 DFFs
        //
        if (cell->type.in(ID(dff), ID(dffe), ID(dffr), ID(dffer),
                          ID(dffs), ID(dffrs), ID(dffes), ID(dffers))) {
             nb++;
        }

        // Xilinx 'xc4v' DFFs
        //
        if (cell->type.in(ID(FDCE), ID(FDPE), ID(FDRE), ID(FDRE_1),
                          ID(FDSE))) {
             nb++;
        }
    }

    return nb;
  }

  void help() override
  {
	//   |---v---|---v---|---v---|---v---|---v---|---v---|---v---|---v---|---v---|---v---|
	log("\n");
	log("    report_stat\n");
	log("\n");
	log("This command reports stat on a flattened netlist. Data are dumped.\n");
	log("in file 'stat.csv'.\n");
	log("\n");

	help_script();
	log("\n");
  }

  void clear_flags() override
  {
  }

  void execute(std::vector<std::string> args, RTLIL::Design *design) override
  {
	string run_from, run_to;
	clear_flags();

	G_design = design;

	size_t argidx;
	for (argidx = 1; argidx < args.size(); argidx++)
	{
	}
	extra_args(args, argidx, design);

	if (!design->full_selection()) {
           log_cmd_error("This command only operates on fully selected designs!\n");
	}

	log_header(design, "Executing 'report_stat'.\n");
	log_push();

	run_script(design, run_from, run_to);

	log_pop();
  }

  // ---------------------------------------------------------------------------
  // report_stat 
  // ---------------------------------------------------------------------------
  void script() override
  {
    Module* topModule = G_design->top_module();

    if (!topModule) {
       log_warning("Design seems empty !\n");
       return;
    }

    string fileName = "stat.csv";

    string topName = log_id(topModule->name);

    int nbLuts = getNumberOfLuts();

    int nbDffs = getNumberOfDffs();

    int maxlvl = -1;

    // call 'max_level' command if not called yet
    //
    run("max_level -summary"); // -> store 'maxlvl' in scratchpad with 'za_max_level'

    maxlvl = G_design->scratchpad_get_int("za_max_level", 0);

    // -----
    // Open the csv file and dump the stats.
    //
    std::ofstream csv_file(fileName);

    csv_file << topName + ",";
    csv_file << std::to_string(nbLuts) + ",";
    csv_file << std::to_string(nbDffs) + ",";
    csv_file << std::to_string(maxlvl) + ",";
    csv_file << std::to_string(0);
    csv_file << std::endl;

    csv_file.close();

    log("\n   Dumped file %s\n", fileName.c_str());

    run("stat");

  } // end script()

} ReportStatPass;

PRIVATE_NAMESPACE_END
