// This file contains the function declarations for I type instructions
#ifndef I_TYPE_INSTRUCTIONS
#define I_TYPE_INSTRUCTIONS
#include "headers.h"
using namespace std;
#endif

class i_type_instructions{
    public:
        uint32_t code = 0;
        uint32_t src1 = 0;
        uint32_t dest = 0;
        uint32_t adata = 0;
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
        void addi(State* &S, INSTR_TYPE& src1, INSTR_TYPE& dest, INSTR_TYPE& sx_adata);
        void addiu(State* &S, INSTR_TYPE& src1, INSTR_TYPE& dest, INSTR_TYPE& sx_adata);

        
    private:
};

int i_type_instructions::execute()
{
    /*
	Opcode - 6 bits
	Source 1 - 5 bits
	Dest - 5 bits
	Immediate constant - 16 bits
	*/

    cerr << ">> Executing I type instruction ";
    code = (S->instr & 0xFC000000) >> 26;
    src1 = (S->instr & 0x3E00000) >> 21;
    dest = (S->instr & 0x1F0000) >> 16;
    adata = (S->instr & 0xFFFF);
    // Sign extend 16bit immediate
    INSTR_TYPE sx_adata;
    if (adata >> 15)
    {
        sx_adata = adata | 0xFFFF0000;
    }
    else
    {
        sx_adata = adata;
    }
    
    switch (code) {
        case 0x8:
            addi(S, src1, dest, sx_adata);
            return 1;
        case 0x9:
            addiu(S, src1, dest, sx_adata);
            return 1;
        case 0xC:
            // andi(S, src1, dest, adata);
            return 1;
        case 0x4:
            // beq(S, src1, dest, sx_adata);
            return 1;
        case 0x5:
            // bne(S, src1, dest, sx_adata);
            return 1;
        case 0x24:
            // lbu(S, src1, dest, sx_adata);
            return 1;
        case 0x20:
            // lb(S, src1, dest, sx_adata);
            return 1;
        case 0x25:
            // lhu(S, src1, dest, sx_adata);
            return 1;
        case 0x21:
            // lh(S, src1, dest, sx_adata);
            return 1;
        case 0xF:
            // lui(S, src1, dest, adata);
            return 1;
        case 0x23:
            // lw(S, src1, dest, sx_adata);
            return 1;
        case 0x22:
            // lwl(S, src1, dest, sx_adata);
            return 1;
        case 0x26:
            // lwr(S, src1, dest, sx_adata);
            return 1;
        case 0x28:
            // sb(S, src1, dest, sx_adata);
            return 1;
        case 0x29:
            // sh(S, src1, dest, sx_adata);
            return 1;
        case 0x2B:
            // sw(S, src1, dest, sx_adata);
            return 1;
        case 0xA:
            // slti(S, src1, dest, sx_adata);
            return 1;
        case 0xB:
            // sltiu(S, src1, dest, sx_adata);
            return 1;
        case 0xE:
            // xori(S, src1, dest, adata);
            return 1;
        case 0xD:
            // ori(S, src1, dest, adata);
            return 1;
        case 0x7:
            // bgtz(S, src1, dest, sx_adata);
            return 1;
        case 0x6:
            // blez(S, src1, dest, sx_adata);
            return 1;
        case 0x1:
            // bdecoder(S, src1, dest, sx_adata);
            return 1;
        default:
            return -12;
    }
}

void i_type_instructions::addi(State* &S, INSTR_TYPE& src1, INSTR_TYPE& dest, INSTR_TYPE& sx_adata){
    cerr << "ADDI" <<endl;
    
}

void i_type_instructions::addiu(State* &S, INSTR_TYPE& src1, INSTR_TYPE& dest, INSTR_TYPE& sx_adata){
    cerr << "ADDIU" <<endl;
    (*S).display();
}
