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
#define ADDR_INSTR_OFFSET 0x4000000 //0x10000000 / 4
#define ADDR_DATA_OFFSET 0x8000000  //0x20000000 / 4
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
bool within_memory_bounds(const ADDR_TYPE &mem_addr, const char &mode);
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
    std::vector<MEM_TYPE> instruction_mem;
    REG_TYPE regHI;
    REG_TYPE regLO;
    MEM_TYPE PUTC;

    CPU()
    {
        pc = ADDR_INSTR_OFFSET; // PC starts at beginning of executable memory
        npc = ADDR_INSTR_OFFSET + 1;
        reg.resize(REGISTER_SIZE, 0);
        mem.resize(ADDR_DATA_LENGTH, 0);           // Initialize to length of r/w data area
        instruction_mem.resize(ADDR_INSTR_LENGTH); // Initialize with null
        regHI = 0;
        regLO = 0;
        PUTC = 0;
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
        std::cerr << "|\n| "
                  << "$LO"
                  << "\t" << regLO << std::endl;
        std::cerr << "| "
                  << "$HI"
                  << "\t" << regHI << std::endl;
        std::cerr << "+---------------+" << "\n";
        std::cerr << "|\n| "<< "PUTC"<< "\t" << PUTC << std::endl;
        std::cerr << "+---------------+" << std::endl<< "\n";
    }
    MEM_TYPE read_from_memory(const ADDR_TYPE &loc)
    {
        if (loc >= ADDR_INSTR_OFFSET && loc <= (ADDR_INSTR_OFFSET + ADDR_INSTR_LENGTH))
        {
            return instruction_mem[loc - ADDR_INSTR_OFFSET];
        }
        else if (loc >= ADDR_DATA_OFFSET && loc <= (ADDR_DATA_OFFSET + ADDR_DATA_LENGTH))
        {
            return mem[loc - ADDR_DATA_OFFSET];
        }
        else if (loc == ADDR_GETC)
        {
            char input = read_char();
            return sign_extend_int32(input, 8);
        }
        else
        {
            throw(MEMORY_EXIT_CODE);
        }
    }
    void write_to_memory(const ADDR_TYPE &loc, const ADDR_TYPE &offset, const char &type, const MEM_TYPE &val)
    {
        if (loc >= ADDR_DATA_OFFSET && loc <= (ADDR_DATA_OFFSET + ADDR_DATA_LENGTH))
        {
            if (type == 'b')
            {    
                switch (offset)
                { // Byte
                case 3:
                    mem[loc - ADDR_DATA_OFFSET] = (mem[loc - ADDR_DATA_OFFSET] & 0xFFFFFF00) | val;
                    return;
                case 2:
                    mem[loc - ADDR_DATA_OFFSET] = (mem[loc - ADDR_DATA_OFFSET] & 0xFFFF00FF) | (val << 8);
                    return;
                case 1:
                    mem[loc - ADDR_DATA_OFFSET] = (mem[loc - ADDR_DATA_OFFSET] & 0xFF00FFFF) | (val << 16);
                    return;
                case 0:
                    mem[loc - ADDR_DATA_OFFSET] = (mem[loc - ADDR_DATA_OFFSET] & 0xFFFFFF) | (val << 24);
                    return;
                default:;
                }
            }
            else if (type == 'h')
            { // Half
                switch (offset)
                {
                case 2:
                    mem[loc - ADDR_DATA_OFFSET] = (mem[loc - ADDR_DATA_OFFSET] & 0xFFFF0000) | val;
                    return;
                case 0:
                    mem[loc - ADDR_DATA_OFFSET] = (mem[loc - ADDR_DATA_OFFSET] & 0xFFFF) | (val << 16);
                    return;
                default:;
                }
            }
            else if (type == 'w')
            { // Word
                mem[loc - ADDR_DATA_OFFSET] = val;
                return;
            } 
        }
        else if (loc == ADDR_PUTC)
        {
            if (type == 'b')
            {    
                switch (offset)
                { // Byte
                case 3:
                    PUTC = (PUTC & 0xFFFFFF00) | val;
                    break;
                // case 2:
                //     PUTC = (PUTC & 0xFFFF00FF) | (val << 8);
                //     break;
                // case 1:
                //     PUTC = (PUTC & 0xFF00FFFF) | (val << 16);
                //     break;
                // case 0:
                //     PUTC = (PUTC & 0xFFFFFF) | (val << 24);
                //     break;
                default:
                    return; // do nothing
                }
            }
            else if (type == 'h')
            { // Half
                switch (offset)
                {
                case 2:
                    PUTC = (PUTC & 0xFFFF0000) | val;
                    break;
                // case 0:
                //     PUTC = (PUTC & 0xFFFF) | (val << 16);
                //     break;
                default:
                    return; // do nothing
                }
            }
            else if (type == 'w')
            { // Word
                PUTC = val;
            } 
            putchar(PUTC&0xFF);
            if (!std::cout.good()) {throw(IO_EXIT_CODE);}
            return;
        }
        throw(MEMORY_EXIT_CODE);
    }

private:
};

#endif