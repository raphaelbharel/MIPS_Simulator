// This file contains the function definitions for R type instructions
#include "r_type_instructions.hpp"
using namespace std;

int r_type_instructions::execute()
{
    /* Opcode - 6 bits, Source 1 - 5 bits, Source 2 - 5 bits, Dest - 5 bits, Shift - 5 bits, Function - 6 bits */

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
        ADDU(S, src1, src2, dest);
        return 1;
    case 0x44:
        AND(S, src1, src2, dest);
        return 1;
    case 0X8:
        JR(S, src1, src2, dest);
        return 1;
    case 0X25:
        OR(S, src1, src2, dest);
        return 1;
    case 0X2B:
        // SLTU(S, src1, src2, dest, shift, func);
        return 1;

    //COMPLEXITY 2
    case 0X23:
        // SUBU(S, src1, src2, dest, shift, func);
        return 1;
    case 0X26:
        // XOR(S, src1, src2, dest, shift, func);
        return 1;
    case 0X20:
        // ADD(S, src1, src2, dest, shift, func);
        return 1;
    case 0X0:
         SLL(S, src1, src2, dest, shift, func);
        return 1;
    case 0X2A:
        // SLT(S, src1, src2, dest, shift, func);
        return 1;
    case 0X3:
        // SRA(S, src1, src2, dest, shift, func);
        return 1;
    case 0X7:
        // SRAV(S, src1, src2, dest, shift, func);
        return 1;
    case 0X2:
        // SRL(S, src1, src2, dest, shift, func);
        return 1;
    case 0X22:
        // SUB(S, src1, src2, dest, shift, func);
        return 1;

    //COMPLEXITY 3
    case 0X10:
        // MFHI(S, src1, src2, dest, shift, func);
        return 1;
    case 0X12:
        // MFLO(S, src1, src2, dest, shift, func);
        return 1;
    case 0X11:
        // MTHI(S, src1, src2, dest, shift, func);
        return 1;
    case 0X13:
        // MTLO(S, src1, src2, dest, shift, func);
        return 1;
    case 0X4:
        // SLLV(S, src1, src2, dest, shift, func);
        return 1;
    case 0X6:
        // SRLV(S, src1, src2, dest, shift, func);
        return 1;

    //COMPLEXITY 4
    case 0X1A:
        // DIV(S, src1, src2, dest, shift, func);
        return 1;
    case 0X1B:
        // DIVU(S, src1, src2, dest, shift, func);
        return 1;
    case 0X5:
        // JALR(S, src1, src2, dest, shift, func);
        return 1;
    case 0X18:
        // MULT(S, src1, src2, dest, shift, func);
        return 1;
    case 0X19:
        // MULTU(S, src1, src2, dest, shift, func);
        return 1;
    default:
        return -12;
    }
}

void r_type_instructions::ADDU(State *&S, INSTR_TYPE &src1, INSTR_TYPE &src2, INSTR_TYPE &dest)
{
    cerr << "ADDU" << endl;
    S->reg[dest] = static_cast<uint32_t>(static_cast<uint32_t>(S->reg[src1]) + static_cast<uint32_t>(S->reg[src2]));
    S->npc = S->pc + 1;
}
void r_type_instructions::AND(State *&S, INSTR_TYPE &src1, INSTR_TYPE &src2, INSTR_TYPE &dest)
{
    cerr << "AND" << endl;
    S->reg[dest] = S->reg[src1] & S->reg[src2];
    S->npc = S->pc + 1;
}
void r_type_instructions::OR(State *&S, INSTR_TYPE &src1, INSTR_TYPE &src2, INSTR_TYPE &dest)
{
    cerr << "OR" << endl;
    S->reg[dest] = S->reg[src1] | S->reg[src2];
    S->npc = S->pc + 1;
}

void r_type_instructions::JR(State *&S, INSTR_TYPE &src1, INSTR_TYPE &src2, INSTR_TYPE &dest)
{
    cerr << "JR" << endl;
    // if (S->reg[src1] % 4 != 0)
    // {
    //     cerr << "Address Error Exception: target address in src1";
    // }
    // else
    {
        S->npc = S->reg[src1];
    }
}

void r_type_instructions::SLL(State *&S, INSTR_TYPE &src1, INSTR_TYPE &src2, INSTR_TYPE &dest, INSTR_TYPE &shift, INSTR_TYPE &func){
    cerr << "SLL" << endl;
    S->reg[dest] = S->reg[src2] << shift;
    S->npc = S->pc + 1;
}

// void r_type_instructions::SLTU(State *&S, INSTR_TYPE &src1, INSTR_TYPE &src2, INSTR_TYPE &dest, INSTR_TYPE &shift, INSTR_TYPE &func)
// {
//     cerr << "SLTU" << endl;
// }

void r_type_instructions::SUBU(State *&S, INSTR_TYPE &src1, INSTR_TYPE &src2, INSTR_TYPE &dest)
{
    cerr << "SUBU" << endl;
    S->reg[dest] = static_cast<uint32_t>(static_cast<uint32_t>(S->reg[src1]) - static_cast<uint32_t>(S->reg[src2]));
    S->npc = S->pc + 1;
}
void r_type_instructions::XOR(State *&S, INSTR_TYPE &src1, INSTR_TYPE &src2, INSTR_TYPE &dest)
{
    cerr << "XOR" << endl;
    S->reg[dest] = S->reg[src1] ^ S->reg[src2];
    S->npc = S->pc + 1;
}
void r_type_instructions::ADD(State *&S, INSTR_TYPE &src1, INSTR_TYPE &src2, INSTR_TYPE &dest)
{
    cerr << "ADD" << endl;
    S->reg[dest] = S->reg[src1] + S->reg[src2]; // TODO, OVERFLOWS
    S->npc = S->pc + 1;
}

// void r_type_instructions::SLT(State *&S, INSTR_TYPE &src1, INSTR_TYPE &src2, INSTR_TYPE &dest, INSTR_TYPE &shift, INSTR_TYPE &func)
// {
//     cerr << "SLT" << endl;
// }
// void r_type_instructions::SRA(State *&S, INSTR_TYPE &src1, INSTR_TYPE &src2, INSTR_TYPE &dest, INSTR_TYPE &shift, INSTR_TYPE &func)
// {
//     cerr << "SRA" << endl;
// }
// void r_type_instructions::SRAV(State *&S, INSTR_TYPE &src1, INSTR_TYPE &src2, INSTR_TYPE &dest, INSTR_TYPE &shift, INSTR_TYPE &func)
// {
//     cerr << "SRAV" << endl;
// }
// void r_type_instructions::SRL(State *&S, INSTR_TYPE &src1, INSTR_TYPE &src2, INSTR_TYPE &dest, INSTR_TYPE &shift, INSTR_TYPE &func)
// {
//     cerr << "SRL" << endl;
// }
// void r_type_instructions::SUB(State *&S, INSTR_TYPE &src1, INSTR_TYPE &src2, INSTR_TYPE &dest, INSTR_TYPE &shift, INSTR_TYPE &func)
// {
//     cerr << "SUB" << endl;
// }
// void r_type_instructions::MFHI(State *&S, INSTR_TYPE &src1, INSTR_TYPE &src2, INSTR_TYPE &dest, INSTR_TYPE &shift, INSTR_TYPE &func)
// {
//     cerr << "MFHI" << endl;
// }
// void r_type_instructions::MFLO(State *&S, INSTR_TYPE &src1, INSTR_TYPE &src2, INSTR_TYPE &dest, INSTR_TYPE &shift, INSTR_TYPE &func)
// {
//     cerr << "MFLO" << endl;
// }
// void r_type_instructions::MTHI(State *&S, INSTR_TYPE &src1, INSTR_TYPE &src2, INSTR_TYPE &dest, INSTR_TYPE &shift, INSTR_TYPE &func)
// {
//     cerr << "MTHI" << endl;
// }
// void r_type_instructions::MTLO(State *&S, INSTR_TYPE &src1, INSTR_TYPE &src2, INSTR_TYPE &dest, INSTR_TYPE &shift, INSTR_TYPE &func)
// {
//     cerr << "MTLO" << endl;
// }
// void r_type_instructions::SLLV(State *&S, INSTR_TYPE &src1, INSTR_TYPE &src2, INSTR_TYPE &dest, INSTR_TYPE &shift, INSTR_TYPE &func)
// {
//     cerr << "SLLV" << endl;
// }
// void r_type_instructions::SRLV(State *&S, INSTR_TYPE &src1, INSTR_TYPE &src2, INSTR_TYPE &dest, INSTR_TYPE &shift, INSTR_TYPE &func)
// {
//     cerr << "SRLV" << endl;
// }
// void r_type_instructions::DIV(State *&S, INSTR_TYPE &src1, INSTR_TYPE &src2, INSTR_TYPE &dest, INSTR_TYPE &shift, INSTR_TYPE &func)
// {
//     cerr << "DIV" << endl;
// }
// void r_type_instructions::DIVU(State *&S, INSTR_TYPE &src1, INSTR_TYPE &src2, INSTR_TYPE &dest, INSTR_TYPE &shift, INSTR_TYPE &func)
// {
//     cerr << "DIVU" << endl;
// }
// void r_type_instructions::JALR(State *&S, INSTR_TYPE &src1, INSTR_TYPE &src2, INSTR_TYPE &dest, INSTR_TYPE &shift, INSTR_TYPE &func)
// {
//     cerr << "JALR" << endl;
// }
// void r_type_instructions::MULT(State *&S, INSTR_TYPE &src1, INSTR_TYPE &src2, INSTR_TYPE &dest, INSTR_TYPE &shift, INSTR_TYPE &func)
// {
//     cerr << "MULT" << endl;
// }
// void r_type_instructions::MULTU(State *&S, INSTR_TYPE &src1, INSTR_TYPE &src2, INSTR_TYPE &dest, INSTR_TYPE &shift, INSTR_TYPE &func)
// {
//     cerr << "MULTU" << endl;
// }
