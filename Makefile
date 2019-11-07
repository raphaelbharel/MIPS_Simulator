# Example usage:
# If you have testbench/my_test.c, you can execute the following to create a MIPS binary
# make testbench/my_test.mips.bin

# For simulator
CC = g++
CPPFLAGS = -W -std=c++11 #Wall means Write All

# For MIPS binaries. Turn on all warnings, enable all optimisations and link everything statically
MIPS_CC = mips-linux-gnu-gcc
MIPS_OBJCOPY = mips-linux-gnu-objcopy
MIPS_OBJDUMP = mips-linux-gnu-objdump
MIPS_CPPFLAGS = -W -Wall -O3 -fno-builtin -march=mips1 -mfp32
MIPS_LDFLAGS = -nostdlib -Wl,-melf32btsmip -march=mips1 -nostartfiles -mno-check-zero-division -Wl,--gpsize=0 -static -Wl,-Bstatic -Wl,--build-id=none

# Compile C file (.c) into MIPS object file (.o)
%.mips.o: %.c
	$(MIPS_CC) $(MIPS_CPPFLAGS) -c $< -o $@

# Assemble MIPS assembly file (.s) into MIPS object file (.o)
%.mips.o: %.s
	$(MIPS_CC) $(MIPS_CPPFLAGS) -c $< -o $@

# Link MIPS object file (.o), producing .elf, using memory locations specified in spec
%.mips.elf: %.mips.o
	$(MIPS_CC) $(MIPS_CPPFLAGS) $(MIPS_LDFLAGS) -T linker.ld $< -o $@

# Extract binary instructions only from linked object file (.elf)
%.mips.bin: %.mips.elf
	$(MIPS_OBJCOPY) -O binary --only-section=.text $< $@

# Disassemble linked object file (.elf), pulling out instructions as MIPS assembly file (.s)
%.mips.s : %.mips.elf
	$(MIPS_OBJDUMP) -j .text -D $< > $@

#----------------------------------------------------
#SIMULATOR											 
#----------------------------------------------------
# Build simulator, write output file in bin folder as mips_simulator

SRC_FILES = src/simulator.cpp src/r_type_instructions.cpp src/i_type_instructions.cpp  src/j_type_instructions.cpp
bin/mips_simulator: $(SRC_FILES)
	mkdir -p bin
	$(CC) $(CPPFLAGS) $(SRC_FILES) -o bin/mips_simulator

# Dummy for build simulator to conform to spec
simulator1: bin/mips_simulator src/test1.bin
	./bin/mips_simulator src/test1.bin
	
simulator2: bin/mips_simulator src/test2.bin
	./bin/mips_simulator src/test2.bin
	
simulator3: bin/mips_simulator src/test3.bin
	./bin/mips_simulator src/test3.bin

simulator4: bin/mips_simulator src/test4.bin
	./bin/mips_simulator src/test4.bin

simulator_addiu1: bin/mips_simulator src/addiu_1.bin
	./bin/mips_simulator src/addiu_1.bin

simulator_addiu2: bin/mips_simulator src/addiu_2.bin
	./bin/mips_simulator src/addiu_2.bin

#----------------------------------------------------
#TESTBENCH
#----------------------------------------------------


# Dummy for build testbench to conform to spec. Could do nothing. 
testbench: 
	mkdir -p bin
	$(CC) $(CPPFLAGS) test/tb.cpp -o bin/mips_testbench

#Run tests on MIPS_Simulator
bin/mips_testbench: bin/mips_simulator
	#run tests
	#any temp files to be stored in test/temp
	#output of testbench created in test/output. i.e per test logfiles
	#once all tests run, print CSV file to stdout, with each row corresponding to one execution of Simulator under test.

clean:
	rm bin/mips_simulator