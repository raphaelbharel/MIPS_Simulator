// This file contains the function declarations for R type instructions
#ifndef R_TYPE_INSTRUCTIONS
#define R_TYPE_INSTRUCTIONS
#include "headers.hpp"
using namespace std;

class r_type_instructions{
    public:
        uint32_t code = 0;
        uint32_t src1 = 0;
        uint32_t src2 = 0;
        uint32_t dest = 0;
        uint32_t shift = 0;
        uint32_t func = 0;
        State* S;

        r_type_instructions(State& cpu_state) {
            S = &cpu_state;
        }

        void display(){
            cerr << "r_type_instruction state: " << endl;
            cerr <<hex<< "pc: " << S->pc << endl;
            cerr <<hex<< "npc: " << S->npc << endl;
            cerr <<hex<< "addr: " << S->addr << endl;
            cerr <<hex<< "instr: " << S->instr << endl;
            cout << "code: " << bitset<CODE_SIZE>(code) << endl;
            cout << "src1: " << bitset<SRC1_SIZE>(src1) << endl;
            cout << "src2: " << bitset<SRC2_SIZE>(src2) << endl;
            cout << "dest: " << bitset<DEST_SIZE>(dest) << endl;
            cout << "shift: " << bitset<SHIFT_SIZE>(shift) << endl;
            cout << "funct: " << bitset<FUNC_SIZE>(func) << endl;
        }
        int execute();

        //COMPLEXITY 1
        void addu(State* &S, INSTR_TYPE& src1, INSTR_TYPE& src2, INSTR_TYPE& dest, INSTR_TYPE& shift, INSTR_TYPE& func);
        void and(State* &S, INSTR_TYPE& src1, INSTR_TYPE& src2, INSTR_TYPE& dest, INSTR_TYPE& shift, INSTR_TYPE& func);
        void jr(State* &S, INSTR_TYPE& src1, INSTR_TYPE& src2, INSTR_TYPE& dest, INSTR_TYPE& shift, INSTR_TYPE& func);
        void or(State* &S, INSTR_TYPE& src1, INSTR_TYPE& src2, INSTR_TYPE& dest, INSTR_TYPE& shift, INSTR_TYPE& func);
        void sltu(State* &S, INSTR_TYPE& src1, INSTR_TYPE& src2, INSTR_TYPE& dest, INSTR_TYPE& shift, INSTR_TYPE& func);
        void subu();
        //COMPLEXITY 2
        void xor();        
        void add(State* &S, INSTR_TYPE& src1, INSTR_TYPE& src2, INSTR_TYPE& dest, INSTR_TYPE& shift, INSTR_TYPE& func);
        void sll(State* &S, INSTR_TYPE& src1, INSTR_TYPE& src2, INSTR_TYPE& dest, INSTR_TYPE& shift, INSTR_TYPE& func);
        void slt(State* &S, INSTR_TYPE& src1, INSTR_TYPE& src2, INSTR_TYPE& dest, INSTR_TYPE& shift, INSTR_TYPE& func);
        void sra(State* &S, INSTR_TYPE& src1, INSTR_TYPE& src2, INSTR_TYPE& dest, INSTR_TYPE& shift, INSTR_TYPE& func);
        void srav(State* &S, INSTR_TYPE& src1, INSTR_TYPE& src2, INSTR_TYPE& dest, INSTR_TYPE& shift, INSTR_TYPE& func);
        void srl(State* &S, INSTR_TYPE& src1, INSTR_TYPE& src2, INSTR_TYPE& dest, INSTR_TYPE& shift, INSTR_TYPE& func);
        void sub(State* &S, INSTR_TYPE& src1, INSTR_TYPE& src2, INSTR_TYPE& dest, INSTR_TYPE& shift, INSTR_TYPE& func);
        //COMPLEXITY 3
        void mfhi(State* &S, INSTR_TYPE& src1, INSTR_TYPE& src2, INSTR_TYPE& dest, INSTR_TYPE& shift, INSTR_TYPE& func);
        void mflo(State* &S, INSTR_TYPE& src1, INSTR_TYPE& src2, INSTR_TYPE& dest, INSTR_TYPE& shift, INSTR_TYPE& func);
        void mthi(State* &S, INSTR_TYPE& src1, INSTR_TYPE& src2, INSTR_TYPE& dest, INSTR_TYPE& shift, INSTR_TYPE& func);
        void mtlo(State* &S, INSTR_TYPE& src1, INSTR_TYPE& src2, INSTR_TYPE& dest, INSTR_TYPE& shift, INSTR_TYPE& func);
        void sllv(State* &S, INSTR_TYPE& src1, INSTR_TYPE& src2, INSTR_TYPE& dest, INSTR_TYPE& shift, INSTR_TYPE& func);
        void srlv(State* &S, INSTR_TYPE& src1, INSTR_TYPE& src2, INSTR_TYPE& dest, INSTR_TYPE& shift, INSTR_TYPE& func);
        //COMPLEXITY 4
        void div(State* &S, INSTR_TYPE& src1, INSTR_TYPE& src2, INSTR_TYPE& dest, INSTR_TYPE& shift, INSTR_TYPE& func);
        void divu(State* &S, INSTR_TYPE& src1, INSTR_TYPE& src2, INSTR_TYPE& dest, INSTR_TYPE& shift, INSTR_TYPE& func);
        void jalr(State* &S, INSTR_TYPE& src1, INSTR_TYPE& src2, INSTR_TYPE& dest, INSTR_TYPE& shift, INSTR_TYPE& func);
        void mult(State* &S, INSTR_TYPE& src1, INSTR_TYPE& src2, INSTR_TYPE& dest, INSTR_TYPE& shift, INSTR_TYPE& func);
        void multu(State* &S, INSTR_TYPE& src1, INSTR_TYPE& src2, INSTR_TYPE& dest, INSTR_TYPE& shift, INSTR_TYPE& func);

    private:
};

#endif