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
    CPU *C;

    j_type_instructions(CPU &cpu_state)
    {
        C = &cpu_state;
    }

    void execute();
    void J(CPU *&C, INSTR_TYPE &jdata);
    void JAL(CPU *&C, INSTR_TYPE &jdata);

private:
};
#endif
