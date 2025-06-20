cell_help["$not"] = {
  "$not",
  "Bit-wise inverter",
  "(A, Y)",
  "simlib.v:40",
  "This corresponds to the Verilog unary prefix '~' operator.",
  "module \\$not (A, Y);\n    \n    parameter A_SIGNED = 0;\n    parameter A_WIDTH = 0;\n    parameter Y_WIDTH = 0;\n    \n    input [A_WIDTH-1:0] A;\n    output [Y_WIDTH-1:0] Y;\n    \n    generate\n        if (A_SIGNED) begin:BLOCK1\n            assign Y = ~$signed(A);\n        end else begin:BLOCK2\n            assign Y = ~A;\n        end\n    endgenerate\n    \nendmodule",
  "unary",
  "2",
  "",
};

cell_help["$pos"] = {
  "$pos",
  "",
  "(A, Y)",
  "simlib.v:68",
  "A buffer. This corresponds to the Verilog unary prefix '+' operator.",
  "module \\$pos (A, Y);\n    \n    parameter A_SIGNED = 0;\n    parameter A_WIDTH = 0;\n    parameter Y_WIDTH = 0;\n    \n    input [A_WIDTH-1:0] A;\n    output [Y_WIDTH-1:0] Y;\n    \n    generate\n        if (A_SIGNED) begin:BLOCK1\n            assign Y = $signed(A);\n        end else begin:BLOCK2\n            assign Y = A;\n        end\n    endgenerate\n    \nendmodule",
  "unary",
  "1",
  "",
};

cell_help["$buf"] = {
  "$buf",
  "",
  "(A, Y)",
  "simlib.v:98",
  "A simple coarse-grain buffer cell type for the experimental buffered-normalized\nmode. Note this cell does't get removed by 'opt_clean' and is not recommended\nfor general use.",
  "module \\$buf (A, Y);\n    \n    parameter WIDTH = 0;\n    \n    input [WIDTH-1:0] A;\n    output [WIDTH-1:0] Y;\n    \n    assign Y = A;\n    \nendmodule",
  "unary",
  "1",
  "",
};

cell_help["$neg"] = {
  "$neg",
  "",
  "(A, Y)",
  "simlib.v:118",
  "An arithmetic inverter. This corresponds to the Verilog unary prefix '-' operator.",
  "module \\$neg (A, Y);\n    \n    parameter A_SIGNED = 0;\n    parameter A_WIDTH = 0;\n    parameter Y_WIDTH = 0;\n    \n    input [A_WIDTH-1:0] A;\n    output [Y_WIDTH-1:0] Y;\n    \n    generate\n        if (A_SIGNED) begin:BLOCK1\n            assign Y = -$signed(A);\n        end else begin:BLOCK2\n            assign Y = -A;\n        end\n    endgenerate\n    \nendmodule",
  "unary",
  "1",
  "",
};

cell_help["$and"] = {
  "$and",
  "",
  "(A, B, Y)",
  "simlib.v:146",
  "A bit-wise AND. This corresponds to the Verilog '&' operator.",
  "module \\$and (A, B, Y);\n    \n    parameter A_SIGNED = 0;\n    parameter B_SIGNED = 0;\n    parameter A_WIDTH = 0;\n    parameter B_WIDTH = 0;\n    parameter Y_WIDTH = 0;\n    \n    input [A_WIDTH-1:0] A;\n    input [B_WIDTH-1:0] B;\n    output [Y_WIDTH-1:0] Y;\n    \n    generate\n        if (A_SIGNED && B_SIGNED) begin:BLOCK1\n            assign Y = $signed(A) & $signed(B);\n        end else begin:BLOCK2\n            assign Y = A & B;\n        end\n    endgenerate\n    \nendmodule",
  "binary",
  "1",
  "",
};

cell_help["$or"] = {
  "$or",
  "",
  "(A, B, Y)",
  "simlib.v:177",
  "A bit-wise OR. This corresponds to the Verilog '|' operator.",
  "module \\$or (A, B, Y);\n    \n    parameter A_SIGNED = 0;\n    parameter B_SIGNED = 0;\n    parameter A_WIDTH = 0;\n    parameter B_WIDTH = 0;\n    parameter Y_WIDTH = 0;\n    \n    input [A_WIDTH-1:0] A;\n    input [B_WIDTH-1:0] B;\n    output [Y_WIDTH-1:0] Y;\n    \n    generate\n        if (A_SIGNED && B_SIGNED) begin:BLOCK1\n            assign Y = $signed(A) | $signed(B);\n        end else begin:BLOCK2\n            assign Y = A | B;\n        end\n    endgenerate\n    \nendmodule",
  "binary",
  "1",
  "",
};

cell_help["$xor"] = {
  "$xor",
  "",
  "(A, B, Y)",
  "simlib.v:208",
  "A bit-wise XOR. This corresponds to the Verilog '^' operator.",
  "module \\$xor (A, B, Y);\n    \n    parameter A_SIGNED = 0;\n    parameter B_SIGNED = 0;\n    parameter A_WIDTH = 0;\n    parameter B_WIDTH = 0;\n    parameter Y_WIDTH = 0;\n    \n    input [A_WIDTH-1:0] A;\n    input [B_WIDTH-1:0] B;\n    output [Y_WIDTH-1:0] Y;\n    \n    generate\n        if (A_SIGNED && B_SIGNED) begin:BLOCK1\n            assign Y = $signed(A) ^ $signed(B);\n        end else begin:BLOCK2\n            assign Y = A ^ B;\n        end\n    endgenerate\n    \nendmodule",
  "binary",
  "1",
  "",
};

cell_help["$xnor"] = {
  "$xnor",
  "",
  "(A, B, Y)",
  "simlib.v:239",
  "A bit-wise XNOR. This corresponds to the Verilog '~^' operator.",
  "module \\$xnor (A, B, Y);\n    \n    parameter A_SIGNED = 0;\n    parameter B_SIGNED = 0;\n    parameter A_WIDTH = 0;\n    parameter B_WIDTH = 0;\n    parameter Y_WIDTH = 0;\n    \n    input [A_WIDTH-1:0] A;\n    input [B_WIDTH-1:0] B;\n    output [Y_WIDTH-1:0] Y;\n    \n    generate\n        if (A_SIGNED && B_SIGNED) begin:BLOCK1\n            assign Y = $signed(A) ~^ $signed(B);\n        end else begin:BLOCK2\n            assign Y = A ~^ B;\n        end\n    endgenerate\n    \nendmodule",
  "binary",
  "1",
  "",
};

cell_help["$reduce_and"] = {
  "$reduce_and",
  "",
  "(A, Y)",
  "simlib.v:270",
  "An AND reduction. This corresponds to the Verilog unary prefix '&' operator.",
  "module \\$reduce_and (A, Y);\n    \n    parameter A_SIGNED = 0;\n    parameter A_WIDTH = 0;\n    parameter Y_WIDTH = 0;\n    \n    input [A_WIDTH-1:0] A;\n    output [Y_WIDTH-1:0] Y;\n    \n    generate\n        if (A_SIGNED) begin:BLOCK1\n            assign Y = &$signed(A);\n        end else begin:BLOCK2\n            assign Y = &A;\n        end\n    endgenerate\n    \nendmodule",
  "unary",
  "1",
  "",
};

cell_help["$reduce_or"] = {
  "$reduce_or",
  "",
  "(A, Y)",
  "simlib.v:298",
  "An OR reduction. This corresponds to the Verilog unary prefix '|' operator.",
  "module \\$reduce_or (A, Y);\n    \n    parameter A_SIGNED = 0;\n    parameter A_WIDTH = 0;\n    parameter Y_WIDTH = 0;\n    \n    input [A_WIDTH-1:0] A;\n    output [Y_WIDTH-1:0] Y;\n    \n    generate\n        if (A_SIGNED) begin:BLOCK1\n            assign Y = |$signed(A);\n        end else begin:BLOCK2\n            assign Y = |A;\n        end\n    endgenerate\n    \nendmodule",
  "unary",
  "1",
  "",
};

cell_help["$reduce_xor"] = {
  "$reduce_xor",
  "",
  "(A, Y)",
  "simlib.v:326",
  "A XOR reduction. This corresponds to the Verilog unary prefix '^' operator.",
  "module \\$reduce_xor (A, Y);\n    \n    parameter A_SIGNED = 0;\n    parameter A_WIDTH = 0;\n    parameter Y_WIDTH = 0;\n    \n    input [A_WIDTH-1:0] A;\n    output [Y_WIDTH-1:0] Y;\n    \n    generate\n        if (A_SIGNED) begin:BLOCK1\n            assign Y = ^$signed(A);\n        end else begin:BLOCK2\n            assign Y = ^A;\n        end\n    endgenerate\n    \nendmodule",
  "unary",
  "1",
  "",
};

cell_help["$reduce_xnor"] = {
  "$reduce_xnor",
  "",
  "(A, Y)",
  "simlib.v:354",
  "A XNOR reduction. This corresponds to the Verilog unary prefix '~^' operator.",
  "module \\$reduce_xnor (A, Y);\n    \n    parameter A_SIGNED = 0;\n    parameter A_WIDTH = 0;\n    parameter Y_WIDTH = 0;\n    \n    input [A_WIDTH-1:0] A;\n    output [Y_WIDTH-1:0] Y;\n    \n    generate\n        if (A_SIGNED) begin:BLOCK1\n            assign Y = ~^$signed(A);\n        end else begin:BLOCK2\n            assign Y = ~^A;\n        end\n    endgenerate\n    \nendmodule",
  "unary",
  "1",
  "",
};

cell_help["$reduce_bool"] = {
  "$reduce_bool",
  "",
  "(A, Y)",
  "simlib.v:383",
  "An OR reduction. This cell type is used instead of $reduce_or when a signal is\nimplicitly converted to a boolean signal, e.g. for operands of '&&' and '||'.",
  "module \\$reduce_bool (A, Y);\n    \n    parameter A_SIGNED = 0;\n    parameter A_WIDTH = 0;\n    parameter Y_WIDTH = 0;\n    \n    input [A_WIDTH-1:0] A;\n    output [Y_WIDTH-1:0] Y;\n    \n    generate\n        if (A_SIGNED) begin:BLOCK1\n            assign Y = !(!$signed(A));\n        end else begin:BLOCK2\n            assign Y = !(!A);\n        end\n    endgenerate\n    \nendmodule",
  "unary",
  "1",
  "",
};

cell_help["$shl"] = {
  "$shl",
  "",
  "(A, B, Y)",
  "simlib.v:411",
  "A logical shift-left operation. This corresponds to the Verilog '<<' operator.",
  "module \\$shl (A, B, Y);\n    \n    parameter A_SIGNED = 0;\n    parameter B_SIGNED = 0;\n    parameter A_WIDTH = 0;\n    parameter B_WIDTH = 0;\n    parameter Y_WIDTH = 0;\n    \n    input [A_WIDTH-1:0] A;\n    input [B_WIDTH-1:0] B;\n    output [Y_WIDTH-1:0] Y;\n    \n    generate\n        if (A_SIGNED) begin:BLOCK1\n            assign Y = $signed(A) << B;\n        end else begin:BLOCK2\n            assign Y = A << B;\n        end\n    endgenerate\n    \nendmodule",
  "binary",
  "1",
  "",
};

cell_help["$shr"] = {
  "$shr",
  "",
  "(A, B, Y)",
  "simlib.v:442",
  "A logical shift-right operation. This corresponds to the Verilog '>>' operator.",
  "module \\$shr (A, B, Y);\n    \n    parameter A_SIGNED = 0;\n    parameter B_SIGNED = 0;\n    parameter A_WIDTH = 0;\n    parameter B_WIDTH = 0;\n    parameter Y_WIDTH = 0;\n    \n    input [A_WIDTH-1:0] A;\n    input [B_WIDTH-1:0] B;\n    output [Y_WIDTH-1:0] Y;\n    \n    generate\n        if (A_SIGNED) begin:BLOCK1\n            assign Y = $signed(A) >> B;\n        end else begin:BLOCK2\n            assign Y = A >> B;\n        end\n    endgenerate\n    \nendmodule",
  "binary",
  "1",
  "",
};

cell_help["$sshl"] = {
  "$sshl",
  "",
  "(A, B, Y)",
  "simlib.v:474",
  "An arithmatic shift-left operation.\nThis corresponds to the Verilog '<<<' operator.",
  "module \\$sshl (A, B, Y);\n    \n    parameter A_SIGNED = 0;\n    parameter B_SIGNED = 0;\n    parameter A_WIDTH = 0;\n    parameter B_WIDTH = 0;\n    parameter Y_WIDTH = 0;\n    \n    input [A_WIDTH-1:0] A;\n    input [B_WIDTH-1:0] B;\n    output [Y_WIDTH-1:0] Y;\n    \n    generate\n        if (A_SIGNED) begin:BLOCK1\n            assign Y = $signed(A) <<< B;\n        end else begin:BLOCK2\n            assign Y = A <<< B;\n        end\n    endgenerate\n    \nendmodule",
  "binary",
  "1",
  "",
};

cell_help["$sshr"] = {
  "$sshr",
  "",
  "(A, B, Y)",
  "simlib.v:506",
  "An arithmatic shift-right operation.\nThis corresponds to the Verilog '>>>' operator.",
  "module \\$sshr (A, B, Y);\n    \n    parameter A_SIGNED = 0;\n    parameter B_SIGNED = 0;\n    parameter A_WIDTH = 0;\n    parameter B_WIDTH = 0;\n    parameter Y_WIDTH = 0;\n    \n    input [A_WIDTH-1:0] A;\n    input [B_WIDTH-1:0] B;\n    output [Y_WIDTH-1:0] Y;\n    \n    generate\n        if (A_SIGNED) begin:BLOCK1\n            assign Y = $signed(A) >>> B;\n        end else begin:BLOCK2\n            assign Y = A >>> B;\n        end\n    endgenerate\n    \nendmodule",
  "binary",
  "1",
  "",
};

cell_help["$shift"] = {
  "$shift",
  "Variable shifter",
  "(A, B, Y)",
  "simlib.v:535",
  "Performs a right logical shift if the second operand is positive (or\nunsigned), and a left logical shift if it is negative.",
  "module \\$shift (A, B, Y);\n    \n    parameter A_SIGNED = 0;\n    parameter B_SIGNED = 0;\n    parameter A_WIDTH = 0;\n    parameter B_WIDTH = 0;\n    parameter Y_WIDTH = 0;\n    \n    input [A_WIDTH-1:0] A;\n    input [B_WIDTH-1:0] B;\n    output [Y_WIDTH-1:0] Y;\n    \n    generate\n        if (A_SIGNED) begin:BLOCK1\n            if (B_SIGNED) begin:BLOCK2\n                assign Y = $signed(B) < 0 ? $signed(A) << -B : $signed(A) >> B;\n            end else begin:BLOCK3\n                assign Y = $signed(A) >> B;\n            end\n        end else begin:BLOCK4\n            if (B_SIGNED) begin:BLOCK5\n                assign Y = $signed(B) < 0 ? A << -B : A >> B;\n            end else begin:BLOCK6\n                assign Y = A >> B;\n            end\n        end\n    endgenerate\n    \nendmodule",
  "binary",
  "2",
  "",
};

cell_help["$shiftx"] = {
  "$shiftx",
  "Indexed part-select",
  "(A, B, Y)",
  "simlib.v:572",
  "Same as the `$shift` cell, but fills with 'x'.",
  "module \\$shiftx (A, B, Y);\n    \n    parameter A_SIGNED = 0;\n    parameter B_SIGNED = 0;\n    parameter A_WIDTH = 0;\n    parameter B_WIDTH = 0;\n    parameter Y_WIDTH = 0;\n    \n    input [A_WIDTH-1:0] A;\n    input [B_WIDTH-1:0] B;\n    output [Y_WIDTH-1:0] Y;\n    \n    generate\n        if (Y_WIDTH > 0)\n            if (B_SIGNED) begin:BLOCK1\n                assign Y = A[$signed(B) +: Y_WIDTH];\n            end else begin:BLOCK2\n                assign Y = A[B +: Y_WIDTH];\n            end\n    endgenerate\n    \nendmodule",
  "binary",
  "2",
  "x-output",
};

cell_help["$fa"] = {
  "$fa",
  "",
  "(A, B, C, X, Y)",
  "simlib.v:597",
  "",
  "module \\$fa (A, B, C, X, Y);\n    \n    parameter WIDTH = 1;\n    \n    input [WIDTH-1:0] A, B, C;\n    output [WIDTH-1:0] X, Y;\n    \n    wire [WIDTH-1:0] t1, t2, t3;\n    \n    assign t1 = A ^ B, t2 = A & B, t3 = C & t1;\n    assign Y = t1 ^ C, X = (t2 | t3) ^ (Y ^ Y);\n    \nendmodule",
  "arith",
  "1",
  "",
};

cell_help["$lcu"] = {
  "$lcu",
  "",
  "(P, G, CI, CO)",
  "simlib.v:625",
  "Lookahead carry unit\nA building block dedicated to fast computation of carry-bits used in binary\narithmetic operations. By replacing the ripple carry structure used in full-adder\nblocks, the more significant  bits of the sum can be expected to be computed more\nquickly.\nTypically created during `techmap` of $alu cells (see the \"_90_alu\" rule in\n+/techmap.v).",
  "module \\$lcu (P, G, CI, CO);\n    \n    parameter WIDTH = 1;\n    \n    input [WIDTH-1:0] P;    // Propagate\n    input [WIDTH-1:0] G;    // Generate\n    input CI;               // Carry-in\n    \n    output reg [WIDTH-1:0] CO; // Carry-out\n    \n    integer i;\n    always @* begin\n        CO = 'bx;\n        if (^{P, G, CI} !== 1'bx) begin\n            CO[0] = G[0] || (P[0] && CI);\n            for (i = 1; i < WIDTH; i = i+1)\n                CO[i] = G[i] || (P[i] && CO[i-1]);\n        end\n    end\n    \nendmodule",
  "arith",
  "1",
  "",
};

cell_help["$alu"] = {
  "$alu",
  "Arithmetic logic unit",
  "(A, B, CI, BI, X, Y, CO)",
  "simlib.v:657",
  "A building block supporting both binary addition/subtraction operations, and\nindirectly, comparison operations.\nTypically created by the `alumacc` pass, which transforms:\n`$add`, `$sub`, `$lt`, `$le`, `$ge`, `$gt`, `$eq`, `$eqx`, `$ne`, `$nex`\ncells into this `$alu` cell.",
  "module \\$alu (A, B, CI, BI, X, Y, CO);\n    \n    parameter A_SIGNED = 0;\n    parameter B_SIGNED = 0;\n    parameter A_WIDTH = 1;\n    parameter B_WIDTH = 1;\n    parameter Y_WIDTH = 1;\n    \n    input [A_WIDTH-1:0] A;      // Input operand\n    input [B_WIDTH-1:0] B;      // Input operand\n    output [Y_WIDTH-1:0] X;     // A xor B (sign-extended, optional B inversion,\n                                //          used in combination with\n                                //          reduction-AND for $eq/$ne ops)\n    output [Y_WIDTH-1:0] Y;     // Sum\n    \n    input CI;                   // Carry-in (set for $sub)\n    input BI;                   // Invert-B (set for $sub)\n    output [Y_WIDTH-1:0] CO;    // Carry-out\n    \n    wire [Y_WIDTH-1:0] AA, BB;\n    \n    generate\n        if (A_SIGNED && B_SIGNED) begin:BLOCK1\n            assign AA = $signed(A), BB = BI ? ~$signed(B) : $signed(B);\n        end else begin:BLOCK2\n            assign AA = $unsigned(A), BB = BI ? ~$unsigned(B) : $unsigned(B);\n        end\n    endgenerate\n    \n    // this is 'x' if Y and CO should be all 'x', and '0' otherwise\n    wire y_co_undef = ^{A, A, B, B, CI, CI, BI, BI};\n    \n    assign X = AA ^ BB;\n    // Full adder\n    assign Y = (AA + BB + CI) ^ {Y_WIDTH{y_co_undef}};\n    \n    function get_carry;\n        input a, b, c;\n        get_carry = (a&b) | (a&c) | (b&c);\n    endfunction\n    \n    genvar i;\n    generate\n        assign CO[0] = get_carry(AA[0], BB[0], CI) ^ y_co_undef;\n        for (i = 1; i < Y_WIDTH; i = i+1) begin:BLOCK3\n            assign CO[i] = get_carry(AA[i], BB[i], CO[i-1]) ^ y_co_undef;\n        end\n    endgenerate\n    \nendmodule",
  "arith",
  "2",
  "",
};

cell_help["$lt"] = {
  "$lt",
  "",
  "(A, B, Y)",
  "simlib.v:718",
  "A less-than comparison between inputs 'A' and 'B'.\nThis corresponds to the Verilog '<' operator.",
  "module \\$lt (A, B, Y);\n    \n    parameter A_SIGNED = 0;\n    parameter B_SIGNED = 0;\n    parameter A_WIDTH = 0;\n    parameter B_WIDTH = 0;\n    parameter Y_WIDTH = 0;\n    \n    input [A_WIDTH-1:0] A;\n    input [B_WIDTH-1:0] B;\n    output [Y_WIDTH-1:0] Y;\n    \n    generate\n        if (A_SIGNED && B_SIGNED) begin:BLOCK1\n            assign Y = $signed(A) < $signed(B);\n        end else begin:BLOCK2\n            assign Y = A < B;\n        end\n    endgenerate\n    \nendmodule",
  "binary",
  "1",
  "",
};

cell_help["$le"] = {
  "$le",
  "",
  "(A, B, Y)",
  "simlib.v:750",
  "A less-than-or-equal-to comparison between inputs 'A' and 'B'.\nThis corresponds to the Verilog '<=' operator.",
  "module \\$le (A, B, Y);\n    \n    parameter A_SIGNED = 0;\n    parameter B_SIGNED = 0;\n    parameter A_WIDTH = 0;\n    parameter B_WIDTH = 0;\n    parameter Y_WIDTH = 0;\n    \n    input [A_WIDTH-1:0] A;\n    input [B_WIDTH-1:0] B;\n    output [Y_WIDTH-1:0] Y;\n    \n    generate\n        if (A_SIGNED && B_SIGNED) begin:BLOCK1\n            assign Y = $signed(A) <= $signed(B);\n        end else begin:BLOCK2\n            assign Y = A <= B;\n        end\n    endgenerate\n    \nendmodule",
  "binary",
  "1",
  "",
};

cell_help["$eq"] = {
  "$eq",
  "",
  "(A, B, Y)",
  "simlib.v:782",
  "An equality comparison between inputs 'A' and 'B'.\nThis corresponds to the Verilog '==' operator.",
  "module \\$eq (A, B, Y);\n    \n    parameter A_SIGNED = 0;\n    parameter B_SIGNED = 0;\n    parameter A_WIDTH = 0;\n    parameter B_WIDTH = 0;\n    parameter Y_WIDTH = 0;\n    \n    input [A_WIDTH-1:0] A;\n    input [B_WIDTH-1:0] B;\n    output [Y_WIDTH-1:0] Y;\n    \n    generate\n        if (A_SIGNED && B_SIGNED) begin:BLOCK1\n            assign Y = $signed(A) == $signed(B);\n        end else begin:BLOCK2\n            assign Y = A == B;\n        end\n    endgenerate\n    \nendmodule",
  "binary",
  "1",
  "",
};

cell_help["$ne"] = {
  "$ne",
  "",
  "(A, B, Y)",
  "simlib.v:814",
  "An inequality comparison between inputs 'A' and 'B'.\nThis corresponds to the Verilog '!=' operator.",
  "module \\$ne (A, B, Y);\n    \n    parameter A_SIGNED = 0;\n    parameter B_SIGNED = 0;\n    parameter A_WIDTH = 0;\n    parameter B_WIDTH = 0;\n    parameter Y_WIDTH = 0;\n    \n    input [A_WIDTH-1:0] A;\n    input [B_WIDTH-1:0] B;\n    output [Y_WIDTH-1:0] Y;\n    \n    generate\n        if (A_SIGNED && B_SIGNED) begin:BLOCK1\n            assign Y = $signed(A) != $signed(B);\n        end else begin:BLOCK2\n            assign Y = A != B;\n        end\n    endgenerate\n    \nendmodule",
  "binary",
  "1",
  "",
};

cell_help["$eqx"] = {
  "$eqx",
  "Case equality",
  "(A, B, Y)",
  "simlib.v:847",
  "An exact equality comparison between inputs 'A' and 'B'. Also known as the\ncase equality operator. This corresponds to the Verilog '===' operator.\nUnlike equality comparison that can give 'x' as output, an exact equality\ncomparison will strictly give '0' or '1' as output, even if input includes\n'x' or 'z' values.",
  "module \\$eqx (A, B, Y);\n    \n    parameter A_SIGNED = 0;\n    parameter B_SIGNED = 0;\n    parameter A_WIDTH = 0;\n    parameter B_WIDTH = 0;\n    parameter Y_WIDTH = 0;\n    \n    input [A_WIDTH-1:0] A;\n    input [B_WIDTH-1:0] B;\n    output [Y_WIDTH-1:0] Y;\n    \n    generate\n        if (A_SIGNED && B_SIGNED) begin:BLOCK1\n            assign Y = $signed(A) === $signed(B);\n        end else begin:BLOCK2\n            assign Y = A === B;\n        end\n    endgenerate\n    \nendmodule",
  "binary",
  "2",
  "x-aware",
};

cell_help["$nex"] = {
  "$nex",
  "Case inequality",
  "(A, B, Y)",
  "simlib.v:878",
  "This corresponds to the Verilog '!==' operator.\n\nRefer to `$eqx` for more details.",
  "module \\$nex (A, B, Y);\n    \n    parameter A_SIGNED = 0;\n    parameter B_SIGNED = 0;\n    parameter A_WIDTH = 0;\n    parameter B_WIDTH = 0;\n    parameter Y_WIDTH = 0;\n    \n    input [A_WIDTH-1:0] A;\n    input [B_WIDTH-1:0] B;\n    output [Y_WIDTH-1:0] Y;\n    \n    generate\n        if (A_SIGNED && B_SIGNED) begin:BLOCK1\n            assign Y = $signed(A) !== $signed(B);\n        end else begin:BLOCK2\n            assign Y = A !== B;\n        end\n    endgenerate\n    \nendmodule",
  "binary",
  "2",
  "x-aware",
};

cell_help["$ge"] = {
  "$ge",
  "",
  "(A, B, Y)",
  "simlib.v:910",
  "A greater-than-or-equal-to comparison between inputs 'A' and 'B'.\nThis corresponds to the Verilog '>=' operator.",
  "module \\$ge (A, B, Y);\n    \n    parameter A_SIGNED = 0;\n    parameter B_SIGNED = 0;\n    parameter A_WIDTH = 0;\n    parameter B_WIDTH = 0;\n    parameter Y_WIDTH = 0;\n    \n    input [A_WIDTH-1:0] A;\n    input [B_WIDTH-1:0] B;\n    output [Y_WIDTH-1:0] Y;\n    \n    generate\n        if (A_SIGNED && B_SIGNED) begin:BLOCK1\n            assign Y = $signed(A) >= $signed(B);\n        end else begin:BLOCK2\n            assign Y = A >= B;\n        end\n    endgenerate\n    \nendmodule",
  "binary",
  "1",
  "",
};

cell_help["$gt"] = {
  "$gt",
  "",
  "(A, B, Y)",
  "simlib.v:942",
  "A greater-than comparison between inputs 'A' and 'B'.\nThis corresponds to the Verilog '>' operator.",
  "module \\$gt (A, B, Y);\n    \n    parameter A_SIGNED = 0;\n    parameter B_SIGNED = 0;\n    parameter A_WIDTH = 0;\n    parameter B_WIDTH = 0;\n    parameter Y_WIDTH = 0;\n    \n    input [A_WIDTH-1:0] A;\n    input [B_WIDTH-1:0] B;\n    output [Y_WIDTH-1:0] Y;\n    \n    generate\n        if (A_SIGNED && B_SIGNED) begin:BLOCK1\n            assign Y = $signed(A) > $signed(B);\n        end else begin:BLOCK2\n            assign Y = A > B;\n        end\n    endgenerate\n    \nendmodule",
  "binary",
  "1",
  "",
};

cell_help["$add"] = {
  "$add",
  "",
  "(A, B, Y)",
  "simlib.v:973",
  "Addition of inputs 'A' and 'B'. This corresponds to the Verilog '+' operator.",
  "module \\$add (A, B, Y);\n    \n    parameter A_SIGNED = 0;\n    parameter B_SIGNED = 0;\n    parameter A_WIDTH = 0;\n    parameter B_WIDTH = 0;\n    parameter Y_WIDTH = 0;\n    \n    input [A_WIDTH-1:0] A;\n    input [B_WIDTH-1:0] B;\n    output [Y_WIDTH-1:0] Y;\n    \n    generate\n        if (A_SIGNED && B_SIGNED) begin:BLOCK1\n            assign Y = $signed(A) + $signed(B);\n        end else begin:BLOCK2\n            assign Y = A + B;\n        end\n    endgenerate\n    \nendmodule",
  "binary",
  "1",
  "",
};

cell_help["$sub"] = {
  "$sub",
  "",
  "(A, B, Y)",
  "simlib.v:1005",
  "Subtraction between inputs 'A' and 'B'.\nThis corresponds to the Verilog '-' operator.",
  "module \\$sub (A, B, Y);\n    \n    parameter A_SIGNED = 0;\n    parameter B_SIGNED = 0;\n    parameter A_WIDTH = 0;\n    parameter B_WIDTH = 0;\n    parameter Y_WIDTH = 0;\n    \n    input [A_WIDTH-1:0] A;\n    input [B_WIDTH-1:0] B;\n    output [Y_WIDTH-1:0] Y;\n    \n    generate\n        if (A_SIGNED && B_SIGNED) begin:BLOCK1\n            assign Y = $signed(A) - $signed(B);\n        end else begin:BLOCK2\n            assign Y = A - B;\n        end\n    endgenerate\n    \nendmodule",
  "binary",
  "1",
  "",
};

cell_help["$mul"] = {
  "$mul",
  "",
  "(A, B, Y)",
  "simlib.v:1037",
  "Multiplication of inputs 'A' and 'B'.\nThis corresponds to the Verilog '*' operator.",
  "module \\$mul (A, B, Y);\n    \n    parameter A_SIGNED = 0;\n    parameter B_SIGNED = 0;\n    parameter A_WIDTH = 0;\n    parameter B_WIDTH = 0;\n    parameter Y_WIDTH = 0;\n    \n    input [A_WIDTH-1:0] A;\n    input [B_WIDTH-1:0] B;\n    output [Y_WIDTH-1:0] Y;\n    \n    generate\n        if (A_SIGNED && B_SIGNED) begin:BLOCK1\n            assign Y = $signed(A) * $signed(B);\n        end else begin:BLOCK2\n            assign Y = A * B;\n        end\n    endgenerate\n    \nendmodule",
  "binary",
  "1",
  "",
};

cell_help["$macc"] = {
  "$macc",
  "",
  "(A, B, Y)",
  "simlib.v:1073",
  "Multiply and accumulate.\nA building block for summing any number of negated and unnegated signals\nand arithmetic products of pairs of signals. Cell port A concatenates pairs\nof signals to be multiplied together. When the second signal in a pair is zero\nlength, a constant 1 is used instead as the second factor. Cell port B\nconcatenates 1-bit-wide signals to also be summed, such as \"carry in\" in adders.\nTypically created by the `alumacc` pass, which transforms $add and $mul\ninto $macc cells.",
  "module \\$macc (A, B, Y);\n    \n    parameter A_WIDTH = 0;\n    parameter B_WIDTH = 0;\n    parameter Y_WIDTH = 0;\n    // CONFIG determines the layout of A, as explained below\n    parameter CONFIG = 4'b0000;\n    parameter CONFIG_WIDTH = 4;\n    \n    // In the terms used for this cell, there's mixed meanings for the term \"port\". To disambiguate:\n    // A cell port is for example the A input (it is constructed in C++ as cell->setPort(ID::A, ...))\n    // Multiplier ports are pairs of multiplier inputs (\"factors\").\n    // If the second signal in such a pair is zero length, no multiplication is necessary, and the first signal is just added to the sum.\n    input [A_WIDTH-1:0] A; // Cell port A is the concatenation of all arithmetic ports\n    input [B_WIDTH-1:0] B; // Cell port B is the concatenation of single-bit unsigned signals to be also added to the sum\n    output reg [Y_WIDTH-1:0] Y; // Output sum\n    \n    // Xilinx XSIM does not like $clog2() below..\n    function integer my_clog2;\n        input integer v;\n        begin\n            if (v > 0)\n                v = v - 1;\n            my_clog2 = 0;\n            while (v) begin\n                v = v >> 1;\n                my_clog2 = my_clog2 + 1;\n            end\n        end\n    endfunction\n    \n    // Bits that a factor's length field in CONFIG per factor in cell port A\n    localparam integer num_bits = CONFIG[3:0] > 0 ? CONFIG[3:0] : 1;\n    // Number of multiplier ports\n    localparam integer num_ports = (CONFIG_WIDTH-4) / (2 + 2*num_bits);\n    // Minium bit width of an induction variable to iterate over all bits of cell port A\n    localparam integer num_abits = my_clog2(A_WIDTH) > 0 ? my_clog2(A_WIDTH) : 1;\n    \n    // In this pseudocode, u(foo) means an unsigned int that's foo bits long.\n    // The CONFIG parameter carries the following information:\n    //    struct CONFIG {\n    //        u4 num_bits;\n    //        struct port_field {\n    //            bool is_signed;\n    //            bool is_subtract;\n    //            u(num_bits) factor1_len;\n    //            u(num_bits) factor2_len;\n    //        }[num_ports];\n    //    };\n    \n    // The A cell port carries the following information:\n    //    struct A {\n    //        u(CONFIG.port_field[0].factor1_len) port0factor1;\n    //        u(CONFIG.port_field[0].factor2_len) port0factor2;\n    //        u(CONFIG.port_field[1].factor1_len) port1factor1;\n    //        u(CONFIG.port_field[1].factor2_len) port1factor2;\n    //        ...\n    //    };\n    // and log(sizeof(A)) is num_abits.\n    // No factor1 may have a zero length.\n    // A factor2 having a zero length implies factor2 is replaced with a constant 1.\n    \n    // Additionally, B is an array of 1-bit-wide unsigned integers to also be summed up.\n    // Finally, we have:\n    // Y = port0factor1 * port0factor2 + port1factor1 * port1factor2 + ...\n    //     * B[0] + B[1] + ...\n    \n    function [2*num_ports*num_abits-1:0] get_port_offsets;\n        input [CONFIG_WIDTH-1:0] cfg;\n        integer i, cursor;\n        begin\n            cursor = 0;\n            get_port_offsets = 0;\n            for (i = 0; i < num_ports; i = i+1) begin\n                get_port_offsets[(2*i + 0)*num_abits +: num_abits] = cursor;\n                cursor = cursor + cfg[4 + i*(2 + 2*num_bits) + 2 +: num_bits];\n                get_port_offsets[(2*i + 1)*num_abits +: num_abits] = cursor;\n                cursor = cursor + cfg[4 + i*(2 + 2*num_bits) + 2 + num_bits +: num_bits];\n            end\n        end\n    endfunction\n    \n    localparam [2*num_ports*num_abits-1:0] port_offsets = get_port_offsets(CONFIG);\n    \n    `define PORT_IS_SIGNED   (0 + CONFIG[4 + i*(2 + 2*num_bits)])\n    `define PORT_DO_SUBTRACT (0 + CONFIG[4 + i*(2 + 2*num_bits) + 1])\n    `define PORT_SIZE_A      (0 + CONFIG[4 + i*(2 + 2*num_bits) + 2 +: num_bits])\n    `define PORT_SIZE_B      (0 + CONFIG[4 + i*(2 + 2*num_bits) + 2 + num_bits +: num_bits])\n    `define PORT_OFFSET_A    (0 + port_offsets[2*i*num_abits +: num_abits])\n    `define PORT_OFFSET_B    (0 + port_offsets[2*i*num_abits + num_abits +: num_abits])\n    \n    integer i, j;\n    reg [Y_WIDTH-1:0] tmp_a, tmp_b;\n    \n    always @* begin\n        Y = 0;\n        for (i = 0; i < num_ports; i = i+1)\n        begin\n            tmp_a = 0;\n            tmp_b = 0;\n    \n            for (j = 0; j < `PORT_SIZE_A; j = j+1)\n                tmp_a[j] = A[`PORT_OFFSET_A + j];\n    \n            if (`PORT_IS_SIGNED && `PORT_SIZE_A > 0)\n                for (j = `PORT_SIZE_A; j < Y_WIDTH; j = j+1)\n                    tmp_a[j] = tmp_a[`PORT_SIZE_A-1];\n    \n            for (j = 0; j < `PORT_SIZE_B; j = j+1)\n                tmp_b[j] = A[`PORT_OFFSET_B + j];\n    \n            if (`PORT_IS_SIGNED && `PORT_SIZE_B > 0)\n                for (j = `PORT_SIZE_B; j < Y_WIDTH; j = j+1)\n                    tmp_b[j] = tmp_b[`PORT_SIZE_B-1];\n    \n            if (`PORT_SIZE_B > 0)\n                tmp_a = tmp_a * tmp_b;\n    \n            if (`PORT_DO_SUBTRACT)\n                Y = Y - tmp_a;\n            else\n                Y = Y + tmp_a;\n        end\n        for (i = 0; i < B_WIDTH; i = i+1) begin\n            Y = Y + B[i];\n        end\n    end\n    \n    `undef PORT_IS_SIGNED\n    `undef PORT_DO_SUBTRACT\n    `undef PORT_SIZE_A\n    `undef PORT_SIZE_B\n    `undef PORT_OFFSET_A\n    `undef PORT_OFFSET_B\n    \nendmodule",
  "arith",
  "1",
  "",
};

cell_help["$macc_v2"] = {
  "$macc_v2",
  "",
  "(A, B, C, Y)",
  "simlib.v:1220",
  "Multiply and add.\nThis cell represents a generic fused multiply-add operation, it supersedes the\nearlier $macc cell.",
  "module \\$macc_v2 (A, B, C, Y);\n    \n    parameter NPRODUCTS = 0;\n    parameter NADDENDS = 0;\n    parameter A_WIDTHS = 16'h0000;\n    parameter B_WIDTHS = 16'h0000;\n    parameter C_WIDTHS = 16'h0000;\n    parameter Y_WIDTH = 0;\n    \n    parameter PRODUCT_NEGATED = 1'bx;\n    parameter ADDEND_NEGATED = 1'bx;\n    parameter A_SIGNED = 1'bx;\n    parameter B_SIGNED = 1'bx;\n    parameter C_SIGNED = 1'bx;\n    \n    function integer sum_widths1;\n        input [(16*NPRODUCTS)-1:0] widths;\n        integer i;\n        begin\n            sum_widths1 = 0;\n            for (i = 0; i < NPRODUCTS; i++) begin\n                sum_widths1 = sum_widths1 + widths[16*i+:16];\n            end\n        end\n    endfunction\n    \n    function integer sum_widths2;\n        input [(16*NADDENDS)-1:0] widths;\n        integer i;\n        begin\n            sum_widths2 = 0;\n            for (i = 0; i < NADDENDS; i++) begin\n                sum_widths2 = sum_widths2 + widths[16*i+:16];\n            end\n        end\n    endfunction\n    \n    input [sum_widths1(A_WIDTHS)-1:0] A; // concatenation of LHS factors\n    input [sum_widths1(B_WIDTHS)-1:0] B; // concatenation of RHS factors\n    input [sum_widths2(C_WIDTHS)-1:0] C; // concatenation of summands\n    output reg [Y_WIDTH-1:0] Y; // output sum\n    \n    integer i, j, ai, bi, ci, aw, bw, cw;\n    reg [Y_WIDTH-1:0] product;\n    reg [Y_WIDTH-1:0] addend, oper_a, oper_b;\n    \n    always @* begin\n        Y = 0;\n        ai = 0;\n        bi = 0;\n        for (i = 0; i < NPRODUCTS; i = i+1)\n        begin\n            aw = A_WIDTHS[16*i+:16];\n            bw = B_WIDTHS[16*i+:16];\n    \n            oper_a = 0;\n            oper_b = 0;\n            for (j = 0; j < Y_WIDTH && j < aw; j = j + 1)\n                oper_a[j] = A[ai + j];\n            for (j = 0; j < Y_WIDTH && j < bw; j = j + 1)\n                oper_b[j] = B[bi + j];\n            // A_SIGNED[i] == B_SIGNED[i] as RTLIL invariant\n            if (A_SIGNED[i] && B_SIGNED[i]) begin\n                for (j = aw; j > 0 && j < Y_WIDTH; j = j + 1)\n                    oper_a[j] = oper_a[j - 1];\n                for (j = bw; j > 0 && j < Y_WIDTH; j = j + 1)\n                    oper_b[j] = oper_b[j - 1];\n            end\n    \n            product = oper_a * oper_b;\n    \n            if (PRODUCT_NEGATED[i])\n                Y = Y - product;\n            else\n                Y = Y + product;\n    \n            ai = ai + aw;\n            bi = bi + bw;\n        end\n    \n        ci = 0;\n        for (i = 0; i < NADDENDS; i = i+1)\n        begin\n            cw = C_WIDTHS[16*i+:16];\n    \n            addend = 0;\n            for (j = 0; j < Y_WIDTH && j < cw; j = j + 1)\n                addend[j] = C[ci + j];\n            if (C_SIGNED[i]) begin\n                for (j = cw; j > 0 && j < Y_WIDTH; j = j + 1)\n                    addend[j] = addend[j - 1];\n            end\n    \n            if (ADDEND_NEGATED[i])\n                Y = Y - addend;\n            else\n                Y = Y + addend;\n    \n            ci = ci + cw;\n        end\n    end\n    \nendmodule",
  "arith",
  "1",
  "",
};

cell_help["$div"] = {
  "$div",
  "Divider",
  "(A, B, Y)",
  "simlib.v:1332",
  "This corresponds to the Verilog '/' operator, performing division and\ntruncating the result (rounding towards 0).",
  "module \\$div (A, B, Y);\n    \n    parameter A_SIGNED = 0;\n    parameter B_SIGNED = 0;\n    parameter A_WIDTH = 0;\n    parameter B_WIDTH = 0;\n    parameter Y_WIDTH = 0;\n    \n    input [A_WIDTH-1:0] A;\n    input [B_WIDTH-1:0] B;\n    output [Y_WIDTH-1:0] Y;\n    \n    generate\n        if (A_SIGNED && B_SIGNED) begin:BLOCK1\n            assign Y = $signed(A) / $signed(B);\n        end else begin:BLOCK2\n            assign Y = A / B;\n        end\n    endgenerate\n    \nendmodule",
  "binary",
  "2",
  "x-output",
};

cell_help["$mod"] = {
  "$mod",
  "Modulo",
  "(A, B, Y)",
  "simlib.v:1364",
  "This corresponds to the Verilog '%' operator, giving the module (or\nremainder) of division and truncating the result (rounding towards 0).\n\nInvariant: $div(A, B) * B + $mod(A, B) == A",
  "module \\$mod (A, B, Y);\n    \n    parameter A_SIGNED = 0;\n    parameter B_SIGNED = 0;\n    parameter A_WIDTH = 0;\n    parameter B_WIDTH = 0;\n    parameter Y_WIDTH = 0;\n    \n    input [A_WIDTH-1:0] A;\n    input [B_WIDTH-1:0] B;\n    output [Y_WIDTH-1:0] Y;\n    \n    generate\n        if (A_SIGNED && B_SIGNED) begin:BLOCK1\n            assign Y = $signed(A) % $signed(B);\n        end else begin:BLOCK2\n            assign Y = A % B;\n        end\n    endgenerate\n    \nendmodule",
  "binary",
  "2",
  "x-output",
};

cell_help["$divfloor"] = {
  "$divfloor",
  "",
  "(A, B, Y)",
  "simlib.v:1395",
  "Division with floored result (rounded towards negative infinity).",
  "module \\$divfloor (A, B, Y);\n    \n    parameter A_SIGNED = 0;\n    parameter B_SIGNED = 0;\n    parameter A_WIDTH = 0;\n    parameter B_WIDTH = 0;\n    parameter Y_WIDTH = 0;\n    \n    input [A_WIDTH-1:0] A;\n    input [B_WIDTH-1:0] B;\n    output [Y_WIDTH-1:0] Y;\n    \n    generate\n        if (A_SIGNED && B_SIGNED) begin:BLOCK1\n            localparam WIDTH =\n                    A_WIDTH >= B_WIDTH && A_WIDTH >= Y_WIDTH ? A_WIDTH :\n                    B_WIDTH >= A_WIDTH && B_WIDTH >= Y_WIDTH ? B_WIDTH : Y_WIDTH;\n            wire [WIDTH:0] A_buf, B_buf, N_buf;\n            assign A_buf = $signed(A);\n            assign B_buf = $signed(B);\n            assign N_buf = (A[A_WIDTH-1] == B[B_WIDTH-1]) || A == 0 ? A_buf : $signed(A_buf - (B[B_WIDTH-1] ? B_buf+1 : B_buf-1));\n            assign Y = $signed(N_buf) / $signed(B_buf);\n        end else begin:BLOCK2\n            assign Y = A / B;\n        end\n    endgenerate\n    \nendmodule",
  "binary",
  "1",
  "",
};

cell_help["$modfloor"] = {
  "$modfloor",
  "",
  "(A, B, Y)",
  "simlib.v:1435",
  "Modulo/remainder of division with floored result (rounded towards negative infinity).\n\nInvariant: $divfloor(A, B) * B + $modfloor(A, B) == A",
  "module \\$modfloor (A, B, Y);\n    \n    parameter A_SIGNED = 0;\n    parameter B_SIGNED = 0;\n    parameter A_WIDTH = 0;\n    parameter B_WIDTH = 0;\n    parameter Y_WIDTH = 0;\n    \n    input [A_WIDTH-1:0] A;\n    input [B_WIDTH-1:0] B;\n    output [Y_WIDTH-1:0] Y;\n    \n    generate\n        if (A_SIGNED && B_SIGNED) begin:BLOCK1\n            localparam WIDTH = B_WIDTH >= Y_WIDTH ? B_WIDTH : Y_WIDTH;\n            wire [WIDTH-1:0] B_buf, Y_trunc;\n            assign B_buf = $signed(B);\n            assign Y_trunc = $signed(A) % $signed(B);\n            // flooring mod is the same as truncating mod for positive division results (A and B have\n            // the same sign), as well as when there's no remainder.\n            // For all other cases, they behave as `floor - trunc = B`\n            assign Y = (A[A_WIDTH-1] == B[B_WIDTH-1]) || Y_trunc == 0 ? Y_trunc : $signed(B_buf) + $signed(Y_trunc);\n        end else begin:BLOCK2\n            // no difference between truncating and flooring for unsigned\n            assign Y = A % B;\n        end\n    endgenerate\n    \nendmodule",
  "binary",
  "1",
  "",
};

cell_help["$pow"] = {
  "$pow",
  "",
  "(A, B, Y)",
  "simlib.v:1477",
  "Exponentiation of an input (Y = A ** B).\nThis corresponds to the Verilog '**' operator.",
  "module \\$pow (A, B, Y);\n    \n    parameter A_SIGNED = 0;\n    parameter B_SIGNED = 0;\n    parameter A_WIDTH = 0;\n    parameter B_WIDTH = 0;\n    parameter Y_WIDTH = 0;\n    \n    input [A_WIDTH-1:0] A;\n    input [B_WIDTH-1:0] B;\n    output [Y_WIDTH-1:0] Y;\n    \n    generate\n        if (A_SIGNED && B_SIGNED) begin:BLOCK1\n            assign Y = $signed(A) ** $signed(B);\n        end else if (A_SIGNED) begin:BLOCK2\n            assign Y = $signed(A) ** B;\n        end else if (B_SIGNED) begin:BLOCK3\n            assign Y = A ** $signed(B);\n        end else begin:BLOCK4\n            assign Y = A ** B;\n        end\n    endgenerate\n    \nendmodule",
  "binary",
  "1",
  "",
};

cell_help["$logic_not"] = {
  "$logic_not",
  "",
  "(A, Y)",
  "simlib.v:1513",
  "A logical inverter. This corresponds to the Verilog unary prefix '!' operator.",
  "module \\$logic_not (A, Y);\n    \n    parameter A_SIGNED = 0;\n    parameter A_WIDTH = 0;\n    parameter Y_WIDTH = 0;\n    \n    input [A_WIDTH-1:0] A;\n    output [Y_WIDTH-1:0] Y;\n    \n    generate\n        if (A_SIGNED) begin:BLOCK1\n            assign Y = !$signed(A);\n        end else begin:BLOCK2\n            assign Y = !A;\n        end\n    endgenerate\n    \nendmodule",
  "unary",
  "1",
  "",
};

cell_help["$logic_and"] = {
  "$logic_and",
  "",
  "(A, B, Y)",
  "simlib.v:1541",
  "A logical AND. This corresponds to the Verilog '&&' operator.",
  "module \\$logic_and (A, B, Y);\n    \n    parameter A_SIGNED = 0;\n    parameter B_SIGNED = 0;\n    parameter A_WIDTH = 0;\n    parameter B_WIDTH = 0;\n    parameter Y_WIDTH = 0;\n    \n    input [A_WIDTH-1:0] A;\n    input [B_WIDTH-1:0] B;\n    output [Y_WIDTH-1:0] Y;\n    \n    generate\n        if (A_SIGNED && B_SIGNED) begin:BLOCK1\n            assign Y = $signed(A) && $signed(B);\n        end else begin:BLOCK2\n            assign Y = A && B;\n        end\n    endgenerate\n    \nendmodule",
  "binary",
  "1",
  "",
};

cell_help["$logic_or"] = {
  "$logic_or",
  "",
  "(A, B, Y)",
  "simlib.v:1572",
  "A logical OR. This corresponds to the Verilog '||' operator.",
  "module \\$logic_or (A, B, Y);\n    \n    parameter A_SIGNED = 0;\n    parameter B_SIGNED = 0;\n    parameter A_WIDTH = 0;\n    parameter B_WIDTH = 0;\n    parameter Y_WIDTH = 0;\n    \n    input [A_WIDTH-1:0] A;\n    input [B_WIDTH-1:0] B;\n    output [Y_WIDTH-1:0] Y;\n    \n    generate\n        if (A_SIGNED && B_SIGNED) begin:BLOCK1\n            assign Y = $signed(A) || $signed(B);\n        end else begin:BLOCK2\n            assign Y = A || B;\n        end\n    endgenerate\n    \nendmodule",
  "binary",
  "1",
  "",
};

cell_help["$slice"] = {
  "$slice",
  "",
  "(A, Y)",
  "simlib.v:1596",
  "",
  "module \\$slice (A, Y);\n    \n    parameter OFFSET = 0;\n    parameter A_WIDTH = 0;\n    parameter Y_WIDTH = 0;\n    \n    input [A_WIDTH-1:0] A;\n    output [Y_WIDTH-1:0] Y;\n    \n    assign Y = A >> OFFSET;\n    \nendmodule",
  "wire",
  "1",
  "",
};

cell_help["$concat"] = {
  "$concat",
  "",
  "(A, B, Y)",
  "simlib.v:1617",
  "Concatenation of inputs into a single output ( Y = {B, A} ).",
  "module \\$concat (A, B, Y);\n    \n    parameter A_WIDTH = 0;\n    parameter B_WIDTH = 0;\n    \n    input [A_WIDTH-1:0] A;\n    input [B_WIDTH-1:0] B;\n    output [A_WIDTH+B_WIDTH-1:0] Y;\n    \n    assign Y = {B, A};\n    \nendmodule",
  "wire",
  "1",
  "",
};

cell_help["$mux"] = {
  "$mux",
  "",
  "(A, B, S, Y)",
  "simlib.v:1639",
  "Multiplexer i.e selecting between two inputs based on select signal.",
  "module \\$mux (A, B, S, Y);\n    \n    parameter WIDTH = 0;\n    \n    input [WIDTH-1:0] A, B;\n    input S;\n    output [WIDTH-1:0] Y;\n    \n    assign Y = S ? B : A;\n    \nendmodule",
  "mux",
  "1",
  "",
};

cell_help["$bmux"] = {
  "$bmux",
  "Binary-encoded multiplexer",
  "(A, S, Y)",
  "simlib.v:1658",
  "Selects between 'slices' of A where each value of S corresponds to a unique\nslice.",
  "module \\$bmux (A, S, Y);\n    \n    parameter WIDTH = 0;\n    parameter S_WIDTH = 0;\n    \n    input [(WIDTH << S_WIDTH)-1:0] A;\n    input [S_WIDTH-1:0] S;\n    output [WIDTH-1:0] Y;\n    \n    wire [WIDTH-1:0] bm0_out, bm1_out;\n    \n    generate\n        if (S_WIDTH > 1) begin:muxlogic\n            \\$bmux #(.WIDTH(WIDTH), .S_WIDTH(S_WIDTH-1)) bm0 (.A(A[(WIDTH << (S_WIDTH - 1))-1:0]), .S(S[S_WIDTH-2:0]), .Y(bm0_out));\n            \\$bmux #(.WIDTH(WIDTH), .S_WIDTH(S_WIDTH-1)) bm1 (.A(A[(WIDTH << S_WIDTH)-1:WIDTH << (S_WIDTH - 1)]), .S(S[S_WIDTH-2:0]), .Y(bm1_out));\n            assign Y = S[S_WIDTH-1] ? bm1_out : bm0_out;\n        end else if (S_WIDTH == 1) begin:simple\n            assign Y = S ? A[2*WIDTH-1:WIDTH] : A[WIDTH-1:0];\n        end else begin:passthru\n            assign Y = A;\n        end\n    endgenerate\n    \nendmodule",
  "mux",
  "2",
  "",
};

cell_help["$pmux"] = {
  "$pmux",
  "Priority-encoded multiplexer",
  "(A, B, S, Y)",
  "simlib.v:1691",
  "Selects between 'slices' of B where each slice corresponds to a single bit\nof S. Outputs A when all bits of S are low.",
  "module \\$pmux (A, B, S, Y);\n    \n    parameter WIDTH = 0;\n    parameter S_WIDTH = 0;\n    \n    input [WIDTH-1:0] A;\n    input [WIDTH*S_WIDTH-1:0] B;\n    input [S_WIDTH-1:0] S;\n    output reg [WIDTH-1:0] Y;\n    \n    integer i;\n    reg found_active_sel_bit;\n    \n    always @* begin\n        Y = A;\n        found_active_sel_bit = 0;\n        for (i = 0; i < S_WIDTH; i = i+1)\n            case (S[i])\n                1'b1: begin\n                    Y = found_active_sel_bit ? 'bx : B >> (WIDTH*i);\n                    found_active_sel_bit = 1;\n                end\n                1'b0: ;\n                1'bx: begin\n                    Y = 'bx;\n                    found_active_sel_bit = 'bx;\n                end\n            endcase\n    end\n    \nendmodule",
  "mux",
  "2",
  "x-output",
};

cell_help["$demux"] = {
  "$demux",
  "",
  "(A, S, Y)",
  "simlib.v:1733",
  "Demultiplexer i.e routing single input to several outputs based on select signal.\nUnselected outputs are driven to zero.",
  "module \\$demux (A, S, Y);\n    \n    parameter WIDTH = 1;\n    parameter S_WIDTH = 1;\n    \n    input [WIDTH-1:0] A;\n    input [S_WIDTH-1:0] S;\n    output [(WIDTH << S_WIDTH)-1:0] Y;\n    \n    genvar i;\n    generate\n        for (i = 0; i < (1 << S_WIDTH); i = i + 1) begin:slices\n            assign Y[i*WIDTH+:WIDTH] = (S == i) ? A : 0;\n        end\n    endgenerate\n    \nendmodule",
  "mux",
  "1",
  "",
};

cell_help["$lut"] = {
  "$lut",
  "",
  "(A, Y)",
  "simlib.v:1755",
  "",
  "module \\$lut (A, Y);\n    \n    parameter WIDTH = 0;\n    parameter LUT = 0;\n    \n    input [WIDTH-1:0] A;\n    output Y;\n    \n    \\$bmux #(.WIDTH(1), .S_WIDTH(WIDTH)) mux(.A(LUT[(1<<WIDTH)-1:0]), .S(A), .Y(Y));\n    \nendmodule",
  "logic",
  "1",
  "",
};

cell_help["$sop"] = {
  "$sop",
  "",
  "(A, Y)",
  "simlib.v:1771",
  "",
  "module \\$sop (A, Y);\n    \n    parameter WIDTH = 0;\n    parameter DEPTH = 0;\n    parameter TABLE = 0;\n    \n    input [WIDTH-1:0] A;\n    output reg Y;\n    \n    integer i, j;\n    reg match;\n    \n    always @* begin\n        Y = 0;\n        for (i = 0; i < DEPTH; i=i+1) begin\n            match = 1;\n            for (j = 0; j < WIDTH; j=j+1) begin\n                if (TABLE[2*WIDTH*i + 2*j + 0] && A[j]) match = 0;\n                if (TABLE[2*WIDTH*i + 2*j + 1] && !A[j]) match = 0;\n            end\n            if (match) Y = 1;\n        end\n    end\n    \nendmodule",
  "logic",
  "1",
  "",
};

cell_help["$tribuf"] = {
  "$tribuf",
  "",
  "(A, EN, Y)",
  "simlib.v:1808",
  "A tri-state buffer.\nThis buffer conditionally drives the output with the value of the input\nbased on the enable signal.",
  "module \\$tribuf (A, EN, Y);\n    \n    parameter WIDTH = 0;\n    \n    input [WIDTH-1:0] A;\n    input EN;\n    output [WIDTH-1:0] Y;\n    \n    assign Y = EN ? A : 'bz;\n    \nendmodule",
  "mux",
  "1",
  "",
};

cell_help["$specify2"] = {
  "$specify2",
  "",
  "(EN, SRC, DST)",
  "simlib.v:1823",
  "",
  "module \\$specify2 (EN, SRC, DST);\n    \n    parameter FULL = 0;\n    parameter SRC_WIDTH = 1;\n    parameter DST_WIDTH = 1;\n    \n    parameter SRC_DST_PEN = 0;\n    parameter SRC_DST_POL = 0;\n    \n    parameter T_RISE_MIN = 0;\n    parameter T_RISE_TYP = 0;\n    parameter T_RISE_MAX = 0;\n    \n    parameter T_FALL_MIN = 0;\n    parameter T_FALL_TYP = 0;\n    parameter T_FALL_MAX = 0;\n    \n    input EN;\n    input [SRC_WIDTH-1:0] SRC;\n    input [DST_WIDTH-1:0] DST;\n    \n    localparam SD = SRC_DST_PEN ? (SRC_DST_POL ? 1 : 2) : 0;\n    \n    `ifdef SIMLIB_SPECIFY\n    specify\n        if (EN && SD==0 && !FULL) (SRC  => DST) = (T_RISE_MIN:T_RISE_TYP:T_RISE_MAX, T_FALL_MIN:T_FALL_TYP:T_FALL_MAX);\n        if (EN && SD==0 &&  FULL) (SRC  *> DST) = (T_RISE_MIN:T_RISE_TYP:T_RISE_MAX, T_FALL_MIN:T_FALL_TYP:T_FALL_MAX);\n        if (EN && SD==1 && !FULL) (SRC +=> DST) = (T_RISE_MIN:T_RISE_TYP:T_RISE_MAX, T_FALL_MIN:T_FALL_TYP:T_FALL_MAX);\n        if (EN && SD==1 &&  FULL) (SRC +*> DST) = (T_RISE_MIN:T_RISE_TYP:T_RISE_MAX, T_FALL_MIN:T_FALL_TYP:T_FALL_MAX);\n        if (EN && SD==2 && !FULL) (SRC -=> DST) = (T_RISE_MIN:T_RISE_TYP:T_RISE_MAX, T_FALL_MIN:T_FALL_TYP:T_FALL_MAX);\n        if (EN && SD==2 &&  FULL) (SRC -*> DST) = (T_RISE_MIN:T_RISE_TYP:T_RISE_MAX, T_FALL_MIN:T_FALL_TYP:T_FALL_MAX);\n    endspecify\n    `endif\n    \nendmodule",
  "spec",
  "1",
  "",
};

cell_help["$specify3"] = {
  "$specify3",
  "",
  "(EN, SRC, DST, DAT)",
  "simlib.v:1862",
  "",
  "module \\$specify3 (EN, SRC, DST, DAT);\n    \n    parameter FULL = 0;\n    parameter SRC_WIDTH = 1;\n    parameter DST_WIDTH = 1;\n    \n    parameter EDGE_EN = 0;\n    parameter EDGE_POL = 0;\n    \n    parameter SRC_DST_PEN = 0;\n    parameter SRC_DST_POL = 0;\n    \n    parameter DAT_DST_PEN = 0;\n    parameter DAT_DST_POL = 0;\n    \n    parameter T_RISE_MIN = 0;\n    parameter T_RISE_TYP = 0;\n    parameter T_RISE_MAX = 0;\n    \n    parameter T_FALL_MIN = 0;\n    parameter T_FALL_TYP = 0;\n    parameter T_FALL_MAX = 0;\n    \n    input EN;\n    input [SRC_WIDTH-1:0] SRC;\n    input [DST_WIDTH-1:0] DST, DAT;\n    \n    localparam ED = EDGE_EN     ? (EDGE_POL    ? 1 : 2) : 0;\n    localparam SD = SRC_DST_PEN ? (SRC_DST_POL ? 1 : 2) : 0;\n    localparam DD = DAT_DST_PEN ? (DAT_DST_POL ? 1 : 2) : 0;\n    \n    `ifdef SIMLIB_SPECIFY\n    specify\n        // DD=0\n    \n        if (EN && DD==0 && SD==0 && ED==0 && !FULL) (        SRC  => (DST  : DAT)) = (T_RISE_MIN:T_RISE_TYP:T_RISE_MAX, T_FALL_MIN:T_FALL_TYP:T_FALL_MAX);\n        if (EN && DD==0 && SD==0 && ED==0 &&  FULL) (        SRC  *> (DST  : DAT)) = (T_RISE_MIN:T_RISE_TYP:T_RISE_MAX, T_FALL_MIN:T_FALL_TYP:T_FALL_MAX);\n        if (EN && DD==0 && SD==0 && ED==1 && !FULL) (posedge SRC  => (DST  : DAT)) = (T_RISE_MIN:T_RISE_TYP:T_RISE_MAX, T_FALL_MIN:T_FALL_TYP:T_FALL_MAX);\n        if (EN && DD==0 && SD==0 && ED==1 &&  FULL) (posedge SRC  *> (DST  : DAT)) = (T_RISE_MIN:T_RISE_TYP:T_RISE_MAX, T_FALL_MIN:T_FALL_TYP:T_FALL_MAX);\n        if (EN && DD==0 && SD==0 && ED==2 && !FULL) (negedge SRC  => (DST  : DAT)) = (T_RISE_MIN:T_RISE_TYP:T_RISE_MAX, T_FALL_MIN:T_FALL_TYP:T_FALL_MAX);\n        if (EN && DD==0 && SD==0 && ED==2 &&  FULL) (negedge SRC  *> (DST  : DAT)) = (T_RISE_MIN:T_RISE_TYP:T_RISE_MAX, T_FALL_MIN:T_FALL_TYP:T_FALL_MAX);\n    \n        if (EN && DD==0 && SD==1 && ED==0 && !FULL) (        SRC +=> (DST  : DAT)) = (T_RISE_MIN:T_RISE_TYP:T_RISE_MAX, T_FALL_MIN:T_FALL_TYP:T_FALL_MAX);\n        if (EN && DD==0 && SD==1 && ED==0 &&  FULL) (        SRC +*> (DST  : DAT)) = (T_RISE_MIN:T_RISE_TYP:T_RISE_MAX, T_FALL_MIN:T_FALL_TYP:T_FALL_MAX);\n        if (EN && DD==0 && SD==1 && ED==1 && !FULL) (posedge SRC +=> (DST  : DAT)) = (T_RISE_MIN:T_RISE_TYP:T_RISE_MAX, T_FALL_MIN:T_FALL_TYP:T_FALL_MAX);\n        if (EN && DD==0 && SD==1 && ED==1 &&  FULL) (posedge SRC +*> (DST  : DAT)) = (T_RISE_MIN:T_RISE_TYP:T_RISE_MAX, T_FALL_MIN:T_FALL_TYP:T_FALL_MAX);\n        if (EN && DD==0 && SD==1 && ED==2 && !FULL) (negedge SRC +=> (DST  : DAT)) = (T_RISE_MIN:T_RISE_TYP:T_RISE_MAX, T_FALL_MIN:T_FALL_TYP:T_FALL_MAX);\n        if (EN && DD==0 && SD==1 && ED==2 &&  FULL) (negedge SRC +*> (DST  : DAT)) = (T_RISE_MIN:T_RISE_TYP:T_RISE_MAX, T_FALL_MIN:T_FALL_TYP:T_FALL_MAX);\n    \n        if (EN && DD==0 && SD==2 && ED==0 && !FULL) (        SRC -=> (DST  : DAT)) = (T_RISE_MIN:T_RISE_TYP:T_RISE_MAX, T_FALL_MIN:T_FALL_TYP:T_FALL_MAX);\n        if (EN && DD==0 && SD==2 && ED==0 &&  FULL) (        SRC -*> (DST  : DAT)) = (T_RISE_MIN:T_RISE_TYP:T_RISE_MAX, T_FALL_MIN:T_FALL_TYP:T_FALL_MAX);\n        if (EN && DD==0 && SD==2 && ED==1 && !FULL) (posedge SRC -=> (DST  : DAT)) = (T_RISE_MIN:T_RISE_TYP:T_RISE_MAX, T_FALL_MIN:T_FALL_TYP:T_FALL_MAX);\n        if (EN && DD==0 && SD==2 && ED==1 &&  FULL) (posedge SRC -*> (DST  : DAT)) = (T_RISE_MIN:T_RISE_TYP:T_RISE_MAX, T_FALL_MIN:T_FALL_TYP:T_FALL_MAX);\n        if (EN && DD==0 && SD==2 && ED==2 && !FULL) (negedge SRC -=> (DST  : DAT)) = (T_RISE_MIN:T_RISE_TYP:T_RISE_MAX, T_FALL_MIN:T_FALL_TYP:T_FALL_MAX);\n        if (EN && DD==0 && SD==2 && ED==2 &&  FULL) (negedge SRC -*> (DST  : DAT)) = (T_RISE_MIN:T_RISE_TYP:T_RISE_MAX, T_FALL_MIN:T_FALL_TYP:T_FALL_MAX);\n    \n        // DD=1\n    \n        if (EN && DD==1 && SD==0 && ED==0 && !FULL) (        SRC  => (DST +: DAT)) = (T_RISE_MIN:T_RISE_TYP:T_RISE_MAX, T_FALL_MIN:T_FALL_TYP:T_FALL_MAX);\n        if (EN && DD==1 && SD==0 && ED==0 &&  FULL) (        SRC  *> (DST +: DAT)) = (T_RISE_MIN:T_RISE_TYP:T_RISE_MAX, T_FALL_MIN:T_FALL_TYP:T_FALL_MAX);\n        if (EN && DD==1 && SD==0 && ED==1 && !FULL) (posedge SRC  => (DST +: DAT)) = (T_RISE_MIN:T_RISE_TYP:T_RISE_MAX, T_FALL_MIN:T_FALL_TYP:T_FALL_MAX);\n        if (EN && DD==1 && SD==0 && ED==1 &&  FULL) (posedge SRC  *> (DST +: DAT)) = (T_RISE_MIN:T_RISE_TYP:T_RISE_MAX, T_FALL_MIN:T_FALL_TYP:T_FALL_MAX);\n        if (EN && DD==1 && SD==0 && ED==2 && !FULL) (negedge SRC  => (DST +: DAT)) = (T_RISE_MIN:T_RISE_TYP:T_RISE_MAX, T_FALL_MIN:T_FALL_TYP:T_FALL_MAX);\n        if (EN && DD==1 && SD==0 && ED==2 &&  FULL) (negedge SRC  *> (DST +: DAT)) = (T_RISE_MIN:T_RISE_TYP:T_RISE_MAX, T_FALL_MIN:T_FALL_TYP:T_FALL_MAX);\n    \n        if (EN && DD==1 && SD==1 && ED==0 && !FULL) (        SRC +=> (DST +: DAT)) = (T_RISE_MIN:T_RISE_TYP:T_RISE_MAX, T_FALL_MIN:T_FALL_TYP:T_FALL_MAX);\n        if (EN && DD==1 && SD==1 && ED==0 &&  FULL) (        SRC +*> (DST +: DAT)) = (T_RISE_MIN:T_RISE_TYP:T_RISE_MAX, T_FALL_MIN:T_FALL_TYP:T_FALL_MAX);\n        if (EN && DD==1 && SD==1 && ED==1 && !FULL) (posedge SRC +=> (DST +: DAT)) = (T_RISE_MIN:T_RISE_TYP:T_RISE_MAX, T_FALL_MIN:T_FALL_TYP:T_FALL_MAX);\n        if (EN && DD==1 && SD==1 && ED==1 &&  FULL) (posedge SRC +*> (DST +: DAT)) = (T_RISE_MIN:T_RISE_TYP:T_RISE_MAX, T_FALL_MIN:T_FALL_TYP:T_FALL_MAX);\n        if (EN && DD==1 && SD==1 && ED==2 && !FULL) (negedge SRC +=> (DST +: DAT)) = (T_RISE_MIN:T_RISE_TYP:T_RISE_MAX, T_FALL_MIN:T_FALL_TYP:T_FALL_MAX);\n        if (EN && DD==1 && SD==1 && ED==2 &&  FULL) (negedge SRC +*> (DST +: DAT)) = (T_RISE_MIN:T_RISE_TYP:T_RISE_MAX, T_FALL_MIN:T_FALL_TYP:T_FALL_MAX);\n    \n        if (EN && DD==1 && SD==2 && ED==0 && !FULL) (        SRC -=> (DST +: DAT)) = (T_RISE_MIN:T_RISE_TYP:T_RISE_MAX, T_FALL_MIN:T_FALL_TYP:T_FALL_MAX);\n        if (EN && DD==1 && SD==2 && ED==0 &&  FULL) (        SRC -*> (DST +: DAT)) = (T_RISE_MIN:T_RISE_TYP:T_RISE_MAX, T_FALL_MIN:T_FALL_TYP:T_FALL_MAX);\n        if (EN && DD==1 && SD==2 && ED==1 && !FULL) (posedge SRC -=> (DST +: DAT)) = (T_RISE_MIN:T_RISE_TYP:T_RISE_MAX, T_FALL_MIN:T_FALL_TYP:T_FALL_MAX);\n        if (EN && DD==1 && SD==2 && ED==1 &&  FULL) (posedge SRC -*> (DST +: DAT)) = (T_RISE_MIN:T_RISE_TYP:T_RISE_MAX, T_FALL_MIN:T_FALL_TYP:T_FALL_MAX);\n        if (EN && DD==1 && SD==2 && ED==2 && !FULL) (negedge SRC -=> (DST +: DAT)) = (T_RISE_MIN:T_RISE_TYP:T_RISE_MAX, T_FALL_MIN:T_FALL_TYP:T_FALL_MAX);\n        if (EN && DD==1 && SD==2 && ED==2 &&  FULL) (negedge SRC -*> (DST +: DAT)) = (T_RISE_MIN:T_RISE_TYP:T_RISE_MAX, T_FALL_MIN:T_FALL_TYP:T_FALL_MAX);\n    \n        // DD=2\n    \n        if (EN && DD==2 && SD==0 && ED==0 && !FULL) (        SRC  => (DST -: DAT)) = (T_RISE_MIN:T_RISE_TYP:T_RISE_MAX, T_FALL_MIN:T_FALL_TYP:T_FALL_MAX);\n        if (EN && DD==2 && SD==0 && ED==0 &&  FULL) (        SRC  *> (DST -: DAT)) = (T_RISE_MIN:T_RISE_TYP:T_RISE_MAX, T_FALL_MIN:T_FALL_TYP:T_FALL_MAX);\n        if (EN && DD==2 && SD==0 && ED==1 && !FULL) (posedge SRC  => (DST -: DAT)) = (T_RISE_MIN:T_RISE_TYP:T_RISE_MAX, T_FALL_MIN:T_FALL_TYP:T_FALL_MAX);\n        if (EN && DD==2 && SD==0 && ED==1 &&  FULL) (posedge SRC  *> (DST -: DAT)) = (T_RISE_MIN:T_RISE_TYP:T_RISE_MAX, T_FALL_MIN:T_FALL_TYP:T_FALL_MAX);\n        if (EN && DD==2 && SD==0 && ED==2 && !FULL) (negedge SRC  => (DST -: DAT)) = (T_RISE_MIN:T_RISE_TYP:T_RISE_MAX, T_FALL_MIN:T_FALL_TYP:T_FALL_MAX);\n        if (EN && DD==2 && SD==0 && ED==2 &&  FULL) (negedge SRC  *> (DST -: DAT)) = (T_RISE_MIN:T_RISE_TYP:T_RISE_MAX, T_FALL_MIN:T_FALL_TYP:T_FALL_MAX);\n    \n        if (EN && DD==2 && SD==1 && ED==0 && !FULL) (        SRC +=> (DST -: DAT)) = (T_RISE_MIN:T_RISE_TYP:T_RISE_MAX, T_FALL_MIN:T_FALL_TYP:T_FALL_MAX);\n        if (EN && DD==2 && SD==1 && ED==0 &&  FULL) (        SRC +*> (DST -: DAT)) = (T_RISE_MIN:T_RISE_TYP:T_RISE_MAX, T_FALL_MIN:T_FALL_TYP:T_FALL_MAX);\n        if (EN && DD==2 && SD==1 && ED==1 && !FULL) (posedge SRC +=> (DST -: DAT)) = (T_RISE_MIN:T_RISE_TYP:T_RISE_MAX, T_FALL_MIN:T_FALL_TYP:T_FALL_MAX);\n        if (EN && DD==2 && SD==1 && ED==1 &&  FULL) (posedge SRC +*> (DST -: DAT)) = (T_RISE_MIN:T_RISE_TYP:T_RISE_MAX, T_FALL_MIN:T_FALL_TYP:T_FALL_MAX);\n        if (EN && DD==2 && SD==1 && ED==2 && !FULL) (negedge SRC +=> (DST -: DAT)) = (T_RISE_MIN:T_RISE_TYP:T_RISE_MAX, T_FALL_MIN:T_FALL_TYP:T_FALL_MAX);\n        if (EN && DD==2 && SD==1 && ED==2 &&  FULL) (negedge SRC +*> (DST -: DAT)) = (T_RISE_MIN:T_RISE_TYP:T_RISE_MAX, T_FALL_MIN:T_FALL_TYP:T_FALL_MAX);\n    \n        if (EN && DD==2 && SD==2 && ED==0 && !FULL) (        SRC -=> (DST -: DAT)) = (T_RISE_MIN:T_RISE_TYP:T_RISE_MAX, T_FALL_MIN:T_FALL_TYP:T_FALL_MAX);\n        if (EN && DD==2 && SD==2 && ED==0 &&  FULL) (        SRC -*> (DST -: DAT)) = (T_RISE_MIN:T_RISE_TYP:T_RISE_MAX, T_FALL_MIN:T_FALL_TYP:T_FALL_MAX);\n        if (EN && DD==2 && SD==2 && ED==1 && !FULL) (posedge SRC -=> (DST -: DAT)) = (T_RISE_MIN:T_RISE_TYP:T_RISE_MAX, T_FALL_MIN:T_FALL_TYP:T_FALL_MAX);\n        if (EN && DD==2 && SD==2 && ED==1 &&  FULL) (posedge SRC -*> (DST -: DAT)) = (T_RISE_MIN:T_RISE_TYP:T_RISE_MAX, T_FALL_MIN:T_FALL_TYP:T_FALL_MAX);\n        if (EN && DD==2 && SD==2 && ED==2 && !FULL) (negedge SRC -=> (DST -: DAT)) = (T_RISE_MIN:T_RISE_TYP:T_RISE_MAX, T_FALL_MIN:T_FALL_TYP:T_FALL_MAX);\n        if (EN && DD==2 && SD==2 && ED==2 &&  FULL) (negedge SRC -*> (DST -: DAT)) = (T_RISE_MIN:T_RISE_TYP:T_RISE_MAX, T_FALL_MIN:T_FALL_TYP:T_FALL_MAX);\n    endspecify\n    `endif\n    \nendmodule",
  "spec",
  "1",
  "",
};

cell_help["$specrule"] = {
  "$specrule",
  "",
  "(EN_SRC, EN_DST, SRC, DST)",
  "simlib.v:1971",
  "",
  "module \\$specrule (EN_SRC, EN_DST, SRC, DST);\n    \n    parameter TYPE = \"\";\n    parameter T_LIMIT = 0;\n    parameter T_LIMIT2 = 0;\n    \n    parameter SRC_WIDTH = 1;\n    parameter DST_WIDTH = 1;\n    \n    parameter SRC_PEN = 0;\n    parameter SRC_POL = 0;\n    \n    parameter DST_PEN = 0;\n    parameter DST_POL = 0;\n    \n    input EN_SRC, EN_DST;\n    input [SRC_WIDTH-1:0] SRC;\n    input [DST_WIDTH-1:0] DST;\n    \n    `ifdef SIMLIB_SPECIFY\n    specify\n        // TBD\n    endspecify\n    `endif\n    \nendmodule",
  "spec",
  "1",
  "",
};

cell_help["$bweqx"] = {
  "$bweqx",
  "Bit-wise case equality",
  "(A, B, Y)",
  "simlib.v:2005",
  "A bit-wise version of `$eqx`.",
  "module \\$bweqx (A, B, Y);\n    \n    parameter WIDTH = 0;\n    \n    input [WIDTH-1:0] A, B;\n    output [WIDTH-1:0] Y;\n    \n    genvar i;\n    generate\n        for (i = 0; i < WIDTH; i = i + 1) begin:slices\n            assign Y[i] = A[i] === B[i];\n        end\n    endgenerate\n    \nendmodule",
  "binary",
  "2",
  "x-aware",
};

cell_help["$bwmux"] = {
  "$bwmux",
  "Bit-wise multiplexer",
  "(A, B, S, Y)",
  "simlib.v:2027",
  "Equivalent to a series of 1-bit wide `$mux` cells.",
  "module \\$bwmux (A, B, S, Y);\n    \n    parameter WIDTH = 0;\n    \n    input [WIDTH-1:0] A, B;\n    input [WIDTH-1:0] S;\n    output [WIDTH-1:0] Y;\n    \n    genvar i;\n    generate\n        for (i = 0; i < WIDTH; i = i + 1) begin:slices\n            assign Y[i] = S[i] ? B[i] : A[i];\n        end\n    endgenerate\n    \nendmodule",
  "mux",
  "2",
  "",
};

cell_help["$assert"] = {
  "$assert",
  "",
  "(A, EN)",
  "simlib.v:2047",
  "",
  "module \\$assert (A, EN);\n    \n    input A, EN;\n    \n    `ifndef SIMLIB_NOCHECKS\n    always @* begin\n        if (A !== 1'b1 && EN === 1'b1) begin\n            $display(\"Assertion %m failed!\");\n            $stop;\n        end\n    end\n    `endif\n    \nendmodule",
  "formal",
  "1",
  "",
};

cell_help["$assume"] = {
  "$assume",
  "",
  "(A, EN)",
  "simlib.v:2065",
  "",
  "module \\$assume (A, EN);\n    \n    input A, EN;\n    \n    `ifndef SIMLIB_NOCHECKS\n    always @* begin\n        if (A !== 1'b1 && EN === 1'b1) begin\n            $display(\"Assumption %m failed!\");\n            $stop;\n        end\n    end\n    `endif\n    \nendmodule",
  "formal",
  "1",
  "",
};

cell_help["$live"] = {
  "$live",
  "",
  "(A, EN)",
  "simlib.v:2083",
  "",
  "module \\$live (A, EN);\n    \n    input A, EN;\n    \nendmodule",
  "formal",
  "1",
  "",
};

cell_help["$fair"] = {
  "$fair",
  "",
  "(A, EN)",
  "simlib.v:2092",
  "",
  "module \\$fair (A, EN);\n    \n    input A, EN;\n    \nendmodule",
  "formal",
  "1",
  "",
};

cell_help["$cover"] = {
  "$cover",
  "",
  "(A, EN)",
  "simlib.v:2101",
  "",
  "module \\$cover (A, EN);\n    \n    input A, EN;\n    \nendmodule",
  "formal",
  "1",
  "",
};

cell_help["$initstate"] = {
  "$initstate",
  "",
  "(Y)",
  "simlib.v:2110",
  "",
  "module \\$initstate (Y);\n    \n    output reg Y = 1;\n    reg [3:0] cnt = 1;\n    reg trig = 0;\n    \n    initial trig <= 1;\n    \n    always @(cnt, trig) begin\n        Y <= |cnt;\n        cnt <= cnt + |cnt;\n    end\n    \nendmodule",
  "formal",
  "1",
  "",
};

cell_help["$anyconst"] = {
  "$anyconst",
  "",
  "(Y)",
  "simlib.v:2128",
  "",
  "module \\$anyconst (Y);\n    \n    parameter WIDTH = 0;\n    \n    output [WIDTH-1:0] Y;\n    \n    assign Y = 'bx;\n    \nendmodule",
  "formal",
  "1",
  "",
};

cell_help["$anyseq"] = {
  "$anyseq",
  "",
  "(Y)",
  "simlib.v:2141",
  "",
  "module \\$anyseq (Y);\n    \n    parameter WIDTH = 0;\n    \n    output [WIDTH-1:0] Y;\n    \n    assign Y = 'bx;\n    \nendmodule",
  "formal",
  "1",
  "",
};

cell_help["$anyinit"] = {
  "$anyinit",
  "",
  "(D, Q)",
  "simlib.v:2157",
  "",
  "module \\$anyinit (D, Q);\n    \n    parameter WIDTH = 0;\n    \n    input [WIDTH-1:0] D;\n    output reg [WIDTH-1:0] Q;\n    \n    initial Q <= 'bx;\n    \n    always @(`SIMLIB_GLOBAL_CLOCK) begin\n        Q <= D;\n    end\n    \nendmodule",
  "formal",
  "1",
  "",
};

cell_help["$allconst"] = {
  "$allconst",
  "",
  "(Y)",
  "simlib.v:2175",
  "",
  "module \\$allconst (Y);\n    \n    parameter WIDTH = 0;\n    \n    output [WIDTH-1:0] Y;\n    \n    assign Y = 'bx;\n    \nendmodule",
  "formal",
  "1",
  "",
};

cell_help["$allseq"] = {
  "$allseq",
  "",
  "(Y)",
  "simlib.v:2188",
  "",
  "module \\$allseq (Y);\n    \n    parameter WIDTH = 0;\n    \n    output [WIDTH-1:0] Y;\n    \n    assign Y = 'bx;\n    \nendmodule",
  "formal",
  "1",
  "",
};

cell_help["$equiv"] = {
  "$equiv",
  "",
  "(A, B, Y)",
  "simlib.v:2201",
  "",
  "module \\$equiv (A, B, Y);\n    \n    input A, B;\n    output Y;\n    \n    assign Y = (A !== 1'bx && A !== B) ? 1'bx : A;\n    \n    `ifndef SIMLIB_NOCHECKS\n    always @* begin\n        if (A !== 1'bx && A !== B) begin\n            $display(\"Equivalence failed!\");\n            $stop;\n        end\n    end\n    `endif\n    \nendmodule",
  "formal",
  "1",
  "",
};

cell_help["$print"] = {
  "$print",
  "",
  "(EN, TRG, ARGS)",
  "simlib.v:2222",
  "",
  "module \\$print (EN, TRG, ARGS);\n    \n    parameter PRIORITY = 0;\n    \n    parameter FORMAT = \"\";\n    parameter signed ARGS_WIDTH = 0;\n    \n    parameter TRG_ENABLE = 1;\n    parameter signed TRG_WIDTH = 0;\n    parameter TRG_POLARITY = 0;\n    \n    input EN;\n    input [TRG_WIDTH-1:0] TRG;\n    input [ARGS_WIDTH-1:0] ARGS;\n    \nendmodule",
  "debug",
  "1",
  "",
};

cell_help["$check"] = {
  "$check",
  "",
  "(A, EN, TRG, ARGS)",
  "simlib.v:2242",
  "",
  "module \\$check (A, EN, TRG, ARGS);\n    \n    parameter FLAVOR = \"\";\n    parameter PRIORITY = 0;\n    \n    parameter FORMAT = \"\";\n    parameter ARGS_WIDTH = 0;\n    \n    parameter TRG_ENABLE = 1;\n    parameter TRG_WIDTH = 0;\n    parameter TRG_POLARITY = 0;\n    \n    input A;\n    input EN;\n    input [TRG_WIDTH-1:0] TRG;\n    input [ARGS_WIDTH-1:0] ARGS;\n    \nendmodule",
  "debug",
  "1",
  "",
};

cell_help["$sr"] = {
  "$sr",
  "",
  "(SET, CLR, Q)",
  "simlib.v:2265",
  "",
  "module \\$sr (SET, CLR, Q);\n    \n    parameter WIDTH = 0;\n    parameter SET_POLARITY = 1'b1;\n    parameter CLR_POLARITY = 1'b1;\n    \n    input [WIDTH-1:0] SET, CLR;\n    output reg [WIDTH-1:0] Q;\n    \n    wire [WIDTH-1:0] pos_set = SET_POLARITY ? SET : ~SET;\n    wire [WIDTH-1:0] pos_clr = CLR_POLARITY ? CLR : ~CLR;\n    \n    genvar i;\n    generate\n        for (i = 0; i < WIDTH; i = i+1) begin:bitslices\n            always @*\n                if (pos_clr[i])\n                    Q[i] <= 0;\n                else if (pos_set[i])\n                    Q[i] <= 1;\n        end\n    endgenerate\n    \nendmodule",
  "reg",
  "1",
  "",
};

cell_help["$ff"] = {
  "$ff",
  "",
  "(D, Q)",
  "simlib.v:2298",
  "",
  "module \\$ff (D, Q);\n    \n    parameter WIDTH = 0;\n    \n    input [WIDTH-1:0] D;\n    output reg [WIDTH-1:0] Q;\n    \n    always @(`SIMLIB_GLOBAL_CLOCK) begin\n        Q <= D;\n    end\n    \nendmodule",
  "formal",
  "1",
  "",
};

cell_help["$dff"] = {
  "$dff",
  "",
  "(CLK, D, Q)",
  "simlib.v:2315",
  "",
  "module \\$dff (CLK, D, Q);\n    \n    parameter WIDTH = 0;\n    parameter CLK_POLARITY = 1'b1;\n    \n    input CLK;\n    input [WIDTH-1:0] D;\n    output reg [WIDTH-1:0] Q;\n    wire pos_clk = CLK == CLK_POLARITY;\n    \n    always @(posedge pos_clk) begin\n        Q <= D;\n    end\n    \nendmodule",
  "reg",
  "1",
  "",
};

cell_help["$dffe"] = {
  "$dffe",
  "",
  "(CLK, EN, D, Q)",
  "simlib.v:2334",
  "",
  "module \\$dffe (CLK, EN, D, Q);\n    \n    parameter WIDTH = 0;\n    parameter CLK_POLARITY = 1'b1;\n    parameter EN_POLARITY = 1'b1;\n    \n    input CLK, EN;\n    input [WIDTH-1:0] D;\n    output reg [WIDTH-1:0] Q;\n    wire pos_clk = CLK == CLK_POLARITY;\n    \n    always @(posedge pos_clk) begin\n        if (EN == EN_POLARITY) Q <= D;\n    end\n    \nendmodule",
  "reg",
  "1",
  "",
};

cell_help["$dffsr"] = {
  "$dffsr",
  "",
  "(CLK, SET, CLR, D, Q)",
  "simlib.v:2355",
  "",
  "module \\$dffsr (CLK, SET, CLR, D, Q);\n    \n    parameter WIDTH = 0;\n    parameter CLK_POLARITY = 1'b1;\n    parameter SET_POLARITY = 1'b1;\n    parameter CLR_POLARITY = 1'b1;\n    \n    input CLK;\n    input [WIDTH-1:0] SET, CLR, D;\n    output reg [WIDTH-1:0] Q;\n    \n    wire pos_clk = CLK == CLK_POLARITY;\n    wire [WIDTH-1:0] pos_set = SET_POLARITY ? SET : ~SET;\n    wire [WIDTH-1:0] pos_clr = CLR_POLARITY ? CLR : ~CLR;\n    \n    genvar i;\n    generate\n        for (i = 0; i < WIDTH; i = i+1) begin:bitslices\n            always @(posedge pos_set[i], posedge pos_clr[i], posedge pos_clk)\n                if (pos_clr[i])\n                    Q[i] <= 0;\n                else if (pos_set[i])\n                    Q[i] <= 1;\n                else\n                    Q[i] <= D[i];\n        end\n    endgenerate\n    \nendmodule",
  "reg",
  "1",
  "",
};

cell_help["$dffsre"] = {
  "$dffsre",
  "",
  "(CLK, SET, CLR, EN, D, Q)",
  "simlib.v:2388",
  "",
  "module \\$dffsre (CLK, SET, CLR, EN, D, Q);\n    \n    parameter WIDTH = 0;\n    parameter CLK_POLARITY = 1'b1;\n    parameter SET_POLARITY = 1'b1;\n    parameter CLR_POLARITY = 1'b1;\n    parameter EN_POLARITY = 1'b1;\n    \n    input CLK, EN;\n    input [WIDTH-1:0] SET, CLR, D;\n    output reg [WIDTH-1:0] Q;\n    \n    wire pos_clk = CLK == CLK_POLARITY;\n    wire [WIDTH-1:0] pos_set = SET_POLARITY ? SET : ~SET;\n    wire [WIDTH-1:0] pos_clr = CLR_POLARITY ? CLR : ~CLR;\n    \n    genvar i;\n    generate\n        for (i = 0; i < WIDTH; i = i+1) begin:bitslices\n            always @(posedge pos_set[i], posedge pos_clr[i], posedge pos_clk)\n                if (pos_clr[i])\n                    Q[i] <= 0;\n                else if (pos_set[i])\n                    Q[i] <= 1;\n                else if (EN == EN_POLARITY)\n                    Q[i] <= D[i];\n        end\n    endgenerate\n    \nendmodule",
  "reg",
  "1",
  "",
};

cell_help["$adff"] = {
  "$adff",
  "",
  "(CLK, ARST, D, Q)",
  "simlib.v:2423",
  "",
  "module \\$adff (CLK, ARST, D, Q);\n    \n    parameter WIDTH = 0;\n    parameter CLK_POLARITY = 1'b1;\n    parameter ARST_POLARITY = 1'b1;\n    parameter ARST_VALUE = 0;\n    \n    input CLK, ARST;\n    input [WIDTH-1:0] D;\n    output reg [WIDTH-1:0] Q;\n    wire pos_clk = CLK == CLK_POLARITY;\n    wire pos_arst = ARST == ARST_POLARITY;\n    \n    always @(posedge pos_clk, posedge pos_arst) begin\n        if (pos_arst)\n            Q <= ARST_VALUE;\n        else\n            Q <= D;\n    end\n    \nendmodule",
  "reg",
  "1",
  "",
};

cell_help["$aldff"] = {
  "$aldff",
  "",
  "(CLK, ALOAD, AD, D, Q)",
  "simlib.v:2448",
  "",
  "module \\$aldff (CLK, ALOAD, AD, D, Q);\n    \n    parameter WIDTH = 0;\n    parameter CLK_POLARITY = 1'b1;\n    parameter ALOAD_POLARITY = 1'b1;\n    \n    input CLK, ALOAD;\n    input [WIDTH-1:0] AD;\n    input [WIDTH-1:0] D;\n    output reg [WIDTH-1:0] Q;\n    wire pos_clk = CLK == CLK_POLARITY;\n    wire pos_aload = ALOAD == ALOAD_POLARITY;\n    \n    always @(posedge pos_clk, posedge pos_aload) begin\n        if (pos_aload)\n            Q <= AD;\n        else\n            Q <= D;\n    end\n    \nendmodule",
  "reg",
  "1",
  "",
};

cell_help["$sdff"] = {
  "$sdff",
  "",
  "(CLK, SRST, D, Q)",
  "simlib.v:2473",
  "",
  "module \\$sdff (CLK, SRST, D, Q);\n    \n    parameter WIDTH = 0;\n    parameter CLK_POLARITY = 1'b1;\n    parameter SRST_POLARITY = 1'b1;\n    parameter SRST_VALUE = 0;\n    \n    input CLK, SRST;\n    input [WIDTH-1:0] D;\n    output reg [WIDTH-1:0] Q;\n    wire pos_clk = CLK == CLK_POLARITY;\n    wire pos_srst = SRST == SRST_POLARITY;\n    \n    always @(posedge pos_clk) begin\n        if (pos_srst)\n            Q <= SRST_VALUE;\n        else\n            Q <= D;\n    end\n    \nendmodule",
  "reg",
  "1",
  "",
};

cell_help["$adffe"] = {
  "$adffe",
  "",
  "(CLK, ARST, EN, D, Q)",
  "simlib.v:2498",
  "",
  "module \\$adffe (CLK, ARST, EN, D, Q);\n    \n    parameter WIDTH = 0;\n    parameter CLK_POLARITY = 1'b1;\n    parameter EN_POLARITY = 1'b1;\n    parameter ARST_POLARITY = 1'b1;\n    parameter ARST_VALUE = 0;\n    \n    input CLK, ARST, EN;\n    input [WIDTH-1:0] D;\n    output reg [WIDTH-1:0] Q;\n    wire pos_clk = CLK == CLK_POLARITY;\n    wire pos_arst = ARST == ARST_POLARITY;\n    \n    always @(posedge pos_clk, posedge pos_arst) begin\n        if (pos_arst)\n            Q <= ARST_VALUE;\n        else if (EN == EN_POLARITY)\n            Q <= D;\n    end\n    \nendmodule",
  "reg",
  "1",
  "",
};

cell_help["$aldffe"] = {
  "$aldffe",
  "",
  "(CLK, ALOAD, AD, EN, D, Q)",
  "simlib.v:2524",
  "",
  "module \\$aldffe (CLK, ALOAD, AD, EN, D, Q);\n    \n    parameter WIDTH = 0;\n    parameter CLK_POLARITY = 1'b1;\n    parameter EN_POLARITY = 1'b1;\n    parameter ALOAD_POLARITY = 1'b1;\n    \n    input CLK, ALOAD, EN;\n    input [WIDTH-1:0] D;\n    input [WIDTH-1:0] AD;\n    output reg [WIDTH-1:0] Q;\n    wire pos_clk = CLK == CLK_POLARITY;\n    wire pos_aload = ALOAD == ALOAD_POLARITY;\n    \n    always @(posedge pos_clk, posedge pos_aload) begin\n        if (pos_aload)\n            Q <= AD;\n        else if (EN == EN_POLARITY)\n            Q <= D;\n    end\n    \nendmodule",
  "reg",
  "1",
  "",
};

cell_help["$sdffe"] = {
  "$sdffe",
  "",
  "(CLK, SRST, EN, D, Q)",
  "simlib.v:2550",
  "",
  "module \\$sdffe (CLK, SRST, EN, D, Q);\n    \n    parameter WIDTH = 0;\n    parameter CLK_POLARITY = 1'b1;\n    parameter EN_POLARITY = 1'b1;\n    parameter SRST_POLARITY = 1'b1;\n    parameter SRST_VALUE = 0;\n    \n    input CLK, SRST, EN;\n    input [WIDTH-1:0] D;\n    output reg [WIDTH-1:0] Q;\n    wire pos_clk = CLK == CLK_POLARITY;\n    wire pos_srst = SRST == SRST_POLARITY;\n    \n    always @(posedge pos_clk) begin\n        if (pos_srst)\n            Q <= SRST_VALUE;\n        else if (EN == EN_POLARITY)\n            Q <= D;\n    end\n    \nendmodule",
  "reg",
  "1",
  "",
};

cell_help["$sdffce"] = {
  "$sdffce",
  "",
  "(CLK, SRST, EN, D, Q)",
  "simlib.v:2576",
  "",
  "module \\$sdffce (CLK, SRST, EN, D, Q);\n    \n    parameter WIDTH = 0;\n    parameter CLK_POLARITY = 1'b1;\n    parameter EN_POLARITY = 1'b1;\n    parameter SRST_POLARITY = 1'b1;\n    parameter SRST_VALUE = 0;\n    \n    input CLK, SRST, EN;\n    input [WIDTH-1:0] D;\n    output reg [WIDTH-1:0] Q;\n    wire pos_clk = CLK == CLK_POLARITY;\n    wire pos_srst = SRST == SRST_POLARITY;\n    \n    always @(posedge pos_clk) begin\n        if (EN == EN_POLARITY) begin\n            if (pos_srst)\n                Q <= SRST_VALUE;\n            else\n                Q <= D;\n        end\n    end\n    \nendmodule",
  "reg",
  "1",
  "",
};

cell_help["$dlatch"] = {
  "$dlatch",
  "",
  "(EN, D, Q)",
  "simlib.v:2604",
  "",
  "module \\$dlatch (EN, D, Q);\n    \n    parameter WIDTH = 0;\n    parameter EN_POLARITY = 1'b1;\n    \n    input EN;\n    input [WIDTH-1:0] D;\n    output reg [WIDTH-1:0] Q;\n    \n    always @* begin\n        if (EN == EN_POLARITY)\n            Q = D;\n    end\n    \nendmodule",
  "reg",
  "1",
  "",
};

cell_help["$adlatch"] = {
  "$adlatch",
  "",
  "(EN, ARST, D, Q)",
  "simlib.v:2623",
  "",
  "module \\$adlatch (EN, ARST, D, Q);\n    \n    parameter WIDTH = 0;\n    parameter EN_POLARITY = 1'b1;\n    parameter ARST_POLARITY = 1'b1;\n    parameter ARST_VALUE = 0;\n    \n    input EN, ARST;\n    input [WIDTH-1:0] D;\n    output reg [WIDTH-1:0] Q;\n    \n    always @* begin\n        if (ARST == ARST_POLARITY)\n            Q = ARST_VALUE;\n        else if (EN == EN_POLARITY)\n            Q = D;\n    end\n    \nendmodule",
  "reg",
  "1",
  "",
};

cell_help["$dlatchsr"] = {
  "$dlatchsr",
  "",
  "(EN, SET, CLR, D, Q)",
  "simlib.v:2647",
  "",
  "module \\$dlatchsr (EN, SET, CLR, D, Q);\n    \n    parameter WIDTH = 0;\n    parameter EN_POLARITY = 1'b1;\n    parameter SET_POLARITY = 1'b1;\n    parameter CLR_POLARITY = 1'b1;\n    \n    input EN;\n    input [WIDTH-1:0] SET, CLR, D;\n    output reg [WIDTH-1:0] Q;\n    \n    wire pos_en = EN == EN_POLARITY;\n    wire [WIDTH-1:0] pos_set = SET_POLARITY ? SET : ~SET;\n    wire [WIDTH-1:0] pos_clr = CLR_POLARITY ? CLR : ~CLR;\n    \n    genvar i;\n    generate\n        for (i = 0; i < WIDTH; i = i+1) begin:bitslices\n            always @*\n                if (pos_clr[i])\n                    Q[i] = 0;\n                else if (pos_set[i])\n                    Q[i] = 1;\n                else if (pos_en)\n                    Q[i] = D[i];\n        end\n    endgenerate\n    \nendmodule",
  "reg",
  "1",
  "",
};

cell_help["$fsm"] = {
  "$fsm",
  "",
  "(CLK, ARST, CTRL_IN, CTRL_OUT)",
  "simlib.v:2681",
  "",
  "module \\$fsm (CLK, ARST, CTRL_IN, CTRL_OUT);\n    \n    parameter NAME = \"\";\n    \n    parameter CLK_POLARITY = 1'b1;\n    parameter ARST_POLARITY = 1'b1;\n    \n    parameter CTRL_IN_WIDTH = 1;\n    parameter CTRL_OUT_WIDTH = 1;\n    \n    parameter STATE_BITS = 1;\n    parameter STATE_NUM = 1;\n    parameter STATE_NUM_LOG2 = 1;\n    parameter STATE_RST = 0;\n    parameter STATE_TABLE = 1'b0;\n    \n    parameter TRANS_NUM = 1;\n    parameter TRANS_TABLE = 4'b0x0x;\n    \n    input CLK, ARST;\n    input [CTRL_IN_WIDTH-1:0] CTRL_IN;\n    output reg [CTRL_OUT_WIDTH-1:0] CTRL_OUT;\n    \n    wire pos_clk = CLK == CLK_POLARITY;\n    wire pos_arst = ARST == ARST_POLARITY;\n    \n    reg [STATE_BITS-1:0] state;\n    reg [STATE_BITS-1:0] state_tmp;\n    reg [STATE_BITS-1:0] next_state;\n    \n    reg [STATE_BITS-1:0] tr_state_in;\n    reg [STATE_BITS-1:0] tr_state_out;\n    reg [CTRL_IN_WIDTH-1:0] tr_ctrl_in;\n    reg [CTRL_OUT_WIDTH-1:0] tr_ctrl_out;\n    \n    integer i;\n    \n    task tr_fetch;\n        input [31:0] tr_num;\n        reg [31:0] tr_pos;\n        reg [STATE_NUM_LOG2-1:0] state_num;\n        begin\n            tr_pos = (2*STATE_NUM_LOG2+CTRL_IN_WIDTH+CTRL_OUT_WIDTH)*tr_num;\n            tr_ctrl_out = TRANS_TABLE >> tr_pos;\n            tr_pos = tr_pos + CTRL_OUT_WIDTH;\n            state_num = TRANS_TABLE >> tr_pos;\n            tr_state_out = STATE_TABLE >> (STATE_BITS*state_num);\n            tr_pos = tr_pos + STATE_NUM_LOG2;\n            tr_ctrl_in = TRANS_TABLE >> tr_pos;\n            tr_pos = tr_pos + CTRL_IN_WIDTH;\n            state_num = TRANS_TABLE >> tr_pos;\n            tr_state_in = STATE_TABLE >> (STATE_BITS*state_num);\n            tr_pos = tr_pos + STATE_NUM_LOG2;\n        end\n    endtask\n    \n    always @(posedge pos_clk, posedge pos_arst) begin\n        if (pos_arst) begin\n            state_tmp = STATE_TABLE[STATE_BITS*(STATE_RST+1)-1:STATE_BITS*STATE_RST];\n            for (i = 0; i < STATE_BITS; i = i+1)\n                if (state_tmp[i] === 1'bz)\n                    state_tmp[i] = 0;\n            state <= state_tmp;\n        end else begin\n            state_tmp = next_state;\n            for (i = 0; i < STATE_BITS; i = i+1)\n                if (state_tmp[i] === 1'bz)\n                    state_tmp[i] = 0;\n            state <= state_tmp;\n        end\n    end\n    \n    always @(state, CTRL_IN) begin\n        next_state <= STATE_TABLE[STATE_BITS*(STATE_RST+1)-1:STATE_BITS*STATE_RST];\n        CTRL_OUT <= 'bx;\n        // $display(\"---\");\n        // $display(\"Q: %b %b\", state, CTRL_IN);\n        for (i = 0; i < TRANS_NUM; i = i+1) begin\n            tr_fetch(i);\n            // $display(\"T: %b %b -> %b %b [%d]\", tr_state_in, tr_ctrl_in, tr_state_out, tr_ctrl_out, i);\n            casez ({state, CTRL_IN})\n                {tr_state_in, tr_ctrl_in}: begin\n                    // $display(\"-> %b %b <-   MATCH\", state, CTRL_IN);\n                    {next_state, CTRL_OUT} <= {tr_state_out, tr_ctrl_out};\n                end\n            endcase\n        end\n    end\n    \nendmodule",
  "fsm",
  "1",
  "",
};

cell_help["$memrd"] = {
  "$memrd",
  "",
  "(CLK, EN, ADDR, DATA)",
  "simlib.v:2776",
  "",
  "module \\$memrd (CLK, EN, ADDR, DATA);\n    \n    parameter MEMID = \"\";\n    parameter ABITS = 8;\n    parameter WIDTH = 8;\n    \n    parameter CLK_ENABLE = 0;\n    parameter CLK_POLARITY = 0;\n    parameter TRANSPARENT = 0;\n    \n    input CLK, EN;\n    input [ABITS-1:0] ADDR;\n    output [WIDTH-1:0] DATA;\n    \n    initial begin\n        if (MEMID != \"\") begin\n            $display(\"ERROR: Found non-simulatable instance of $memrd!\");\n            $finish;\n        end\n    end\n    \nendmodule",
  "mem",
  "1",
  "",
};

cell_help["$memrd_v2"] = {
  "$memrd_v2",
  "",
  "(CLK, EN, ARST, SRST, ADDR, DATA)",
  "simlib.v:2801",
  "",
  "module \\$memrd_v2 (CLK, EN, ARST, SRST, ADDR, DATA);\n    \n    parameter MEMID = \"\";\n    parameter ABITS = 8;\n    parameter WIDTH = 8;\n    \n    parameter CLK_ENABLE = 0;\n    parameter CLK_POLARITY = 0;\n    parameter TRANSPARENCY_MASK = 0;\n    parameter COLLISION_X_MASK = 0;\n    parameter ARST_VALUE = 0;\n    parameter SRST_VALUE = 0;\n    parameter INIT_VALUE = 0;\n    parameter CE_OVER_SRST = 0;\n    \n    input CLK, EN, ARST, SRST;\n    input [ABITS-1:0] ADDR;\n    output [WIDTH-1:0] DATA;\n    \n    initial begin\n        if (MEMID != \"\") begin\n            $display(\"ERROR: Found non-simulatable instance of $memrd_v2!\");\n            $finish;\n        end\n    end\n    \nendmodule",
  "mem",
  "1",
  "",
};

cell_help["$memwr"] = {
  "$memwr",
  "",
  "(CLK, EN, ADDR, DATA)",
  "simlib.v:2832",
  "",
  "module \\$memwr (CLK, EN, ADDR, DATA);\n    \n    parameter MEMID = \"\";\n    parameter ABITS = 8;\n    parameter WIDTH = 8;\n    \n    parameter CLK_ENABLE = 0;\n    parameter CLK_POLARITY = 0;\n    parameter PRIORITY = 0;\n    \n    input CLK;\n    input [WIDTH-1:0] EN;\n    input [ABITS-1:0] ADDR;\n    input [WIDTH-1:0] DATA;\n    \n    initial begin\n        if (MEMID != \"\") begin\n            $display(\"ERROR: Found non-simulatable instance of $memwr!\");\n            $finish;\n        end\n    end\n    \nendmodule",
  "mem",
  "1",
  "",
};

cell_help["$memwr_v2"] = {
  "$memwr_v2",
  "",
  "(CLK, EN, ADDR, DATA)",
  "simlib.v:2857",
  "",
  "module \\$memwr_v2 (CLK, EN, ADDR, DATA);\n    \n    parameter MEMID = \"\";\n    parameter ABITS = 8;\n    parameter WIDTH = 8;\n    \n    parameter CLK_ENABLE = 0;\n    parameter CLK_POLARITY = 0;\n    parameter PORTID = 0;\n    parameter PRIORITY_MASK = 0;\n    \n    input CLK;\n    input [WIDTH-1:0] EN;\n    input [ABITS-1:0] ADDR;\n    input [WIDTH-1:0] DATA;\n    \n    initial begin\n        if (MEMID != \"\") begin\n            $display(\"ERROR: Found non-simulatable instance of $memwr_v2!\");\n            $finish;\n        end\n    end\n    \nendmodule",
  "mem",
  "1",
  "",
};

cell_help["$meminit"] = {
  "$meminit",
  "",
  "(ADDR, DATA)",
  "simlib.v:2885",
  "",
  "module \\$meminit (ADDR, DATA);\n    \n    parameter MEMID = \"\";\n    parameter ABITS = 8;\n    parameter WIDTH = 8;\n    parameter WORDS = 1;\n    \n    parameter PRIORITY = 0;\n    \n    input [ABITS-1:0] ADDR;\n    input [WORDS*WIDTH-1:0] DATA;\n    \n    initial begin\n        if (MEMID != \"\") begin\n            $display(\"ERROR: Found non-simulatable instance of $meminit!\");\n            $finish;\n        end\n    end\n    \nendmodule",
  "mem",
  "1",
  "",
};

cell_help["$meminit_v2"] = {
  "$meminit_v2",
  "",
  "(ADDR, DATA, EN)",
  "simlib.v:2909",
  "",
  "module \\$meminit_v2 (ADDR, DATA, EN);\n    \n    parameter MEMID = \"\";\n    parameter ABITS = 8;\n    parameter WIDTH = 8;\n    parameter WORDS = 1;\n    \n    parameter PRIORITY = 0;\n    \n    input [ABITS-1:0] ADDR;\n    input [WORDS*WIDTH-1:0] DATA;\n    input [WIDTH-1:0] EN;\n    \n    initial begin\n        if (MEMID != \"\") begin\n            $display(\"ERROR: Found non-simulatable instance of $meminit_v2!\");\n            $finish;\n        end\n    end\n    \nendmodule",
  "mem",
  "1",
  "",
};

cell_help["$mem"] = {
  "$mem",
  "",
  "(RD_CLK, RD_EN, RD_ADDR, RD_DATA, WR_CLK, WR_EN, WR_ADDR, WR_DATA)",
  "simlib.v:2934",
  "",
  "module \\$mem (RD_CLK, RD_EN, RD_ADDR, RD_DATA, WR_CLK, WR_EN, WR_ADDR, WR_DATA);\n    \n    parameter MEMID = \"\";\n    parameter signed SIZE = 4;\n    parameter signed OFFSET = 0;\n    parameter signed ABITS = 2;\n    parameter signed WIDTH = 8;\n    parameter signed INIT = 1'bx;\n    \n    parameter signed RD_PORTS = 1;\n    parameter RD_CLK_ENABLE = 1'b1;\n    parameter RD_CLK_POLARITY = 1'b1;\n    parameter RD_TRANSPARENT = 1'b1;\n    \n    parameter signed WR_PORTS = 1;\n    parameter WR_CLK_ENABLE = 1'b1;\n    parameter WR_CLK_POLARITY = 1'b1;\n    \n    input [RD_PORTS-1:0] RD_CLK;\n    input [RD_PORTS-1:0] RD_EN;\n    input [RD_PORTS*ABITS-1:0] RD_ADDR;\n    output reg [RD_PORTS*WIDTH-1:0] RD_DATA;\n    \n    input [WR_PORTS-1:0] WR_CLK;\n    input [WR_PORTS*WIDTH-1:0] WR_EN;\n    input [WR_PORTS*ABITS-1:0] WR_ADDR;\n    input [WR_PORTS*WIDTH-1:0] WR_DATA;\n    \n    reg [WIDTH-1:0] memory [SIZE-1:0];\n    \n    integer i, j;\n    reg [WR_PORTS-1:0] LAST_WR_CLK;\n    reg [RD_PORTS-1:0] LAST_RD_CLK;\n    \n    function port_active;\n        input clk_enable;\n        input clk_polarity;\n        input last_clk;\n        input this_clk;\n        begin\n            casez ({clk_enable, clk_polarity, last_clk, this_clk})\n                4'b0???: port_active = 1;\n                4'b1101: port_active = 1;\n                4'b1010: port_active = 1;\n                default: port_active = 0;\n            endcase\n        end\n    endfunction\n    \n    initial begin\n        for (i = 0; i < SIZE; i = i+1)\n            memory[i] = INIT >>> (i*WIDTH);\n    end\n    \n    always @(RD_CLK, RD_ADDR, RD_DATA, WR_CLK, WR_EN, WR_ADDR, WR_DATA) begin\n    `ifdef SIMLIB_MEMDELAY\n        #`SIMLIB_MEMDELAY;\n    `endif\n        for (i = 0; i < RD_PORTS; i = i+1) begin\n            if (!RD_TRANSPARENT[i] && RD_CLK_ENABLE[i] && RD_EN[i] && port_active(RD_CLK_ENABLE[i], RD_CLK_POLARITY[i], LAST_RD_CLK[i], RD_CLK[i])) begin\n                // $display(\"Read from %s: addr=%b data=%b\", MEMID, RD_ADDR[i*ABITS +: ABITS],  memory[RD_ADDR[i*ABITS +: ABITS] - OFFSET]);\n                RD_DATA[i*WIDTH +: WIDTH] <= memory[RD_ADDR[i*ABITS +: ABITS] - OFFSET];\n            end\n        end\n    \n        for (i = 0; i < WR_PORTS; i = i+1) begin\n            if (port_active(WR_CLK_ENABLE[i], WR_CLK_POLARITY[i], LAST_WR_CLK[i], WR_CLK[i]))\n                for (j = 0; j < WIDTH; j = j+1)\n                    if (WR_EN[i*WIDTH+j]) begin\n                        // $display(\"Write to %s: addr=%b data=%b\", MEMID, WR_ADDR[i*ABITS +: ABITS], WR_DATA[i*WIDTH+j]);\n                        memory[WR_ADDR[i*ABITS +: ABITS] - OFFSET][j] = WR_DATA[i*WIDTH+j];\n                    end\n        end\n    \n        for (i = 0; i < RD_PORTS; i = i+1) begin\n            if ((RD_TRANSPARENT[i] || !RD_CLK_ENABLE[i]) && port_active(RD_CLK_ENABLE[i], RD_CLK_POLARITY[i], LAST_RD_CLK[i], RD_CLK[i])) begin\n                // $display(\"Transparent read from %s: addr=%b data=%b\", MEMID, RD_ADDR[i*ABITS +: ABITS],  memory[RD_ADDR[i*ABITS +: ABITS] - OFFSET]);\n                RD_DATA[i*WIDTH +: WIDTH] <= memory[RD_ADDR[i*ABITS +: ABITS] - OFFSET];\n            end\n        end\n    \n        LAST_RD_CLK <= RD_CLK;\n        LAST_WR_CLK <= WR_CLK;\n    end\n    \nendmodule",
  "mem",
  "1",
  "",
};

cell_help["$mem_v2"] = {
  "$mem_v2",
  "",
  "(RD_CLK, RD_EN, RD_ARST, RD_SRST, RD_ADDR, RD_DATA, WR_CLK, WR_EN, WR_ADDR, WR_DATA)",
  "simlib.v:3023",
  "",
  "module \\$mem_v2 (RD_CLK, RD_EN, RD_ARST, RD_SRST, RD_ADDR, RD_DATA, WR_CLK, WR_EN, WR_ADDR, WR_DATA);\n    \n    parameter MEMID = \"\";\n    parameter signed SIZE = 4;\n    parameter signed OFFSET = 0;\n    parameter signed ABITS = 2;\n    parameter signed WIDTH = 8;\n    parameter signed INIT = 1'bx;\n    \n    parameter signed RD_PORTS = 1;\n    parameter RD_CLK_ENABLE = 1'b1;\n    parameter RD_CLK_POLARITY = 1'b1;\n    parameter RD_TRANSPARENCY_MASK = 1'b0;\n    parameter RD_COLLISION_X_MASK = 1'b0;\n    parameter RD_WIDE_CONTINUATION = 1'b0;\n    parameter RD_CE_OVER_SRST = 1'b0;\n    parameter RD_ARST_VALUE = 1'b0;\n    parameter RD_SRST_VALUE = 1'b0;\n    parameter RD_INIT_VALUE = 1'b0;\n    \n    parameter signed WR_PORTS = 1;\n    parameter WR_CLK_ENABLE = 1'b1;\n    parameter WR_CLK_POLARITY = 1'b1;\n    parameter WR_PRIORITY_MASK = 1'b0;\n    parameter WR_WIDE_CONTINUATION = 1'b0;\n    \n    input [RD_PORTS-1:0] RD_CLK;\n    input [RD_PORTS-1:0] RD_EN;\n    input [RD_PORTS-1:0] RD_ARST;\n    input [RD_PORTS-1:0] RD_SRST;\n    input [RD_PORTS*ABITS-1:0] RD_ADDR;\n    output reg [RD_PORTS*WIDTH-1:0] RD_DATA;\n    \n    input [WR_PORTS-1:0] WR_CLK;\n    input [WR_PORTS*WIDTH-1:0] WR_EN;\n    input [WR_PORTS*ABITS-1:0] WR_ADDR;\n    input [WR_PORTS*WIDTH-1:0] WR_DATA;\n    \n    reg [WIDTH-1:0] memory [SIZE-1:0];\n    \n    integer i, j, k;\n    reg [WR_PORTS-1:0] LAST_WR_CLK;\n    reg [RD_PORTS-1:0] LAST_RD_CLK;\n    \n    function port_active;\n        input clk_enable;\n        input clk_polarity;\n        input last_clk;\n        input this_clk;\n        begin\n            casez ({clk_enable, clk_polarity, last_clk, this_clk})\n                4'b0???: port_active = 1;\n                4'b1101: port_active = 1;\n                4'b1010: port_active = 1;\n                default: port_active = 0;\n            endcase\n        end\n    endfunction\n    \n    initial begin\n        for (i = 0; i < SIZE; i = i+1)\n            memory[i] = INIT >>> (i*WIDTH);\n        RD_DATA = RD_INIT_VALUE;\n    end\n    \n    always @(RD_CLK, RD_ARST, RD_ADDR, RD_DATA, WR_CLK, WR_EN, WR_ADDR, WR_DATA) begin\n    `ifdef SIMLIB_MEMDELAY\n        #`SIMLIB_MEMDELAY;\n    `endif\n        for (i = 0; i < RD_PORTS; i = i+1) begin\n            if (RD_CLK_ENABLE[i] && RD_EN[i] && port_active(RD_CLK_ENABLE[i], RD_CLK_POLARITY[i], LAST_RD_CLK[i], RD_CLK[i])) begin\n                // $display(\"Read from %s: addr=%b data=%b\", MEMID, RD_ADDR[i*ABITS +: ABITS],  memory[RD_ADDR[i*ABITS +: ABITS] - OFFSET]);\n                RD_DATA[i*WIDTH +: WIDTH] <= memory[RD_ADDR[i*ABITS +: ABITS] - OFFSET];\n    \n                for (j = 0; j < WR_PORTS; j = j+1) begin\n                    if (RD_TRANSPARENCY_MASK[i*WR_PORTS + j] && port_active(WR_CLK_ENABLE[j], WR_CLK_POLARITY[j], LAST_WR_CLK[j], WR_CLK[j]) && RD_ADDR[i*ABITS +: ABITS] == WR_ADDR[j*ABITS +: ABITS])\n                        for (k = 0; k < WIDTH; k = k+1)\n                            if (WR_EN[j*WIDTH+k])\n                                RD_DATA[i*WIDTH+k] <= WR_DATA[j*WIDTH+k];\n                    if (RD_COLLISION_X_MASK[i*WR_PORTS + j] && port_active(WR_CLK_ENABLE[j], WR_CLK_POLARITY[j], LAST_WR_CLK[j], WR_CLK[j]) && RD_ADDR[i*ABITS +: ABITS] == WR_ADDR[j*ABITS +: ABITS])\n                        for (k = 0; k < WIDTH; k = k+1)\n                            if (WR_EN[j*WIDTH+k])\n                                RD_DATA[i*WIDTH+k] <= 1'bx;\n                end\n            end\n        end\n    \n        for (i = 0; i < WR_PORTS; i = i+1) begin\n            if (port_active(WR_CLK_ENABLE[i], WR_CLK_POLARITY[i], LAST_WR_CLK[i], WR_CLK[i]))\n                for (j = 0; j < WIDTH; j = j+1)\n                    if (WR_EN[i*WIDTH+j]) begin\n                        // $display(\"Write to %s: addr=%b data=%b\", MEMID, WR_ADDR[i*ABITS +: ABITS], WR_DATA[i*WIDTH+j]);\n                        memory[WR_ADDR[i*ABITS +: ABITS] - OFFSET][j] = WR_DATA[i*WIDTH+j];\n                    end\n        end\n    \n        for (i = 0; i < RD_PORTS; i = i+1) begin\n            if (!RD_CLK_ENABLE[i]) begin\n                // $display(\"Combinatorial read from %s: addr=%b data=%b\", MEMID, RD_ADDR[i*ABITS +: ABITS],  memory[RD_ADDR[i*ABITS +: ABITS] - OFFSET]);\n                RD_DATA[i*WIDTH +: WIDTH] <= memory[RD_ADDR[i*ABITS +: ABITS] - OFFSET];\n            end\n        end\n    \n        for (i = 0; i < RD_PORTS; i = i+1) begin\n            if (RD_SRST[i] && port_active(RD_CLK_ENABLE[i], RD_CLK_POLARITY[i], LAST_RD_CLK[i], RD_CLK[i]) && (RD_EN[i] || !RD_CE_OVER_SRST[i]))\n                RD_DATA[i*WIDTH +: WIDTH] <= RD_SRST_VALUE[i*WIDTH +: WIDTH];\n            if (RD_ARST[i])\n                RD_DATA[i*WIDTH +: WIDTH] <= RD_ARST_VALUE[i*WIDTH +: WIDTH];\n        end\n    \n        LAST_RD_CLK <= RD_CLK;\n        LAST_WR_CLK <= WR_CLK;\n    end\n    \nendmodule",
  "mem",
  "1",
  "",
};

cell_help["$set_tag"] = {
  "$set_tag",
  "",
  "(A, SET, CLR, Y)",
  "simlib.v:3143",
  "",
  "module \\$set_tag (A, SET, CLR, Y);\n    \n    parameter TAG = \"\";\n    parameter WIDTH = 0;\n    \n    input [WIDTH-1:0] A;\n    input [WIDTH-1:0] SET;\n    input [WIDTH-1:0] CLR;\n    output [WIDTH-1:0] Y;\n    \n    assign Y = A;\n    \nendmodule",
  "formal_tag",
  "1",
  "",
};

cell_help["$get_tag"] = {
  "$get_tag",
  "",
  "(A, Y)",
  "simlib.v:3159",
  "",
  "module \\$get_tag (A, Y);\n    \n    parameter TAG = \"\";\n    parameter WIDTH = 0;\n    \n    input [WIDTH-1:0] A;\n    output [WIDTH-1:0] Y;\n    \n    assign Y = A;\n    \nendmodule",
  "formal_tag",
  "1",
  "",
};

cell_help["$overwrite_tag"] = {
  "$overwrite_tag",
  "",
  "(A, SET, CLR)",
  "simlib.v:3173",
  "",
  "module \\$overwrite_tag (A, SET, CLR);\n    \n    parameter TAG = \"\";\n    parameter WIDTH = 0;\n    \n    input [WIDTH-1:0] A;\n    input [WIDTH-1:0] SET;\n    input [WIDTH-1:0] CLR;\n    \nendmodule",
  "formal_tag",
  "1",
  "",
};

cell_help["$original_tag"] = {
  "$original_tag",
  "",
  "(A, Y)",
  "simlib.v:3186",
  "",
  "module \\$original_tag (A, Y);\n    \n    parameter TAG = \"\";\n    parameter WIDTH = 0;\n    \n    input [WIDTH-1:0] A;\n    output [WIDTH-1:0] Y;\n    \n    assign Y = A;\n    \nendmodule",
  "formal_tag",
  "1",
  "",
};

cell_help["$future_ff"] = {
  "$future_ff",
  "",
  "(A, Y)",
  "simlib.v:3200",
  "",
  "module \\$future_ff (A, Y);\n    \n    parameter WIDTH = 0;\n    \n    input [WIDTH-1:0] A;\n    output [WIDTH-1:0] Y;\n    \n    assign Y = A;\n    \nendmodule",
  "formal_tag",
  "1",
  "",
};

cell_help["$scopeinfo"] = {
  "$scopeinfo",
  "",
  "()",
  "simlib.v:3214",
  "",
  "module \\$scopeinfo ();\n    \n    parameter TYPE = \"\";\n    \nendmodule",
  "debug",
  "1",
  "",
};

