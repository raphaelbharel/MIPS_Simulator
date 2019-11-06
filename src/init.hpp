// This file contains constant defitions and includes

#ifndef SETUP_H

#define SETUP_H

#include <cstdlib>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <iterator>
#include <cmath>
#include <bitset>

#define ADDR_NULL 0x00000000
#define ADDR_INSTR_LENGTH 0x400000//0x1000000 / 4 
#define ADDR_INSTR_OFFSET 0x4000000//0x10000000 / 4 
#define ADDR_DATA 0x8000000//0x20000000 / 4
#define ADDR_DATA_OFFSET 0x1000000//0x4000000 / 4
#define ADDR_GETC 0xC000000//0x30000000 / 4
#define ADDR_PUTC 0xC000001//0x30000004 / 4
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

class State
{
public:
    ADDR_TYPE pc;
    ADDR_TYPE npc;
    INSTR_TYPE instr;
    std::vector<INSTR_TYPE> reg;
    State(std::vector<MEM_TYPE> &mem_block)
    {
        pc = ADDR_INSTR_OFFSET; // PC starts at beginning of executable memory
        npc = ADDR_INSTR_OFFSET;
        instr = mem_block[ADDR_INSTR_OFFSET]; //start from first 
        initialize_regs();
    }
    void display()
    {
        std::cerr << std::hex << "pc: " << pc << std::endl;
        std::cerr << std::hex << "npc: " << npc << std::endl;
        std::cerr << std::hex << "instr: " << instr << std::endl;
    }
    void initialize_regs()
    {
        //ADDR_TYPE address = ADDR_DATA_OFFSET; //place on mem_block?
        for (int i = 0; i < REGISTER_SIZE; i++)
        {
            reg.push_back(0);
        }
        reg.resize(32);
    }

    void view_regs()
    {
        for (int index = 0; index<REGISTER_SIZE;index++)
        {
            std::cerr << "$" << index << " : " << reg[index] << std::endl;
        }
    }
    void update()
    {
        pc = npc; // Update the program
    }

private:
};

#endif