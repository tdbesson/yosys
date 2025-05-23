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
#include <iomanip>

#define SYNTH_FPGA_VERSION "1.0"

USING_YOSYS_NAMESPACE
PRIVATE_NAMESPACE_BEGIN

struct ReportStatPass : public ScriptPass
{
  // Global data
  //
  RTLIL::Design *G_design = NULL; 
  string csv_stat_file;

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
	     continue;
         }

         // Xilinx 'xc4v' Luts
         //
         if (cell->type.in(ID(LUT1), ID(LUT2), ID(LUT3), ID(LUT4), ID(INV))) {
             nb++;
	     continue;
         }
	 
         // Lattice 'Mach xo2' Luts
         //
         if (cell->type.in(ID(LUT1), ID(LUT2), ID(LUT3), ID(LUT4))) {
             nb++;
	     continue;
         }
	 
         // ice40 'hx' Luts
         //
         if (cell->type.in(ID(SB_LUT4))) {
             nb++;
	     continue;
         }
	 
         // Quicklogic 'pp3' Luts
         //
         if (cell->type.in(ID(LUT1), ID(LUT2), ID(LUT3), ID(LUT4))) {
             nb++;
	     continue;
         }
	 
         // Quicklogic 'pp3' mux4x0
         //
         if (cell->type.in(ID(mux4x0))) {
             nb += 3;  // equivalent to 3 LUT3 (Mux)
	     continue;
         }
	 
         // Quicklogic 'pp3' mux8x0
         //
         if (cell->type.in(ID(mux4x0))) {
             nb += 7;  // equivalent to 7 LUT3 (Mux)
	     continue;
         }
	 
         // Microchip 'polarfire' Luts
         //
         if (cell->type.in(ID(CFG1), ID(CFG2), ID(CFG3), ID(CFG4))) {
             nb++;
	     continue;
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
	     continue;
        }

        // Xilinx 'xc4v' DFFs
        //
        if (cell->type.in(ID(FDCE), ID(FDPE), ID(FDRE), ID(FDRE_1),
                          ID(FDSE),
			  ID(LDCE))) { // LATCH !!!
             nb++;
	     continue;
        }
	
        // Lattice 'Mach ox2' DFFs
        //
        if (cell->type.in(ID(TRELLIS_FF))) {
             nb++;
	     continue;
        }
	
        // ice40 'hx' DFFs
        //
        if (cell->type.in(ID(SB_DFF), ID(SB_DFFE), ID(SB_DFFER), ID(SB_DFFESR), 
                          ID(SB_DFFESS), ID(SB_DFFN), ID(SB_DFFR), ID(SB_DFFS), 
			  ID(SB_DFFSR), ID(SB_DFFES))) {
            nb++;
            continue;
        }
	
        // Quicklogic 'pp3' DFFs
        //
        if (cell->type.in(ID(dffepc))) { 
            nb++;
            continue;
        }
	
        // Microchip 'polarfire' DFFs
        //
        if (cell->type.in(ID(SLE))) { 
            nb++;
            continue;
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
        log("    -csv <file>\n");
        log("        write design statistics into a CSV file. Default file name\n");
        log("        is 'stat.csv'.\n");
	log("\n");


	help_script();
	log("\n");
  }

  void clear_flags() override
  {
        csv_stat_file = "stat.csv";
  }

  void execute(std::vector<std::string> args, RTLIL::Design *design) override
  {
	string run_from, run_to;
	clear_flags();

	G_design = design;

	size_t argidx;
	for (argidx = 1; argidx < args.size(); argidx++)
	{
	        if (args[argidx] == "-csv" && argidx+1 < args.size()) {
                        csv_stat_file = args[++argidx];
                        continue;
                }
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
  // getTimeDifference 
  // ---------------------------------------------------------------------------
  // May return the wrong time difference if it exceeds 24 hours
  //
  int getTimeDifference(string& end, string& start)
  {
    // Extract time_t value from strings
    //
    struct std::tm tm_end = {};
    std::istringstream ss_end(end);
    ss_end >> std::get_time(&tm_end, "%T"); // %T for %H:%M:%S format
    std::time_t end_time = mktime(&tm_end);

    struct std::tm tm_start = {};
    std::istringstream ss_start(start);
    ss_start >> std::get_time(&tm_start, "%T"); // %T for %H:%M:%S format
    std::time_t start_time = mktime(&tm_start);

#if 0
    // Code to check that extraction worked well
    //
    struct tm  datetime_end;
    char output_end[50];
    datetime_end = *localtime(&end_time);
    strftime(output_end, 50, "%T", &datetime_end);
    log("New end = %s\n", output_end);

    struct tm  datetime_start;
    char output_start[50];
    datetime_start = *localtime(&start_time);
    strftime(output_start, 50, "%T", &datetime_start);
    log("New start = %s\n", output_start);
#endif
    
    // Return time in seconds between 'end' and 'start'
    //
    double duration = difftime(end_time, start_time) + 1;

    if (duration <= 0) { // corner case where we went through midnight

	string hour_twfo = "23:59:59";

        struct std::tm tm_twfo = {};
        std::istringstream ss_twfo(hour_twfo);
        ss_twfo >> std::get_time(&tm_twfo, "%T"); // %T for %H:%M:%S format
        std::time_t twfo_time = mktime(&tm_twfo);

        double duration1 = difftime(twfo_time, start_time);

        string hour_zero = "00:00:00";

        struct std::tm tm_zero = {};
        std::istringstream ss_zero(hour_zero);
        ss_zero >> std::get_time(&tm_zero, "%T"); // %T for %H:%M:%S format
        std::time_t zero_time = mktime(&tm_zero);

        double duration2 = difftime(end_time, zero_time);

        double duration = duration1 + duration2 + 1;

        return (int)duration; // round to int
    }

    return (int)duration; // round to int
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

    string topName = log_id(topModule->name);

    int nbLuts = getNumberOfLuts();

    int nbDffs = getNumberOfDffs();

    int maxlvl = -1;

    // call 'max_level' command if not called yet
    //
    run("max_level -noff"); // -> store 'maxlvl' in scratchpad with 'za_max_level'

    maxlvl = G_design->scratchpad_get_int("za_max_level", 0);

    string start = G_design->scratchpad_get_string("time_chrono_start");
    string end =  G_design->scratchpad_get_string("time_chrono_end");

    int duration = getTimeDifference(end, start);

#if 0
    log("   Start time = %s\n", start.c_str());
    log("   End time   = %s\n", end.c_str());
#endif

    // -----
    // Open the csv file and dump the stats.
    //
    std::ofstream csv_file(csv_stat_file);

    csv_file << topName + ",";
    csv_file << std::to_string(nbLuts) + ",";
    csv_file << std::to_string(nbDffs) + ",";
    csv_file << std::to_string(maxlvl) + ",";
    csv_file << std::to_string(duration);
    csv_file << std::endl;

    csv_file.close();

    log("\n   Dumped file %s\n", csv_stat_file.c_str());

    run("stat");

  } // end script()

} ReportStatPass;

PRIVATE_NAMESPACE_END
