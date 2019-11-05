// This file contains the function declarations for J type instructions
#ifndef J_TYPE_INSTRUCTIONS
#define J_TYPE_INSTRUCTIONS
// This file contains the function declarations for I type instructions
#include "headers.hpp"
using namespace std;

class j_type_instructions{
    public:
        uint32_t code = 0;
        uint32_t jdata = 0;
        State* S;

        j_type_instructions(State& cpu_state) {
            S = &cpu_state;
        }

        void display(){
            cerr << "i_type_instruction state: " << endl;
            cerr <<hex<< "pc: " << S->pc << endl;
            cerr <<hex<< "npc: " << S->npc << endl;
            cerr <<hex<< "addr: " << S->addr << endl;
            cerr <<hex<< "instr: " << S->instr << endl;
            cout << "code: " << bitset<CODE_SIZE>(code) << endl;
            cout << "adata: " << bitset<J_ADRESS_SIZE>(jdata) << endl;
        }
        int execute();
        //COMPLEXITY 3
        void j(State* &S, INSTR_TYPE& jdata);
        //COMPLEXITY 4
        void jal(State* &S, INSTR_TYPE& jdata);
        
    private:
};
#endif
