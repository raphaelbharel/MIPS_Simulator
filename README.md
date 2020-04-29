# MIPS_Simulator
Co-author: @daryllimyt 

MIPS CPU simulator written in C++ that executes MIPS-1 big-endian binary assembly instructions in compliance with the MIPS RISC ISA specification. 

## Introduction
As part of ELEC95007 - Computer Architecture 2 2019-2020 at Imperial College London, we were tasked to design and implement a MIPS CPU Simulator from scratch, along with a testbench to test any MIPS simulator including our own.

TL;DR - simulator receives sequence of 32 bits (MIPS-1 big endian instructions), outputs MIPS CPU operations by writing to a mapped 32-bit memory location. 

## Requirements
- Simulator is a binary compiled from C++ sources
- Can be compiled from target environment
- A Simulator should not assume it is being executed from any particular directory, so it should not try to open any data files. It should also not create or write to any other files.

## Simulator 
The following section details how to run the simulator on your local environment, along with an overview of the key components of the simulator.

### Build and Execution

Compile simulator (simulator.cpp) into bin folder, from root of repository
```
make simulator
```
Assuming a binary file containing MIPS-1 big-endian instructions called m.bin exists, we can simulate it using:
```
bin/mips_simulator x.bin
```
You may create m.bin yourself, or use our own binaries from the folder test/input 

To recompile in target environment, execute the following commands in the root of repository
```
rm bin/mips_simulator
make simulator
```

**Note:** On startup all MIPS registers will be zero, any uninitialised memory will be zero, and the program counter will point at the first instruction in memory.

## Memory-Map
The memory map of the simulated process is as follows:

```
Offset     |  Length     | Name       | R | W | X |
-----------|-------------|------------|---|---|---|--------------------------------------------------------------------
0x00000000 |        0x4  | ADDR_NULL  |   |   | Y | Jumping to this address means the Binary has finished execution.
0x00000004 |  0xFFFFFFC  | ....       |   |   |   |
0x10000000 |  0x1000000  | ADDR_INSTR | Y |   | Y | Executable memory. The Binary should be loaded here.
0x11000000 |  0xF000000  | ....       |   |   |   |
0x20000000 |  0x4000000  | ADDR_DATA  | Y | Y |   | Read-write data area. Should be zero-initialised.
0x24000000 |  0xC000000  | ....       |   |   |   |
0x30000000 |        0x4  | ADDR_GETC  | Y |   |   | Location of memory mapped input. Read-only.
0x30000004 |        0x4  | ADDR_PUTC  |   | Y |   | Location of memory mapped output. Write-only.
0x30000008 | 0xCFFFFFF8  | ....       |   |   |   |
-----------|-------------|------------|---|---|---|--------------------------------------------------------
```
The Binary is not allowed to modify its own code, nor should it attempt to execute code outside the executable memory.

When a simulated program reads from address ADDR_GETC, the simulator should

Block until a character is available (e.g. if a key needs to be pressed)
Return the 8-bit extended to 32-bits as the result of the memory read.
If there are no more characters (EOF), the memory read should return -1.
When a simulated program writes to address ADDR_PUTC, the simulator should write the character to stdout. If the write fails, the appropriate Error should be signalled.


## Instructions
Instructions of interest are:
Code    |   Meaning                                    
--------|---------------------------------------------
ADD     |  Add (with overflow)                            
ADDI    |  Add immediate (with overflow)                  
ADDIU   |  Add immediate unsigned (no overflow)            
ADDU    |  Add unsigned (no overflow)                       
AND     |  Bitwise and                                       
ANDI    |  Bitwise and immediate                           
BEQ     |  Branch on equal                                 
BGEZ    |  Branch on greater than or equal to zero        
BGEZAL  |  Branch on non-negative (>=0) and link          
BGTZ    |  Branch on greater than zero                     
BLEZ    |  Branch on less than or equal to zero            
BLTZ    |  Branch on less than zero                        
BLTZAL  |  Branch on less than zero and link             
BNE     |  Branch on not equal                              
DIV     |  Divide                                        
DIVU    |  Divide unsigned                                 
J       |  Jump                                          
JALR    |  Jump and link register                         
JAL     |  Jump and link                                
JR      |  Jump register                                    
LB      |  Load byte                                       
LBU     |  Load byte unsigned                             
LH      |  Load half-word                                   
LHU     |  Load half-word unsigned                          
LUI     |  Load upper immediate                            
LW      |  Load word                                        
LWL     |  Load word left                                
LWR     |  Load word right                              
MFHI    |  Move from HI                                  
MFLO    |  Move from LO                                    
MTHI    |  Move to HI                                     
MTLO    |  Move to LO                                    
MULT    |  Multiply                                      
MULTU   |  Multiply unsigned                            
OR      |  Bitwise or                                      
ORI     |  Bitwise or immediate                            
SB      |  Store byte                                      
SH      |  Store half-word                              
SLL     |  Shift left logical                            
SLLV    |  Shift left logical variable                    
SLT     |  Set on less than (signed)                     
SLTI    |  Set on less than immediate (signed)               
SLTIU   |  Set on less than immediate unsigned             
SLTU    |  Set on less than unsigned                     
SRA     |  Shift right arithmetic                          
SRAV    |  Shift right arithmetic                         
SRL     |  Shift right logical                           
SRLV    |  Shift right logical variable                   
SUB     |  Subtract                                       
SUBU    |  Subtract unsigned                               
SW      |  Store word                                      
XOR     |  Bitwise exclusive or                             
XORI    |  Bitwise exclusive or immediate                  
--------|---------------------------------------------
INTERNAL|  Not associated with a specific instruction
FUNCTION|  Testing the ability to support functions  
STACK   |  Testing for functions using the stack     

The final instructions are pseudo-instructions, for cases where they don't map to
a single instruction. You are not required to use them, but they may be useful
for tests which are looking at more complex functionality, rather than narrowly
looking at one.


**To compile testbench (tb.cpp) into bin folder**
```
make testbench
```

**To run simulator on testbench (skeleton)**
```

bin/mips_testbench bin/mips_simulator
```

## Exceptions and Errors
Exceptions are due to instructions which the Binary wants to execute which result in some kind of exceptional or abnormal situation. Exceptions occur due to bugs or errors within the Simulator. All exceptions are classified into three types, each of which has a numeric code:

**Exception codes:**
Arithmetic exception (-10) : Any kind of arithmetic problem, such as overflow, divide by zero, ...

Memory exception (-11) : Any problem relating to memory, such as address out of range, writing to read-only memory, reading from an address that cannot be read, executing an address that cannot be executed ...

Invalid instruction (-12) : The Binary tries to execute a memory location that does not contain a valid instruction (this is not the same as trying to read a value that cannot be executed).

Errors are due to problems occuring within the simulator, rather than something that the Binary did wrong. As with exceptions, an error may indicate a genuine problem with the Simulator, or it may be due to an interaction between the Simulator and the Environment. An example of the former is where a Simulator doesn't support a particular op-code (yet), so cannot execute a correct Binary.

**Error codes:**
Internal error (-20) : the simulator has failed due to some unknown error
IO error (-21) : the simulator encountered an error reading/writing input/output
