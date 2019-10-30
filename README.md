# MIPS_Simulator

MIPS Simulator for Daryl & Raphael
Group name: WMIPS

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
