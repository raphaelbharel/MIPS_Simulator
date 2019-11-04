# MIPS_Simulator

MIPS Simulator for Daryl & Raphael
Group name: WMIPS

**NOTE**

current build behaviour: if binary is not multiple of 32, remaining N bits will be considered as LSB

**To compile simulator (simulator_1.cpp) into bin folder**

make simulator

**To compile testbench (tb.cpp) into bin folder**

make testbench

**To run simulator on testbench (skeleton)**

bin/mips_testbench bin/mips_simulator

**Reading arguments from command line, argc and argv**

argc (ARGument Count) is int and stores number of command-line arguments passed by the user including the name of the program. So if we pass a value to a program, value of argc would be 2 (one for argument and one for program name)
The value of argc should be non negative.
argv(ARGument Vector) is array of character pointers listing all the arguments.
If argc is greater than zero,the array elements from argv[0] to argv[argc-1] will contain pointers to strings.
Argv[0] is the name of the program , After that till argv[argc-1] every element is command -line arguments.

In the command line we would type:
bin/mips_simulator file_name.bin
to run the simulator on file_name.bin. argv[0] = bin/mips_simulator, argv[1] = file_name.bin

**Exit codes**
Arithmetic exception (-10) : Any kind of arithmetic problem, such as overflow, divide by zero, ...

Memory exception (-11) : Any problem relating to memory, such as address out of range, writing to read-only memory, reading from an address that cannot be read, executing an address that cannot be executed ...

Invalid instruction (-12) : The Binary tries to execute a memory location that does not contain a valid instruction (this is not the same as trying to read a value that cannot be executed).

Code	Meaning	Complexity	Type
ADD	Add (with overflow)	2 XX	R
ADDU	Add unsigned (no overflow)	1 X	R
AND	Bitwise and	1 X	R
DIV	Divide	4 XXXX	R
DIVU	Divide unsigned	4 XXXX	R
JALR	Jump and link register	4 XXXX	R
JR	Jump register	1 X	R
MFHI	Move from HI	3 XXX	R
MFLO	Move from LO	3 XXX	R
MTHI	Move to HI	3 XXX	R
MTLO	Move to LO	3 XXX	R
MULT	Multiply	4 XXXX	R
MULTU	Multiply unsigned	4 XXXX	R
OR	Bitwise or	1 X	R
SLL	Shift left logical	2 XX	R
SLLV	Shift left logical variable	3 XXX	R
SLT	Set on less than (signed)	2 XX	R
SLTU	Set on less than unsigned	1 X	R
SRA	Shift right arithmetic	2 XX	R
SRAV	Shift right arithmetic	2 XX	R
SRL	Shift right logical	2 XX	R
SRLV	Shift right logical variable	3 XXX	R
SUB	Subtract	2 XX	R
SUBU	Subtract unsigned	1 X	R
XOR	Bitwise exclusive or	1 X	R
J	Jump	3 XXX	J
JAL	Jump and link	4 XXXX	J
ADDI	Add immediate (with overflow)	2 XX	I
ADDIU	Add immediate unsigned (no overflow)	2 XX	I
ANDI	Bitwise and immediate	2 XX	I
BEQ	Branch on equal	3 XXX	I
BGEZ	Branch on greater than or equal to zero	3 XXX	I
BGEZAL	Branch on non-negative (>=0) and link	4 XXXX	I
BGTZ	Branch on greater than zero	3 XXX	I
BLEZ	Branch on less than or equal to zero	3 XXX	I
BLTZ	Branch on less than zero	3 XXX	I
BLTZAL	Branch on less than zero and link	4 XXXX	I
BNE	Branch on not equal	3 XXX	I
LB	Load byte	3 XXX	I
LBU	Load byte unsigned	3 XXX	I
LH	Load half-word	3 XXX	I
LHU	Load half-word unsigned	3 XXX	I
LUI	Load upper immediate	2 XX	I
LW	Load word	2 XX	I
LWL	Load word left	5 XXXXX	I
LWR	Load word right	5 XXXXX	I
ORI	Bitwise or immediate	2 XX	I
SB	Store byte	3 XXX	I
SH	Store half-word	3 XXX	I
SLTI	Set on less than immediate (signed)	3 XXX	I
SLTIU	Set on less than immediate unsigned	3 XXX	I
SW	Store word	2 XX	I
XORI	Bitwise exclusive or immediate	2 XX	I
