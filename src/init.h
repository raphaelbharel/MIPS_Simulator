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
#define ADDR_INSTR 0x10000000
#define ADDR_INSTR_OFFSET 0x1000000
#define ADDR_DATA 0x20000000
#define ADDR_DATA_OFFSET 0x4000000
#define ADDR_GETC 0x30000000
#define ADDR_PUTC 0x30000004
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
#define IMEM_SIZE 0x4000000

typedef uint32_t INSTR_TYPE;
typedef uint32_t ADDR_TYPE;
typedef char BUFFER_TYPE;
typedef std::pair<ADDR_TYPE, INSTR_TYPE> MEM_TYPE;

class State
{
public:
    ADDR_TYPE pc;
    ADDR_TYPE npc;
    ADDR_TYPE addr;
    INSTR_TYPE instr;
    State(std::vector<MEM_TYPE> &imem)
    {
        pc = ADDR_INSTR; // PC starts at beginning of executable memory
        npc = ADDR_INSTR + 4;
        addr = imem[0].first;
        instr = imem[0].second;
    }
    void display() {
        std::cerr <<std::hex<< "pc: " << pc << std::endl;
        std::cerr <<std::hex<< "npc: " << npc << std::endl;
        std::cerr <<std::hex<< "addr: " << addr << std::endl;
        std::cerr <<std::hex<< "instr: " << instr << std::endl;
    }

private:
};

#endif