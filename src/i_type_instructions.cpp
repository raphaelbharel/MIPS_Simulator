// This file contains the function definitions for I type instructions
#include "i_type_instructions.hpp"
using namespace std;

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
    idata = (S->instr & 0xFFFF);
    // Sign extend 16bit immediate
    if (idata >> 15)
    {
        sx_idata = idata | 0xFFFF0000;
    }
    else
    {
        sx_idata = idata;
    }

    switch (code)
    {
    case 0x8:
        addi(S, src1, dest, sx_idata);
        return 1;
    case 0x9:
        addiu(S, src1, dest, sx_idata);
        return 1;
    case 0xC:
        // andi(S, src1, dest, idata);
        return 1;
    case 0x4:
        // beq(S, src1, dest, sx_idata);
        return 1;
    case 0x5:
        // bne(S, src1, dest, sx_idata);
        return 1;
    case 0x24:
        // lbu(S, src1, dest, sx_idata);
        return 1;
    case 0x20:
        // lb(S, src1, dest, sx_idata);
        return 1;
    case 0x25:
        // lhu(S, src1, dest, sx_idata);
        return 1;
    case 0x21:
        // lh(S, src1, dest, sx_idata);
        return 1;
    case 0xF:
        // lui(S, src1, dest, idata);
        return 1;
    case 0x23:
        // lw(S, src1, dest, sx_idata);
        return 1;
    case 0x22:
        // lwl(S, src1, dest, sx_idata);
        return 1;
    case 0x26:
        // lwr(S, src1, dest, sx_idata);
        return 1;
    case 0x28:
        // sb(S, src1, dest, sx_idata);
        return 1;
    case 0x29:
        // sh(S, src1, dest, sx_idata);
        return 1;
    case 0x2B:
        // sw(S, src1, dest, sx_idata);
        return 1;
    case 0xA:
        // slti(S, src1, dest, sx_idata);
        return 1;
    case 0xB:
        // sltiu(S, src1, dest, sx_idata);
        return 1;
    case 0xE:
        // xori(S, src1, dest, idata);
        return 1;
    case 0xD:
        // ori(S, src1, dest, idata);
        return 1;
    case 0x7:
        // bgtz(S, src1, dest, sx_idata);
        return 1;
    case 0x6:
        // blez(S, src1, dest, sx_idata);
        return 1;
    case 0x1:
        // bdecoder(S, src1, dest, sx_idata);
        return 1;
    default:
        return -12;
    }
}

void i_type_instructions::addi(State *&S, INSTR_TYPE &src1, INSTR_TYPE &dest, INSTR_TYPE &sx_idata)
{
    cerr << "ADDI" << endl;
}

void i_type_instructions::addiu(State *&S, INSTR_TYPE &src1, INSTR_TYPE &dest, INSTR_TYPE &sx_idata)
{
    cerr << "ADDIU" << endl;
    S->reg[dest].second = S->reg[src1].second + sx_idata;
    S->display();
}

void i_type_instructions::andi(State *&S, INSTR_TYPE &src1, INSTR_TYPE &dest, INSTR_TYPE &idata)
{
}
void i_type_instructions::beq(State *&S, INSTR_TYPE &src1, INSTR_TYPE &dest, INSTR_TYPE &sx_idata)
{
}
void i_type_instructions::bne(State *&S, INSTR_TYPE &src1, INSTR_TYPE &dest, INSTR_TYPE &sx_idata)
{
}
void i_type_instructions::lbu(State *&S, INSTR_TYPE &src1, INSTR_TYPE &dest, INSTR_TYPE &sx_idata)
{
}
void i_type_instructions::lb(State *&S, INSTR_TYPE &src1, INSTR_TYPE &dest, INSTR_TYPE &sx_idata)
{
}
void i_type_instructions::lhu(State *&S, INSTR_TYPE &src1, INSTR_TYPE &dest, INSTR_TYPE &sx_idata)
{
}
void i_type_instructions::lh(State *&S, INSTR_TYPE &src1, INSTR_TYPE &dest, INSTR_TYPE &sx_idata)
{
}
void i_type_instructions::lui(State *&S, INSTR_TYPE &src1, INSTR_TYPE &dest, INSTR_TYPE &idata)
{
}
void i_type_instructions::lw(State *&S, INSTR_TYPE &src1, INSTR_TYPE &dest, INSTR_TYPE &sx_idata)
{
}
void i_type_instructions::lwl(State *&S, INSTR_TYPE &src1, INSTR_TYPE &dest, INSTR_TYPE &sx_idata)
{
}
void i_type_instructions::lwr(State *&S, INSTR_TYPE &src1, INSTR_TYPE &dest, INSTR_TYPE &sx_idata)
{
}
void i_type_instructions::ori(State *&S, INSTR_TYPE &src1, INSTR_TYPE &dest, INSTR_TYPE &idata)
{
}
void i_type_instructions::xori(State *&S, INSTR_TYPE &src1, INSTR_TYPE &dest, INSTR_TYPE &idata)
{
}
void i_type_instructions::slti(State *&S, INSTR_TYPE &src1, INSTR_TYPE &dest, INSTR_TYPE &sx_idata)
{
}
void i_type_instructions::sltiu(State *&S, INSTR_TYPE &src1, INSTR_TYPE &dest, INSTR_TYPE &sx_idata)
{
}
void i_type_instructions::sb(State *&S, INSTR_TYPE &src1, INSTR_TYPE &dest, INSTR_TYPE &sx_idata)
{
}
void i_type_instructions::sh(State *&S, INSTR_TYPE &src1, INSTR_TYPE &dest, INSTR_TYPE &sx_idata)
{
}
void i_type_instructions::sw(State *&S, INSTR_TYPE &src1, INSTR_TYPE &dest, INSTR_TYPE &sx_idata)
{
}
void i_type_instructions::bgez(State *&S, INSTR_TYPE &src1, INSTR_TYPE &sx_idata)
{
}
void i_type_instructions::bgezal(State *&S, INSTR_TYPE &src1, INSTR_TYPE &sx_idata)
{
}
void i_type_instructions::bgtz(State *&S, INSTR_TYPE &src1, INSTR_TYPE &dest, INSTR_TYPE &sx_idata)
{
}
void i_type_instructions::blez(State *&S, INSTR_TYPE &src1, INSTR_TYPE &dest, INSTR_TYPE &sx_idata)
{
}
void i_type_instructions::bltz(State *&S, INSTR_TYPE &src1, INSTR_TYPE &sx_idata)
{
}
void i_type_instructions::bltzal(State *&S, INSTR_TYPE &src1, INSTR_TYPE &sx_idata)
{
}
void i_type_instructions::bdecoder(State *&S, INSTR_TYPE &src1, INSTR_TYPE &dest, INSTR_TYPE &sx_idata)
{
}
