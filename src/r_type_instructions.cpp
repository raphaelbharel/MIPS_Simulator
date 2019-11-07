// This file contains the function definitions for R type instructions
#include "r_type_instructions.hpp"
using namespace std;

int r_type_instructions::execute()
{
    /*
	Opcode - 6 bits
	Source 1 - 5 bits
  Source 2 - 5 bits
	Dest - 5 bits
  Shift - 5 bits
  Function - 6 bits
	*/

    cerr << ">> Executing R type instruction ";
    code = (S->instr & 0xFC000000) >> 26; //right shift 26
    src1 = (S->instr & 0x3E00000) >> 21;
    src2 = (S->instr & 0x1F0000) >> 16;
    dest = (S->instr & 0xF800) >> 11;
    shift = (S->instr & 0x7C0) >> 6;
    func = (S->instr & 0x3F);

    switch (func)
    {
    case 0x21:
        //void addu(S, src1, src2, dest, shift, func);
        return 1;
    case 0x44:
        //void and(S, src1, src2, dest, shift, func);
        return 1;
    case 0x8:
        //jr(S, src1, src2, dest, shift, func);
        return 1;
    case 0x25:
        // or(S, src1, src2, dest, shift, func);
        return 1;
    case 0x2B:
        // sltu(S, src1, src2, dest, shift, func);
        return 1;

    //Complexity 2
    case 0x23:
        // subu(S, src1, src2, dest, shift, func);
        return 1;
    case 0x26:
        // xor(S, src1, src2, dest, shift, func);
        return 1;
    case 0x20:
        // add(S, src1, src2, dest, shift, func);
        return 1;
    case 0x0:
        // sll(S, src1, src2, dest, shift, func);
        return 1;
    case 0x2A:
        // slt(S, src1, src2, dest, shift, func);
        return 1;
    case 0x3:
        // sra(S, src1, src2, dest, shift, func);
        return 1;
    case 0x7:
        // srav(S, src1, src2, dest, shift, func);
        return 1;
    case 0x2:
        // srl(S, src1, src2, dest, shift, func);
        return 1;
    case 0x22:
        // sub(S, src1, src2, dest, shift, func);
        return 1;

    //Complexity 3
    case 0x10:
        // mfhi(S, src1, src2, dest, shift, func);
        return 1;
    case 0x12:
        // mflo(S, src1, src2, dest, shift, func);
        return 1;
    case 0x11:
        // mthi(S, src1, src2, dest, shift, func);
        return 1;
    case 0x13:
        // mtlo(S, src1, src2, dest, shift, func);
        return 1;
    case 0x4:
        // sllv(S, src1, src2, dest, shift, func);
        return 1;
    case 0x6:
        // srlv(S, src1, src2, dest, shift, func);
        return 1;

    //Complexity 4
    case 0x1A:
        // div(S, src1, src2, dest, shift, func);
        return 1;
    case 0x1B:
        // divu(S, src1, src2, dest, shift, func);
        return 1;
    case 0x5:
        // jalr(S, src1, src2, dest, shift, func);
        return 1;
    case 0x18:
        // mult(S, src1, src2, dest, shift, func);
        return 1;
    case 0x19:
        // multu(S, src1, src2, dest, shift, func);
        return 1;
    default:
        return -12;
    }
}

// void r_type_instructions::jr(State *&S, INSTR_TYPE &src1, INSTR_TYPE &src2, INSTR_TYPE &dest, INSTR_TYPE &shift, INSTR_TYPE &func){    

//     if(S.reg[src1] % 4 != 0){
// 	    cerr << "Address Error Exception: target address in src1";
// 	}
// 	else{
// 		s.npc = s.reg[rs] / 4;
// 	}

// }