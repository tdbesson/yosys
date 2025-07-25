//
// Zero Asic Corp. Plug-in
//
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
#include "version.h"
#include <chrono>
#include <algorithm>
#include <cctype>
#include <filesystem>

#define SYNTH_FPGA_VERSION "1.0-" YOSYS_SYN_REVISION

#define HUGE_NB_CELLS 5000000 // 5 Million cells
#define BIG_NB_CELLS 500000   // 500K cells

USING_YOSYS_NAMESPACE
PRIVATE_NAMESPACE_BEGIN

struct SynthFpgaPass : public ScriptPass
{
  // Global data
  //
  RTLIL::Design *G_design = NULL; 
  string top_opt, verilog_file, part_name, opt;
  string abc_script_version;
  bool no_flatten, dff_enable, dff_async_set, dff_async_reset;
  bool obs_clean, wait, show_max_level, csv, insbuf, resynthesis, autoname;
  bool bram, dsp48, no_seq_opt, show_config;
  string sc_syn_lut_size;
  string config_file = "";
  bool config_file_success = false;

  pool<string> opt_options  = {"default", "fast", "area", "delay"};
  pool<string> partnames  = {"Z1000", "Z1010"};

  // ----------------------------
  // Key 'yosys-syn' parameters
  //
  string               ys_root_path = "";

  // DFFs
  //
  pool<string>         ys_dff_features;
  dict<string, string> ys_dff_models;
  string               ys_dff_techmap = ""; 

  // BRAMs
  //
  string ys_brams_memory_libmap = ""; 
  string ys_brams_techmap = ""; 

  // DSPs
  //
  string                  ys_dsps_techmap = "";
  dict<string, int>       ys_dsps_parameter_int;
  dict<string, string>    ys_dsps_parameter_string;

  // Methods
  //
  SynthFpgaPass() : ScriptPass("synth_fpga", "Zero Asic FPGA synthesis flow") { }


  // -------------------------
  // Json reader
  // -------------------------
  struct JsonNode
  {
	char type; // S=String, N=Number, A=Array, D=Dict
	string data_string;
	int64_t data_number;
	vector<JsonNode*> data_array;
	dict<string, JsonNode*> data_dict;
	vector<string> data_dict_keys;

	JsonNode(std::istream &f, string& cf_file, int& line)
	{
		type = 0;
		data_number = 0;

		while (1)
		{
			int ch = f.get();

			if (ch == EOF)
				log_error("Unexpected EOF in JSON file.\n");

			if (ch == '\n')
				line++;
			if (ch == ' ' || ch == '\t' || ch == '\r' || ch == '\n')
				continue;

			if (ch == '"')
			{
				type = 'S';

				while (1)
				{
					ch = f.get();

					if (ch == EOF)
						log_error("Unexpected EOF in JSON string.\n");

					if (ch == '"')
						break;

					if (ch == '\\') {
						ch = f.get();

						switch (ch) {
							case EOF: log_error("Unexpected EOF in JSON string.\n"); break;
							case '"':
							case '/':
							case '\\':           break;
							case 'b': ch = '\b'; break;
							case 'f': ch = '\f'; break;
							case 'n': ch = '\n'; break;
							case 'r': ch = '\r'; break;
							case 't': ch = '\t'; break;
							case 'u':
								int val = 0;
								for (int i = 0; i < 4; i++) {
									ch = f.get();
									val <<= 4;
									if (ch >= '0' && '9' >= ch) {
										val += ch - '0';
									} else if (ch >= 'A' && 'F' >= ch) {
										val += 10 + ch - 'A';
									} else if (ch >= 'a' && 'f' >= ch) {
										val += 10 + ch - 'a';
									} else
										log_error("Unexpected non-digit character in \\uXXXX sequence: %c at line %d.\n", ch, line);
								}
								if (val < 128)
									ch = val;
								else
									log_error("Unsupported \\uXXXX sequence in JSON string: %04X at line %d.\n", val, line);
								break;
						}
					}

					data_string += ch;
				}

				break;
			}

			if (('0' <= ch && ch <= '9') || ch == '-')
			{
				bool negative = false;
				type = 'N';
				if (ch == '-') {
					data_number = 0;
				       	negative = true;
				} else {
					data_number = ch - '0';
				}

				data_string += ch;

				while (1)
				{
					ch = f.get();

					if (ch == EOF)
						break;

					if (ch == '.')
						goto parse_real;

					if (ch < '0' || '9' < ch) {
						f.unget();
						break;
					}

					data_number = data_number*10 + (ch - '0');
					data_string += ch;
				}

				data_number = negative ? -data_number : data_number;
				data_string = "";
				break;

			parse_real:
				type = 'S';
				data_number = 0;
				data_string += ch;

				while (1)
				{
					ch = f.get();

					if (ch == EOF)
						break;

					if (ch < '0' || '9' < ch) {
						f.unget();
						break;
					}

					data_string += ch;
				}

				break;
			}

			if (ch == '[')
			{
				type = 'A';

				while (1)
				{
					ch = f.get();

					if (ch == EOF)
						log_error("Unexpected EOF in JSON file '%s'.\n",
							  cf_file.c_str());

			                if (ch == '\n')
				                line++;

					if (ch == ' ' || ch == '\t' || ch == '\r' || ch == '\n' || ch == ',')
						continue;

					if (ch == ']')
						break;

					f.unget();
					data_array.push_back(new JsonNode(f, cf_file, line));
				}

				break;
			}

			if (ch == '{')
			{
				type = 'D';

				while (1)
				{
					ch = f.get();

					if (ch == EOF)
						log_error("Unexpected EOF in JSON file '%s'.\n",
							  cf_file.c_str());

			                if (ch == '\n')
				                line++;

					if (ch == ' ' || ch == '\t' || ch == '\r' || ch == '\n' || ch == ',')
						continue;

					if (ch == '}')
						break;

					f.unget();
					JsonNode key(f, cf_file, line);

					while (1)
					{
						ch = f.get();

						if (ch == EOF)
						       log_error("Unexpected EOF in JSON file '%s'.\n",
							         cf_file.c_str());

			                        if (ch == '\n')
				                        line++;

						if (ch == ' ' || ch == '\t' || ch == '\r' || ch == '\n' || ch == ':')
							continue;

						f.unget();
						break;
					}

					JsonNode *value = new JsonNode(f, cf_file, line);

					if (key.type != 'S')
						log_error("Unexpected non-string key in JSON dict at line %d.\n", line);

					data_dict[key.data_string] = value;
					data_dict_keys.push_back(key.data_string);
				}

				break;
			}

			log_error("Unexpected character '%c' in config file '%s' at line %d.\n", 
		                  ch, cf_file.c_str(), line);
		}
	}

	~JsonNode()
	{
		for (auto it : data_array)
			delete it;
		for (auto &it : data_dict)
			delete it.second;
	}
  };

  typedef struct {
	  string config_file;
	  int    version;
	  string partname;
	  int    lut_size;
	  string root_path;

	  // DFF related
	  //
	  pool<string>         dff_features;
	  dict<string, string> dff_models;
	  string               dff_techmap;

          // BRAM related
	  //
	  string brams_memory_libmap;
	  string brams_techmap;
	  
	  //
          // DSP related
	  //
	  string               dsps_family;
	  string               dsps_techmap;
	  dict<string, int>    dsps_parameter_int;
	  dict<string, string> dsps_parameter_string;

  } config_type;

  // The global config object
  //
  config_type G_config;

  // -------------------------
  // show_config_file
  // -------------------------
  void show_config_file() 
  {

    if (!show_config) {
      return;
    }

    log_header(G_design, "Show config file : \n");

    log("\n");
    log(" ==========================================================================\n");
    log("  Config file        : %s\n", (G_config.config_file).c_str());
    log("  Version            : %d\n", G_config.version);
    log("  partname           : %s\n", (G_config.partname).c_str());
    log("  lut_size           : %d\n", G_config.lut_size);
    log("  root_path          : %s\n", (G_config.root_path).c_str());

    log("  DFF Features       : \n");
    for (auto it : G_config.dff_features) {
       log("                       - %s\n", it.c_str());
    }

    log("  DFF MODELS         : \n");
    for (auto it : G_config.dff_models) {
       log("                       - %s %s\n", (it.first).c_str(), (it.second).c_str());
    }

    log("  DFF techmap        : \n");
    log("                       %s\n", (G_config.dff_techmap).c_str());

    log("  BRAM memory_libmap : \n");
    log("                       %s\n", (G_config.brams_memory_libmap).c_str());

    log("  BRAM techmap       : \n");
    log("                       %s\n", (G_config.brams_techmap).c_str());

    log("  DSP family         : \n");
    log("                       %s\n", (G_config.dsps_family).c_str());

    log("  DSP techmap        : \n");
    log("                       %s\n", (G_config.dsps_techmap).c_str());

    log("  DSP techparam      : \n");

    log("      int param      : \n");
    for (auto it : G_config.dsps_parameter_int) {
       log("                       - %s = %d\n", (it.first).c_str(), it.second);
    }

    log("      string param   : \n");
    for (auto it : G_config.dsps_parameter_string) {
       log("                       - %s = %s\n", (it.first).c_str(), (it.second).c_str());
    }
    log("\n");

    log(" ==========================================================================\n");
  }

  // -------------------------
  // setup_options
  // -------------------------
  // We setup the options according to 'config' file, if any, and command
  // line options.
  // If options conflict (ex: lut_size) between the two, 'config' file 
  // setting has the priority.
  //
  void setup_options()
  {
    // If there is a config file with successful analysis then we set up
    // all the yosys-syn parameters with it.
    //
    if (config_file_success) {

       ys_root_path = G_config.root_path;


       // DFF parameters setting
       //
       for (auto it : G_config.dff_features) {
          ys_dff_features.insert(it);
       }
       for (auto it : G_config.dff_models) {
          ys_dff_models[it.first] = it.second;
       }
       ys_dff_techmap = G_config.root_path + G_config.dff_techmap;


       // BRAMs parameters setting
       //
       ys_brams_memory_libmap = G_config.root_path + G_config.brams_memory_libmap; 
       ys_brams_techmap = G_config.root_path + G_config.brams_techmap; 

       
       // DSPs parameters setting
       //
       ys_dsps_techmap = G_config.root_path + G_config.dsps_techmap;
       for (auto it : G_config.dsps_parameter_int) {
	   ys_dsps_parameter_int[it.first] = it.second;
       }
       for (auto it : G_config.dsps_parameter_string) {
	   ys_dsps_parameter_string[it.first] = it.second;
       }


       // Processing cases where 'config' file overides user command options.
       //
       if (ys_dff_features.count("enable") == 0) {
         log_warning("Config file will switch on '-no_dff_enable' option.\n");
         dff_enable = false;
       }

       if (ys_dff_features.count("async reset") == 0) {
         log_warning("Config file will switch on '-no_dff_async_reset' option.\n");
         dff_async_reset = false;
       }

       if (ys_dff_features.count("async set") == 0) {
         log_warning("Config file will switch on '-no_dff_async_set' option.\n");
         dff_async_set = false;
       }
       
       if (std::to_string(G_config.lut_size) != sc_syn_lut_size) {
         log_warning("Config file will change lut size value from %s to %d.\n",
	             sc_syn_lut_size.c_str(), G_config.lut_size);
         sc_syn_lut_size = std::to_string(G_config.lut_size);
       }

    } else {

      // Default settings when 'config' file is not specified.
    
      // DFF setting
      //
      ys_dff_techmap = "+/yosys-syn/ARCHITECTURE/" + part_name + "/techlib/tech_flops.v";
      ys_dff_features.insert("async reset");
      ys_dff_features.insert("async set");
      ys_dff_features.insert("enable");

      ys_dff_models["dffers"] = "+/yosys-syn/SRC/FF_MODELS/dffers.v";
      ys_dff_models["dffer"] = "+/yosys-syn/SRC/FF_MODELS/dffer.v";
      ys_dff_models["dffes"] = "+/yosys-syn/SRC/FF_MODELS/dffes.v";
      ys_dff_models["dffe"] = "+/yosys-syn/SRC/FF_MODELS/dffe.v";
      ys_dff_models["dffrs"] = "+/yosys-syn/SRC/FF_MODELS/dffrs.v";
      ys_dff_models["dffr"] = "+/yosys-syn/SRC/FF_MODELS/dffr.v";
      ys_dff_models["dffs"] = "+/yosys-syn/SRC/FF_MODELS/dffs.v";
      ys_dff_models["dff"] = "+/yosys-syn/SRC/FF_MODELS/dff.v";

      // BRAM setting
      // Picked up from Micro chip
      //
      ys_brams_memory_libmap = "+/yosys-syn/ARCHITECTURE/" + part_name + "/BRAM/LSRAM.txt -lib +/yosys-syn/ARCHITECTURE/" + part_name + "/BRAM/uSRAM.txt";
      ys_brams_techmap = "+/yosys-syn/ARCHITECTURE/" + part_name + "/BRAM/LSRAM_map.v -map +/yosys-syn/ARCHITECTURE/" + part_name + "/BRAM/uSRAM_map.v";
  
  
      // DSP setting
      //
      ys_dsps_techmap = "+/yosys-syn/ARCHITECTURE/" + part_name + "/DSP/mult18x18_DSP48.v ";
      ys_dsps_parameter_int["DSP_A_MAXWIDTH"] = 18;
      ys_dsps_parameter_int["DSP_B_MAXWIDTH"] = 18;
      ys_dsps_parameter_int["DSP_A_MINWIDTH"] = 2;
      ys_dsps_parameter_int["DSP_B_MINWIDTH"] = 2;
      ys_dsps_parameter_int["DSP_Y_MINWIDTH"] = 9;
      ys_dsps_parameter_int["DSP_SIGNEDONLY"] = 1;
      ys_dsps_parameter_string["DSP_NAME"] = "$__MUL18X18";
    }

  }

  // -------------------------
  // check_options
  // -------------------------
  void check_options()
  {
     if (!config_file_success) {

       // Converting 'partname' to upper case only if part name is 
       // used as 'synth_fpga' option and not through config file. 
       // If we do that also for partname set from config file, we may 
       // have trouble since we may upper case 3rd party partnames and
       // we would have no way to refer to the exact partname name,
       // set from config file, therefore the check on 'config_file_success'.
       //
       std::transform (part_name.begin(), part_name.end(), 
		       part_name.begin(), ::toupper);
     }

     if (partnames.count(part_name) == 0) {
        log("ERROR: -partname '%s' is unknown.\n", part_name.c_str());
        log("       Available partnames are :\n");
        for (auto part_name : partnames) {
           log ("               - %s\n", part_name.c_str());
        }
        log_error("Please select a correct partname.\n");
    }

    if ((sc_syn_lut_size != "4") && (sc_syn_lut_size != "6")) {
        log_error("Lut sizes can be only 4 or 6.\n");
    }
  }

  // -------------------------
  // read_config
  // -------------------------
  // Read eventually config file that will setup main synthesis parameters like
  // partname, lut size, DFF models, DSP and BRAM techmap files, ...
  //
  // This should be in sync with the 'config_type' type since we will fill up
  // this data structure in this 'read_config' function.
  //
  void read_config() 
  {

    // if no 'config_file' specified return right away
    //
    if (config_file == "") {
      return;
    }

    log_header(G_design, "Reading config file '%s'\n", config_file.c_str());

    if (!std::filesystem::exists(config_file.c_str())) {
      log_error("Cannot find file '%s'.\n", config_file.c_str());
    }

    // Read the config file
    // 
    std::ifstream f;

    f.open(config_file);

    int line = 1;
    JsonNode root(f, config_file, line);

    // Analyze the 'root' config data structre and fill up 'G_config' with it
    //
    if (root.type != 'D') {
      log_error("'%s' file is not a dictionary.\n", config_file.c_str());
    }

    // Check that all sections are there and performs type verification.
    //

    // version
    //
    if (root.data_dict.count("version") == 0) {
        log_error("'version' number is missing in config file '%s'.\n", config_file.c_str());
    }
    JsonNode *version = root.data_dict.at("version");
    if (version->type != 'N') {
        log_error("'version' must be an integer.\n");
    }

    // partname
    //
    if (root.data_dict.count("partname") == 0) {
        log_error("'partname' is missing in config file '%s'.\n", config_file.c_str());
    }
    JsonNode *partname = root.data_dict.at("partname");
    if (partname->type != 'S') {
        log_error("'partname' must be a string.\n");
    }

    // lut_size
    //
    if (root.data_dict.count("lut_size") == 0) {
        log_error("'lut_size' is missing in config file '%s'.\n", config_file.c_str());
    }
    JsonNode *lut_size = root.data_dict.at("lut_size");
    if (lut_size->type != 'N') {
        log_error("'lut_size' must be an integer.\n");
    }

    // flipflops
    if (root.data_dict.count("flipflops") == 0) {
        log_error("'flipflops' is missing in config file '%s'.\n", config_file.c_str());
    }
    JsonNode *flipflops = root.data_dict.at("flipflops");
    if (flipflops->type != 'D') {
        log_error("'flipflops' must be a dictionnary.\n");
    }

    // brams
    //
    if (root.data_dict.count("brams") == 0) {
        log_error("'brams' is missing in config file '%s'.\n", config_file.c_str());
    }
    JsonNode *brams = root.data_dict.at("brams");
    if (brams->type != 'D') {
        log_error("'brams' must be a dictionnary.\n");
    }

    // dsps
    //
    if (root.data_dict.count("dsps") == 0) {
        log_error("'dsps' is missing in config file '%s'.\n", config_file.c_str());
    }
    JsonNode *dsps = root.data_dict.at("dsps");
    if (dsps->type != 'D') {
        log_error("'dsps' must be a dictionnary.\n");
    }


    // Extract data and fill up 'G_config'
    //
    G_config.config_file = config_file;

    G_config.version = version->data_number;

    G_config.partname = partname->data_string;

    G_config.lut_size = lut_size->data_number;

    const std::filesystem::path config_path(config_file);
    G_config.root_path = std::filesystem::absolute(config_path.parent_path());

    // Extract DFF associated parameters
    //
    if (flipflops->data_dict.count("features") == 0) {
        log_error("'features' from 'flipflops' is missing in config file '%s'.\n", config_file.c_str());
    }
    JsonNode *dff_features = flipflops->data_dict.at("features");
    if (dff_features->type != 'A') {
        log_error("'features' associated to 'flipflops' must be an array.\n");
    }

    for (auto it : dff_features->data_array) {
          JsonNode *dff_mode = it;
          if (dff_mode->type != 'S') {
              log_error("Array associated to DFF 'features' must be contain only strings.\n");
          }
	  string dff_mode_str = dff_mode->data_string;

	  (G_config.dff_features).insert(dff_mode_str);
    }

    JsonNode *dff_models = flipflops->data_dict.at("models");
    if (dff_models->type != 'D') {
        log_error("'models' associated to 'flipflops' must be a dictionnary.\n");
    }

    for (auto it : dff_models->data_dict) {
	  string dff_model_str = it.first;
	  JsonNode* dff_model_path = it.second;
          if (dff_model_path->type != 'S') {
              log_error("Second element associated to DFF models '%s' must be a string.\n",
                        dff_model_str.c_str());
          }
	  G_config.dff_models[dff_model_str] = dff_model_path->data_string;
    }


    if (flipflops->data_dict.count("techmap") == 0) {
        log_error("'techmap' from 'flipflops' is missing in config file '%s'.\n", config_file.c_str());
    }
    JsonNode *techmap_dff = flipflops->data_dict.at("techmap");
    if (techmap_dff->type != 'S') {
        log_error("'techmap' associated to 'flipflops' must be a string.\n");
    }
    G_config.dff_techmap = techmap_dff->data_string;



    // Extract 'brams' associated parameters
    // 
    if (brams->data_dict.count("memory_libmap") == 0) {
        log_error("'memory_libmap' from 'brams' is missing in config file '%s'.\n", config_file.c_str());
    }
    JsonNode *memory_libmap = brams->data_dict.at("memory_libmap");
    if (memory_libmap->type != 'S') {
        log_error("'memory_libmap' associated to 'brams' must be a string.\n");
    }
    G_config.brams_memory_libmap = memory_libmap->data_string;


    if (brams->data_dict.count("techmap") == 0) {
        log_error("'techmap' from 'brams' is missing in config file '%s'.\n", config_file.c_str());
    }
    JsonNode *brams_techmap = brams->data_dict.at("techmap");
    if (brams_techmap->type != 'S') {
        log_error("'techmap' associated to 'brams' must be a string.\n");
    }
    G_config.brams_techmap = brams_techmap->data_string;




    // Extract 'dsps' associated parameters
    // 
    if (dsps->data_dict.count("family") == 0) {
        log_error("'family' from 'dsps' is missing in config file '%s'.\n", config_file.c_str());
    }
    JsonNode *family = dsps->data_dict.at("family");
    if (family->type != 'S') {
        log_error("'family' associated to 'dsps' must be a string.\n");
    }
    G_config.dsps_family = family->data_string;


    if (dsps->data_dict.count("techmap") == 0) {
        log_error("'techmap' from 'dsps' is missing in config file '%s'.\n", config_file.c_str());
    }
    JsonNode *dsps_techmap = dsps->data_dict.at("techmap");
    if (family->type != 'S') {
        log_error("'techmap' associated to 'dsps' must be a string.\n");
    }
    G_config.dsps_techmap = dsps_techmap->data_string;


    if (dsps->data_dict.count("techmap_parameters") == 0) {
        log_error("'techmap_parameters' from 'dsps' is missing in config file '%s'.\n", config_file.c_str());
    }
    JsonNode *dsps_param = dsps->data_dict.at("techmap_parameters");
    if (dsps_param->type != 'D') {
        log_error("'techmap_parameters' associated to 'dsps' must be a dictionnary.\n");
    }

    for (auto it : dsps_param->data_dict) {
          string param_str = it.first;
          JsonNode* param_value = it.second;

          if ((param_value->type != 'S') && (param_value->type != 'N')) {
              log_error("Second element associated to dsps 'techmap_parameters' '%s' must be either a string or an integer.\n",
                        param_str.c_str());
          }
	  if (param_value->type == 'S') {
            G_config.dsps_parameter_string[param_str] = param_value->data_string;
	    continue;
	  }
	  if (param_value->type == 'N') {
            G_config.dsps_parameter_int[param_str] = param_value->data_number;
	    continue;
	  }
	  log_warning("Ignoring 'dsps' parameter '%s'\n", param_str.c_str());
    }

    log_header(G_design, "Reading config file '%s' done !\n", config_file.c_str());

    show_config_file();

    config_file_success = true;
  }


  // -------------------------
  // getNumberOfLuts
  // -------------------------
  int getNumberOfLuts() {

     int nb = 0;

     if (!G_design) {
       log_warning("Design seems empty !\n");
       return -1;
     }

     for (auto cell : G_design->top_module()->cells()) {
         if (cell->type.in(ID($lut))) {
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

     if (!G_design) {
       log_warning("Design seems empty !\n");
       return -1;
     }

     for (auto cell : G_design->top_module()->cells()) {
         if (cell->type.in(ID(dff), ID(dffe), ID(dffr), ID(dffer),
                           ID(dffs), ID(dffrs), ID(dffes), ID(dffers))) {
           nb++;
         }
     }

     return nb;
  }

  // -------------------------
  // dump_csv_file 
  // -------------------------
  void dump_csv_file(string fileName, int runTime)
  {
     if (!G_design) {
       log_warning("Design seems empty !\n");
       return;
     }

     // -----
     // Get all the stats 
     //
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
     if (!show_max_level) {
         run("max_level -summary"); // -> store 'maxlvl' in scratchpad 
	                            // with 'max_level.max_levels'

	 maxlvl = G_design->scratchpad_get_int("max_level.max_levels", 0);
     }

     // -----
     // Open the csv file and dump the stats.
     //
     std::ofstream csv_file(fileName);

     csv_file << topName + ",";
     csv_file << std::to_string(nbLuts) + ",";
     csv_file << std::to_string(nbDffs) + ",";
     csv_file << std::to_string(maxlvl) + ",";
     csv_file << std::to_string(runTime);
     csv_file << std::endl;

     csv_file.close();

     log("\n   Dumped file %s\n", fileName.c_str());
  }

  // -------------------------
  // load_dff_bb_models 
  // -------------------------
  void load_dff_bb_models()
  {
     run("read_verilog +/yosys-syn/SRC/FF_MODELS/dff.v");
     run("read_verilog +/yosys-syn/SRC/FF_MODELS/dffe.v");
     run("read_verilog +/yosys-syn/SRC/FF_MODELS/dffr.v");
     run("read_verilog +/yosys-syn/SRC/FF_MODELS/dffs.v");
     run("read_verilog +/yosys-syn/SRC/FF_MODELS/dffrs.v");
     run("read_verilog +/yosys-syn/SRC/FF_MODELS/dffer.v");
     run("read_verilog +/yosys-syn/SRC/FF_MODELS/dffes.v");
     run("read_verilog +/yosys-syn/SRC/FF_MODELS/dffers.v");

     run("blackbox dff dffe dffr dffs dffrs dffer dffes dffers");
  }

  // -------------------------
  // dbg_wait 
  // -------------------------
  void dbg_wait ()
  {  
     if (wait) {
       getchar();
     }
  }

  // -------------------------
  // getNumberOfCells
  // -------------------------
  int getNumberOfCells() {
     return ((G_design->top_module()->cells()).size());
  }

  // -------------------------
  // clean_design 
  // -------------------------
  void clean_design(int use_dff_bb_models)
  {
     if (0 || obs_clean) {

        run("splitcells");

        run("splitnets");

	if (use_dff_bb_models) {

	  // Load black box models to get IOs directions for 
	  // 'obs_clean'
	  //
          load_dff_bb_models();
	}

        run("obs_clean");

        run("hierarchy");

     } else {

        run("opt_clean");
     }
  }

  // -------------------------
  // abc_synthesize 
  // -------------------------
  void abc_synthesize()
  {
    if (!G_design) {
       log_warning("Design seems empty !\n");
       return;
    }

    if (opt == "") {
       log_header(G_design, "Performing OFFICIAL PLATYPUS optimization\n");
       run("abc -lut " + sc_syn_lut_size);
       return;
    }

    string mode = opt;

    // Switch to FAST ABC synthesis script for huge designs in order to avoid
    // runtime blow up.
    //
    // ex: 'ifu', 'l2c', 'e203' designs will be impacted with sometime slight max
    // level degradation but with nice speed-up (ex: 'e203' from 5000 sec. downto
    // 1400 sec.)
    //
    int nb_cells = getNumberOfCells();

    if (nb_cells >= HUGE_NB_CELLS) { // example : 'zmcml' from Golden suite

      mode  = "huge";

      log_warning("Optimization script changed from '%s' to '%s' due to design size (%d cells)\n",
                  opt.c_str(), mode.c_str(), nb_cells);

    } else if (nb_cells >= BIG_NB_CELLS) { // example : 'e203_soc_top' from Golden suite

      mode  = "fast";

      log_warning("Optimization script changed from '%s' to '%s' due to design size (%d cells)\n",
                  opt.c_str(), mode.c_str(), nb_cells);
    }

    // Otherwise specific ABC script based flow
    //
    string abc_script = "+/yosys-syn/SRC/ABC_SCRIPTS/LUT" + sc_syn_lut_size + 
	                "/" + abc_script_version + "/" + mode + "_lut" + 
			sc_syn_lut_size + ".scr";

    log_header(G_design, "Calling ABC script in '%s' mode\n", mode.c_str());

    run("abc -script " + abc_script);
  }

  // -------------------------
  // legalize_flops
  // -------------------------
  // Code picked up from procedure 'legalize_flops' in TCL 
  // 'sc_synth_fpga.tcl' (Thierry)
  // DFF features considered so far : 
  //     - enable
  //     - async_set
  //     - async_reset
  //
  void legalize_flops ()
  {

    // Consider all feature combinations 'enable" x "async_set' x 
    // 'async_reset' when features are supported or not : 2x2x2 = 8 
    // combinations to handle.
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

  // -------------------------
  // infer_BRAMs
  // -------------------------
  void infer_BRAMs()
  {
     if (1 && !bram) {
       return;
     }

     string sc_syn_bram_memory_libmap = "memory_libmap -lib " + ys_brams_memory_libmap;
     string sc_syn_bram_techmap = "techmap -map " + ys_brams_techmap;

     //log("Call %s\n", sc_syn_bram_memory_libmap.c_str());
     //
     log("\nWARNING: Make sure you are using the right 'partname' for the BRAM inference in case of failure.\n");
     run(sc_syn_bram_memory_libmap);


     //log("Call %s\n", sc_syn_bram_techmap.c_str());
     //
     log("\nWARNING: Make sure you are using the right 'partname' for the BRAM inference in case of failure.\n");
     run(sc_syn_bram_techmap);

#if 0
     // Current Zero Asic calls to BRAM inference
     //
     run("stat");

     run("memory_libmap -lib +/yosys-syn/ARCHITECTURE/" + part_name + "/BRAM/bram_memory_map.txt");

     run("techmap -map +/yosys-syn/ARCHITECTURE/" + part_name + "/BRAM/tech_bram.v");

#endif

     run("stat");
  }

  // -------------------------
  // infer_DSPs
  // -------------------------
  void infer_DSPs()
  {
     if (!dsp48) {
       return;
     }

     run("stat");

     run("memory_dff"); // 'dsp' will merge registers, reserve memory port registers first

     string sc_syn_dsps_techmap = "techmap -map +/mul2dsp.v -map " + ys_dsps_techmap + " ";

     for (auto it : ys_dsps_parameter_int) {
         sc_syn_dsps_techmap += "-D " + it.first + "=" + std::to_string(it.second) + " ";
     }
     for (auto it : ys_dsps_parameter_string) {
         sc_syn_dsps_techmap += "-D " + it.first + "=" + it.second + " ";
     }

#if 0
     log("Call %s\n", sc_syn_dsps_techmap.c_str());
#endif

     log("\nWARNING: Make sure you are using the right 'partname' for the DSP inference in case of failure.\n");
     run(sc_syn_dsps_techmap);

     run("stat");

     run("select a:mul2dsp");
     run("setattr -unset mul2dsp");
     run("opt_expr -fine");
     run("wreduce");
     run("select -clear");
     run("dsp -family DSP48");
     run("chtype -set $mul t:$__soft_mul");

     run("stat");
  }

  // -------------------------
  // resynthesize
  // -------------------------
  // Avoid the heavy synthesis flow and performs a light structural synthesis
  // because we are re-optimizing and re-mapping a netlist.
  //
  void resynthesize() 
  {
    run("stat");

    run("proc");

    run("flatten");

    run("techmap -map +/techmap.v");

    run("techmap");

    run("opt -fast");
    run("opt_clean");

    // Call light 'opt' if design is huge (ex: 'zmcml')
    //
    if (getNumberOfCells() <= HUGE_NB_CELLS) {
       run("opt -full");
    } else {
       run("opt_expr");
       run("opt_clean");
    }

    legalize_flops ();

    string sc_syn_flop_library = ys_dff_techmap;
    run("techmap -map " + sc_syn_flop_library);

    run("techmap");
    
    // Call light 'opt' if design is huge (ex: 'zmcml')
    //
    if (getNumberOfCells() <= HUGE_NB_CELLS) {
       run("opt -purge");
    } else {
       run("opt_expr");
       run("opt_clean");
    }

    if (insbuf) {
      run("insbuf");
    }

    clean_design(1);

    run("stat");
    abc_synthesize();

    run("setundef -zero");
    run("clean -purge");

    run("stat");
  }

  // -------------------------
  // coarse_synthesis
  // -------------------------
  void coarse_synthesis()
  {
    run("opt_expr");
    run("opt_clean");
    run("check");
    run("opt -nodffe -nosdff");
    run("fsm");
    run("opt");
    run("wreduce");
    run("peepopt");
    run("opt_clean");
    run("share");
    run("techmap -map +/cmp2lut.v -D LUT_WIDTH=" + sc_syn_lut_size);
    run("opt_expr");
    run("opt_clean");
  }

  // -------------------------
  // help
  // -------------------------
  //
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

	log("    -config <file name>\n");
	log("        Specifies the config file setting main 'synth_fpga' parameters.\n");
        log("\n");

	log("    -show_config\n");
	log("        Show the parameters set by the config file.\n");
        log("\n");

        log("    -no_flatten\n");
        log("        skip flatening. By default, design is flatened.\n");
        log("\n");

        log("    -opt\n");
        log("        specifies the optimization target : area, delay, default, fast.\n");
        log("\n");

        log("    -partname\n");
        log("        Specifies the Architecture partname used. By default it is Z1000.\n");
        log("\n");

        log("    -use_BRAM\n");
        log("        Invoke BRAM inference. It is off by default.\n");
        log("\n");

        log("    -use_DSP48\n");
        log("        Invoke DSP48 inference. It is off by default.\n");
        log("\n");

        log("    -resynthesis\n");
        log("        switch synthesis flow to resynthesis mode which means a lighter flow.\n");
        log("        It can be used only after performing a first 'synth_fpga' synthesis pass \n");
        log("\n");

        log("    -insbuf\n");
        log("        performs buffers insertion (off by default).\n");
        log("\n");

        log("    -autoname\n");
        log("        Generate, if possible, better wire and cells names close to RTL names rather than\n");
        log("        $abc generic names.\n");
        log("\n");

	// DFF related options
	//
        log("    -no_dff_enable\n");
        log("        specifies that DFF with enable feature is not supported. By default,\n");
        log("        DFF with enable is supported.\n");
        log("\n");
        log("    -no_dff_async_set\n");
        log("        specifies that DFF with asynchronous set feature is not supported. By default,\n");
        log("        DFF with asynchronous set is supported.\n");
        log("\n");
        log("    -no_dff_async_reset\n");
        log("        specifies that DFF with asynchronous reset feature is not supported. By default,\n");
        log("        DFF with asynchronous reset is supported.\n");
        log("\n");
        log("    -no_seq_opt\n");
        log("        Disable SAT-based sequential optimizations. This is off by default.\n");
        log("\n");

        log("    -obs_clean\n");
        log("        specifies to use 'obs_clean' cleanup function instead of regular \n");
        log("        'opt_clean'.\n");
        log("\n");

        log("    -lut_size\n");
        log("        specifies lut size. By default lut size is 4.\n");
        log("\n");

        log("    -verilog <file>\n");
        log("        write the design to the specified Verilog netlist file. writing of an\n");
        log("        output file is omitted if this parameter is not specified.\n");
	log("\n");

        log("    -show_max_level\n");
        log("        Show longest paths.\n");
        log("\n");

        log("    -csv\n");
        log("        Dump a 'stat.csv' file.\n");
        log("\n");

        log("    -wait\n");
        log("        wait after each 'stat' report for user to touch <enter> key. Help for \n");
        log("        flow analysis/debug.\n");
        log("\n");

	log("The following Yosys commands are executed underneath by 'synth_fpga' :\n");

	help_script();
	log("\n");
  }

  // -------------------------
  // clear_flags
  // -------------------------
  // set default values for global parameters
  //
  void clear_flags() override
  {
	top_opt = "-auto-top";
	opt = "";

	part_name = "Z1000";

	no_flatten = false;
	no_seq_opt = false;
	autoname = false;
	dsp48 = false;
	bram = false;
	resynthesis = false;
	show_config = false;
	show_max_level = false;
	csv = false;
	insbuf = false;

	wait = false;

	dff_enable = true;
	dff_async_set = true;
	dff_async_reset = true;

	obs_clean = false;

	verilog_file = "";

	abc_script_version = "BEST";

	sc_syn_lut_size = "4";
	config_file = "";
	config_file_success = false;
  }

  // -------------------------
  // execute
  // -------------------------
  //
  void execute(std::vector<std::string> args, RTLIL::Design *design) override
  {
	string run_from, run_to;
	clear_flags();

        log_header(design, "Executing 'synth_fpga'\n\n");

	G_design = design;

	size_t argidx;

	for (argidx = 1; argidx < args.size(); argidx++)
        {
          if (args[argidx] == "-top" && argidx+1 < args.size()) {
 	     top_opt = "-top " + args[++argidx];
	     continue;
	  }

          if (args[argidx] == "-config" && argidx+1 < args.size()) {
 	     config_file = args[++argidx];
	     continue;
	  }

          if (args[argidx] == "-show_config") {
             show_config = true;
             continue;
          }

	  if (args[argidx] == "-opt" && argidx+1 < args.size()) {
	     opt = args[++argidx];
	     if (opt_options.count(opt) == 0) {
                log_cmd_error("-opt option '%s' is unknown. Please see help.\n", 
                              (args[argidx]).c_str());
	     }
	     continue;
          }

          if (args[argidx] == "-resynthesis") {
             resynthesis = true;
             continue;
          }

          if (args[argidx] == "-no_flatten") {
             no_flatten = true;
             continue;
          }

          if (args[argidx] == "-no_seq_opt") {
             no_seq_opt = true;
             continue;
          }

          if (args[argidx] == "-use_BRAM") {
             bram = true;
             continue;
          }

          if (args[argidx] == "-use_DSP48") {
             dsp48 = true;
             continue;
          }

          if (args[argidx] == "-insbuf") {
             insbuf = true;
             continue;
          }

          if (args[argidx] == "-autoname") {
             autoname = true;
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

	  if (args[argidx] == "-abc_script_version" && argidx+1 < args.size()) {
             abc_script_version = args[++argidx];
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

          if (args[argidx] == "-show_max_level") {
             show_max_level = true;
             continue;
          }

          if (args[argidx] == "-csv") {
             csv = true;
             continue;
          }

          // for debug, flow analysis
          //
	  if (args[argidx] == "-wait") {
             wait = true;
             continue;
          }

          log_cmd_error("Unknown option : %s\n", (args[argidx]).c_str());
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
  // script (synth_fpga flow) 
  // ---------------------------------------------------------------------------
  //
  // VERSION 1.0 (05/13/2025, Thierry): 
  //
  //        - as a starter, we mimic what is done in : 
  //          '.../siliconcompiler/tools/yosys/sc_synth_fpga.tcl' 
  //
  //        - we try to handle DFF legalization by taking care of DFF features
  //        support like handling DFF with 'enable', 'async_set', 'async_reset'.
  //
  // ---------------------------------------------------------------------------
  void script() override
  {

    if (!G_design) {
       log_warning("Design seems empty !\n");
       return;
    }

    auto startTime = std::chrono::high_resolution_clock::now();

    log("\nPLATYPUS flow using 'synth_fpga' Yosys plugin command\n");

    log("'Zero Asic' FPGA Synthesis Version : %s\n", SYNTH_FPGA_VERSION);

    // Read eventually config file that will setup main synthesis options like
    // partname, lut size, DFF models, DSP and BRAM techmap files, ...
    //
    read_config();

    // We setup the options according to 'config' file, if any, and command
    // line options.
    // If options conflict (ex: lut_size) between the two, 'config' file 
    // setting has the priority over 'synth_fpga' explicit option setting.
    //
    setup_options();

    // Check that all options are valid. 
    // Example : check that the 'partname' do exist.
    //
    check_options();

    // Check hierarch and find the TOP
    //
    run(stringf("hierarchy -check %s", help_mode ? "-top <top>" : top_opt.c_str()));

    Module* topModule = G_design->top_module();

    if (!topModule) {
       log_warning("Design seems empty !\n");
       return;
    }

    // In case user invokes resynthsis at the command line level, 
    // performs a light weight synthesis for the second time.
    //
    if (resynthesis) {

       resynthesize();
       return;
    }

    run("proc");

    dbg_wait();

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

    // Other hard macro passes can happen after the generic optimization
    // passes take place.

    // Generic optimization passes; this is a fusion of the VTR reference
    // flow and the Yosys synth_ice40 flow
    //
    coarse_synthesis();

    // Extra line added versus 'sc_synth_fpga.tcl' tcl script version
    //
    run("stat");

    dbg_wait();

    // Here is a remaining customization pass for DSP tech mapping
    // Map DSP blocks before doing anything else,
    // so that we don't convert any math blocks
    // into other primitives
    //
    // Map DSP components
    //
    infer_DSPs();

    // Mimic ICE40 flow by running an alumacc and memory -nomap passes
    // after DSP mapping
    //  
    run("alumacc");
    run("opt");
    run("memory -nomap");

    run("design -save copy");

    // First strategy : we deeply optimize logic but we may break its
    // nice structure than can map in nice DFF enable 
    // (ex: big_designs/VexRiscv).
    // But it may help for some designs (ex: medium_designs/xtea)
    //
    run("opt -full");
    
    run("techmap -map +/techmap.v");

    // BRAM inference 
    //
    infer_BRAMs();

    // After doing memory mapping, turn any remaining
    // $mem_v2 instances into flop arrays
    //
    run("memory_map");

    run("demuxmap");
    run("simplemap");

    // Call the zero asic version of 'opt_dff', e.g 'zopt_dff', especially 
    // taking care of the -sat option.
    //
    if (!no_seq_opt) {
      run("stat");
      run("zopt_dff -sat");
    }

    // Extra lines that help to win Area (ex: vga_lcd from 31K Lut4 downto 14.8K)
    //
    // IMPROVE-2
    //
    run("techmap");

#if 0
    run("opt -fast");

    run("opt_clean");
    // END IMPROVE-2
#endif

    // Performs 'opt' pass with lightweight version for HUGE designs.
    //
    if (getNumberOfCells() <= HUGE_NB_CELLS) {
       run("opt -full");
    } else {
       run("opt_expr");
       run("opt_clean");
    }

    // original TCL call : legalize_flops $sc_syn_feature_set
    //
    legalize_flops (); // C++ version of TCL call

    // C++ Version
    //
    // Map on the DFF of the architecture (partname)
    //
    string sc_syn_flop_library = ys_dff_techmap;
    run("techmap -map " + sc_syn_flop_library);

    // 'post_techmap' without arguments gives the following 
    // according to '.../siliconcompiler/tools/yosys/procs.tcl'
    // IMPROVE-1
    //
    run("techmap");

    // Performs 'opt' pass with lightweight version for HUGE designs.
    //
    if (getNumberOfCells() <= HUGE_NB_CELLS) {
       run("opt -purge");
    } else {
       run("opt_expr");
       run("opt_clean");
    }
    // END IMPROVE-1

    // Perform preliminary buffer insertion before passing to ABC to help reduce
    // the overhead of final buffer insertion downstream
    //
    if (insbuf) {
      run("insbuf");
    }

    run("stat");

    dbg_wait();

    clean_design(1);

    run("stat");

    dbg_wait();

    // Optimize and map through ABC the combinational logic part of the design.
    //
    run("stat");
    abc_synthesize();

    run("stat");

    dbg_wait();

    run("opt_lut_ins");
    run("opt_lut");

    run("setundef -zero");
    run("clean -purge");

    // tries to give public names instead of using $abc generic names.
    // Right now this procedure blows up runtime for medium/big designs
    //
    if (autoname) {
      run("autoname");
    }

    if (!verilog_file.empty()) {

       log("Dump Verilog file '%s'\n", verilog_file.c_str()); 
       run(stringf("write_verilog -noexpr -nohex -nodec %s", verilog_file.c_str()));

    } else { // Still dump verilog under the hood for debug/analysis reasons.

       run(stringf("write_verilog -noexpr -nohex -nodec %s", "netlist_synth_fpga.verilog"));
    }

    run("stat");

    auto endTime = std::chrono::high_resolution_clock::now();
    auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(endTime - startTime);

    float totalTime = 1 + elapsed.count() * 1e-9;

    log("   PartName : %s\n", part_name.c_str());
    log("\n");
    log("   'Zero Asic' FPGA Synthesis Version : %s\n", SYNTH_FPGA_VERSION);
    log("\n");
    log("   Total Synthesis Run Time = %.1f sec.\n", totalTime);

    // Show longest path in 'delay' mode
    //
    if (show_max_level) {
      run("max_level"); // -> store 'maxlvl' in scratchpad with 'max_level.max_levels'
    }

    if (csv) {
       dump_csv_file("stat.csv", (int)totalTime);
    }

  } // end script()

} SynthFpgaPass;

PRIVATE_NAMESPACE_END
