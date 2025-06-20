cell_help["$_BUF_"] = {
  "$_BUF_",
  "",
  "(A, Y)",
  "simcells.v:40",
  "A buffer. This cell type is always optimized away by the opt_clean pass.\n::\n\n   Truth table:    A | Y\n                  ---+---\n                   0 | 0\n                   1 | 1",
  "module \\$_BUF_ (A, Y);\n    input A;\n    output Y;\n    assign Y = A;\nendmodule",
  "comb_simple",
  "2a",
  "",
};

cell_help["$_NOT_"] = {
  "$_NOT_",
  "",
  "(A, Y)",
  "simcells.v:58",
  "An inverter gate.\n::\n\n   Truth table:    A | Y\n                  ---+---\n                   0 | 1\n                   1 | 0",
  "module \\$_NOT_ (A, Y);\n    input A;\n    output Y;\n    assign Y = ~A;\nendmodule",
  "comb_simple",
  "2a",
  "",
};

cell_help["$_AND_"] = {
  "$_AND_",
  "",
  "(A, B, Y)",
  "simcells.v:78",
  "A 2-input AND gate.\n::\n\n   Truth table:    A B | Y\n                  -----+---\n                   0 0 | 0\n                   0 1 | 0\n                   1 0 | 0\n                   1 1 | 1",
  "module \\$_AND_ (A, B, Y);\n    input A, B;\n    output Y;\n    assign Y = A & B;\nendmodule",
  "comb_simple",
  "2a",
  "",
};

cell_help["$_NAND_"] = {
  "$_NAND_",
  "",
  "(A, B, Y)",
  "simcells.v:98",
  "A 2-input NAND gate.\n::\n\n   Truth table:    A B | Y\n                  -----+---\n                   0 0 | 1\n                   0 1 | 1\n                   1 0 | 1\n                   1 1 | 0",
  "module \\$_NAND_ (A, B, Y);\n    input A, B;\n    output Y;\n    assign Y = ~(A & B);\nendmodule",
  "comb_simple",
  "2a",
  "",
};

cell_help["$_OR_"] = {
  "$_OR_",
  "",
  "(A, B, Y)",
  "simcells.v:118",
  "A 2-input OR gate.\n::\n\n   Truth table:    A B | Y\n                  -----+---\n                   0 0 | 0\n                   0 1 | 1\n                   1 0 | 1\n                   1 1 | 1",
  "module \\$_OR_ (A, B, Y);\n    input A, B;\n    output Y;\n    assign Y = A | B;\nendmodule",
  "comb_simple",
  "2a",
  "",
};

cell_help["$_NOR_"] = {
  "$_NOR_",
  "",
  "(A, B, Y)",
  "simcells.v:138",
  "A 2-input NOR gate.\n::\n\n   Truth table:    A B | Y\n                  -----+---\n                   0 0 | 1\n                   0 1 | 0\n                   1 0 | 0\n                   1 1 | 0",
  "module \\$_NOR_ (A, B, Y);\n    input A, B;\n    output Y;\n    assign Y = ~(A | B);\nendmodule",
  "comb_simple",
  "2a",
  "",
};

cell_help["$_XOR_"] = {
  "$_XOR_",
  "",
  "(A, B, Y)",
  "simcells.v:158",
  "A 2-input XOR gate.\n::\n\n   Truth table:    A B | Y\n                  -----+---\n                   0 0 | 0\n                   0 1 | 1\n                   1 0 | 1\n                   1 1 | 0",
  "module \\$_XOR_ (A, B, Y);\n    input A, B;\n    output Y;\n    assign Y = A ^ B;\nendmodule",
  "comb_simple",
  "2a",
  "",
};

cell_help["$_XNOR_"] = {
  "$_XNOR_",
  "",
  "(A, B, Y)",
  "simcells.v:178",
  "A 2-input XNOR gate.\n::\n\n   Truth table:    A B | Y\n                  -----+---\n                   0 0 | 1\n                   0 1 | 0\n                   1 0 | 0\n                   1 1 | 1",
  "module \\$_XNOR_ (A, B, Y);\n    input A, B;\n    output Y;\n    assign Y = ~(A ^ B);\nendmodule",
  "comb_simple",
  "2a",
  "",
};

cell_help["$_ANDNOT_"] = {
  "$_ANDNOT_",
  "",
  "(A, B, Y)",
  "simcells.v:198",
  "A 2-input AND-NOT gate.\n::\n\n   Truth table:    A B | Y\n                  -----+---\n                   0 0 | 0\n                   0 1 | 0\n                   1 0 | 1\n                   1 1 | 0",
  "module \\$_ANDNOT_ (A, B, Y);\n    input A, B;\n    output Y;\n    assign Y = A & (~B);\nendmodule",
  "comb_combined",
  "2a",
  "",
};

cell_help["$_ORNOT_"] = {
  "$_ORNOT_",
  "",
  "(A, B, Y)",
  "simcells.v:218",
  "A 2-input OR-NOT gate.\n::\n\n   Truth table:    A B | Y\n                  -----+---\n                   0 0 | 1\n                   0 1 | 0\n                   1 0 | 1\n                   1 1 | 1",
  "module \\$_ORNOT_ (A, B, Y);\n    input A, B;\n    output Y;\n    assign Y = A | (~B);\nendmodule",
  "comb_combined",
  "2a",
  "",
};

cell_help["$_MUX_"] = {
  "$_MUX_",
  "",
  "(A, B, S, Y)",
  "simcells.v:236",
  "A 2-input MUX gate.\n::\n\n   Truth table:    A B S | Y\n                  -------+---\n                   a - 0 | a\n                   - b 1 | b",
  "module \\$_MUX_ (A, B, S, Y);\n    input A, B, S;\n    output Y;\n    assign Y = S ? B : A;\nendmodule",
  "comb_simple",
  "2a",
  "",
};

cell_help["$_NMUX_"] = {
  "$_NMUX_",
  "",
  "(A, B, S, Y)",
  "simcells.v:256",
  "A 2-input inverting MUX gate.\n::\n\n   Truth table:    A B S | Y\n                  -------+---\n                   0 - 0 | 1\n                   1 - 0 | 0\n                   - 0 1 | 1\n                   - 1 1 | 0",
  "module \\$_NMUX_ (A, B, S, Y);\n    input A, B, S;\n    output Y;\n    assign Y = S ? !B : !A;\nendmodule",
  "comb_combined",
  "2a",
  "",
};

cell_help["$_MUX4_"] = {
  "$_MUX4_",
  "",
  "(A, B, C, D, S, T, Y)",
  "simcells.v:276",
  "A 4-input MUX gate.\n::\n\n   Truth table:    A B C D S T | Y\n                  -------------+---\n                   a - - - 0 0 | a\n                   - b - - 1 0 | b\n                   - - c - 0 1 | c\n                   - - - d 1 1 | d",
  "module \\$_MUX4_ (A, B, C, D, S, T, Y);\n    input A, B, C, D, S, T;\n    output Y;\n    assign Y = T ? (S ? D : C) :\n                   (S ? B : A);\nendmodule",
  "comb_combined",
  "2a",
  "",
};

cell_help["$_MUX8_"] = {
  "$_MUX8_",
  "",
  "(A, B, C, D, E, F, G, H, S, T, U, Y)",
  "simcells.v:301",
  "An 8-input MUX gate.\n::\n\n   Truth table:    A B C D E F G H S T U | Y\n                  -----------------------+---\n                   a - - - - - - - 0 0 0 | a\n                   - b - - - - - - 1 0 0 | b\n                   - - c - - - - - 0 1 0 | c\n                   - - - d - - - - 1 1 0 | d\n                   - - - - e - - - 0 0 1 | e\n                   - - - - - f - - 1 0 1 | f\n                   - - - - - - g - 0 1 1 | g\n                   - - - - - - - h 1 1 1 | h",
  "module \\$_MUX8_ (A, B, C, D, E, F, G, H, S, T, U, Y);\n    input A, B, C, D, E, F, G, H, S, T, U;\n    output Y;\n    assign Y = U ? T ? (S ? H : G) :\n                       (S ? F : E) :\n                   T ? (S ? D : C) :\n                       (S ? B : A);\nendmodule",
  "comb_combined",
  "2a",
  "",
};

cell_help["$_MUX16_"] = {
  "$_MUX16_",
  "",
  "(A, B, C, D, E, F, G, H, I, J, K, L, M, N, O, P, S, T, U, V, Y)",
  "simcells.v:336",
  "A 16-input MUX gate.\n::\n\n   Truth table:    A B C D E F G H I J K L M N O P S T U V | Y\n                  -----------------------------------------+---\n                   a - - - - - - - - - - - - - - - 0 0 0 0 | a\n                   - b - - - - - - - - - - - - - - 1 0 0 0 | b\n                   - - c - - - - - - - - - - - - - 0 1 0 0 | c\n                   - - - d - - - - - - - - - - - - 1 1 0 0 | d\n                   - - - - e - - - - - - - - - - - 0 0 1 0 | e\n                   - - - - - f - - - - - - - - - - 1 0 1 0 | f\n                   - - - - - - g - - - - - - - - - 0 1 1 0 | g\n                   - - - - - - - h - - - - - - - - 1 1 1 0 | h\n                   - - - - - - - - i - - - - - - - 0 0 0 1 | i\n                   - - - - - - - - - j - - - - - - 1 0 0 1 | j\n                   - - - - - - - - - - k - - - - - 0 1 0 1 | k\n                   - - - - - - - - - - - l - - - - 1 1 0 1 | l\n                   - - - - - - - - - - - - m - - - 0 0 1 1 | m\n                   - - - - - - - - - - - - - n - - 1 0 1 1 | n\n                   - - - - - - - - - - - - - - o - 0 1 1 1 | o\n                   - - - - - - - - - - - - - - - p 1 1 1 1 | p",
  "module \\$_MUX16_ (A, B, C, D, E, F, G, H, I, J, K, L, M, N, O, P, S, T, U, V, Y);\n    input A, B, C, D, E, F, G, H, I, J, K, L, M, N, O, P, S, T, U, V;\n    output Y;\n    assign Y = V ? U ? T ? (S ? P : O) :\n                           (S ? N : M) :\n                       T ? (S ? L : K) :\n                           (S ? J : I) :\n                   U ? T ? (S ? H : G) :\n                           (S ? F : E) :\n                       T ? (S ? D : C) :\n                           (S ? B : A);\nendmodule",
  "comb_combined",
  "2a",
  "",
};

cell_help["$_AOI3_"] = {
  "$_AOI3_",
  "",
  "(A, B, C, Y)",
  "simcells.v:367",
  "A 3-input And-Or-Invert gate.\n::\n\n   Truth table:    A B C | Y\n                  -------+---\n                   0 0 0 | 1\n                   0 0 1 | 0\n                   0 1 0 | 1\n                   0 1 1 | 0\n                   1 0 0 | 1\n                   1 0 1 | 0\n                   1 1 0 | 0\n                   1 1 1 | 0",
  "module \\$_AOI3_ (A, B, C, Y);\n    input A, B, C;\n    output Y;\n    assign Y = ~((A & B) | C);\nendmodule",
  "comb_combined",
  "2a",
  "",
};

cell_help["$_OAI3_"] = {
  "$_OAI3_",
  "",
  "(A, B, C, Y)",
  "simcells.v:391",
  "A 3-input Or-And-Invert gate.\n::\n\n   Truth table:    A B C | Y\n                  -------+---\n                   0 0 0 | 1\n                   0 0 1 | 1\n                   0 1 0 | 1\n                   0 1 1 | 0\n                   1 0 0 | 1\n                   1 0 1 | 0\n                   1 1 0 | 1\n                   1 1 1 | 0",
  "module \\$_OAI3_ (A, B, C, Y);\n    input A, B, C;\n    output Y;\n    assign Y = ~((A | B) & C);\nendmodule",
  "comb_combined",
  "2a",
  "",
};

cell_help["$_AOI4_"] = {
  "$_AOI4_",
  "",
  "(A, B, C, D, Y)",
  "simcells.v:423",
  "A 4-input And-Or-Invert gate.\n::\n\n   Truth table:    A B C D | Y\n                  ---------+---\n                   0 0 0 0 | 1\n                   0 0 0 1 | 1\n                   0 0 1 0 | 1\n                   0 0 1 1 | 0\n                   0 1 0 0 | 1\n                   0 1 0 1 | 1\n                   0 1 1 0 | 1\n                   0 1 1 1 | 0\n                   1 0 0 0 | 1\n                   1 0 0 1 | 1\n                   1 0 1 0 | 1\n                   1 0 1 1 | 0\n                   1 1 0 0 | 0\n                   1 1 0 1 | 0\n                   1 1 1 0 | 0\n                   1 1 1 1 | 0",
  "module \\$_AOI4_ (A, B, C, D, Y);\n    input A, B, C, D;\n    output Y;\n    assign Y = ~((A & B) | (C & D));\nendmodule",
  "comb_combined",
  "2a",
  "",
};

cell_help["$_OAI4_"] = {
  "$_OAI4_",
  "",
  "(A, B, C, D, Y)",
  "simcells.v:455",
  "A 4-input Or-And-Invert gate.\n::\n\n   Truth table:    A B C D | Y\n                  ---------+---\n                   0 0 0 0 | 1\n                   0 0 0 1 | 1\n                   0 0 1 0 | 1\n                   0 0 1 1 | 1\n                   0 1 0 0 | 1\n                   0 1 0 1 | 0\n                   0 1 1 0 | 0\n                   0 1 1 1 | 0\n                   1 0 0 0 | 1\n                   1 0 0 1 | 0\n                   1 0 1 0 | 0\n                   1 0 1 1 | 0\n                   1 1 0 0 | 1\n                   1 1 0 1 | 0\n                   1 1 1 0 | 0\n                   1 1 1 1 | 0",
  "module \\$_OAI4_ (A, B, C, D, Y);\n    input A, B, C, D;\n    output Y;\n    assign Y = ~((A | B) & (C | D));\nendmodule",
  "comb_combined",
  "2a",
  "",
};

cell_help["$_TBUF_"] = {
  "$_TBUF_",
  "",
  "(A, E, Y)",
  "simcells.v:473",
  "A tri-state buffer.\n::\n\n   Truth table:    A E | Y\n                  -----+---\n                   a 1 | a\n                   - 0 | z",
  "module \\$_TBUF_ (A, E, Y);\n    input A, E;\n    output Y;\n    assign Y = E ? A : 1'bz;\nendmodule",
  "gate_other",
  "2a",
  "",
};

cell_help["$_SR_NN_"] = {
  "$_SR_NN_",
  "",
  "(S, R, Q)",
  "simcells.v:497",
  "A set-reset latch with negative polarity SET and negative polarity RESET.\n::\n\n   Truth table:    S R | Q\n                  -----+---\n                   - 0 | 0\n                   0 - | 1\n                   - - | q",
  "module \\$_SR_NN_ (S, R, Q);\n    input S, R;\n    output reg Q;\n    always @* begin\n        if (R == 0)\n            Q <= 0;\n        else if (S == 0)\n            Q <= 1;\n    end\nendmodule",
  "reg_latch",
  "2a",
  "",
};

cell_help["$_SR_NP_"] = {
  "$_SR_NP_",
  "",
  "(S, R, Q)",
  "simcells.v:521",
  "A set-reset latch with negative polarity SET and positive polarity RESET.\n::\n\n   Truth table:    S R | Q\n                  -----+---\n                   - 1 | 0\n                   0 - | 1\n                   - - | q",
  "module \\$_SR_NP_ (S, R, Q);\n    input S, R;\n    output reg Q;\n    always @* begin\n        if (R == 1)\n            Q <= 0;\n        else if (S == 0)\n            Q <= 1;\n    end\nendmodule",
  "reg_latch",
  "2a",
  "",
};

cell_help["$_SR_PN_"] = {
  "$_SR_PN_",
  "",
  "(S, R, Q)",
  "simcells.v:545",
  "A set-reset latch with positive polarity SET and negative polarity RESET.\n::\n\n   Truth table:    S R | Q\n                  -----+---\n                   - 0 | 0\n                   1 - | 1\n                   - - | q",
  "module \\$_SR_PN_ (S, R, Q);\n    input S, R;\n    output reg Q;\n    always @* begin\n        if (R == 0)\n            Q <= 0;\n        else if (S == 1)\n            Q <= 1;\n    end\nendmodule",
  "reg_latch",
  "2a",
  "",
};

cell_help["$_SR_PP_"] = {
  "$_SR_PP_",
  "",
  "(S, R, Q)",
  "simcells.v:569",
  "A set-reset latch with positive polarity SET and positive polarity RESET.\n::\n\n   Truth table:    S R | Q\n                  -----+---\n                   - 1 | 0\n                   1 - | 1\n                   - - | q",
  "module \\$_SR_PP_ (S, R, Q);\n    input S, R;\n    output reg Q;\n    always @* begin\n        if (R == 1)\n            Q <= 0;\n        else if (S == 1)\n            Q <= 1;\n    end\nendmodule",
  "reg_latch",
  "2a",
  "",
};

cell_help["$_FF_"] = {
  "$_FF_",
  "",
  "(D, Q)",
  "simcells.v:589",
  "A D-type flip-flop that is clocked from the implicit global clock. (This cell\ntype is usually only used in netlists for formal verification.)",
  "module \\$_FF_ (D, Q);\n    input D;\n    output reg Q;\n    always @($global_clock) begin\n        Q <= D;\n    end\nendmodule",
  "reg_ff",
  "2a",
  "",
};

cell_help["$_DFF_N_"] = {
  "$_DFF_N_",
  "",
  "(D, C, Q)",
  "simcells.v:610",
  "A negative edge D-type flip-flop.\n::\n\n   Truth table:    D C | Q\n                  -----+---\n                   d \\ | d\n                   - - | q",
  "module \\$_DFF_N_ (D, C, Q);\n    input D, C;\n    output reg Q;\n    always @(negedge C) begin\n        Q <= D;\n    end\nendmodule",
  "reg_ff",
  "2a",
  "",
};

cell_help["$_DFF_P_"] = {
  "$_DFF_P_",
  "",
  "(D, C, Q)",
  "simcells.v:630",
  "A positive edge D-type flip-flop.\n::\n\n   Truth table:    D C | Q\n                  -----+---\n                   d / | d\n                   - - | q",
  "module \\$_DFF_P_ (D, C, Q);\n    input D, C;\n    output reg Q;\n    always @(posedge C) begin\n        Q <= D;\n    end\nendmodule",
  "reg_ff",
  "2a",
  "",
};

cell_help["$_DFFE_NN_"] = {
  "$_DFFE_NN_",
  "",
  "(D, C, E, Q)",
  "simcells.v:650",
  "A negative edge D-type flip-flop with negative polarity enable.\n::\n\n   Truth table:    D C E | Q\n                  -------+---\n                   d \\ 0 | d\n                   - - - | q",
  "module \\$_DFFE_NN_ (D, C, E, Q);\n    input D, C, E;\n    output reg Q;\n    always @(negedge C) begin\n        if (!E) Q <= D;\n    end\nendmodule",
  "reg_ff",
  "2a",
  "",
};

cell_help["$_DFFE_NP_"] = {
  "$_DFFE_NP_",
  "",
  "(D, C, E, Q)",
  "simcells.v:670",
  "A negative edge D-type flip-flop with positive polarity enable.\n::\n\n   Truth table:    D C E | Q\n                  -------+---\n                   d \\ 1 | d\n                   - - - | q",
  "module \\$_DFFE_NP_ (D, C, E, Q);\n    input D, C, E;\n    output reg Q;\n    always @(negedge C) begin\n        if (E) Q <= D;\n    end\nendmodule",
  "reg_ff",
  "2a",
  "",
};

cell_help["$_DFFE_PN_"] = {
  "$_DFFE_PN_",
  "",
  "(D, C, E, Q)",
  "simcells.v:690",
  "A positive edge D-type flip-flop with negative polarity enable.\n::\n\n   Truth table:    D C E | Q\n                  -------+---\n                   d / 0 | d\n                   - - - | q",
  "module \\$_DFFE_PN_ (D, C, E, Q);\n    input D, C, E;\n    output reg Q;\n    always @(posedge C) begin\n        if (!E) Q <= D;\n    end\nendmodule",
  "reg_ff",
  "2a",
  "",
};

cell_help["$_DFFE_PP_"] = {
  "$_DFFE_PP_",
  "",
  "(D, C, E, Q)",
  "simcells.v:710",
  "A positive edge D-type flip-flop with positive polarity enable.\n::\n\n   Truth table:    D C E | Q\n                  -------+---\n                   d / 1 | d\n                   - - - | q",
  "module \\$_DFFE_PP_ (D, C, E, Q);\n    input D, C, E;\n    output reg Q;\n    always @(posedge C) begin\n        if (E) Q <= D;\n    end\nendmodule",
  "reg_ff",
  "2a",
  "",
};

cell_help["$_DFF_NN0_"] = {
  "$_DFF_NN0_",
  "",
  "(D, C, R, Q)",
  "simcells.v:731",
  "A negative edge D-type flip-flop with negative polarity reset.\n::\n\n   Truth table:    D C R | Q\n                  -------+---\n                   - - 0 | 0\n                   d \\ - | d\n                   - - - | q",
  "module \\$_DFF_NN0_ (D, C, R, Q);\n    input D, C, R;\n    output reg Q;\n    always @(negedge C or negedge R) begin\n        if (R == 0)\n            Q <= 0;\n        else\n            Q <= D;\n    end\nendmodule",
  "reg_ff",
  "2a",
  "",
};

cell_help["$_DFF_NN1_"] = {
  "$_DFF_NN1_",
  "",
  "(D, C, R, Q)",
  "simcells.v:755",
  "A negative edge D-type flip-flop with negative polarity set.\n::\n\n   Truth table:    D C R | Q\n                  -------+---\n                   - - 0 | 1\n                   d \\ - | d\n                   - - - | q",
  "module \\$_DFF_NN1_ (D, C, R, Q);\n    input D, C, R;\n    output reg Q;\n    always @(negedge C or negedge R) begin\n        if (R == 0)\n            Q <= 1;\n        else\n            Q <= D;\n    end\nendmodule",
  "reg_ff",
  "2a",
  "",
};

cell_help["$_DFF_NP0_"] = {
  "$_DFF_NP0_",
  "",
  "(D, C, R, Q)",
  "simcells.v:779",
  "A negative edge D-type flip-flop with positive polarity reset.\n::\n\n   Truth table:    D C R | Q\n                  -------+---\n                   - - 1 | 0\n                   d \\ - | d\n                   - - - | q",
  "module \\$_DFF_NP0_ (D, C, R, Q);\n    input D, C, R;\n    output reg Q;\n    always @(negedge C or posedge R) begin\n        if (R == 1)\n            Q <= 0;\n        else\n            Q <= D;\n    end\nendmodule",
  "reg_ff",
  "2a",
  "",
};

cell_help["$_DFF_NP1_"] = {
  "$_DFF_NP1_",
  "",
  "(D, C, R, Q)",
  "simcells.v:803",
  "A negative edge D-type flip-flop with positive polarity set.\n::\n\n   Truth table:    D C R | Q\n                  -------+---\n                   - - 1 | 1\n                   d \\ - | d\n                   - - - | q",
  "module \\$_DFF_NP1_ (D, C, R, Q);\n    input D, C, R;\n    output reg Q;\n    always @(negedge C or posedge R) begin\n        if (R == 1)\n            Q <= 1;\n        else\n            Q <= D;\n    end\nendmodule",
  "reg_ff",
  "2a",
  "",
};

cell_help["$_DFF_PN0_"] = {
  "$_DFF_PN0_",
  "",
  "(D, C, R, Q)",
  "simcells.v:827",
  "A positive edge D-type flip-flop with negative polarity reset.\n::\n\n   Truth table:    D C R | Q\n                  -------+---\n                   - - 0 | 0\n                   d / - | d\n                   - - - | q",
  "module \\$_DFF_PN0_ (D, C, R, Q);\n    input D, C, R;\n    output reg Q;\n    always @(posedge C or negedge R) begin\n        if (R == 0)\n            Q <= 0;\n        else\n            Q <= D;\n    end\nendmodule",
  "reg_ff",
  "2a",
  "",
};

cell_help["$_DFF_PN1_"] = {
  "$_DFF_PN1_",
  "",
  "(D, C, R, Q)",
  "simcells.v:851",
  "A positive edge D-type flip-flop with negative polarity set.\n::\n\n   Truth table:    D C R | Q\n                  -------+---\n                   - - 0 | 1\n                   d / - | d\n                   - - - | q",
  "module \\$_DFF_PN1_ (D, C, R, Q);\n    input D, C, R;\n    output reg Q;\n    always @(posedge C or negedge R) begin\n        if (R == 0)\n            Q <= 1;\n        else\n            Q <= D;\n    end\nendmodule",
  "reg_ff",
  "2a",
  "",
};

cell_help["$_DFF_PP0_"] = {
  "$_DFF_PP0_",
  "",
  "(D, C, R, Q)",
  "simcells.v:875",
  "A positive edge D-type flip-flop with positive polarity reset.\n::\n\n   Truth table:    D C R | Q\n                  -------+---\n                   - - 1 | 0\n                   d / - | d\n                   - - - | q",
  "module \\$_DFF_PP0_ (D, C, R, Q);\n    input D, C, R;\n    output reg Q;\n    always @(posedge C or posedge R) begin\n        if (R == 1)\n            Q <= 0;\n        else\n            Q <= D;\n    end\nendmodule",
  "reg_ff",
  "2a",
  "",
};

cell_help["$_DFF_PP1_"] = {
  "$_DFF_PP1_",
  "",
  "(D, C, R, Q)",
  "simcells.v:899",
  "A positive edge D-type flip-flop with positive polarity set.\n::\n\n   Truth table:    D C R | Q\n                  -------+---\n                   - - 1 | 1\n                   d / - | d\n                   - - - | q",
  "module \\$_DFF_PP1_ (D, C, R, Q);\n    input D, C, R;\n    output reg Q;\n    always @(posedge C or posedge R) begin\n        if (R == 1)\n            Q <= 1;\n        else\n            Q <= D;\n    end\nendmodule",
  "reg_ff",
  "2a",
  "",
};

cell_help["$_DFFE_NN0N_"] = {
  "$_DFFE_NN0N_",
  "",
  "(D, C, R, E, Q)",
  "simcells.v:924",
  "A negative edge D-type flip-flop with negative polarity reset and negative\npolarity clock enable.\n::\n\n   Truth table:    D C R E | Q\n                  ---------+---\n                   - - 0 - | 0\n                   d \\ - 0 | d\n                   - - - - | q",
  "module \\$_DFFE_NN0N_ (D, C, R, E, Q);\n    input D, C, R, E;\n    output reg Q;\n    always @(negedge C or negedge R) begin\n        if (R == 0)\n            Q <= 0;\n        else if (E == 0)\n            Q <= D;\n    end\nendmodule",
  "reg_ff",
  "2a",
  "",
};

cell_help["$_DFFE_NN0P_"] = {
  "$_DFFE_NN0P_",
  "",
  "(D, C, R, E, Q)",
  "simcells.v:949",
  "A negative edge D-type flip-flop with negative polarity reset and positive\npolarity clock enable.\n::\n\n   Truth table:    D C R E | Q\n                  ---------+---\n                   - - 0 - | 0\n                   d \\ - 1 | d\n                   - - - - | q",
  "module \\$_DFFE_NN0P_ (D, C, R, E, Q);\n    input D, C, R, E;\n    output reg Q;\n    always @(negedge C or negedge R) begin\n        if (R == 0)\n            Q <= 0;\n        else if (E == 1)\n            Q <= D;\n    end\nendmodule",
  "reg_ff",
  "2a",
  "",
};

cell_help["$_DFFE_NN1N_"] = {
  "$_DFFE_NN1N_",
  "",
  "(D, C, R, E, Q)",
  "simcells.v:974",
  "A negative edge D-type flip-flop with negative polarity set and negative\npolarity clock enable.\n::\n\n   Truth table:    D C R E | Q\n                  ---------+---\n                   - - 0 - | 1\n                   d \\ - 0 | d\n                   - - - - | q",
  "module \\$_DFFE_NN1N_ (D, C, R, E, Q);\n    input D, C, R, E;\n    output reg Q;\n    always @(negedge C or negedge R) begin\n        if (R == 0)\n            Q <= 1;\n        else if (E == 0)\n            Q <= D;\n    end\nendmodule",
  "reg_ff",
  "2a",
  "",
};

cell_help["$_DFFE_NN1P_"] = {
  "$_DFFE_NN1P_",
  "",
  "(D, C, R, E, Q)",
  "simcells.v:999",
  "A negative edge D-type flip-flop with negative polarity set and positive\npolarity clock enable.\n::\n\n   Truth table:    D C R E | Q\n                  ---------+---\n                   - - 0 - | 1\n                   d \\ - 1 | d\n                   - - - - | q",
  "module \\$_DFFE_NN1P_ (D, C, R, E, Q);\n    input D, C, R, E;\n    output reg Q;\n    always @(negedge C or negedge R) begin\n        if (R == 0)\n            Q <= 1;\n        else if (E == 1)\n            Q <= D;\n    end\nendmodule",
  "reg_ff",
  "2a",
  "",
};

cell_help["$_DFFE_NP0N_"] = {
  "$_DFFE_NP0N_",
  "",
  "(D, C, R, E, Q)",
  "simcells.v:1024",
  "A negative edge D-type flip-flop with positive polarity reset and negative\npolarity clock enable.\n::\n\n   Truth table:    D C R E | Q\n                  ---------+---\n                   - - 1 - | 0\n                   d \\ - 0 | d\n                   - - - - | q",
  "module \\$_DFFE_NP0N_ (D, C, R, E, Q);\n    input D, C, R, E;\n    output reg Q;\n    always @(negedge C or posedge R) begin\n        if (R == 1)\n            Q <= 0;\n        else if (E == 0)\n            Q <= D;\n    end\nendmodule",
  "reg_ff",
  "2a",
  "",
};

cell_help["$_DFFE_NP0P_"] = {
  "$_DFFE_NP0P_",
  "",
  "(D, C, R, E, Q)",
  "simcells.v:1049",
  "A negative edge D-type flip-flop with positive polarity reset and positive\npolarity clock enable.\n::\n\n   Truth table:    D C R E | Q\n                  ---------+---\n                   - - 1 - | 0\n                   d \\ - 1 | d\n                   - - - - | q",
  "module \\$_DFFE_NP0P_ (D, C, R, E, Q);\n    input D, C, R, E;\n    output reg Q;\n    always @(negedge C or posedge R) begin\n        if (R == 1)\n            Q <= 0;\n        else if (E == 1)\n            Q <= D;\n    end\nendmodule",
  "reg_ff",
  "2a",
  "",
};

cell_help["$_DFFE_NP1N_"] = {
  "$_DFFE_NP1N_",
  "",
  "(D, C, R, E, Q)",
  "simcells.v:1074",
  "A negative edge D-type flip-flop with positive polarity set and negative\npolarity clock enable.\n::\n\n   Truth table:    D C R E | Q\n                  ---------+---\n                   - - 1 - | 1\n                   d \\ - 0 | d\n                   - - - - | q",
  "module \\$_DFFE_NP1N_ (D, C, R, E, Q);\n    input D, C, R, E;\n    output reg Q;\n    always @(negedge C or posedge R) begin\n        if (R == 1)\n            Q <= 1;\n        else if (E == 0)\n            Q <= D;\n    end\nendmodule",
  "reg_ff",
  "2a",
  "",
};

cell_help["$_DFFE_NP1P_"] = {
  "$_DFFE_NP1P_",
  "",
  "(D, C, R, E, Q)",
  "simcells.v:1099",
  "A negative edge D-type flip-flop with positive polarity set and positive\npolarity clock enable.\n::\n\n   Truth table:    D C R E | Q\n                  ---------+---\n                   - - 1 - | 1\n                   d \\ - 1 | d\n                   - - - - | q",
  "module \\$_DFFE_NP1P_ (D, C, R, E, Q);\n    input D, C, R, E;\n    output reg Q;\n    always @(negedge C or posedge R) begin\n        if (R == 1)\n            Q <= 1;\n        else if (E == 1)\n            Q <= D;\n    end\nendmodule",
  "reg_ff",
  "2a",
  "",
};

cell_help["$_DFFE_PN0N_"] = {
  "$_DFFE_PN0N_",
  "",
  "(D, C, R, E, Q)",
  "simcells.v:1124",
  "A positive edge D-type flip-flop with negative polarity reset and negative\npolarity clock enable.\n::\n\n   Truth table:    D C R E | Q\n                  ---------+---\n                   - - 0 - | 0\n                   d / - 0 | d\n                   - - - - | q",
  "module \\$_DFFE_PN0N_ (D, C, R, E, Q);\n    input D, C, R, E;\n    output reg Q;\n    always @(posedge C or negedge R) begin\n        if (R == 0)\n            Q <= 0;\n        else if (E == 0)\n            Q <= D;\n    end\nendmodule",
  "reg_ff",
  "2a",
  "",
};

cell_help["$_DFFE_PN0P_"] = {
  "$_DFFE_PN0P_",
  "",
  "(D, C, R, E, Q)",
  "simcells.v:1149",
  "A positive edge D-type flip-flop with negative polarity reset and positive\npolarity clock enable.\n::\n\n   Truth table:    D C R E | Q\n                  ---------+---\n                   - - 0 - | 0\n                   d / - 1 | d\n                   - - - - | q",
  "module \\$_DFFE_PN0P_ (D, C, R, E, Q);\n    input D, C, R, E;\n    output reg Q;\n    always @(posedge C or negedge R) begin\n        if (R == 0)\n            Q <= 0;\n        else if (E == 1)\n            Q <= D;\n    end\nendmodule",
  "reg_ff",
  "2a",
  "",
};

cell_help["$_DFFE_PN1N_"] = {
  "$_DFFE_PN1N_",
  "",
  "(D, C, R, E, Q)",
  "simcells.v:1174",
  "A positive edge D-type flip-flop with negative polarity set and negative\npolarity clock enable.\n::\n\n   Truth table:    D C R E | Q\n                  ---------+---\n                   - - 0 - | 1\n                   d / - 0 | d\n                   - - - - | q",
  "module \\$_DFFE_PN1N_ (D, C, R, E, Q);\n    input D, C, R, E;\n    output reg Q;\n    always @(posedge C or negedge R) begin\n        if (R == 0)\n            Q <= 1;\n        else if (E == 0)\n            Q <= D;\n    end\nendmodule",
  "reg_ff",
  "2a",
  "",
};

cell_help["$_DFFE_PN1P_"] = {
  "$_DFFE_PN1P_",
  "",
  "(D, C, R, E, Q)",
  "simcells.v:1199",
  "A positive edge D-type flip-flop with negative polarity set and positive\npolarity clock enable.\n::\n\n   Truth table:    D C R E | Q\n                  ---------+---\n                   - - 0 - | 1\n                   d / - 1 | d\n                   - - - - | q",
  "module \\$_DFFE_PN1P_ (D, C, R, E, Q);\n    input D, C, R, E;\n    output reg Q;\n    always @(posedge C or negedge R) begin\n        if (R == 0)\n            Q <= 1;\n        else if (E == 1)\n            Q <= D;\n    end\nendmodule",
  "reg_ff",
  "2a",
  "",
};

cell_help["$_DFFE_PP0N_"] = {
  "$_DFFE_PP0N_",
  "",
  "(D, C, R, E, Q)",
  "simcells.v:1224",
  "A positive edge D-type flip-flop with positive polarity reset and negative\npolarity clock enable.\n::\n\n   Truth table:    D C R E | Q\n                  ---------+---\n                   - - 1 - | 0\n                   d / - 0 | d\n                   - - - - | q",
  "module \\$_DFFE_PP0N_ (D, C, R, E, Q);\n    input D, C, R, E;\n    output reg Q;\n    always @(posedge C or posedge R) begin\n        if (R == 1)\n            Q <= 0;\n        else if (E == 0)\n            Q <= D;\n    end\nendmodule",
  "reg_ff",
  "2a",
  "",
};

cell_help["$_DFFE_PP0P_"] = {
  "$_DFFE_PP0P_",
  "",
  "(D, C, R, E, Q)",
  "simcells.v:1249",
  "A positive edge D-type flip-flop with positive polarity reset and positive\npolarity clock enable.\n::\n\n   Truth table:    D C R E | Q\n                  ---------+---\n                   - - 1 - | 0\n                   d / - 1 | d\n                   - - - - | q",
  "module \\$_DFFE_PP0P_ (D, C, R, E, Q);\n    input D, C, R, E;\n    output reg Q;\n    always @(posedge C or posedge R) begin\n        if (R == 1)\n            Q <= 0;\n        else if (E == 1)\n            Q <= D;\n    end\nendmodule",
  "reg_ff",
  "2a",
  "",
};

cell_help["$_DFFE_PP1N_"] = {
  "$_DFFE_PP1N_",
  "",
  "(D, C, R, E, Q)",
  "simcells.v:1274",
  "A positive edge D-type flip-flop with positive polarity set and negative\npolarity clock enable.\n::\n\n   Truth table:    D C R E | Q\n                  ---------+---\n                   - - 1 - | 1\n                   d / - 0 | d\n                   - - - - | q",
  "module \\$_DFFE_PP1N_ (D, C, R, E, Q);\n    input D, C, R, E;\n    output reg Q;\n    always @(posedge C or posedge R) begin\n        if (R == 1)\n            Q <= 1;\n        else if (E == 0)\n            Q <= D;\n    end\nendmodule",
  "reg_ff",
  "2a",
  "",
};

cell_help["$_DFFE_PP1P_"] = {
  "$_DFFE_PP1P_",
  "",
  "(D, C, R, E, Q)",
  "simcells.v:1299",
  "A positive edge D-type flip-flop with positive polarity set and positive\npolarity clock enable.\n::\n\n   Truth table:    D C R E | Q\n                  ---------+---\n                   - - 1 - | 1\n                   d / - 1 | d\n                   - - - - | q",
  "module \\$_DFFE_PP1P_ (D, C, R, E, Q);\n    input D, C, R, E;\n    output reg Q;\n    always @(posedge C or posedge R) begin\n        if (R == 1)\n            Q <= 1;\n        else if (E == 1)\n            Q <= D;\n    end\nendmodule",
  "reg_ff",
  "2a",
  "",
};

cell_help["$_ALDFF_NN_"] = {
  "$_ALDFF_NN_",
  "",
  "(D, C, L, AD, Q)",
  "simcells.v:1323",
  "A negative edge D-type flip-flop with negative polarity async load.\n::\n\n   Truth table:    D C L AD | Q\n                  ----------+---\n                   - - 0 a  | a\n                   d \\ - -  | d\n                   - - - -  | q",
  "module \\$_ALDFF_NN_ (D, C, L, AD, Q);\n    input D, C, L, AD;\n    output reg Q;\n    always @(negedge C or negedge L) begin\n        if (L == 0)\n            Q <= AD;\n        else\n            Q <= D;\n    end\nendmodule",
  "reg_ff",
  "2a",
  "",
};

cell_help["$_ALDFF_NP_"] = {
  "$_ALDFF_NP_",
  "",
  "(D, C, L, AD, Q)",
  "simcells.v:1347",
  "A negative edge D-type flip-flop with positive polarity async load.\n::\n\n   Truth table:    D C L AD | Q\n                  ----------+---\n                   - - 1 a  | a\n                   d \\ - -  | d\n                   - - - -  | q",
  "module \\$_ALDFF_NP_ (D, C, L, AD, Q);\n    input D, C, L, AD;\n    output reg Q;\n    always @(negedge C or posedge L) begin\n        if (L == 1)\n            Q <= AD;\n        else\n            Q <= D;\n    end\nendmodule",
  "reg_ff",
  "2a",
  "",
};

cell_help["$_ALDFF_PN_"] = {
  "$_ALDFF_PN_",
  "",
  "(D, C, L, AD, Q)",
  "simcells.v:1371",
  "A positive edge D-type flip-flop with negative polarity async load.\n::\n\n   Truth table:    D C L AD | Q\n                  ----------+---\n                   - - 0 a  | a\n                   d / - -  | d\n                   - - - -  | q",
  "module \\$_ALDFF_PN_ (D, C, L, AD, Q);\n    input D, C, L, AD;\n    output reg Q;\n    always @(posedge C or negedge L) begin\n        if (L == 0)\n            Q <= AD;\n        else\n            Q <= D;\n    end\nendmodule",
  "reg_ff",
  "2a",
  "",
};

cell_help["$_ALDFF_PP_"] = {
  "$_ALDFF_PP_",
  "",
  "(D, C, L, AD, Q)",
  "simcells.v:1395",
  "A positive edge D-type flip-flop with positive polarity async load.\n::\n\n   Truth table:    D C L AD | Q\n                  ----------+---\n                   - - 1 a  | a\n                   d / - -  | d\n                   - - - -  | q",
  "module \\$_ALDFF_PP_ (D, C, L, AD, Q);\n    input D, C, L, AD;\n    output reg Q;\n    always @(posedge C or posedge L) begin\n        if (L == 1)\n            Q <= AD;\n        else\n            Q <= D;\n    end\nendmodule",
  "reg_ff",
  "2a",
  "",
};

cell_help["$_ALDFFE_NNN_"] = {
  "$_ALDFFE_NNN_",
  "",
  "(D, C, L, AD, E, Q)",
  "simcells.v:1420",
  "A negative edge D-type flip-flop with negative polarity async load and negative\npolarity clock enable.\n::\n\n   Truth table:    D C L AD E | Q\n                  ------------+---\n                   - - 0 a  - | a\n                   d \\ - -  0 | d\n                   - - - -  - | q",
  "module \\$_ALDFFE_NNN_ (D, C, L, AD, E, Q);\n    input D, C, L, AD, E;\n    output reg Q;\n    always @(negedge C or negedge L) begin\n        if (L == 0)\n            Q <= AD;\n        else if (E == 0)\n            Q <= D;\n    end\nendmodule",
  "reg_ff",
  "2a",
  "",
};

cell_help["$_ALDFFE_NNP_"] = {
  "$_ALDFFE_NNP_",
  "",
  "(D, C, L, AD, E, Q)",
  "simcells.v:1445",
  "A negative edge D-type flip-flop with negative polarity async load and positive\npolarity clock enable.\n::\n\n   Truth table:    D C L AD E | Q\n                  ------------+---\n                   - - 0 a  - | a\n                   d \\ - -  1 | d\n                   - - - -  - | q",
  "module \\$_ALDFFE_NNP_ (D, C, L, AD, E, Q);\n    input D, C, L, AD, E;\n    output reg Q;\n    always @(negedge C or negedge L) begin\n        if (L == 0)\n            Q <= AD;\n        else if (E == 1)\n            Q <= D;\n    end\nendmodule",
  "reg_ff",
  "2a",
  "",
};

cell_help["$_ALDFFE_NPN_"] = {
  "$_ALDFFE_NPN_",
  "",
  "(D, C, L, AD, E, Q)",
  "simcells.v:1470",
  "A negative edge D-type flip-flop with positive polarity async load and negative\npolarity clock enable.\n::\n\n   Truth table:    D C L AD E | Q\n                  ------------+---\n                   - - 1 a  - | a\n                   d \\ - -  0 | d\n                   - - - -  - | q",
  "module \\$_ALDFFE_NPN_ (D, C, L, AD, E, Q);\n    input D, C, L, AD, E;\n    output reg Q;\n    always @(negedge C or posedge L) begin\n        if (L == 1)\n            Q <= AD;\n        else if (E == 0)\n            Q <= D;\n    end\nendmodule",
  "reg_ff",
  "2a",
  "",
};

cell_help["$_ALDFFE_NPP_"] = {
  "$_ALDFFE_NPP_",
  "",
  "(D, C, L, AD, E, Q)",
  "simcells.v:1495",
  "A negative edge D-type flip-flop with positive polarity async load and positive\npolarity clock enable.\n::\n\n   Truth table:    D C L AD E | Q\n                  ------------+---\n                   - - 1 a  - | a\n                   d \\ - -  1 | d\n                   - - - -  - | q",
  "module \\$_ALDFFE_NPP_ (D, C, L, AD, E, Q);\n    input D, C, L, AD, E;\n    output reg Q;\n    always @(negedge C or posedge L) begin\n        if (L == 1)\n            Q <= AD;\n        else if (E == 1)\n            Q <= D;\n    end\nendmodule",
  "reg_ff",
  "2a",
  "",
};

cell_help["$_ALDFFE_PNN_"] = {
  "$_ALDFFE_PNN_",
  "",
  "(D, C, L, AD, E, Q)",
  "simcells.v:1520",
  "A positive edge D-type flip-flop with negative polarity async load and negative\npolarity clock enable.\n::\n\n   Truth table:    D C L AD E | Q\n                  ------------+---\n                   - - 0 a  - | a\n                   d / - -  0 | d\n                   - - - -  - | q",
  "module \\$_ALDFFE_PNN_ (D, C, L, AD, E, Q);\n    input D, C, L, AD, E;\n    output reg Q;\n    always @(posedge C or negedge L) begin\n        if (L == 0)\n            Q <= AD;\n        else if (E == 0)\n            Q <= D;\n    end\nendmodule",
  "reg_ff",
  "2a",
  "",
};

cell_help["$_ALDFFE_PNP_"] = {
  "$_ALDFFE_PNP_",
  "",
  "(D, C, L, AD, E, Q)",
  "simcells.v:1545",
  "A positive edge D-type flip-flop with negative polarity async load and positive\npolarity clock enable.\n::\n\n   Truth table:    D C L AD E | Q\n                  ------------+---\n                   - - 0 a  - | a\n                   d / - -  1 | d\n                   - - - -  - | q",
  "module \\$_ALDFFE_PNP_ (D, C, L, AD, E, Q);\n    input D, C, L, AD, E;\n    output reg Q;\n    always @(posedge C or negedge L) begin\n        if (L == 0)\n            Q <= AD;\n        else if (E == 1)\n            Q <= D;\n    end\nendmodule",
  "reg_ff",
  "2a",
  "",
};

cell_help["$_ALDFFE_PPN_"] = {
  "$_ALDFFE_PPN_",
  "",
  "(D, C, L, AD, E, Q)",
  "simcells.v:1570",
  "A positive edge D-type flip-flop with positive polarity async load and negative\npolarity clock enable.\n::\n\n   Truth table:    D C L AD E | Q\n                  ------------+---\n                   - - 1 a  - | a\n                   d / - -  0 | d\n                   - - - -  - | q",
  "module \\$_ALDFFE_PPN_ (D, C, L, AD, E, Q);\n    input D, C, L, AD, E;\n    output reg Q;\n    always @(posedge C or posedge L) begin\n        if (L == 1)\n            Q <= AD;\n        else if (E == 0)\n            Q <= D;\n    end\nendmodule",
  "reg_ff",
  "2a",
  "",
};

cell_help["$_ALDFFE_PPP_"] = {
  "$_ALDFFE_PPP_",
  "",
  "(D, C, L, AD, E, Q)",
  "simcells.v:1595",
  "A positive edge D-type flip-flop with positive polarity async load and positive\npolarity clock enable.\n::\n\n   Truth table:    D C L AD E | Q\n                  ------------+---\n                   - - 1 a  - | a\n                   d / - -  1 | d\n                   - - - -  - | q",
  "module \\$_ALDFFE_PPP_ (D, C, L, AD, E, Q);\n    input D, C, L, AD, E;\n    output reg Q;\n    always @(posedge C or posedge L) begin\n        if (L == 1)\n            Q <= AD;\n        else if (E == 1)\n            Q <= D;\n    end\nendmodule",
  "reg_ff",
  "2a",
  "",
};

cell_help["$_DFFSR_NNN_"] = {
  "$_DFFSR_NNN_",
  "",
  "(C, S, R, D, Q)",
  "simcells.v:1621",
  "A negative edge D-type flip-flop with negative polarity set and negative\npolarity reset.\n::\n\n   Truth table:    C S R D | Q\n                  ---------+---\n                   - - 0 - | 0\n                   - 0 - - | 1\n                   \\ - - d | d\n                   - - - - | q",
  "module \\$_DFFSR_NNN_ (C, S, R, D, Q);\n    input C, S, R, D;\n    output reg Q;\n    always @(negedge C, negedge S, negedge R) begin\n        if (R == 0)\n            Q <= 0;\n        else if (S == 0)\n            Q <= 1;\n        else\n            Q <= D;\n    end\nendmodule",
  "reg_ff",
  "2a",
  "",
};

cell_help["$_DFFSR_NNP_"] = {
  "$_DFFSR_NNP_",
  "",
  "(C, S, R, D, Q)",
  "simcells.v:1649",
  "A negative edge D-type flip-flop with negative polarity set and positive\npolarity reset.\n::\n\n   Truth table:    C S R D | Q\n                  ---------+---\n                   - - 1 - | 0\n                   - 0 - - | 1\n                   \\ - - d | d\n                   - - - - | q",
  "module \\$_DFFSR_NNP_ (C, S, R, D, Q);\n    input C, S, R, D;\n    output reg Q;\n    always @(negedge C, negedge S, posedge R) begin\n        if (R == 1)\n            Q <= 0;\n        else if (S == 0)\n            Q <= 1;\n        else\n            Q <= D;\n    end\nendmodule",
  "reg_ff",
  "2a",
  "",
};

cell_help["$_DFFSR_NPN_"] = {
  "$_DFFSR_NPN_",
  "",
  "(C, S, R, D, Q)",
  "simcells.v:1677",
  "A negative edge D-type flip-flop with positive polarity set and negative\npolarity reset.\n::\n\n   Truth table:    C S R D | Q\n                  ---------+---\n                   - - 0 - | 0\n                   - 1 - - | 1\n                   \\ - - d | d\n                   - - - - | q",
  "module \\$_DFFSR_NPN_ (C, S, R, D, Q);\n    input C, S, R, D;\n    output reg Q;\n    always @(negedge C, posedge S, negedge R) begin\n        if (R == 0)\n            Q <= 0;\n        else if (S == 1)\n            Q <= 1;\n        else\n            Q <= D;\n    end\nendmodule",
  "reg_ff",
  "2a",
  "",
};

cell_help["$_DFFSR_NPP_"] = {
  "$_DFFSR_NPP_",
  "",
  "(C, S, R, D, Q)",
  "simcells.v:1705",
  "A negative edge D-type flip-flop with positive polarity set and positive\npolarity reset.\n::\n\n   Truth table:    C S R D | Q\n                  ---------+---\n                   - - 1 - | 0\n                   - 1 - - | 1\n                   \\ - - d | d\n                   - - - - | q",
  "module \\$_DFFSR_NPP_ (C, S, R, D, Q);\n    input C, S, R, D;\n    output reg Q;\n    always @(negedge C, posedge S, posedge R) begin\n        if (R == 1)\n            Q <= 0;\n        else if (S == 1)\n            Q <= 1;\n        else\n            Q <= D;\n    end\nendmodule",
  "reg_ff",
  "2a",
  "",
};

cell_help["$_DFFSR_PNN_"] = {
  "$_DFFSR_PNN_",
  "",
  "(C, S, R, D, Q)",
  "simcells.v:1733",
  "A positive edge D-type flip-flop with negative polarity set and negative\npolarity reset.\n::\n\n   Truth table:    C S R D | Q\n                  ---------+---\n                   - - 0 - | 0\n                   - 0 - - | 1\n                   / - - d | d\n                   - - - - | q",
  "module \\$_DFFSR_PNN_ (C, S, R, D, Q);\n    input C, S, R, D;\n    output reg Q;\n    always @(posedge C, negedge S, negedge R) begin\n        if (R == 0)\n            Q <= 0;\n        else if (S == 0)\n            Q <= 1;\n        else\n            Q <= D;\n    end\nendmodule",
  "reg_ff",
  "2a",
  "",
};

cell_help["$_DFFSR_PNP_"] = {
  "$_DFFSR_PNP_",
  "",
  "(C, S, R, D, Q)",
  "simcells.v:1761",
  "A positive edge D-type flip-flop with negative polarity set and positive\npolarity reset.\n::\n\n   Truth table:    C S R D | Q\n                  ---------+---\n                   - - 1 - | 0\n                   - 0 - - | 1\n                   / - - d | d\n                   - - - - | q",
  "module \\$_DFFSR_PNP_ (C, S, R, D, Q);\n    input C, S, R, D;\n    output reg Q;\n    always @(posedge C, negedge S, posedge R) begin\n        if (R == 1)\n            Q <= 0;\n        else if (S == 0)\n            Q <= 1;\n        else\n            Q <= D;\n    end\nendmodule",
  "reg_ff",
  "2a",
  "",
};

cell_help["$_DFFSR_PPN_"] = {
  "$_DFFSR_PPN_",
  "",
  "(C, S, R, D, Q)",
  "simcells.v:1789",
  "A positive edge D-type flip-flop with positive polarity set and negative\npolarity reset.\n::\n\n   Truth table:    C S R D | Q\n                  ---------+---\n                   - - 0 - | 0\n                   - 1 - - | 1\n                   / - - d | d\n                   - - - - | q",
  "module \\$_DFFSR_PPN_ (C, S, R, D, Q);\n    input C, S, R, D;\n    output reg Q;\n    always @(posedge C, posedge S, negedge R) begin\n        if (R == 0)\n            Q <= 0;\n        else if (S == 1)\n            Q <= 1;\n        else\n            Q <= D;\n    end\nendmodule",
  "reg_ff",
  "2a",
  "",
};

cell_help["$_DFFSR_PPP_"] = {
  "$_DFFSR_PPP_",
  "",
  "(C, S, R, D, Q)",
  "simcells.v:1817",
  "A positive edge D-type flip-flop with positive polarity set and positive\npolarity reset.\n::\n\n   Truth table:    C S R D | Q\n                  ---------+---\n                   - - 1 - | 0\n                   - 1 - - | 1\n                   / - - d | d\n                   - - - - | q",
  "module \\$_DFFSR_PPP_ (C, S, R, D, Q);\n    input C, S, R, D;\n    output reg Q;\n    always @(posedge C, posedge S, posedge R) begin\n        if (R == 1)\n            Q <= 0;\n        else if (S == 1)\n            Q <= 1;\n        else\n            Q <= D;\n    end\nendmodule",
  "reg_ff",
  "2a",
  "",
};

cell_help["$_DFFSRE_NNNN_"] = {
  "$_DFFSRE_NNNN_",
  "",
  "(C, S, R, E, D, Q)",
  "simcells.v:1845",
  "A negative edge D-type flip-flop with negative polarity set, negative\npolarity reset and negative polarity clock enable.\n::\n\n   Truth table:    C S R E D | Q\n                  -----------+---\n                   - - 0 - - | 0\n                   - 0 - - - | 1\n                   \\ - - 0 d | d\n                   - - - - - | q",
  "module \\$_DFFSRE_NNNN_ (C, S, R, E, D, Q);\n    input C, S, R, E, D;\n    output reg Q;\n    always @(negedge C, negedge S, negedge R) begin\n        if (R == 0)\n            Q <= 0;\n        else if (S == 0)\n            Q <= 1;\n            else if (E == 0)\n            Q <= D;\n    end\nendmodule",
  "reg_ff",
  "2a",
  "",
};

cell_help["$_DFFSRE_NNNP_"] = {
  "$_DFFSRE_NNNP_",
  "",
  "(C, S, R, E, D, Q)",
  "simcells.v:1873",
  "A negative edge D-type flip-flop with negative polarity set, negative\npolarity reset and positive polarity clock enable.\n::\n\n   Truth table:    C S R E D | Q\n                  -----------+---\n                   - - 0 - - | 0\n                   - 0 - - - | 1\n                   \\ - - 1 d | d\n                   - - - - - | q",
  "module \\$_DFFSRE_NNNP_ (C, S, R, E, D, Q);\n    input C, S, R, E, D;\n    output reg Q;\n    always @(negedge C, negedge S, negedge R) begin\n        if (R == 0)\n            Q <= 0;\n        else if (S == 0)\n            Q <= 1;\n            else if (E == 1)\n            Q <= D;\n    end\nendmodule",
  "reg_ff",
  "2a",
  "",
};

cell_help["$_DFFSRE_NNPN_"] = {
  "$_DFFSRE_NNPN_",
  "",
  "(C, S, R, E, D, Q)",
  "simcells.v:1901",
  "A negative edge D-type flip-flop with negative polarity set, positive\npolarity reset and negative polarity clock enable.\n::\n\n   Truth table:    C S R E D | Q\n                  -----------+---\n                   - - 1 - - | 0\n                   - 0 - - - | 1\n                   \\ - - 0 d | d\n                   - - - - - | q",
  "module \\$_DFFSRE_NNPN_ (C, S, R, E, D, Q);\n    input C, S, R, E, D;\n    output reg Q;\n    always @(negedge C, negedge S, posedge R) begin\n        if (R == 1)\n            Q <= 0;\n        else if (S == 0)\n            Q <= 1;\n            else if (E == 0)\n            Q <= D;\n    end\nendmodule",
  "reg_ff",
  "2a",
  "",
};

cell_help["$_DFFSRE_NNPP_"] = {
  "$_DFFSRE_NNPP_",
  "",
  "(C, S, R, E, D, Q)",
  "simcells.v:1929",
  "A negative edge D-type flip-flop with negative polarity set, positive\npolarity reset and positive polarity clock enable.\n::\n\n   Truth table:    C S R E D | Q\n                  -----------+---\n                   - - 1 - - | 0\n                   - 0 - - - | 1\n                   \\ - - 1 d | d\n                   - - - - - | q",
  "module \\$_DFFSRE_NNPP_ (C, S, R, E, D, Q);\n    input C, S, R, E, D;\n    output reg Q;\n    always @(negedge C, negedge S, posedge R) begin\n        if (R == 1)\n            Q <= 0;\n        else if (S == 0)\n            Q <= 1;\n            else if (E == 1)\n            Q <= D;\n    end\nendmodule",
  "reg_ff",
  "2a",
  "",
};

cell_help["$_DFFSRE_NPNN_"] = {
  "$_DFFSRE_NPNN_",
  "",
  "(C, S, R, E, D, Q)",
  "simcells.v:1957",
  "A negative edge D-type flip-flop with positive polarity set, negative\npolarity reset and negative polarity clock enable.\n::\n\n   Truth table:    C S R E D | Q\n                  -----------+---\n                   - - 0 - - | 0\n                   - 1 - - - | 1\n                   \\ - - 0 d | d\n                   - - - - - | q",
  "module \\$_DFFSRE_NPNN_ (C, S, R, E, D, Q);\n    input C, S, R, E, D;\n    output reg Q;\n    always @(negedge C, posedge S, negedge R) begin\n        if (R == 0)\n            Q <= 0;\n        else if (S == 1)\n            Q <= 1;\n            else if (E == 0)\n            Q <= D;\n    end\nendmodule",
  "reg_ff",
  "2a",
  "",
};

cell_help["$_DFFSRE_NPNP_"] = {
  "$_DFFSRE_NPNP_",
  "",
  "(C, S, R, E, D, Q)",
  "simcells.v:1985",
  "A negative edge D-type flip-flop with positive polarity set, negative\npolarity reset and positive polarity clock enable.\n::\n\n   Truth table:    C S R E D | Q\n                  -----------+---\n                   - - 0 - - | 0\n                   - 1 - - - | 1\n                   \\ - - 1 d | d\n                   - - - - - | q",
  "module \\$_DFFSRE_NPNP_ (C, S, R, E, D, Q);\n    input C, S, R, E, D;\n    output reg Q;\n    always @(negedge C, posedge S, negedge R) begin\n        if (R == 0)\n            Q <= 0;\n        else if (S == 1)\n            Q <= 1;\n            else if (E == 1)\n            Q <= D;\n    end\nendmodule",
  "reg_ff",
  "2a",
  "",
};

cell_help["$_DFFSRE_NPPN_"] = {
  "$_DFFSRE_NPPN_",
  "",
  "(C, S, R, E, D, Q)",
  "simcells.v:2013",
  "A negative edge D-type flip-flop with positive polarity set, positive\npolarity reset and negative polarity clock enable.\n::\n\n   Truth table:    C S R E D | Q\n                  -----------+---\n                   - - 1 - - | 0\n                   - 1 - - - | 1\n                   \\ - - 0 d | d\n                   - - - - - | q",
  "module \\$_DFFSRE_NPPN_ (C, S, R, E, D, Q);\n    input C, S, R, E, D;\n    output reg Q;\n    always @(negedge C, posedge S, posedge R) begin\n        if (R == 1)\n            Q <= 0;\n        else if (S == 1)\n            Q <= 1;\n            else if (E == 0)\n            Q <= D;\n    end\nendmodule",
  "reg_ff",
  "2a",
  "",
};

cell_help["$_DFFSRE_NPPP_"] = {
  "$_DFFSRE_NPPP_",
  "",
  "(C, S, R, E, D, Q)",
  "simcells.v:2041",
  "A negative edge D-type flip-flop with positive polarity set, positive\npolarity reset and positive polarity clock enable.\n::\n\n   Truth table:    C S R E D | Q\n                  -----------+---\n                   - - 1 - - | 0\n                   - 1 - - - | 1\n                   \\ - - 1 d | d\n                   - - - - - | q",
  "module \\$_DFFSRE_NPPP_ (C, S, R, E, D, Q);\n    input C, S, R, E, D;\n    output reg Q;\n    always @(negedge C, posedge S, posedge R) begin\n        if (R == 1)\n            Q <= 0;\n        else if (S == 1)\n            Q <= 1;\n            else if (E == 1)\n            Q <= D;\n    end\nendmodule",
  "reg_ff",
  "2a",
  "",
};

cell_help["$_DFFSRE_PNNN_"] = {
  "$_DFFSRE_PNNN_",
  "",
  "(C, S, R, E, D, Q)",
  "simcells.v:2069",
  "A positive edge D-type flip-flop with negative polarity set, negative\npolarity reset and negative polarity clock enable.\n::\n\n   Truth table:    C S R E D | Q\n                  -----------+---\n                   - - 0 - - | 0\n                   - 0 - - - | 1\n                   / - - 0 d | d\n                   - - - - - | q",
  "module \\$_DFFSRE_PNNN_ (C, S, R, E, D, Q);\n    input C, S, R, E, D;\n    output reg Q;\n    always @(posedge C, negedge S, negedge R) begin\n        if (R == 0)\n            Q <= 0;\n        else if (S == 0)\n            Q <= 1;\n            else if (E == 0)\n            Q <= D;\n    end\nendmodule",
  "reg_ff",
  "2a",
  "",
};

cell_help["$_DFFSRE_PNNP_"] = {
  "$_DFFSRE_PNNP_",
  "",
  "(C, S, R, E, D, Q)",
  "simcells.v:2097",
  "A positive edge D-type flip-flop with negative polarity set, negative\npolarity reset and positive polarity clock enable.\n::\n\n   Truth table:    C S R E D | Q\n                  -----------+---\n                   - - 0 - - | 0\n                   - 0 - - - | 1\n                   / - - 1 d | d\n                   - - - - - | q",
  "module \\$_DFFSRE_PNNP_ (C, S, R, E, D, Q);\n    input C, S, R, E, D;\n    output reg Q;\n    always @(posedge C, negedge S, negedge R) begin\n        if (R == 0)\n            Q <= 0;\n        else if (S == 0)\n            Q <= 1;\n            else if (E == 1)\n            Q <= D;\n    end\nendmodule",
  "reg_ff",
  "2a",
  "",
};

cell_help["$_DFFSRE_PNPN_"] = {
  "$_DFFSRE_PNPN_",
  "",
  "(C, S, R, E, D, Q)",
  "simcells.v:2125",
  "A positive edge D-type flip-flop with negative polarity set, positive\npolarity reset and negative polarity clock enable.\n::\n\n   Truth table:    C S R E D | Q\n                  -----------+---\n                   - - 1 - - | 0\n                   - 0 - - - | 1\n                   / - - 0 d | d\n                   - - - - - | q",
  "module \\$_DFFSRE_PNPN_ (C, S, R, E, D, Q);\n    input C, S, R, E, D;\n    output reg Q;\n    always @(posedge C, negedge S, posedge R) begin\n        if (R == 1)\n            Q <= 0;\n        else if (S == 0)\n            Q <= 1;\n            else if (E == 0)\n            Q <= D;\n    end\nendmodule",
  "reg_ff",
  "2a",
  "",
};

cell_help["$_DFFSRE_PNPP_"] = {
  "$_DFFSRE_PNPP_",
  "",
  "(C, S, R, E, D, Q)",
  "simcells.v:2153",
  "A positive edge D-type flip-flop with negative polarity set, positive\npolarity reset and positive polarity clock enable.\n::\n\n   Truth table:    C S R E D | Q\n                  -----------+---\n                   - - 1 - - | 0\n                   - 0 - - - | 1\n                   / - - 1 d | d\n                   - - - - - | q",
  "module \\$_DFFSRE_PNPP_ (C, S, R, E, D, Q);\n    input C, S, R, E, D;\n    output reg Q;\n    always @(posedge C, negedge S, posedge R) begin\n        if (R == 1)\n            Q <= 0;\n        else if (S == 0)\n            Q <= 1;\n            else if (E == 1)\n            Q <= D;\n    end\nendmodule",
  "reg_ff",
  "2a",
  "",
};

cell_help["$_DFFSRE_PPNN_"] = {
  "$_DFFSRE_PPNN_",
  "",
  "(C, S, R, E, D, Q)",
  "simcells.v:2181",
  "A positive edge D-type flip-flop with positive polarity set, negative\npolarity reset and negative polarity clock enable.\n::\n\n   Truth table:    C S R E D | Q\n                  -----------+---\n                   - - 0 - - | 0\n                   - 1 - - - | 1\n                   / - - 0 d | d\n                   - - - - - | q",
  "module \\$_DFFSRE_PPNN_ (C, S, R, E, D, Q);\n    input C, S, R, E, D;\n    output reg Q;\n    always @(posedge C, posedge S, negedge R) begin\n        if (R == 0)\n            Q <= 0;\n        else if (S == 1)\n            Q <= 1;\n            else if (E == 0)\n            Q <= D;\n    end\nendmodule",
  "reg_ff",
  "2a",
  "",
};

cell_help["$_DFFSRE_PPNP_"] = {
  "$_DFFSRE_PPNP_",
  "",
  "(C, S, R, E, D, Q)",
  "simcells.v:2209",
  "A positive edge D-type flip-flop with positive polarity set, negative\npolarity reset and positive polarity clock enable.\n::\n\n   Truth table:    C S R E D | Q\n                  -----------+---\n                   - - 0 - - | 0\n                   - 1 - - - | 1\n                   / - - 1 d | d\n                   - - - - - | q",
  "module \\$_DFFSRE_PPNP_ (C, S, R, E, D, Q);\n    input C, S, R, E, D;\n    output reg Q;\n    always @(posedge C, posedge S, negedge R) begin\n        if (R == 0)\n            Q <= 0;\n        else if (S == 1)\n            Q <= 1;\n            else if (E == 1)\n            Q <= D;\n    end\nendmodule",
  "reg_ff",
  "2a",
  "",
};

cell_help["$_DFFSRE_PPPN_"] = {
  "$_DFFSRE_PPPN_",
  "",
  "(C, S, R, E, D, Q)",
  "simcells.v:2237",
  "A positive edge D-type flip-flop with positive polarity set, positive\npolarity reset and negative polarity clock enable.\n::\n\n   Truth table:    C S R E D | Q\n                  -----------+---\n                   - - 1 - - | 0\n                   - 1 - - - | 1\n                   / - - 0 d | d\n                   - - - - - | q",
  "module \\$_DFFSRE_PPPN_ (C, S, R, E, D, Q);\n    input C, S, R, E, D;\n    output reg Q;\n    always @(posedge C, posedge S, posedge R) begin\n        if (R == 1)\n            Q <= 0;\n        else if (S == 1)\n            Q <= 1;\n            else if (E == 0)\n            Q <= D;\n    end\nendmodule",
  "reg_ff",
  "2a",
  "",
};

cell_help["$_DFFSRE_PPPP_"] = {
  "$_DFFSRE_PPPP_",
  "",
  "(C, S, R, E, D, Q)",
  "simcells.v:2265",
  "A positive edge D-type flip-flop with positive polarity set, positive\npolarity reset and positive polarity clock enable.\n::\n\n   Truth table:    C S R E D | Q\n                  -----------+---\n                   - - 1 - - | 0\n                   - 1 - - - | 1\n                   / - - 1 d | d\n                   - - - - - | q",
  "module \\$_DFFSRE_PPPP_ (C, S, R, E, D, Q);\n    input C, S, R, E, D;\n    output reg Q;\n    always @(posedge C, posedge S, posedge R) begin\n        if (R == 1)\n            Q <= 0;\n        else if (S == 1)\n            Q <= 1;\n            else if (E == 1)\n            Q <= D;\n    end\nendmodule",
  "reg_ff",
  "2a",
  "",
};

cell_help["$_SDFF_NN0_"] = {
  "$_SDFF_NN0_",
  "",
  "(D, C, R, Q)",
  "simcells.v:2291",
  "A negative edge D-type flip-flop with negative polarity synchronous reset.\n::\n\n   Truth table:    D C R | Q\n                  -------+---\n                   - \\ 0 | 0\n                   d \\ - | d\n                   - - - | q",
  "module \\$_SDFF_NN0_ (D, C, R, Q);\n    input D, C, R;\n    output reg Q;\n    always @(negedge C) begin\n        if (R == 0)\n            Q <= 0;\n        else\n            Q <= D;\n    end\nendmodule",
  "reg_ff",
  "2a",
  "",
};

cell_help["$_SDFF_NN1_"] = {
  "$_SDFF_NN1_",
  "",
  "(D, C, R, Q)",
  "simcells.v:2315",
  "A negative edge D-type flip-flop with negative polarity synchronous set.\n::\n\n   Truth table:    D C R | Q\n                  -------+---\n                   - \\ 0 | 1\n                   d \\ - | d\n                   - - - | q",
  "module \\$_SDFF_NN1_ (D, C, R, Q);\n    input D, C, R;\n    output reg Q;\n    always @(negedge C) begin\n        if (R == 0)\n            Q <= 1;\n        else\n            Q <= D;\n    end\nendmodule",
  "reg_ff",
  "2a",
  "",
};

cell_help["$_SDFF_NP0_"] = {
  "$_SDFF_NP0_",
  "",
  "(D, C, R, Q)",
  "simcells.v:2339",
  "A negative edge D-type flip-flop with positive polarity synchronous reset.\n::\n\n   Truth table:    D C R | Q\n                  -------+---\n                   - \\ 1 | 0\n                   d \\ - | d\n                   - - - | q",
  "module \\$_SDFF_NP0_ (D, C, R, Q);\n    input D, C, R;\n    output reg Q;\n    always @(negedge C) begin\n        if (R == 1)\n            Q <= 0;\n        else\n            Q <= D;\n    end\nendmodule",
  "reg_ff",
  "2a",
  "",
};

cell_help["$_SDFF_NP1_"] = {
  "$_SDFF_NP1_",
  "",
  "(D, C, R, Q)",
  "simcells.v:2363",
  "A negative edge D-type flip-flop with positive polarity synchronous set.\n::\n\n   Truth table:    D C R | Q\n                  -------+---\n                   - \\ 1 | 1\n                   d \\ - | d\n                   - - - | q",
  "module \\$_SDFF_NP1_ (D, C, R, Q);\n    input D, C, R;\n    output reg Q;\n    always @(negedge C) begin\n        if (R == 1)\n            Q <= 1;\n        else\n            Q <= D;\n    end\nendmodule",
  "reg_ff",
  "2a",
  "",
};

cell_help["$_SDFF_PN0_"] = {
  "$_SDFF_PN0_",
  "",
  "(D, C, R, Q)",
  "simcells.v:2387",
  "A positive edge D-type flip-flop with negative polarity synchronous reset.\n::\n\n   Truth table:    D C R | Q\n                  -------+---\n                   - / 0 | 0\n                   d / - | d\n                   - - - | q",
  "module \\$_SDFF_PN0_ (D, C, R, Q);\n    input D, C, R;\n    output reg Q;\n    always @(posedge C) begin\n        if (R == 0)\n            Q <= 0;\n        else\n            Q <= D;\n    end\nendmodule",
  "reg_ff",
  "2a",
  "",
};

cell_help["$_SDFF_PN1_"] = {
  "$_SDFF_PN1_",
  "",
  "(D, C, R, Q)",
  "simcells.v:2411",
  "A positive edge D-type flip-flop with negative polarity synchronous set.\n::\n\n   Truth table:    D C R | Q\n                  -------+---\n                   - / 0 | 1\n                   d / - | d\n                   - - - | q",
  "module \\$_SDFF_PN1_ (D, C, R, Q);\n    input D, C, R;\n    output reg Q;\n    always @(posedge C) begin\n        if (R == 0)\n            Q <= 1;\n        else\n            Q <= D;\n    end\nendmodule",
  "reg_ff",
  "2a",
  "",
};

cell_help["$_SDFF_PP0_"] = {
  "$_SDFF_PP0_",
  "",
  "(D, C, R, Q)",
  "simcells.v:2435",
  "A positive edge D-type flip-flop with positive polarity synchronous reset.\n::\n\n   Truth table:    D C R | Q\n                  -------+---\n                   - / 1 | 0\n                   d / - | d\n                   - - - | q",
  "module \\$_SDFF_PP0_ (D, C, R, Q);\n    input D, C, R;\n    output reg Q;\n    always @(posedge C) begin\n        if (R == 1)\n            Q <= 0;\n        else\n            Q <= D;\n    end\nendmodule",
  "reg_ff",
  "2a",
  "",
};

cell_help["$_SDFF_PP1_"] = {
  "$_SDFF_PP1_",
  "",
  "(D, C, R, Q)",
  "simcells.v:2459",
  "A positive edge D-type flip-flop with positive polarity synchronous set.\n::\n\n   Truth table:    D C R | Q\n                  -------+---\n                   - / 1 | 1\n                   d / - | d\n                   - - - | q",
  "module \\$_SDFF_PP1_ (D, C, R, Q);\n    input D, C, R;\n    output reg Q;\n    always @(posedge C) begin\n        if (R == 1)\n            Q <= 1;\n        else\n            Q <= D;\n    end\nendmodule",
  "reg_ff",
  "2a",
  "",
};

cell_help["$_SDFFE_NN0N_"] = {
  "$_SDFFE_NN0N_",
  "",
  "(D, C, R, E, Q)",
  "simcells.v:2484",
  "A negative edge D-type flip-flop with negative polarity synchronous reset and negative\npolarity clock enable (with reset having priority).\n::\n\n   Truth table:    D C R E | Q\n                  ---------+---\n                   - \\ 0 - | 0\n                   d \\ - 0 | d\n                   - - - - | q",
  "module \\$_SDFFE_NN0N_ (D, C, R, E, Q);\n    input D, C, R, E;\n    output reg Q;\n    always @(negedge C) begin\n        if (R == 0)\n            Q <= 0;\n        else if (E == 0)\n            Q <= D;\n    end\nendmodule",
  "reg_ff",
  "2a",
  "",
};

cell_help["$_SDFFE_NN0P_"] = {
  "$_SDFFE_NN0P_",
  "",
  "(D, C, R, E, Q)",
  "simcells.v:2509",
  "A negative edge D-type flip-flop with negative polarity synchronous reset and positive\npolarity clock enable (with reset having priority).\n::\n\n   Truth table:    D C R E | Q\n                  ---------+---\n                   - \\ 0 - | 0\n                   d \\ - 1 | d\n                   - - - - | q",
  "module \\$_SDFFE_NN0P_ (D, C, R, E, Q);\n    input D, C, R, E;\n    output reg Q;\n    always @(negedge C) begin\n        if (R == 0)\n            Q <= 0;\n        else if (E == 1)\n            Q <= D;\n    end\nendmodule",
  "reg_ff",
  "2a",
  "",
};

cell_help["$_SDFFE_NN1N_"] = {
  "$_SDFFE_NN1N_",
  "",
  "(D, C, R, E, Q)",
  "simcells.v:2534",
  "A negative edge D-type flip-flop with negative polarity synchronous set and negative\npolarity clock enable (with set having priority).\n::\n\n   Truth table:    D C R E | Q\n                  ---------+---\n                   - \\ 0 - | 1\n                   d \\ - 0 | d\n                   - - - - | q",
  "module \\$_SDFFE_NN1N_ (D, C, R, E, Q);\n    input D, C, R, E;\n    output reg Q;\n    always @(negedge C) begin\n        if (R == 0)\n            Q <= 1;\n        else if (E == 0)\n            Q <= D;\n    end\nendmodule",
  "reg_ff",
  "2a",
  "",
};

cell_help["$_SDFFE_NN1P_"] = {
  "$_SDFFE_NN1P_",
  "",
  "(D, C, R, E, Q)",
  "simcells.v:2559",
  "A negative edge D-type flip-flop with negative polarity synchronous set and positive\npolarity clock enable (with set having priority).\n::\n\n   Truth table:    D C R E | Q\n                  ---------+---\n                   - \\ 0 - | 1\n                   d \\ - 1 | d\n                   - - - - | q",
  "module \\$_SDFFE_NN1P_ (D, C, R, E, Q);\n    input D, C, R, E;\n    output reg Q;\n    always @(negedge C) begin\n        if (R == 0)\n            Q <= 1;\n        else if (E == 1)\n            Q <= D;\n    end\nendmodule",
  "reg_ff",
  "2a",
  "",
};

cell_help["$_SDFFE_NP0N_"] = {
  "$_SDFFE_NP0N_",
  "",
  "(D, C, R, E, Q)",
  "simcells.v:2584",
  "A negative edge D-type flip-flop with positive polarity synchronous reset and negative\npolarity clock enable (with reset having priority).\n::\n\n   Truth table:    D C R E | Q\n                  ---------+---\n                   - \\ 1 - | 0\n                   d \\ - 0 | d\n                   - - - - | q",
  "module \\$_SDFFE_NP0N_ (D, C, R, E, Q);\n    input D, C, R, E;\n    output reg Q;\n    always @(negedge C) begin\n        if (R == 1)\n            Q <= 0;\n        else if (E == 0)\n            Q <= D;\n    end\nendmodule",
  "reg_ff",
  "2a",
  "",
};

cell_help["$_SDFFE_NP0P_"] = {
  "$_SDFFE_NP0P_",
  "",
  "(D, C, R, E, Q)",
  "simcells.v:2609",
  "A negative edge D-type flip-flop with positive polarity synchronous reset and positive\npolarity clock enable (with reset having priority).\n::\n\n   Truth table:    D C R E | Q\n                  ---------+---\n                   - \\ 1 - | 0\n                   d \\ - 1 | d\n                   - - - - | q",
  "module \\$_SDFFE_NP0P_ (D, C, R, E, Q);\n    input D, C, R, E;\n    output reg Q;\n    always @(negedge C) begin\n        if (R == 1)\n            Q <= 0;\n        else if (E == 1)\n            Q <= D;\n    end\nendmodule",
  "reg_ff",
  "2a",
  "",
};

cell_help["$_SDFFE_NP1N_"] = {
  "$_SDFFE_NP1N_",
  "",
  "(D, C, R, E, Q)",
  "simcells.v:2634",
  "A negative edge D-type flip-flop with positive polarity synchronous set and negative\npolarity clock enable (with set having priority).\n::\n\n   Truth table:    D C R E | Q\n                  ---------+---\n                   - \\ 1 - | 1\n                   d \\ - 0 | d\n                   - - - - | q",
  "module \\$_SDFFE_NP1N_ (D, C, R, E, Q);\n    input D, C, R, E;\n    output reg Q;\n    always @(negedge C) begin\n        if (R == 1)\n            Q <= 1;\n        else if (E == 0)\n            Q <= D;\n    end\nendmodule",
  "reg_ff",
  "2a",
  "",
};

cell_help["$_SDFFE_NP1P_"] = {
  "$_SDFFE_NP1P_",
  "",
  "(D, C, R, E, Q)",
  "simcells.v:2659",
  "A negative edge D-type flip-flop with positive polarity synchronous set and positive\npolarity clock enable (with set having priority).\n::\n\n   Truth table:    D C R E | Q\n                  ---------+---\n                   - \\ 1 - | 1\n                   d \\ - 1 | d\n                   - - - - | q",
  "module \\$_SDFFE_NP1P_ (D, C, R, E, Q);\n    input D, C, R, E;\n    output reg Q;\n    always @(negedge C) begin\n        if (R == 1)\n            Q <= 1;\n        else if (E == 1)\n            Q <= D;\n    end\nendmodule",
  "reg_ff",
  "2a",
  "",
};

cell_help["$_SDFFE_PN0N_"] = {
  "$_SDFFE_PN0N_",
  "",
  "(D, C, R, E, Q)",
  "simcells.v:2684",
  "A positive edge D-type flip-flop with negative polarity synchronous reset and negative\npolarity clock enable (with reset having priority).\n::\n\n   Truth table:    D C R E | Q\n                  ---------+---\n                   - / 0 - | 0\n                   d / - 0 | d\n                   - - - - | q",
  "module \\$_SDFFE_PN0N_ (D, C, R, E, Q);\n    input D, C, R, E;\n    output reg Q;\n    always @(posedge C) begin\n        if (R == 0)\n            Q <= 0;\n        else if (E == 0)\n            Q <= D;\n    end\nendmodule",
  "reg_ff",
  "2a",
  "",
};

cell_help["$_SDFFE_PN0P_"] = {
  "$_SDFFE_PN0P_",
  "",
  "(D, C, R, E, Q)",
  "simcells.v:2709",
  "A positive edge D-type flip-flop with negative polarity synchronous reset and positive\npolarity clock enable (with reset having priority).\n::\n\n   Truth table:    D C R E | Q\n                  ---------+---\n                   - / 0 - | 0\n                   d / - 1 | d\n                   - - - - | q",
  "module \\$_SDFFE_PN0P_ (D, C, R, E, Q);\n    input D, C, R, E;\n    output reg Q;\n    always @(posedge C) begin\n        if (R == 0)\n            Q <= 0;\n        else if (E == 1)\n            Q <= D;\n    end\nendmodule",
  "reg_ff",
  "2a",
  "",
};

cell_help["$_SDFFE_PN1N_"] = {
  "$_SDFFE_PN1N_",
  "",
  "(D, C, R, E, Q)",
  "simcells.v:2734",
  "A positive edge D-type flip-flop with negative polarity synchronous set and negative\npolarity clock enable (with set having priority).\n::\n\n   Truth table:    D C R E | Q\n                  ---------+---\n                   - / 0 - | 1\n                   d / - 0 | d\n                   - - - - | q",
  "module \\$_SDFFE_PN1N_ (D, C, R, E, Q);\n    input D, C, R, E;\n    output reg Q;\n    always @(posedge C) begin\n        if (R == 0)\n            Q <= 1;\n        else if (E == 0)\n            Q <= D;\n    end\nendmodule",
  "reg_ff",
  "2a",
  "",
};

cell_help["$_SDFFE_PN1P_"] = {
  "$_SDFFE_PN1P_",
  "",
  "(D, C, R, E, Q)",
  "simcells.v:2759",
  "A positive edge D-type flip-flop with negative polarity synchronous set and positive\npolarity clock enable (with set having priority).\n::\n\n   Truth table:    D C R E | Q\n                  ---------+---\n                   - / 0 - | 1\n                   d / - 1 | d\n                   - - - - | q",
  "module \\$_SDFFE_PN1P_ (D, C, R, E, Q);\n    input D, C, R, E;\n    output reg Q;\n    always @(posedge C) begin\n        if (R == 0)\n            Q <= 1;\n        else if (E == 1)\n            Q <= D;\n    end\nendmodule",
  "reg_ff",
  "2a",
  "",
};

cell_help["$_SDFFE_PP0N_"] = {
  "$_SDFFE_PP0N_",
  "",
  "(D, C, R, E, Q)",
  "simcells.v:2784",
  "A positive edge D-type flip-flop with positive polarity synchronous reset and negative\npolarity clock enable (with reset having priority).\n::\n\n   Truth table:    D C R E | Q\n                  ---------+---\n                   - / 1 - | 0\n                   d / - 0 | d\n                   - - - - | q",
  "module \\$_SDFFE_PP0N_ (D, C, R, E, Q);\n    input D, C, R, E;\n    output reg Q;\n    always @(posedge C) begin\n        if (R == 1)\n            Q <= 0;\n        else if (E == 0)\n            Q <= D;\n    end\nendmodule",
  "reg_ff",
  "2a",
  "",
};

cell_help["$_SDFFE_PP0P_"] = {
  "$_SDFFE_PP0P_",
  "",
  "(D, C, R, E, Q)",
  "simcells.v:2809",
  "A positive edge D-type flip-flop with positive polarity synchronous reset and positive\npolarity clock enable (with reset having priority).\n::\n\n   Truth table:    D C R E | Q\n                  ---------+---\n                   - / 1 - | 0\n                   d / - 1 | d\n                   - - - - | q",
  "module \\$_SDFFE_PP0P_ (D, C, R, E, Q);\n    input D, C, R, E;\n    output reg Q;\n    always @(posedge C) begin\n        if (R == 1)\n            Q <= 0;\n        else if (E == 1)\n            Q <= D;\n    end\nendmodule",
  "reg_ff",
  "2a",
  "",
};

cell_help["$_SDFFE_PP1N_"] = {
  "$_SDFFE_PP1N_",
  "",
  "(D, C, R, E, Q)",
  "simcells.v:2834",
  "A positive edge D-type flip-flop with positive polarity synchronous set and negative\npolarity clock enable (with set having priority).\n::\n\n   Truth table:    D C R E | Q\n                  ---------+---\n                   - / 1 - | 1\n                   d / - 0 | d\n                   - - - - | q",
  "module \\$_SDFFE_PP1N_ (D, C, R, E, Q);\n    input D, C, R, E;\n    output reg Q;\n    always @(posedge C) begin\n        if (R == 1)\n            Q <= 1;\n        else if (E == 0)\n            Q <= D;\n    end\nendmodule",
  "reg_ff",
  "2a",
  "",
};

cell_help["$_SDFFE_PP1P_"] = {
  "$_SDFFE_PP1P_",
  "",
  "(D, C, R, E, Q)",
  "simcells.v:2859",
  "A positive edge D-type flip-flop with positive polarity synchronous set and positive\npolarity clock enable (with set having priority).\n::\n\n   Truth table:    D C R E | Q\n                  ---------+---\n                   - / 1 - | 1\n                   d / - 1 | d\n                   - - - - | q",
  "module \\$_SDFFE_PP1P_ (D, C, R, E, Q);\n    input D, C, R, E;\n    output reg Q;\n    always @(posedge C) begin\n        if (R == 1)\n            Q <= 1;\n        else if (E == 1)\n            Q <= D;\n    end\nendmodule",
  "reg_ff",
  "2a",
  "",
};

cell_help["$_SDFFCE_NN0N_"] = {
  "$_SDFFCE_NN0N_",
  "",
  "(D, C, R, E, Q)",
  "simcells.v:2884",
  "A negative edge D-type flip-flop with negative polarity synchronous reset and negative\npolarity clock enable (with clock enable having priority).\n::\n\n   Truth table:    D C R E | Q\n                  ---------+---\n                   - \\ 0 0 | 0\n                   d \\ - 0 | d\n                   - - - - | q",
  "module \\$_SDFFCE_NN0N_ (D, C, R, E, Q);\n    input D, C, R, E;\n    output reg Q;\n    always @(negedge C) begin\n        if (E == 0) begin\n            if (R == 0)\n                Q <= 0;\n            else\n                Q <= D;\n        end\n    end\nendmodule",
  "reg_ff",
  "2a",
  "",
};

cell_help["$_SDFFCE_NN0P_"] = {
  "$_SDFFCE_NN0P_",
  "",
  "(D, C, R, E, Q)",
  "simcells.v:2911",
  "A negative edge D-type flip-flop with negative polarity synchronous reset and positive\npolarity clock enable (with clock enable having priority).\n::\n\n   Truth table:    D C R E | Q\n                  ---------+---\n                   - \\ 0 1 | 0\n                   d \\ - 1 | d\n                   - - - - | q",
  "module \\$_SDFFCE_NN0P_ (D, C, R, E, Q);\n    input D, C, R, E;\n    output reg Q;\n    always @(negedge C) begin\n        if (E == 1) begin\n            if (R == 0)\n                Q <= 0;\n            else\n                Q <= D;\n        end\n    end\nendmodule",
  "reg_ff",
  "2a",
  "",
};

cell_help["$_SDFFCE_NN1N_"] = {
  "$_SDFFCE_NN1N_",
  "",
  "(D, C, R, E, Q)",
  "simcells.v:2938",
  "A negative edge D-type flip-flop with negative polarity synchronous set and negative\npolarity clock enable (with clock enable having priority).\n::\n\n   Truth table:    D C R E | Q\n                  ---------+---\n                   - \\ 0 0 | 1\n                   d \\ - 0 | d\n                   - - - - | q",
  "module \\$_SDFFCE_NN1N_ (D, C, R, E, Q);\n    input D, C, R, E;\n    output reg Q;\n    always @(negedge C) begin\n        if (E == 0) begin\n            if (R == 0)\n                Q <= 1;\n            else\n                Q <= D;\n        end\n    end\nendmodule",
  "reg_ff",
  "2a",
  "",
};

cell_help["$_SDFFCE_NN1P_"] = {
  "$_SDFFCE_NN1P_",
  "",
  "(D, C, R, E, Q)",
  "simcells.v:2965",
  "A negative edge D-type flip-flop with negative polarity synchronous set and positive\npolarity clock enable (with clock enable having priority).\n::\n\n   Truth table:    D C R E | Q\n                  ---------+---\n                   - \\ 0 1 | 1\n                   d \\ - 1 | d\n                   - - - - | q",
  "module \\$_SDFFCE_NN1P_ (D, C, R, E, Q);\n    input D, C, R, E;\n    output reg Q;\n    always @(negedge C) begin\n        if (E == 1) begin\n            if (R == 0)\n                Q <= 1;\n            else\n                Q <= D;\n        end\n    end\nendmodule",
  "reg_ff",
  "2a",
  "",
};

cell_help["$_SDFFCE_NP0N_"] = {
  "$_SDFFCE_NP0N_",
  "",
  "(D, C, R, E, Q)",
  "simcells.v:2992",
  "A negative edge D-type flip-flop with positive polarity synchronous reset and negative\npolarity clock enable (with clock enable having priority).\n::\n\n   Truth table:    D C R E | Q\n                  ---------+---\n                   - \\ 1 0 | 0\n                   d \\ - 0 | d\n                   - - - - | q",
  "module \\$_SDFFCE_NP0N_ (D, C, R, E, Q);\n    input D, C, R, E;\n    output reg Q;\n    always @(negedge C) begin\n        if (E == 0) begin\n            if (R == 1)\n                Q <= 0;\n            else\n                Q <= D;\n        end\n    end\nendmodule",
  "reg_ff",
  "2a",
  "",
};

cell_help["$_SDFFCE_NP0P_"] = {
  "$_SDFFCE_NP0P_",
  "",
  "(D, C, R, E, Q)",
  "simcells.v:3019",
  "A negative edge D-type flip-flop with positive polarity synchronous reset and positive\npolarity clock enable (with clock enable having priority).\n::\n\n   Truth table:    D C R E | Q\n                  ---------+---\n                   - \\ 1 1 | 0\n                   d \\ - 1 | d\n                   - - - - | q",
  "module \\$_SDFFCE_NP0P_ (D, C, R, E, Q);\n    input D, C, R, E;\n    output reg Q;\n    always @(negedge C) begin\n        if (E == 1) begin\n            if (R == 1)\n                Q <= 0;\n            else\n                Q <= D;\n        end\n    end\nendmodule",
  "reg_ff",
  "2a",
  "",
};

cell_help["$_SDFFCE_NP1N_"] = {
  "$_SDFFCE_NP1N_",
  "",
  "(D, C, R, E, Q)",
  "simcells.v:3046",
  "A negative edge D-type flip-flop with positive polarity synchronous set and negative\npolarity clock enable (with clock enable having priority).\n::\n\n   Truth table:    D C R E | Q\n                  ---------+---\n                   - \\ 1 0 | 1\n                   d \\ - 0 | d\n                   - - - - | q",
  "module \\$_SDFFCE_NP1N_ (D, C, R, E, Q);\n    input D, C, R, E;\n    output reg Q;\n    always @(negedge C) begin\n        if (E == 0) begin\n            if (R == 1)\n                Q <= 1;\n            else\n                Q <= D;\n        end\n    end\nendmodule",
  "reg_ff",
  "2a",
  "",
};

cell_help["$_SDFFCE_NP1P_"] = {
  "$_SDFFCE_NP1P_",
  "",
  "(D, C, R, E, Q)",
  "simcells.v:3073",
  "A negative edge D-type flip-flop with positive polarity synchronous set and positive\npolarity clock enable (with clock enable having priority).\n::\n\n   Truth table:    D C R E | Q\n                  ---------+---\n                   - \\ 1 1 | 1\n                   d \\ - 1 | d\n                   - - - - | q",
  "module \\$_SDFFCE_NP1P_ (D, C, R, E, Q);\n    input D, C, R, E;\n    output reg Q;\n    always @(negedge C) begin\n        if (E == 1) begin\n            if (R == 1)\n                Q <= 1;\n            else\n                Q <= D;\n        end\n    end\nendmodule",
  "reg_ff",
  "2a",
  "",
};

cell_help["$_SDFFCE_PN0N_"] = {
  "$_SDFFCE_PN0N_",
  "",
  "(D, C, R, E, Q)",
  "simcells.v:3100",
  "A positive edge D-type flip-flop with negative polarity synchronous reset and negative\npolarity clock enable (with clock enable having priority).\n::\n\n   Truth table:    D C R E | Q\n                  ---------+---\n                   - / 0 0 | 0\n                   d / - 0 | d\n                   - - - - | q",
  "module \\$_SDFFCE_PN0N_ (D, C, R, E, Q);\n    input D, C, R, E;\n    output reg Q;\n    always @(posedge C) begin\n        if (E == 0) begin\n            if (R == 0)\n                Q <= 0;\n            else\n                Q <= D;\n        end\n    end\nendmodule",
  "reg_ff",
  "2a",
  "",
};

cell_help["$_SDFFCE_PN0P_"] = {
  "$_SDFFCE_PN0P_",
  "",
  "(D, C, R, E, Q)",
  "simcells.v:3127",
  "A positive edge D-type flip-flop with negative polarity synchronous reset and positive\npolarity clock enable (with clock enable having priority).\n::\n\n   Truth table:    D C R E | Q\n                  ---------+---\n                   - / 0 1 | 0\n                   d / - 1 | d\n                   - - - - | q",
  "module \\$_SDFFCE_PN0P_ (D, C, R, E, Q);\n    input D, C, R, E;\n    output reg Q;\n    always @(posedge C) begin\n        if (E == 1) begin\n            if (R == 0)\n                Q <= 0;\n            else\n                Q <= D;\n        end\n    end\nendmodule",
  "reg_ff",
  "2a",
  "",
};

cell_help["$_SDFFCE_PN1N_"] = {
  "$_SDFFCE_PN1N_",
  "",
  "(D, C, R, E, Q)",
  "simcells.v:3154",
  "A positive edge D-type flip-flop with negative polarity synchronous set and negative\npolarity clock enable (with clock enable having priority).\n::\n\n   Truth table:    D C R E | Q\n                  ---------+---\n                   - / 0 0 | 1\n                   d / - 0 | d\n                   - - - - | q",
  "module \\$_SDFFCE_PN1N_ (D, C, R, E, Q);\n    input D, C, R, E;\n    output reg Q;\n    always @(posedge C) begin\n        if (E == 0) begin\n            if (R == 0)\n                Q <= 1;\n            else\n                Q <= D;\n        end\n    end\nendmodule",
  "reg_ff",
  "2a",
  "",
};

cell_help["$_SDFFCE_PN1P_"] = {
  "$_SDFFCE_PN1P_",
  "",
  "(D, C, R, E, Q)",
  "simcells.v:3181",
  "A positive edge D-type flip-flop with negative polarity synchronous set and positive\npolarity clock enable (with clock enable having priority).\n::\n\n   Truth table:    D C R E | Q\n                  ---------+---\n                   - / 0 1 | 1\n                   d / - 1 | d\n                   - - - - | q",
  "module \\$_SDFFCE_PN1P_ (D, C, R, E, Q);\n    input D, C, R, E;\n    output reg Q;\n    always @(posedge C) begin\n        if (E == 1) begin\n            if (R == 0)\n                Q <= 1;\n            else\n                Q <= D;\n        end\n    end\nendmodule",
  "reg_ff",
  "2a",
  "",
};

cell_help["$_SDFFCE_PP0N_"] = {
  "$_SDFFCE_PP0N_",
  "",
  "(D, C, R, E, Q)",
  "simcells.v:3208",
  "A positive edge D-type flip-flop with positive polarity synchronous reset and negative\npolarity clock enable (with clock enable having priority).\n::\n\n   Truth table:    D C R E | Q\n                  ---------+---\n                   - / 1 0 | 0\n                   d / - 0 | d\n                   - - - - | q",
  "module \\$_SDFFCE_PP0N_ (D, C, R, E, Q);\n    input D, C, R, E;\n    output reg Q;\n    always @(posedge C) begin\n        if (E == 0) begin\n            if (R == 1)\n                Q <= 0;\n            else\n                Q <= D;\n        end\n    end\nendmodule",
  "reg_ff",
  "2a",
  "",
};

cell_help["$_SDFFCE_PP0P_"] = {
  "$_SDFFCE_PP0P_",
  "",
  "(D, C, R, E, Q)",
  "simcells.v:3235",
  "A positive edge D-type flip-flop with positive polarity synchronous reset and positive\npolarity clock enable (with clock enable having priority).\n::\n\n   Truth table:    D C R E | Q\n                  ---------+---\n                   - / 1 1 | 0\n                   d / - 1 | d\n                   - - - - | q",
  "module \\$_SDFFCE_PP0P_ (D, C, R, E, Q);\n    input D, C, R, E;\n    output reg Q;\n    always @(posedge C) begin\n        if (E == 1) begin\n            if (R == 1)\n                Q <= 0;\n            else\n                Q <= D;\n        end\n    end\nendmodule",
  "reg_ff",
  "2a",
  "",
};

cell_help["$_SDFFCE_PP1N_"] = {
  "$_SDFFCE_PP1N_",
  "",
  "(D, C, R, E, Q)",
  "simcells.v:3262",
  "A positive edge D-type flip-flop with positive polarity synchronous set and negative\npolarity clock enable (with clock enable having priority).\n::\n\n   Truth table:    D C R E | Q\n                  ---------+---\n                   - / 1 0 | 1\n                   d / - 0 | d\n                   - - - - | q",
  "module \\$_SDFFCE_PP1N_ (D, C, R, E, Q);\n    input D, C, R, E;\n    output reg Q;\n    always @(posedge C) begin\n        if (E == 0) begin\n            if (R == 1)\n                Q <= 1;\n            else\n                Q <= D;\n        end\n    end\nendmodule",
  "reg_ff",
  "2a",
  "",
};

cell_help["$_SDFFCE_PP1P_"] = {
  "$_SDFFCE_PP1P_",
  "",
  "(D, C, R, E, Q)",
  "simcells.v:3289",
  "A positive edge D-type flip-flop with positive polarity synchronous set and positive\npolarity clock enable (with clock enable having priority).\n::\n\n   Truth table:    D C R E | Q\n                  ---------+---\n                   - / 1 1 | 1\n                   d / - 1 | d\n                   - - - - | q",
  "module \\$_SDFFCE_PP1P_ (D, C, R, E, Q);\n    input D, C, R, E;\n    output reg Q;\n    always @(posedge C) begin\n        if (E == 1) begin\n            if (R == 1)\n                Q <= 1;\n            else\n                Q <= D;\n        end\n    end\nendmodule",
  "reg_ff",
  "2a",
  "",
};

cell_help["$_DLATCH_N_"] = {
  "$_DLATCH_N_",
  "",
  "(E, D, Q)",
  "simcells.v:3314",
  "A negative enable D-type latch.\n::\n\n   Truth table:    E D | Q\n                  -----+---\n                   0 d | d\n                   - - | q",
  "module \\$_DLATCH_N_ (E, D, Q);\n    input E, D;\n    output reg Q;\n    always @* begin\n        if (E == 0)\n            Q <= D;\n    end\nendmodule",
  "reg_latch",
  "2a",
  "",
};

cell_help["$_DLATCH_P_"] = {
  "$_DLATCH_P_",
  "",
  "(E, D, Q)",
  "simcells.v:3335",
  "A positive enable D-type latch.\n::\n\n   Truth table:    E D | Q\n                  -----+---\n                   1 d | d\n                   - - | q",
  "module \\$_DLATCH_P_ (E, D, Q);\n    input E, D;\n    output reg Q;\n    always @* begin\n        if (E == 1)\n            Q <= D;\n    end\nendmodule",
  "reg_latch",
  "2a",
  "",
};

cell_help["$_DLATCH_NN0_"] = {
  "$_DLATCH_NN0_",
  "",
  "(E, R, D, Q)",
  "simcells.v:3357",
  "A negative enable D-type latch with negative polarity reset.\n::\n\n   Truth table:    E R D | Q\n                  -------+---\n                   - 0 - | 0\n                   0 - d | d\n                   - - - | q",
  "module \\$_DLATCH_NN0_ (E, R, D, Q);\n    input E, R, D;\n    output reg Q;\n    always @* begin\n        if (R == 0)\n                    Q <= 0;\n        else if (E == 0)\n            Q <= D;\n    end\nendmodule",
  "reg_latch",
  "2a",
  "",
};

cell_help["$_DLATCH_NN1_"] = {
  "$_DLATCH_NN1_",
  "",
  "(E, R, D, Q)",
  "simcells.v:3381",
  "A negative enable D-type latch with negative polarity set.\n::\n\n   Truth table:    E R D | Q\n                  -------+---\n                   - 0 - | 1\n                   0 - d | d\n                   - - - | q",
  "module \\$_DLATCH_NN1_ (E, R, D, Q);\n    input E, R, D;\n    output reg Q;\n    always @* begin\n        if (R == 0)\n                    Q <= 1;\n        else if (E == 0)\n            Q <= D;\n    end\nendmodule",
  "reg_latch",
  "2a",
  "",
};

cell_help["$_DLATCH_NP0_"] = {
  "$_DLATCH_NP0_",
  "",
  "(E, R, D, Q)",
  "simcells.v:3405",
  "A negative enable D-type latch with positive polarity reset.\n::\n\n   Truth table:    E R D | Q\n                  -------+---\n                   - 1 - | 0\n                   0 - d | d\n                   - - - | q",
  "module \\$_DLATCH_NP0_ (E, R, D, Q);\n    input E, R, D;\n    output reg Q;\n    always @* begin\n        if (R == 1)\n                    Q <= 0;\n        else if (E == 0)\n            Q <= D;\n    end\nendmodule",
  "reg_latch",
  "2a",
  "",
};

cell_help["$_DLATCH_NP1_"] = {
  "$_DLATCH_NP1_",
  "",
  "(E, R, D, Q)",
  "simcells.v:3429",
  "A negative enable D-type latch with positive polarity set.\n::\n\n   Truth table:    E R D | Q\n                  -------+---\n                   - 1 - | 1\n                   0 - d | d\n                   - - - | q",
  "module \\$_DLATCH_NP1_ (E, R, D, Q);\n    input E, R, D;\n    output reg Q;\n    always @* begin\n        if (R == 1)\n                    Q <= 1;\n        else if (E == 0)\n            Q <= D;\n    end\nendmodule",
  "reg_latch",
  "2a",
  "",
};

cell_help["$_DLATCH_PN0_"] = {
  "$_DLATCH_PN0_",
  "",
  "(E, R, D, Q)",
  "simcells.v:3453",
  "A positive enable D-type latch with negative polarity reset.\n::\n\n   Truth table:    E R D | Q\n                  -------+---\n                   - 0 - | 0\n                   1 - d | d\n                   - - - | q",
  "module \\$_DLATCH_PN0_ (E, R, D, Q);\n    input E, R, D;\n    output reg Q;\n    always @* begin\n        if (R == 0)\n                    Q <= 0;\n        else if (E == 1)\n            Q <= D;\n    end\nendmodule",
  "reg_latch",
  "2a",
  "",
};

cell_help["$_DLATCH_PN1_"] = {
  "$_DLATCH_PN1_",
  "",
  "(E, R, D, Q)",
  "simcells.v:3477",
  "A positive enable D-type latch with negative polarity set.\n::\n\n   Truth table:    E R D | Q\n                  -------+---\n                   - 0 - | 1\n                   1 - d | d\n                   - - - | q",
  "module \\$_DLATCH_PN1_ (E, R, D, Q);\n    input E, R, D;\n    output reg Q;\n    always @* begin\n        if (R == 0)\n                    Q <= 1;\n        else if (E == 1)\n            Q <= D;\n    end\nendmodule",
  "reg_latch",
  "2a",
  "",
};

cell_help["$_DLATCH_PP0_"] = {
  "$_DLATCH_PP0_",
  "",
  "(E, R, D, Q)",
  "simcells.v:3501",
  "A positive enable D-type latch with positive polarity reset.\n::\n\n   Truth table:    E R D | Q\n                  -------+---\n                   - 1 - | 0\n                   1 - d | d\n                   - - - | q",
  "module \\$_DLATCH_PP0_ (E, R, D, Q);\n    input E, R, D;\n    output reg Q;\n    always @* begin\n        if (R == 1)\n                    Q <= 0;\n        else if (E == 1)\n            Q <= D;\n    end\nendmodule",
  "reg_latch",
  "2a",
  "",
};

cell_help["$_DLATCH_PP1_"] = {
  "$_DLATCH_PP1_",
  "",
  "(E, R, D, Q)",
  "simcells.v:3525",
  "A positive enable D-type latch with positive polarity set.\n::\n\n   Truth table:    E R D | Q\n                  -------+---\n                   - 1 - | 1\n                   1 - d | d\n                   - - - | q",
  "module \\$_DLATCH_PP1_ (E, R, D, Q);\n    input E, R, D;\n    output reg Q;\n    always @* begin\n        if (R == 1)\n                    Q <= 1;\n        else if (E == 1)\n            Q <= D;\n    end\nendmodule",
  "reg_latch",
  "2a",
  "",
};

cell_help["$_DLATCHSR_NNN_"] = {
  "$_DLATCHSR_NNN_",
  "",
  "(E, S, R, D, Q)",
  "simcells.v:3551",
  "A negative enable D-type latch with negative polarity set and negative\npolarity reset.\n::\n\n   Truth table:    E S R D | Q\n                  ---------+---\n                   - - 0 - | 0\n                   - 0 - - | 1\n                   0 - - d | d\n                   - - - - | q",
  "module \\$_DLATCHSR_NNN_ (E, S, R, D, Q);\n    input E, S, R, D;\n    output reg Q;\n    always @* begin\n        if (R == 0)\n            Q <= 0;\n        else if (S == 0)\n            Q <= 1;\n        else if (E == 0)\n            Q <= D;\n    end\nendmodule",
  "reg_latch",
  "2a",
  "",
};

cell_help["$_DLATCHSR_NNP_"] = {
  "$_DLATCHSR_NNP_",
  "",
  "(E, S, R, D, Q)",
  "simcells.v:3579",
  "A negative enable D-type latch with negative polarity set and positive\npolarity reset.\n::\n\n   Truth table:    E S R D | Q\n                  ---------+---\n                   - - 1 - | 0\n                   - 0 - - | 1\n                   0 - - d | d\n                   - - - - | q",
  "module \\$_DLATCHSR_NNP_ (E, S, R, D, Q);\n    input E, S, R, D;\n    output reg Q;\n    always @* begin\n        if (R == 1)\n            Q <= 0;\n        else if (S == 0)\n            Q <= 1;\n        else if (E == 0)\n            Q <= D;\n    end\nendmodule",
  "reg_latch",
  "2a",
  "",
};

cell_help["$_DLATCHSR_NPN_"] = {
  "$_DLATCHSR_NPN_",
  "",
  "(E, S, R, D, Q)",
  "simcells.v:3607",
  "A negative enable D-type latch with positive polarity set and negative\npolarity reset.\n::\n\n   Truth table:    E S R D | Q\n                  ---------+---\n                   - - 0 - | 0\n                   - 1 - - | 1\n                   0 - - d | d\n                   - - - - | q",
  "module \\$_DLATCHSR_NPN_ (E, S, R, D, Q);\n    input E, S, R, D;\n    output reg Q;\n    always @* begin\n        if (R == 0)\n            Q <= 0;\n        else if (S == 1)\n            Q <= 1;\n        else if (E == 0)\n            Q <= D;\n    end\nendmodule",
  "reg_latch",
  "2a",
  "",
};

cell_help["$_DLATCHSR_NPP_"] = {
  "$_DLATCHSR_NPP_",
  "",
  "(E, S, R, D, Q)",
  "simcells.v:3635",
  "A negative enable D-type latch with positive polarity set and positive\npolarity reset.\n::\n\n   Truth table:    E S R D | Q\n                  ---------+---\n                   - - 1 - | 0\n                   - 1 - - | 1\n                   0 - - d | d\n                   - - - - | q",
  "module \\$_DLATCHSR_NPP_ (E, S, R, D, Q);\n    input E, S, R, D;\n    output reg Q;\n    always @* begin\n        if (R == 1)\n            Q <= 0;\n        else if (S == 1)\n            Q <= 1;\n        else if (E == 0)\n            Q <= D;\n    end\nendmodule",
  "reg_latch",
  "2a",
  "",
};

cell_help["$_DLATCHSR_PNN_"] = {
  "$_DLATCHSR_PNN_",
  "",
  "(E, S, R, D, Q)",
  "simcells.v:3663",
  "A positive enable D-type latch with negative polarity set and negative\npolarity reset.\n::\n\n   Truth table:    E S R D | Q\n                  ---------+---\n                   - - 0 - | 0\n                   - 0 - - | 1\n                   1 - - d | d\n                   - - - - | q",
  "module \\$_DLATCHSR_PNN_ (E, S, R, D, Q);\n    input E, S, R, D;\n    output reg Q;\n    always @* begin\n        if (R == 0)\n            Q <= 0;\n        else if (S == 0)\n            Q <= 1;\n        else if (E == 1)\n            Q <= D;\n    end\nendmodule",
  "reg_latch",
  "2a",
  "",
};

cell_help["$_DLATCHSR_PNP_"] = {
  "$_DLATCHSR_PNP_",
  "",
  "(E, S, R, D, Q)",
  "simcells.v:3691",
  "A positive enable D-type latch with negative polarity set and positive\npolarity reset.\n::\n\n   Truth table:    E S R D | Q\n                  ---------+---\n                   - - 1 - | 0\n                   - 0 - - | 1\n                   1 - - d | d\n                   - - - - | q",
  "module \\$_DLATCHSR_PNP_ (E, S, R, D, Q);\n    input E, S, R, D;\n    output reg Q;\n    always @* begin\n        if (R == 1)\n            Q <= 0;\n        else if (S == 0)\n            Q <= 1;\n        else if (E == 1)\n            Q <= D;\n    end\nendmodule",
  "reg_latch",
  "2a",
  "",
};

cell_help["$_DLATCHSR_PPN_"] = {
  "$_DLATCHSR_PPN_",
  "",
  "(E, S, R, D, Q)",
  "simcells.v:3719",
  "A positive enable D-type latch with positive polarity set and negative\npolarity reset.\n::\n\n   Truth table:    E S R D | Q\n                  ---------+---\n                   - - 0 - | 0\n                   - 1 - - | 1\n                   1 - - d | d\n                   - - - - | q",
  "module \\$_DLATCHSR_PPN_ (E, S, R, D, Q);\n    input E, S, R, D;\n    output reg Q;\n    always @* begin\n        if (R == 0)\n            Q <= 0;\n        else if (S == 1)\n            Q <= 1;\n        else if (E == 1)\n            Q <= D;\n    end\nendmodule",
  "reg_latch",
  "2a",
  "",
};

cell_help["$_DLATCHSR_PPP_"] = {
  "$_DLATCHSR_PPP_",
  "",
  "(E, S, R, D, Q)",
  "simcells.v:3747",
  "A positive enable D-type latch with positive polarity set and positive\npolarity reset.\n::\n\n   Truth table:    E S R D | Q\n                  ---------+---\n                   - - 1 - | 0\n                   - 1 - - | 1\n                   1 - - d | d\n                   - - - - | q",
  "module \\$_DLATCHSR_PPP_ (E, S, R, D, Q);\n    input E, S, R, D;\n    output reg Q;\n    always @* begin\n        if (R == 1)\n            Q <= 0;\n        else if (S == 1)\n            Q <= 1;\n        else if (E == 1)\n            Q <= D;\n    end\nendmodule",
  "reg_latch",
  "2a",
  "",
};

