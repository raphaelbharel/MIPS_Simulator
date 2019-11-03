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
        case 0x00000008:
            addi(S, src1, dest, sx_adata);
            return 1;
        case 0x00000009:
            addiu(S, src1, dest, sx_adata);
            return 1;
        case 0x0000000C:
            // andi(S, src1, dest, adata);
            return 1;
        case 0x00000004:
            // beq(S, src1, dest, sx_adata);
            return 1;
        case 0x00000005:
            // bne(S, src1, dest, sx_adata);
            return 1;
        case 0x00000024:
            // lbu(S, src1, dest, sx_adata);
            return 1;
        case 0x00000020:
            // lb(S, src1, dest, sx_adata);
            return 1;
        case 0x00000025:
            // lhu(S, src1, dest, sx_adata);
            return 1;
        case 0x00000021:
            // lh(S, src1, dest, sx_adata);
            return 1;
        case 0x0000000F:
            // lui(S, src1, dest, adata);
            return 1;
        case 0x00000023:
            // lw(S, src1, dest, sx_adata);
            return 1;
        case 0x00000022:
            // lwl(S, src1, dest, sx_adata);
            return 1;
        case 0x00000026:
            // lwr(S, src1, dest, sx_adata);
            return 1;
        case 0x00000028:
            // sb(S, src1, dest, sx_adata);
            return 1;
        case 0x00000029:
            // sh(S, src1, dest, sx_adata);
            return 1;
        case 0x0000002B:
            // sw(S, src1, dest, sx_adata);
            return 1;
        case 0x0000000A:
            // slti(S, src1, dest, sx_adata);
            return 1;
        case 0x0000000B:
            // sltiu(S, src1, dest, sx_adata);
            return 1;
        case 0x0000000E:
            // xori(S, src1, dest, adata);
            return 1;
        case 0x0000000D:
            // ori(S, src1, dest, adata);
            return 1;
        case 0x00000007:
            // bgtz(S, src1, dest, sx_adata);
            return 1;
        case 0x00000006:
            // blez(S, src1, dest, sx_adata);
            return 1;
        case 0x00000001:
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
