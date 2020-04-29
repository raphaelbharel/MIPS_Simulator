# MIPS_Simulator

MIPS Simulator for Daryl & Raphael
Group name: WMIPS

**NOTE**

current build behaviour: if binary is not multiple of 32, remaining N bits will be considered as LSB

**To compile simulator (simulator.cpp) into bin folder**
```
make simulator
```

**To compile testbench (tb.cpp) into bin folder**
```
make testbench
```

**To run simulator on testbench (skeleton)**
```

bin/mips_testbench bin/mips_simulator
```

**Exit codes**
Arithmetic exception (-10) : Any kind of arithmetic problem, such as overflow, divide by zero, ...

Memory exception (-11) : Any problem relating to memory, such as address out of range, writing to read-only memory, reading from an address that cannot be read, executing an address that cannot be executed ...

Invalid instruction (-12) : The Binary tries to execute a memory location that does not contain a valid instruction (this is not the same as trying to read a value that cannot be executed).
