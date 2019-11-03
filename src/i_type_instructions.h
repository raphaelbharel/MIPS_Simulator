// This file contains the function declarations for I type instructions
#ifndef I_TYPE_INSTRUCTIONS
#define I_TYPE_INSTRUCTIONS
#include "headers.h"
using namespace std;

class i_type_instructions{
    public:
        uint32_t code;
        uint32_t src1;
        uint32_t dest;
        uint32_t adata;
        State* S;

        i_type_instructions(State& cpu_state) {
            S = &cpu_state;
        }

        void display(){
            cerr << "i_type_instruction state: " << endl;
            cerr <<hex<< "pc: " << S->pc << endl;
            cerr <<hex<< "npc: " << S->npc << endl;
            cerr <<hex<< "addr: " << S->addr << endl;
            cerr <<hex<< "instr: " << S->instr << endl;
            cout << "code: " << bitset<CODE_SIZE>(code) << endl;
            cout << "src1: " << bitset<SRC1_SIZE>(src1) << endl;
            cout << "dest: " << bitset<DEST_SIZE>(dest) << endl;
            cout << "adata: " << bitset<I_ADATA_SIZE>(adata) << endl;
        }
        int execute();

        
    private:
};

#endif

int i_type_instructions::execute()
{
    code = (S->instr & 0xFC000000) >> 26;
    src1 = (S->instr & 0x3E00000) >> 21;
    dest = (S->instr & 0x1F0000) >> 16;
    adata = (S->instr & 0xFFFF);
    switch (code)
    {
    case 0b001000:
        addi();
        return 1;
    default:
        return -12;
    }
}

void i_type_instructions::addi(){
    
}
