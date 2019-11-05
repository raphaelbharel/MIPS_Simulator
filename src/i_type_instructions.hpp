// This file contains the function declarations for I type instructions
#ifndef I_TYPE_INSTRUCTIONS
#define I_TYPE_INSTRUCTIONS
#include "headers.hpp"

class i_type_instructions
{
public:
    uint32_t code = 0;
    uint32_t src1 = 0;
    uint32_t dest = 0;
    uint32_t adata = 0;
    State *S;

    i_type_instructions(State &cpu_state)
    {
        S = &cpu_state;
    }

    void display()
    {
        std::cerr << "i_type_instruction state: " << std::endl;
        std::cerr << std::hex << "pc: " << S->pc << std::endl;
        std::cerr << std::hex << "npc: " << S->npc << std::endl;
        std::cerr << std::hex << "addr: " << S->addr << std::endl;
        std::cerr << std::hex << "instr: " << S->instr << std::endl;
        std::cout << "code: " << std::bitset<CODE_SIZE>(code) << std::endl;
        std::cout << "src1: " << std::bitset<SRC1_SIZE>(src1) << std::endl;
        std::cout << "dest: " << std::bitset<DEST_SIZE>(dest) << std::endl;
        std::cout << "adata: " << std::bitset<I_ADATA_SIZE>(adata) << std::endl;
    }
    int execute();
    void addi(State *&S, INSTR_TYPE &src1, INSTR_TYPE &dest, INSTR_TYPE &sx_adata);
    void addiu(State *&S, INSTR_TYPE &src1, INSTR_TYPE &dest, INSTR_TYPE &sx_adata);

private:
};

#endif
