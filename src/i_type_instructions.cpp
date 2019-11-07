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
    case 0X8:
        // ADDI(S, src1, dest, sx_idata);
        return 1;
    case 0X9:
        ADDIU(S, src1, dest, sx_idata);
        return 1;
    case 0XC:
        ANDI(S, src1, dest, idata);
        return 1;
    case 0X4:
        // BEQ(S, src1, dest, sx_idata);
        return 1;
    case 0X5:
        // BNE(S, src1, dest, sx_idata);
        return 1;
    case 0X24:
        // LBU(S, src1, dest, sx_idata);
        return 1;
    case 0X20:
        // LB(S, src1, dest, sx_idata);
        return 1;
    case 0X25:
        // LHU(S, src1, dest, sx_idata);
        return 1;
    case 0X21:
        // LH(S, src1, dest, sx_idata);
        return 1;
    case 0XF:
        // LUI(S, src1, dest, idata);
        return 1;
    case 0X23:
        // LW(S, src1, dest, sx_idata);
        return 1;
    case 0X22:
        // LWL(S, src1, dest, sx_idata);
        return 1;
    case 0X26:
        // LWR(S, src1, dest, sx_idata);
        return 1;
    case 0X28:
        // SB(S, src1, dest, sx_idata);
        return 1;
    case 0X29:
        // SH(S, src1, dest, sx_idata);
        return 1;
    case 0X2B:
        // SW(S, src1, dest, sx_idata);
        return 1;
    case 0XA:
        // SLTI(S, src1, dest, sx_idata);
        return 1;
    case 0XB:
        // SLTIU(S, src1, dest, sx_idata);
        return 1;
    case 0XE:
        // XORI(S, src1, dest, idata);
        return 1;
    case 0XD:
        // ORI(S, src1, dest, idata);
        return 1;
    case 0X7:
        // BGTZ(S, src1, dest, sx_idata);
        return 1;
    case 0X6:
        // BLEZ(S, src1, dest, sx_idata);
        return 1;
    case 0X1:
        // BDECODER(S, src1, dest, sx_idata);
        return 1;
    default:
        return -12;
    }
}

// void i_type_instructions::addi(State *&S, INSTR_TYPE &src1, INSTR_TYPE &dest, INSTR_TYPE &sx_idata)
// {
//     cerr << "ADDI" << endl;
// }

void i_type_instructions::ADDIU(State *&S, INSTR_TYPE &src1, INSTR_TYPE &dest, INSTR_TYPE &sx_idata)
{
    cerr << "ADDIU" << endl;
    S->reg[dest] = static_cast<uint32_t>(static_cast<uint32_t>(S->reg[src1]) + sx_idata);
    S->npc = S->pc + 1;
}

void i_type_instructions::ANDI(State *&S, INSTR_TYPE &src1, INSTR_TYPE &dest, INSTR_TYPE &idata)
{
    cerr << "ANDI" << endl;
    int32_t temp = S->reg[src1]; //register might contained signed number
    S->npc = S->pc + 1;
}

void i_type_instructions::BEQ(State *&S, INSTR_TYPE &src1, INSTR_TYPE &dest, INSTR_TYPE &sx_idata)
{
    cerr << "BEQ" << endl;
}
void i_type_instructions::BNE(State *&S, INSTR_TYPE &src1, INSTR_TYPE &dest, INSTR_TYPE &sx_idata)
{
    cerr << "BNE" << endl;
}
void i_type_instructions::LBU(State *&S, INSTR_TYPE &src1, INSTR_TYPE &dest, INSTR_TYPE &sx_idata)
{
    cerr << "LBU" << endl;
}
void i_type_instructions::LB(State *&S, INSTR_TYPE &src1, INSTR_TYPE &dest, INSTR_TYPE &sx_idata)
{
    cerr << "LB" << endl;
}
void i_type_instructions::LHU(State *&S, INSTR_TYPE &src1, INSTR_TYPE &dest, INSTR_TYPE &sx_idata)
{
    cerr << "LHU" << endl;
}
void i_type_instructions::LH(State *&S, INSTR_TYPE &src1, INSTR_TYPE &dest, INSTR_TYPE &sx_idata)
{
    cerr << "LH" << endl;
}
void i_type_instructions::LUI(State *&S, INSTR_TYPE &src1, INSTR_TYPE &dest, INSTR_TYPE &idata)
{
    cerr << "LUI" << endl;
}
void i_type_instructions::LW(State *&S, INSTR_TYPE &src1, INSTR_TYPE &dest, INSTR_TYPE &sx_idata)
{
    cerr << "LW" << endl;
}
void i_type_instructions::LWL(State *&S, INSTR_TYPE &src1, INSTR_TYPE &dest, INSTR_TYPE &sx_idata)
{
    cerr << "LWL" << endl;
}
void i_type_instructions::LWR(State *&S, INSTR_TYPE &src1, INSTR_TYPE &dest, INSTR_TYPE &sx_idata)
{
    cerr << "LWR" << endl;
}
void i_type_instructions::ORI(State *&S, INSTR_TYPE &src1, INSTR_TYPE &dest, INSTR_TYPE &idata)
{
    cerr << "ORI" << endl;
}
void i_type_instructions::XORI(State *&S, INSTR_TYPE &src1, INSTR_TYPE &dest, INSTR_TYPE &idata)
{
    cerr << "XORI" << endl;
}
void i_type_instructions::SLTI(State *&S, INSTR_TYPE &src1, INSTR_TYPE &dest, INSTR_TYPE &sx_idata)
{
    cerr << "SLTI" << endl;
}
void i_type_instructions::SLTIU(State *&S, INSTR_TYPE &src1, INSTR_TYPE &dest, INSTR_TYPE &sx_idata)
{
    cerr << "SLTIU" << endl;
}
void i_type_instructions::SB(State *&S, INSTR_TYPE &src1, INSTR_TYPE &dest, INSTR_TYPE &sx_idata)
{
    cerr << "SB" << endl;
}
void i_type_instructions::SH(State *&S, INSTR_TYPE &src1, INSTR_TYPE &dest, INSTR_TYPE &sx_idata)
{
    cerr << "SH" << endl;
}
void i_type_instructions::SW(State *&S, INSTR_TYPE &src1, INSTR_TYPE &dest, INSTR_TYPE &sx_idata)
{
    cerr << "SW" << endl;
}
void i_type_instructions::BGEZ(State *&S, INSTR_TYPE &src1, INSTR_TYPE &sx_idata)
{
    cerr << "BGEZ" << endl;
}
void i_type_instructions::BGEZAL(State *&S, INSTR_TYPE &src1, INSTR_TYPE &sx_idata)
{
    cerr << "BGEZAL" << endl;
}
void i_type_instructions::BGTZ(State *&S, INSTR_TYPE &src1, INSTR_TYPE &dest, INSTR_TYPE &sx_idata)
{
    cerr << "BGTZ" << endl;
}
void i_type_instructions::BLEZ(State *&S, INSTR_TYPE &src1, INSTR_TYPE &dest, INSTR_TYPE &sx_idata)
{
    cerr << "BLEZ" << endl;
}
void i_type_instructions::BLTZ(State *&S, INSTR_TYPE &src1, INSTR_TYPE &sx_idata)
{
    cerr << "BLTZ" << endl;
}
void i_type_instructions::BLTZAL(State *&S, INSTR_TYPE &src1, INSTR_TYPE &sx_idata)
{
    cerr << "BLTZAL" << endl;
}
void i_type_instructions::BDECODER(State *&S, INSTR_TYPE &src1, INSTR_TYPE &dest, INSTR_TYPE &sx_idata)
{
    cerr << "BDECODER" << endl;
}
