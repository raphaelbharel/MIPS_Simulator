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

SRC_FILES = src/simulator.cpp src/functions.cpp src/r_type_instructions.cpp src/i_type_instructions.cpp  src/j_type_instructions.cpp
DEBUG_SETTING = 1

bin/mips_simulator: $(SRC_FILES)
	mkdir -p bin
	$(CC) $(CPPFLAGS) $(SRC_FILES) -o bin/mips_simulator

# Dummy for build simulator to conform to spec
simulator: bin/mips_simulator

simulator_DT_jr: bin/mips_simulator Formative_Tests/JR-return-immediate-nodelay.mips.bin
		./bin/mips_simulator Formative_Tests/JR-return-immediate-nodelay.mips.bin

simulator_formative_test: bin/mips_simulator Formative_Tests/JR-return-immediate.mips.bin
		./bin/mips_simulator Formative_Tests/JR-return-immediate.mips.bin $(DEBUG_SETTING)

test_LW_getc: bin/mips_simulator Formative_Tests/LW-getc.mips.bin
		./bin/mips_simulator Formative_Tests/LW-getc.mips.bin $(DEBUG_SETTING)

test-LW-read-data-section: bin/mips_simulator Formative_Tests/LW-read-data-section.mips.bin
		./bin/mips_simulator Formative_Tests/LW-read-data-section.mips.bin $(DEBUG_SETTING)

test-SW-putc: bin/mips_simulator Formative_Tests/SW-putc.mips.bin
		./bin/mips_simulator Formative_Tests/SW-putc.mips.bin $(DEBUG_SETTING)

test-SW-read-write-data-section: bin/mips_simulator Formative_Tests/SW-read-write-data-section.mips.bin
		./bin/mips_simulator Formative_Tests/SW-read-write-data-section.mips.bin $(DEBUG_SETTING)

test-ADD: bin/mips_simulator test/input/add4.bin
		./bin/mips_simulator test/input/add4.bin $(DEBUG_SETTING)

test-lwr5: bin/mips_simulator test/input/lwr5.bin
		./bin/mips_simulator test/input/lwr5.bin $(DEBUG_SETTING)
test-AND: bin/mips_simulator test/input/and2.bin
		./bin/mips_simulator test/input/and2.bin $(DEBUG_SETTING)

test-lw2: bin/mips_simulator test/input/lw2.bin
		./bin/mips_simulator test/input/lw2.bin $(DEBUG_SETTING)

test-bgezal4: bin/mips_simulator test/input/bgezal4.bin
		./bin/mips_simulator test/input/bgezal4.bin $(DEBUG_SETTING)
test-bgezal3: bin/mips_simulator test/input/bgezal3.bin
		./bin/mips_simulator test/input/bgezal3.bin $(DEBUG_SETTING)
test-bgezal1: bin/mips_simulator test/input/bgezal1.bin
		./bin/mips_simulator test/input/bgezal1.bin $(DEBUG_SETTING)

test-sb2: bin/mips_simulator test/input/sb2.bin
		./bin/mips_simulator test/input/sb2.bin $(DEBUG_SETTING)

test-bltz4: bin/mips_simulator test/input/bltz4.bin
		./bin/mips_simulator test/input/bltz4.bin $(DEBUG_SETTING)

test-lb5: bin/mips_simulator test/input/lb5.bin
		./bin/mips_simulator test/input/lb5.bin $(DEBUG_SETTING)

test-bgezal4: bin/mips_simulator test/input/bgezal4.bin
		./bin/mips_simulator test/input/bgezal4.bin $(DEBUG_SETTING)





#----------------------------------------------------
#TESTBENCH
#----------------------------------------------------

# Dummy for build testbench to conform to spec. Could do nothing. 
#bash file executable to be held in bin/mips_testbench. Can copy from test.
#u+x bin/mips_testbench (give user permissions, making it executable)
#TODO: add functionality to make bin folder if not present.
#MAKE: error: always saying "up to date"

bin/mips_testbench: 
	mkdir -p bin 
	cp -a test/mips_testbench bin/
	chmod u+x bin/mips_testbench 

bin/mips_testbench2: 
	mkdir -p bin 
	cp -a test/mips_testbench2 bin/
	chmod u+x bin/mips_testbench2

run_test: bin/mips_simulator bin/mips_testbench2
	./bin/mips_testbench2 bin/mips_simulator test/input/lwr5.bin

runtests: bin/mips_testbench bin/mips_simulator
	./bin/mips_testbench bin/mips_simulator
	
clean:
	rm bin/mips_simulator
	rm bin/mips_testbench

cleartests:
	rm test/output/log.csv
	rm test/output/testing.csv