// This file contains constant defitions and includes

#ifndef SETUP_H

#define SETUP_H

#include <cstdlib>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <iterator>
#include <bitset>

//MEMORY MAP
#define ADDR_NULL 0x00000000
#define ADDR_INSTR_OFFSET 0x4000000 //0x10000000 / 4 - The starting point of Executable memory.
#define ADDR_INSTR_LENGTH 0x400000  //0x1000000 / 4
#define ADDR_DATA_OFFSET 0x8000000  //0x20000000 / 4 - The starting point of Read-write data area.
#define ADDR_DATA_LENGTH 0x1000000  //0x4000000 / 4
#define ADDR_GETC 0xC000000         //0x30000000 / 4
#define ADDR_PUTC 0xC000001         //0x30000004 / 4

//SIZES
#define BUFFER_SIZE 32
#define REGISTER_SIZE 32
#define CODE_SIZE 6
#define SRC1_SIZE 5
#define SRC2_SIZE 5
#define DEST_SIZE 5
#define SHIFT_SIZE 5
#define FUNC_SIZE 6
#define I_ADATA_SIZE 16
#define J_ADDRESS_SIZE 26
#define MEM_SIZE 0xC000002 //0x30000008 / 4

//EXIT CODES
#define ARITHMETIC_EXIT_CODE -10
#define MEMORY_EXIT_CODE -11
#define INSTRUCTION_EXIT_CODE -12
#define INTERNAL_EXIT_CODE -20
#define IO_EXIT_CODE -21

//TYPES
typedef uint32_t INSTR_TYPE;
typedef uint32_t ADDR_TYPE;
typedef char BUFFER_TYPE;
typedef int32_t MEM_TYPE;
typedef int32_t REG_TYPE;

// Function declarations
char read_char();
char read_instruction(INSTR_TYPE &instruction);
uint32_t addr_to_index(const uint32_t &base, const uint32_t &loc);
void __print_memory(const std::vector<MEM_TYPE> &v);
void __print_memory_specific(const std::vector<MEM_TYPE> &v, const int &start_index, const int &end_index);

// Template functions
template <typename T>
int32_t sign_extend_int32(const T &data, const int &initial_length)
{
    T temp = data;
    int32_t rv = temp;
    if (temp >> (initial_length - 1))
    { // Checking MSB
        int extension = 0xFFFFFFFF >> initial_length;
        extension = extension << initial_length;
        rv = extension | temp;
    }
    return static_cast<int32_t>(rv);
}

// Class definitions
class CPU
{
public:
    ADDR_TYPE pc;
    ADDR_TYPE npc;
    INSTR_TYPE instr;
    std::vector<REG_TYPE> reg;
    std::vector<MEM_TYPE> mem;
    REG_TYPE regHI = 0;
    REG_TYPE regLO = 0;

    CPU(std::vector<MEM_TYPE>instruction_mem)
    {
        pc = ADDR_INSTR_OFFSET; // PC starts at beginning of executable memory
        npc = ADDR_INSTR_OFFSET + 1;
        instr = instruction_mem[0]; //start from first
        reg.resize(REGISTER_SIZE, 0);
        mem.resize(ADDR_DATA, 0); // Initialize to length of r/w data area
    }
    void display()
    {
        std::cerr << "+--{DISPLAY}--+" << std::endl;
        std::cerr << "| " << std::hex << "pc: " << pc << std::endl;
        std::cerr << "| " << std::hex << "npc: " << npc << std::endl;
        std::cerr << "| " << std::hex << "instr: " << instr << std::endl;
        std::cerr << "+-------------+" << std::endl
                  << "\n";
    }

    void view_regs()
    {
        std::cerr << "+--{REGISTERS}--+ " << std::endl;
        for (int index = 0; index < REGISTER_SIZE; index++)
        {
            std::cerr << "| "
                      << "$" << index << "\t" << reg[index] << std::endl;
        }
        std::cerr << "+---------------+" << std::endl
                  << "\n";
    }

private:
};

#endif