// This file contains the function declarations for I type instructions
#ifndef I_TYPE_INSTRUCTIONS
#define I_TYPE_INSTRUCTIONS
#include "headers.h"
using namespace std;

class i_type_instructions{
    public:
        i_type_instructions(State &cpu_state) {
            cerr << "i_type_instruction state: " << endl;
            State* S = &cpu_state;
            cerr <<hex<< "pc: " << S->pc << endl;
            cerr <<hex<< "npc: " << S->npc << endl;
            cerr <<hex<< "addr: " << S->addr << endl;
            cerr <<hex<< "instr: " << S->instr << endl;

        }
    private:
};

#endif