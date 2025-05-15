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

struct SynthFpgaPass : public ScriptPass
{
  // Global data
  //
  RTLIL::Design *G_design; 
  string top_opt, verilog_file, part_name, opt;
  bool no_flatten, dff_enable, dff_async_set, dff_async_reset;
  bool obs_clean, wait, show_path;
  string sc_syn_lut_size;

  // Methods
  //
  SynthFpgaPass() : ScriptPass("synth_fpga", "Zero Asic FPGA synthesis flow") { }

  // -------------------------
  // clean_design 
  // -------------------------
  void clean_design()
  {
     if (obs_clean) {
        run("obs_clean -wires -assigns");
     } else {
        run("opt_clean");
     }
  }

  // -------------------------
  // opt_and_map_comb_logic 
  // -------------------------
  void opt_and_map_comb_logic()
  {

    if (opt == "default") {

      log_header(G_design, "Performing SCRIPT-BASED DEFAULT optimization\n");

      if (sc_syn_lut_size == "4") {
        run("abc -script +/zeroasic/opt_scripts/default_lut4.scr");
        return;
      }

      run("abc -script +/zeroasic/opt_scripts/default_lut6.scr");
      return;
    }

    // AREA mode
    //
    if (opt == "area") {

      log_header(G_design, "Performing Min-LUT optimization\n");

      if (sc_syn_lut_size == "4") {
        run("abc -script +/zeroasic/opt_scripts/area_lut4_high_effort.scr");
        return;
      }

      run("abc -script +/zeroasic/opt_scripts/area_lut6x2.scr");

      return;
    }

    // DELAY mode
    //
    if (opt == "delay") {

      log_header(G_design, "Performing Min-LUT-Level optimization\n");

      if (sc_syn_lut_size == "4") {
        run("abc -dff -script +/zeroasic/opt_scripts/delay_lut4_high_effort.scr");
        return;
      }

      run("abc -script +/zeroasic/opt_scripts/delay_lut6x2.scr");

      return;
    }

    // default
    //
    log_header(G_design, "Performing OFFICIAL DEFAULT optimization\n");
    run("abc -lut " + sc_syn_lut_size);
  }

  // -------------------------
  // legalize_flops
  // -------------------------
  // Code picked up from procedure 'legalize_flops' in TCL 'sc_synth_fpga.tcl' (Thierry)
  // DFF features considered so far : 
  //     - enable
  //     - async_set
  //     - async_reset
  //
  void legalize_flops ()
  {

    // Consider all feature combinations 'enable" x "async_set' x 'async_reset' when features
    // are supported or not : 2x2x2 = 8 combinations to handle.
    //
    
    // 1.
    //
    if (dff_enable && dff_async_set && dff_async_reset) {
      log("Legalize list: $_DFF_P_ $_DFF_PN?_ $_DFFE_PP_ $_DFFE_PN?P_ $_DFFSR_PNN_ $_DFFSRE_PNNP_\n");
      run("dfflegalize -cell $_DFF_P_ 01 -cell $_DFF_PN?_ 01 -cell $_DFFE_PP_ 01 -cell $_DFFE_PN?P_ 01 -cell $_DFFSR_PNN_ 01 -cell $_DFFSRE_PNNP_ 01");
      return;
    }

    // 2.
    //
    if (dff_enable && dff_async_set) {
      log("Legalize list: $_DFF_P_ $_DFF_PN1_ $_DFFE_PP_ $_DFFE_PN1P_\n");
      run("dfflegalize -cell $_DFF_P_ 01 -cell $_DFF_PN1_ 01 -cell $_DFFE_PP_ 01 -cell $_DFFE_PN1P_ 01");
      return;
    }

    // 3.
    //
    if (dff_enable && dff_async_reset) {
      log("Legalize list: $_DFF_P_ $_DFF_PN0_ $_DFFE_PP_ $_DFFE_PN0P_\n");
      run("dfflegalize -cell $_DFF_P_ 01 -cell $_DFF_PN0_ 01 -cell $_DFFE_PP_ 01 -cell $_DFFE_PN0P_ 01");
      return;
    }

    // 4.
    //
    if (dff_enable) {
      log("Legalize list: $_DFF_P_ $_DFF_P??_ $_DFFE_PP_ $_DFFE_P??P_\n");
      run("dfflegalize -cell $_DFF_P_ 01 -cell $_DFF_P??_ 01 -cell $_DFFE_PP_ 01 -cell $_DFFE_P??P_ 01");
      return;
    }

    // 5.
    //
    if (dff_async_set && dff_async_reset) {
      log("Legalize list: $_DFF_P_ $_DFF_PN?_ $_DFFSR_PNN_\n");
      run("dfflegalize -cell $_DFF_P_ 01 -cell $_DFF_PN?_ 01 -cell $_DFFSR_PNN_ 01");
      return;
    }

    // 6.
    //
    if (dff_async_set) {
      log("Legalize list: $_DFF_P_ $_DFF_PN1_\n");
      run("dfflegalize -cell $_DFF_P_ 01 -cell $_DFF_PN1_ 01");
      return;
    }

    // 7.
    //
    if (dff_async_reset) {
      log("Legalize list: $_DFF_P_ $_DFF_PN0_\n");
      run("dfflegalize -cell $_DFF_P_ 01 -cell $_DFF_PN0_ 01");
      return;
    }

    // 8.
    //
    // case of all features are not supported
    //
    // Choose to legalize to async resets even though they
    // won't tech map.  Goal is to get the user to fix
    // their code and put in synchronous resets

    log_warning("No DFF features are suported !\n");
    log_warning("Still Legalize list: $_DFF_P_ $_DFF_P??_\n");
    run("dfflegalize -cell $_DFF_P_ 01 -cell $_DFF_P??_ 01");

  }

  void help() override
  {
	//   |---v---|---v---|---v---|---v---|---v---|---v---|---v---|---v---|---v---|---v---|
	log("\n");
	log("    synth_fpga [options]\n");
	log("\n");
	log("This command runs Zero Asic FPGA synthesis flow.\n");
	log("\n");
	log("    -top <module>\n");
	log("        use the specified module as top module\n");
        log("\n");

        log("    -no_flatten\n");
        log("        skip flatening. By default, design is flatened.\n");
        log("\n");

        log("    -opt\n");
        log("        specifies the optimization target : area, delay, default.\n");
        log("\n");

	// DFF related options
	//
        log("    -no_dff_enable\n");
        log("        specifies that DFF with enable feature is supported. By default,\n");
        log("        DFF with enable is supported.\n");
        log("\n");
        log("    -no_dff_async_set\n");
        log("        specifies that DFF with asynchronous set feature is supported. By default,\n");
        log("        DFF with asynchronous set is supported.\n");
        log("\n");
        log("    -no_dff_async_reset\n");
        log("        specifies that DFF with asynchronous reset feature is not supported. By default,\n");
        log("        DFF with asynchronous reset is supported.\n");
        log("\n");

        log("    -obs_clean\n");
        log("        specifies to use 'obs_clean' cleanup function instead of inefficient \n");
        log("        'opt_clean'.\n");
        log("\n");

        log("    -lut_size\n");
        log("        specifies lut size. By default lut size is 4.\n");
        log("\n");

        log("    -verilog <file>\n");
        log("        write the design to the specified Verilog netlist file. writing of an\n");
        log("        output file is omitted if this parameter is not specified.\n");
	log("\n");

        log("    -show_path\n");
        log("        Show longest paths.\n");
        log("\n");

        log("    -wait\n");
        log("        wait after each 'stat' report for user to touch <enter> key. Help for \n");
        log("        flow analysis/debug.\n");
        log("\n");

	log("The following Yosys commands are executed underneath by 'synth_fpga' :\n");

	help_script();
	log("\n");
  }

  void clear_flags() override
  {
	top_opt = "-auto-top";
	opt = "";

	part_name = "z1000";

	no_flatten = false;
	show_path = false;

	wait = false;

	dff_enable = true;
	dff_async_set = true;
	dff_async_reset = true;

	obs_clean = false;

	verilog_file = "";

	sc_syn_lut_size = "4";
  }

  void execute(std::vector<std::string> args, RTLIL::Design *design) override
  {
	string run_from, run_to;
	clear_flags();

	G_design = design;

	size_t argidx;
	for (argidx = 1; argidx < args.size(); argidx++)
	{
		if (args[argidx] == "-top" && argidx+1 < args.size()) {
			top_opt = "-top " + args[++argidx];
			continue;
		}
		if (args[argidx] == "-opt" && argidx+1 < args.size()) {
			opt = args[++argidx];
			continue;
		}
	        if (args[argidx] == "-no_flatten") {
                        no_flatten = true;
                        continue;
                }
		if (args[argidx] == "-partname" && argidx+1 < args.size()) {
			part_name = args[++argidx];
			continue;
		}
	        if (args[argidx] == "-lut_size" && argidx+1 < args.size()) {
                        sc_syn_lut_size = args[++argidx];
                        continue;
                }
	        if (args[argidx] == "-obs_clean") {
                        obs_clean = true;
                        continue;
                }
	        if (args[argidx] == "-verilog" && argidx+1 < args.size()) {
                        verilog_file = args[++argidx];
                        continue;
                }
		// Support of DFF features : with or without 
		//     - enable
		//     - async set
		//     - async reset
		//
	        if (args[argidx] == "-no_dff_enable") {
                        dff_enable = false;
                        continue;
                }
	        if (args[argidx] == "-no_dff_async_set") {
                        dff_async_set = false;
                        continue;
                }
	        if (args[argidx] == "-no_dff_async_reset") {
                        dff_async_reset = false;
                        continue;
                }

	        if (args[argidx] == "-show_path") {
                        show_path = true;
                        continue;
                }

		// for debug, flow analysis
		//
	        if (args[argidx] == "-wait") {
                        wait = true;
                        continue;
                }

	}
	extra_args(args, argidx, design);

	if (!design->full_selection()) {
           log_cmd_error("This command only operates on fully selected designs!\n");
	}

	log_header(design, "Executing Zero Asic 'synth_fpga' flow.\n");
	log_push();

	run_script(design, run_from, run_to);

	log_pop();
  }

  // ---------------------------------------------------------------------------
  // synth_fpga 
  // ---------------------------------------------------------------------------
  //
  // Version 0.0 (05/13/2025, Thierry): 
  //        - as a starter, we mimic what is done in : 
  //          '.../siliconcompiler/tools/yosys/sc_synth_fpga.tcl' 
  //        - we try to handle DFF legalization by taking care of DFF features
  //        support like handling DFF with 'enable', 'async_set', 'async_reset'.
  //        - other encapsulated code with #if 0 coming from 'sc_synth_fpga.tcl'
  //        needs to be handled in this 'synth_fpga' command.
  //
  // ---------------------------------------------------------------------------
  void script() override
  {
    auto startTime = std::chrono::high_resolution_clock::now();

    log("\nPLATYPUS flow using 'synth_fpga' Yosys plugin command\n");

    log("'Zero Asic' FPGA Synthesis Version : %s\n", SYNTH_FPGA_VERSION);

    // Read basic models for resynthesis purpose
    //
    run("read_verilog +/zeroasic/ff_models/dff.v");
    run("read_verilog +/zeroasic/ff_models/dffe.v");
    run("read_verilog +/zeroasic/ff_models/dffr.v");
    run("read_verilog +/zeroasic/ff_models/dffer.v");
    run("hierarchy -check");

#if 0
    # Pre-processing step:  if DSPs instance are hard-coded into
    # the users design, we can use a blackbox flow for DSP mapping
    # as follows:

    if { [sc_cfg_exists fpga $sc_partname file yosys_macrolib] } {
        set sc_syn_macrolibs \
            [sc_cfg_get fpga $sc_partname file yosys_macrolib]

        foreach macrolib $sc_syn_macrolibs {
            yosys read_verilog -lib $macrolib
        }
    }
#endif

    // Extra line added versus 'sc_synth_fpga.tcl' tcl script version
    //
    run(stringf("hierarchy -check %s", help_mode ? "-top <top>" : top_opt.c_str()));

    run("proc");

    // Print stat when design is flatened. We flatened a copy, stat the copy
    // and get back to the original hierarchical design.
    //
    run("design -save original");
    run("flatten");
    log("\n# ------------------------ \n");
    log("#  Design raw statistics  \n");
    log("# ------------------------ \n");
    run("stat");
    run("design -load original");

    if (wait) {
      getchar();
    }

    if (!no_flatten) {
      run("flatten");
    }

    // Note there are two possibilities for how macro mapping might be done:
    // using the extract command (to pattern match user RTL against
    // the techmap) or using the techmap command.  The latter is better
    // for mapping simple multipliers; the former is better (for now)
    // for mapping more complex DSP blocks (MAC, pipelined blocks, etc).
    // and is also more easily extensible to arbitrary hard macros.
    // Run separate passes of both to get best of both worlds

    // An extract pass needs to happen prior to other optimizations,
    // otherwise yosys can transform its internal model into something
    // that doesn't match the patterns defined in the extract library
#if 0
    if { [sc_cfg_exists fpga $sc_partname file yosys_extractlib] } {
        set sc_syn_extractlibs \
            [sc_cfg_get fpga $sc_partname file yosys_extractlib]

        foreach extractlib $sc_syn_extractlibs {
            yosys log "Run extract with $extractlib"
            yosys extract -map $extractlib
        }
    }
#endif

    // Other hard macro passes can happen after the generic optimization
    // passes take place.

    // Generic optimization passes; this is a fusion of the VTR reference
    // flow and the Yosys synth_ice40 flow
    //
    run("opt_expr");
    clean_design();
    run("check");
    run("opt -nodffe -nosdff");
    run("fsm");
    run("opt");
    run("wreduce");
    run("peepopt");
    clean_design();
    run("share");
    run("techmap -map +/cmp2lut.v -D LUT_WIDTH=4");
    run("opt_expr");
    clean_design();

    // Extra line added versus 'sc_synth_fpga.tcl' tcl script version
    //
    run("stat");

    if (wait) {
      getchar();
    }

    // Here is a remaining customization pass for DSP tech mapping

    // Map DSP blocks before doing anything else,
    // so that we don't convert any math blocks
    // into other primitives
    //
#if 0
    if { [sc_cfg_exists fpga $sc_partname file yosys_dsp_techmap] } {
        set sc_syn_dsp_library \
            [sc_cfg_get fpga $sc_partname file yosys_dsp_techmap]

        yosys log "Run techmap flow for DSP Blocks"
        set formatted_dsp_options [get_dsp_options $sc_syn_dsp_options]
        yosys techmap -map +/mul2dsp.v -map $sc_syn_dsp_library \
            {*}$formatted_dsp_options

        post_techmap
    }
#endif

    // Mimic ICE40 flow by running an alumacc and memory -nomap passes
    // after DSP mapping
    //  
    run("alumacc");
    run("opt");
    run("memory -nomap");
    run("opt -full");

    run("techmap -map +/techmap.v");

#if 0
    set sc_syn_memory_libmap ""
    if { [sc_cfg_exists fpga $sc_partname file yosys_memory_libmap] } {
        set sc_syn_memory_libmap \
            [sc_cfg_get fpga $sc_partname file yosys_memory_libmap]
    }
    set sc_do_rom_map [expr { [lsearch -exact $sc_syn_feature_set mem_init] < 0 }]
    set sc_syn_memory_library ""
    if { [sc_cfg_exists fpga $sc_partname file yosys_memory_techmap] } {
        set sc_syn_memory_library \
            [sc_cfg_get fpga $sc_partname file yosys_memory_techmap]
    }

    if { [sc_map_memory $sc_syn_memory_libmap $sc_syn_memory_library $sc_do_rom_map] } {
        post_techmap
    }
#endif

    // After doing memory mapping, turn any remaining
    // $mem_v2 instances into flop arrays
    //
    run("memory_map");
    run("demuxmap");
    run("simplemap");

    // original TCL call : legalize_flops $sc_syn_feature_set
    //
    legalize_flops (); // C++ version of TCL call

#if 0
    if { [sc_cfg_exists fpga $sc_partname file yosys_flop_techmap] } {
        set sc_syn_flop_library \
            [sc_cfg_get fpga $sc_partname file yosys_flop_techmap]
        yosys techmap -map $sc_syn_flop_library

        post_techmap
    }
#else
    // C++ version
    //
    string sc_syn_flop_library = stringf("+/zeroasic/%s/techlib/tech_flops.v", part_name.c_str());
    run("techmap -map " + sc_syn_flop_library);
#endif

    // Perform preliminary buffer insertion before passing to ABC to help reduce
    // the overhead of final buffer insertion downstream
    run("insbuf");

    // Extra line added versus 'sc_synth_fpga.tcl' tcl script version
    //
    run("stat");

    if (wait) {
      getchar();
    }

    opt_and_map_comb_logic();

    run("setundef -zero");
    run("clean -purge");

    if (!verilog_file.empty()) {
       log("Dump Verilog file '%s'\n", verilog_file.c_str()); 
       run(stringf("write_verilog -noexpr -nohex -nodec %s", verilog_file.c_str()));
    }

    // Extra line added versus 'sc_synth_fpga.tcl' tcl script version
    //
    run("stat");

    auto endTime = std::chrono::high_resolution_clock::now();
    auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(endTime - startTime);

    float totalTime = elapsed.count() * 1e-9;

    log("   'Zero Asic' FPGA Synthesis Version : %s\n", SYNTH_FPGA_VERSION);
    log("\n");
    log("   Total Synthesis Run Time = %.1f sec.\n", totalTime);

    // Show longest path in 'delay' mode
    //
    if (show_path) {
      run("path");
    }

  } // end script()

} SynthFpgaPass;

PRIVATE_NAMESPACE_END
