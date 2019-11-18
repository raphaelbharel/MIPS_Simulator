// This file contains the function declarations for J type instructions
#ifndef J_TYPE_INSTRUCTIONS
#define J_TYPE_INSTRUCTIONS
#include "headers.hpp"

class j_type_instructions
{
public:
    uint32_t code = 0;
    uint32_t jdata = 0;
    uint32_t sx_jdata = 0;
    bool DEBUG = 0;
    CPU *C;

    j_type_instructions(CPU &cpu_state, const bool &debug)
    {
        C = &cpu_state;
        DEBUG = debug;
    }

    void display()
    {
        std::cerr << "i_type_instruction state: " << std::endl;
        std::cerr << std::hex << "pc: " << C->pc << std::endl;
        std::cerr << std::hex << "npc: " << C->npc << std::endl;
        std::cerr << std::hex << "instr: " << C->instr << std::endl;
        std::cout << "code: " << std::bitset<CODE_SIZE>(code) << std::endl;
        std::cout << "adata: " << std::bitset<J_ADDRESS_SIZE>(jdata) << std::endl;
    }
    int execute();
    void J(CPU *&C, INSTR_TYPE &jdata);
    void JAL(CPU *&C, INSTR_TYPE &jdata);

private:
};
#endif
