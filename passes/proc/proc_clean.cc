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
#include "kernel/log.h"
#include <stdlib.h>
#include <stdio.h>

YOSYS_NAMESPACE_BEGIN
extern void proc_clean_case(RTLIL::CaseRule *cs, bool &did_something, int &count, int max_depth);
YOSYS_NAMESPACE_END

USING_YOSYS_NAMESPACE
PRIVATE_NAMESPACE_BEGIN

void proc_clean_switch(RTLIL::SwitchRule *sw, RTLIL::CaseRule *parent, bool &did_something, int &count, int max_depth)
{
	if (sw->signal.size() > 0 && sw->signal.is_fully_def())
	{
		int found_matching_case_idx = -1;
		for (int i = 0; i < int(sw->cases.size()) && found_matching_case_idx < 0; i++)
		{
			RTLIL::CaseRule *cs = sw->cases[i];
			if (cs->compare.size() == 0)
				break;
			for (int j = 0; j < int(cs->compare.size()); j++) {
				RTLIL::SigSpec &val = cs->compare[j];
				if (!val.is_fully_def())
					continue;
				if (val == sw->signal) {
					cs->compare.clear();
					found_matching_case_idx = i;
					break;
				} else
					cs->compare.erase(cs->compare.begin()+(j--));
			}
			if (cs->compare.size() == 0 && found_matching_case_idx < 0) {
				sw->cases.erase(sw->cases.begin()+(i--));
				delete cs;
			}
		}
		while (found_matching_case_idx >= 0 && int(sw->cases.size()) > found_matching_case_idx+1) {
			delete sw->cases.back();
			sw->cases.pop_back();
		}
		if (found_matching_case_idx == 0)
			sw->signal = RTLIL::SigSpec();
	}

	if (parent->switches.front() == sw && sw->cases.size() == 1 &&
			(sw->signal.size() == 0 || sw->cases[0]->compare.empty()))
	{
		did_something = true;
		for (auto &action : sw->cases[0]->actions)
			parent->actions.push_back(action);
		parent->switches.insert(parent->switches.begin(), sw->cases[0]->switches.begin(), sw->cases[0]->switches.end());
		sw->cases[0]->switches.clear();
		delete sw->cases[0];
		sw->cases.clear();
	}
	else
	{
		for (auto cs : sw->cases)
			if (max_depth != 0)
				proc_clean_case(cs, did_something, count, max_depth-1);

		bool is_parallel_case = sw->get_bool_attribute(ID::parallel_case);
		bool is_full_case = sw->get_bool_attribute(ID::full_case);

		// Empty case removal.  The rules are:
		//
		// - for full_case: only remove cases if *all* cases are empty
		// - for parallel_case but not full_case: remove any empty case
		// - for non-parallel and non-full case: remove the final case if it's empty

		if (is_full_case)
		{
			bool all_empty = true;
			for (auto cs : sw->cases)
				if (!cs->empty())
					all_empty = false;
			if (all_empty)
			{
				for (auto cs : sw->cases)
					delete cs;
				sw->cases.clear();
			}
		}
		else if (is_parallel_case)
		{
			for (auto cs = sw->cases.begin(); cs != sw->cases.end();)
			{
				if ((*cs)->empty())
				{
					did_something = true;
					delete *cs;
					cs = sw->cases.erase(cs);
				}
				else ++cs;
			}
		}
		else
		{
			while (!sw->cases.empty() && sw->cases.back()->empty())
			{
				did_something = true;
				delete sw->cases.back();
				sw->cases.pop_back();
			}
		}
	}
}

PRIVATE_NAMESPACE_END
YOSYS_NAMESPACE_BEGIN

void proc_clean_case(RTLIL::CaseRule *cs, bool &did_something, int &count, int max_depth)
{
	for (size_t i = 0; i < cs->actions.size(); i++) {
		if (cs->actions[i].first.size() == 0) {
			did_something = true;
			cs->actions.erase(cs->actions.begin() + (i--));
		}
	}
	for (size_t i = 0; i < cs->switches.size(); i++) {
		RTLIL::SwitchRule *sw = cs->switches[i];
		if (sw->empty()) {
			cs->switches.erase(cs->switches.begin() + (i--));
			did_something = true;
			delete sw;
			count++;
		} else if (max_depth != 0)
			proc_clean_switch(sw, cs, did_something, count, max_depth-1);
	}
}

YOSYS_NAMESPACE_END
PRIVATE_NAMESPACE_BEGIN

void proc_clean(RTLIL::Module *mod, RTLIL::Process *proc, int &total_count, bool quiet)
{
	int count = 0;
	bool did_something = true;
	for (size_t i = 0; i < proc->syncs.size(); i++) {
		for (size_t j = 0; j < proc->syncs[i]->actions.size(); j++)
			if (proc->syncs[i]->actions[j].first.size() == 0)
				proc->syncs[i]->actions.erase(proc->syncs[i]->actions.begin() + (j--));
		if (proc->syncs[i]->actions.size() == 0 && proc->syncs[i]->mem_write_actions.size() == 0) {
			delete proc->syncs[i];
			proc->syncs.erase(proc->syncs.begin() + (i--));
		}
	}
	while (did_something) {
		did_something = false;
		proc_clean_case(&proc->root_case, did_something, count, -1);
	}
	if (count > 0 && !quiet)
		log("Found and cleaned up %d empty switch%s in `%s.%s'.\n", count, count == 1 ? "" : "es", mod->name.c_str(), proc->name.c_str());
	total_count += count;
}

struct ProcCleanPass : public Pass {
	ProcCleanPass() : Pass("proc_clean", "remove empty parts of processes") { }
	void help() override
	{
		//   |---v---|---v---|---v---|---v---|---v---|---v---|---v---|---v---|---v---|---v---|
		log("\n");
		log("    proc_clean [options] [selection]\n");
		log("\n");
		log("    -quiet\n");
		log("        do not print any messages.\n");
		log("\n");
		log("This pass removes empty parts of processes and ultimately removes a process\n");
		log("if it contains only empty structures.\n");
		log("\n");
	}
	void execute(std::vector<std::string> args, RTLIL::Design *design) override
	{
		int total_count = 0;
		bool quiet = false;

		if (find(args.begin(), args.end(), "-quiet") == args.end())
			log_header(design, "Executing PROC_CLEAN pass (remove empty switches from decision trees).\n");

		size_t argidx;
		for (argidx = 1; argidx < args.size(); argidx++)
		{
			if (args[argidx] == "-quiet") {
				quiet = true;
				continue;
			}
		}
		extra_args(args, argidx, design);

		for (auto mod : design->all_selected_modules()) {
			std::vector<RTLIL::Process *> delme;
			for (auto proc : mod->selected_processes()) {
				proc_clean(mod, proc, total_count, quiet);
				if (proc->syncs.size() == 0 && proc->root_case.switches.size() == 0 &&
						proc->root_case.actions.size() == 0) {
					if (!quiet)
						log("Removing empty process `%s.%s'.\n", log_id(mod), proc->name.c_str());
					delme.push_back(proc);
				}
			}
			for (auto proc : delme) {
				mod->remove(proc);
			}
		}

		if (!quiet)
			log("Cleaned up %d empty switch%s.\n", total_count, total_count == 1 ? "" : "es");
	}
} ProcCleanPass;

PRIVATE_NAMESPACE_END
