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

typedef uint32_t INSTR_TYPE;
typedef uint32_t ADDR_TYPE;
typedef char BUFFER_TYPE;
typedef uint32_t MEM_TYPE;
typedef int32_t REG_TYPE;

class CPU
{
public:
    ADDR_TYPE pc;
    ADDR_TYPE npc;
    INSTR_TYPE instr;
    std::vector<REG_TYPE> reg;
    CPU(std::vector<MEM_TYPE> &mem_block)
    {
        pc = ADDR_INSTR_OFFSET; // PC starts at beginning of executable memory
        npc = ADDR_INSTR_OFFSET+1;
        instr = mem_block[ADDR_INSTR_OFFSET]; //start from first
        reg.resize(REGISTER_SIZE, 0);
    }
    void display()
    {
        std::cerr << "__DISPLAY__" << std::endl;
        std::cerr << std::hex << "pc: " << pc << std::endl;
        std::cerr << std::hex << "npc: " << npc << std::endl;
        std::cerr << std::hex << "instr: " << instr << std::endl;
    }

    void view_regs()
    {
        std::cerr << "__REGISTERS__" << std::endl;
        for (int index = 0; index < REGISTER_SIZE; index++)
        {
            std::cerr << "$" << index << " : " << reg[index] << std::endl;
        }
    }
    void update()
    {
        pc = npc; // Update the pc
        npc += 4; // Update next pc
        // Update instructions
    }

private:
};

#endif