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

#define ADDR_NULL 0x00000000
#define ADDR_INSTR_LENGTH 0x400000  //0x1000000 / 4
#define ADDR_INSTR_OFFSET 0x4000000 //0x10000000 / 4
#define ADDR_DATA 0x8000000         //0x20000000 / 4
#define ADDR_DATA_OFFSET 0x1000000  //0x4000000 / 4
#define ADDR_GETC 0xC000000         //0x30000000 / 4
#define ADDR_PUTC 0xC000001         //0x30000004 / 4
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
#define ARITHMETIC_EXIT_CODE -10
#define MEMORY_EXIT_CODE -11
#define INSTRUCTION_EXIT_CODE -12
#define INTERNAL_EXIT_CODE -20
#define IO_EXIT_CODE -21

typedef uint32_t INSTR_TYPE;
typedef uint32_t ADDR_TYPE;
typedef char BUFFER_TYPE;
typedef int32_t MEM_TYPE;
typedef int32_t REG_TYPE;


// Function declarations
char read_char();
char read_instruction(INSTR_TYPE &instruction);

void __print_memory(const std::vector<MEM_TYPE> &v);
void __print_memory_specific(const std::vector<MEM_TYPE> &v, const int &start_index, const int &end_index);

// Template functions
template <typename T>
int32_t sign_extend_int32(const T &data, const int &initial_length){
    T temp = data;
    int32_t rv = temp;
    if(temp >> (initial_length-1)){ // Checking MSB
        int extension = 0xFFFFFFFF >> initial_length;
        extension = extension << initial_length;
        rv = extension | temp;
    } 
    return static_cast<int32_t>(rv);
}
// template <typename T>
// void __vertical_print_vector(const std::vector<T> &v)
// {
//     cerr << "Printing vector of size " << v.size() << ":\nSTART [" << endl;
//     for (auto &elem : v)
//     {
//         cerr << hex << elem << "\n";
//     }
//     cerr << "] END" << endl;
// }

// Class definitions
class CPU
{
public:
    ADDR_TYPE pc;
    ADDR_TYPE npc;
    INSTR_TYPE instr;
    std::vector<REG_TYPE> reg;
    std::vector<MEM_TYPE>  * mem;

    CPU(std::vector<MEM_TYPE> &mem_block)
    {
        pc = ADDR_INSTR_OFFSET; // PC starts at beginning of executable memory
        npc = ADDR_INSTR_OFFSET + 1;
        instr = mem_block[ADDR_INSTR_OFFSET]; //start from first
        mem = &mem_block; // Pointer to memory block
        reg.resize(REGISTER_SIZE, 0);
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