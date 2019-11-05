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

    State *S;

    j_type_instructions(State &cpu_state)
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
        std::cout << "adata: " << std::bitset<J_ADDRESS_SIZE>(jdata) << std::endl;
    }
    int execute();
    //COMPLEXITY 3
    void j(State *&S, INSTR_TYPE &jdata);
    //COMPLEXITY 4
    void jal(State *&S, INSTR_TYPE &jdata);

private:
};
#endif
