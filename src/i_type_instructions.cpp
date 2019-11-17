// This file contains the function definitions for I type instructions
#include "i_type_instructions.hpp"
using namespace std;

int i_type_instructions::execute()
{
    /* Opcode - 6 bits, Source 1 - 5 bits, Dest - 5 bits, Immediate constant - 16 bits */

    cerr << ">> Executing I type instruction ";
    code = (C->instr & 0xFC000000) >> 26;
    src1 = (C->instr & 0x3E00000) >> 21;
    dest = (C->instr & 0x1F0000) >> 16;
    idata = (C->instr & 0xFFFF);
    // Sign extend 16bit immediate
    sx_idata = sign_extend_int32(idata, 16);

    switch (code)
    {
    case 0X8:
        ADDI(C, src1, dest, sx_idata);
        return 1;
    case 0X9:
        ADDIU(C, src1, dest, sx_idata);
        return 1;
    case 0XC:
        ANDI(C, src1, dest, idata);
        return 1;
    case 0X4:
        BEQ(C, src1, dest, sx_idata);
        return 1;
    case 0X5:
        BNE(C, src1, dest, sx_idata);
        return 1;
    case 0X24:
        // LBU(C , src1, dest, sx_idata);
        return 1;
    case 0X20:
        // LB(C , src1, dest, sx_idata);
        return 1;
    case 0X25:
        // LHU(C , src1, dest, sx_idata);
        return 1;
    case 0X21:
        // LH(C , src1, dest, sx_idata);
        return 1;
    case 0XF:
        LUI(C, src1, dest, idata);
        return 1;
    case 0X23:
        LW(C, src1, dest, sx_idata);
        return 1;
    case 0X22:
        // LWL(C , src1, dest, sx_idata);
        return 1;
    case 0X26:
        // LWR(C , src1, dest, sx_idata);
        return 1;
    case 0X28:
        // SB(C , src1, dest, sx_idata);
        return 1;
    case 0X29:
        // SH(C, src1, dest, sx_idata);
        return 1;
    case 0X2B:
        SW(C, src1, dest, sx_idata);
        return 1;
    case 0XA:
        // SLTI(C, src1, dest, sx_idata);
        return 1;
    case 0XB:
        // SLTIU(C, src1, dest, sx_idata);
        return 1;
    case 0XE:
        XORI(C, src1, dest, idata);
        return 1;
    case 0XD:
        ORI(C, src1, dest, idata);
        return 1;
    case 0X7:
        // BGTZ(C, src1, dest, sx_idata);
        return 1;
    case 0X6:
        // BLEZ(C, src1, dest, sx_idata);
        return 1;
    case 0X1:
        // BDECODER(C, src1, dest, sx_idata);
        return 1;
    default:
        return -12;
    }
}

void i_type_instructions::ADDI(CPU *&C, INSTR_TYPE &src1, INSTR_TYPE &dest, int32_t &sx_idata)
{
    cerr << "ADDI" << endl;
    if (((C->reg[src1] < 0) && (sx_idata < 0) && (C->reg[src1] + sx_idata >= 0)) ||
        ((C->reg[src1] > 0) && (sx_idata > 0) && (C->reg[src1] + sx_idata <= 0)))
    {
        throw(static_cast<int>(ARITHMETIC_EXIT_CODE));
    }
    else
    {
        C->reg[dest] = C->reg[src1] + sx_idata;
        C->npc = C->npc + 1;
    }
}

void i_type_instructions::ADDIU(CPU *&C, INSTR_TYPE &src1, INSTR_TYPE &dest, int32_t &sx_idata)
{
    cerr << "ADDIU" << endl;
    C->reg[dest] = static_cast<uint32_t>(static_cast<uint32_t>(C->reg[src1]) + sx_idata);
    C->npc = C->npc + 1;
}

void i_type_instructions::ANDI(CPU *&C, INSTR_TYPE &src1, INSTR_TYPE &dest, INSTR_TYPE &idata)
{
    cerr << "ANDI" << endl;
    C->reg[dest] = C->reg[src1] & idata;
    C->npc = C->npc + 1;
}

void i_type_instructions::BEQ(CPU *&C, INSTR_TYPE &src1, INSTR_TYPE &dest, int32_t &sx_idata)
{
    cerr << "BEQ" << endl;
    if (C->reg[src1] == C->reg[dest])
    {
        C->npc = C->npc + sx_idata;
    }
    else
    {
        C->npc = C->npc + 1;
    }
}
void i_type_instructions::BNE(CPU *&C, INSTR_TYPE &src1, INSTR_TYPE &dest, int32_t &sx_idata)
{
    cerr << "BNE" << endl;
    if (C->reg[src1] != C->reg[dest])
    {
        C->npc = C->npc + sx_idata; // Supposedly 16bit shifted left (x4) but since our memory space is divided by 4, don't need to shift
    }
    else
    {
        C->npc = C->npc + 1;
    }
}
// void i_type_instructions::LBU(CPU *&C, INSTR_TYPE &src1, INSTR_TYPE &dest, int32_t &sx_idata)
// {
//     cerr << "LBU" << endl; // Load byte unsigned LBU $1 16bOFFSET($2)
// }
// void i_type_instructions::LB(CPU *&C, INSTR_TYPE &src1, INSTR_TYPE &dest, int32_t &sx_idata)
// {
//     cerr << "LB" << endl;
// }
// void i_type_instructions::LHU(CPU *&C, INSTR_TYPE &src1, INSTR_TYPE &dest, int32_t &sx_idata)
// {
//     cerr << "LHU" << endl;
// }
// void i_type_instructions::LH(CPU *&C, INSTR_TYPE &src1, INSTR_TYPE &dest, int32_t &sx_idata)
// {
//     cerr << "LH" << endl;
// }

void i_type_instructions::LUI(CPU *&C, INSTR_TYPE &src1, INSTR_TYPE &dest, INSTR_TYPE &idata)
{
    cerr << "LUI" << endl;
    //Shift IDATA by 16 bits, load into RT (DEST). Exceptions: none.
    if (src1 == 0)
    {
        idata = idata << 16;
        C->reg[dest] = idata;
    }
    else
    {
        cerr << "src1 != 0. Making LUI invalid. Error not yet thrown.";
    }

    C->npc = C->npc + 1;
}
void i_type_instructions::LW(CPU *&C, INSTR_TYPE &src1, INSTR_TYPE &dest, int32_t &sx_idata)
{
    cerr << "LW" << endl;
    int32_t raw_mem_addr = sx_idata + C->reg[src1];
    int32_t mem_addr = raw_mem_addr / 4;
    if (DEBUG) {cerr << hex << ">> LW Effective memory address: " << mem_addr << "\n";}

    if ((mem_addr < 0) || (raw_mem_addr%4 != 0)) // If either of the two LSB of address are non-zero then throw exception
    {
        throw(static_cast<int>(MEMORY_EXIT_CODE));
    }
    else if (mem_addr == ADDR_GETC)
    {
        char input = read_char();
        C->reg[dest] = sign_extend_int32(input, 8);
    }
    else // Normal LW
    {
        C->reg[dest] = (*(C->mem))[mem_addr]; // mem is a pointer to the memory block
    }
    C->npc = C->npc + 1;
}
// void i_type_instructions::LWL(CPU *&C, INSTR_TYPE &src1, INSTR_TYPE &dest, int32_t &sx_idata)
// {
//     cerr << "LWL" << endl;
// }
// void i_type_instructions::LWR(CPU *&C, INSTR_TYPE &src1, INSTR_TYPE &dest, int32_t &sx_idata)
// {
//     cerr << "LWR" << endl;
// }
void i_type_instructions::ORI(CPU *&C, INSTR_TYPE &src1, INSTR_TYPE &dest, INSTR_TYPE &idata)
{
    cerr << "ORI" << endl;
    C->reg[dest] = C->reg[src1] | idata;
    C->npc = C->npc + 1;
}
void i_type_instructions::XORI(CPU *&C, INSTR_TYPE &src1, INSTR_TYPE &dest, INSTR_TYPE &idata)
{
    cerr << "XORI" << endl;
    C->reg[dest] = C->reg[src1] ^ idata;
    C->npc = C->npc + 1;
}
// void i_type_instructions::SLTI(CPU *&C, INSTR_TYPE &src1, INSTR_TYPE &dest, int32_t &sx_idata)
// {
//     cerr << "SLTI" << endl;
// }
// void i_type_instructions::SLTIU(CPU *&C, INSTR_TYPE &src1, INSTR_TYPE &dest, int32_t &sx_idata)
// {
//     cerr << "SLTIU" << endl;
// }
// void i_type_instructions::SB(CPU *&C, INSTR_TYPE &src1, INSTR_TYPE &dest, int32_t &sx_idata)
// {
//     cerr << "SB" << endl;
// }
// void i_type_instructions::SH(CPU *&C, INSTR_TYPE &src1, INSTR_TYPE &dest, int32_t &sx_idata)
// {
//     cerr << "SH" << endl;
// }
void i_type_instructions::SW(CPU *&C, INSTR_TYPE &src1, INSTR_TYPE &dest, int32_t &sx_idata)
{
    cerr << "SW" << endl;
    INSTR_TYPE raw_mem_addr = sx_idata + C->reg[src1];
    INSTR_TYPE mem_addr = raw_mem_addr / 4;
    if (DEBUG) {cerr << hex << ">> SW Effective memory address: " << mem_addr << "\n";}

    if ((mem_addr < 0) || (raw_mem_addr%4 != 0)) // If either of the two LSB of address are non-zero then throw exception
    {
        throw(static_cast<int>(MEMORY_EXIT_CODE));
    }
    else if (mem_addr == ADDR_PUTC)
    {
        cout << (C->reg[dest] & 0xFF) << "\n"; // Write to std::cout
    }
    else // Normal SW
    {
        (*(C->mem))[mem_addr] = C->reg[dest]; // mem is a pointer to the memory block
    }
    C->npc = C->npc + 1;
}
// void i_type_instructions::BGEZ(CPU *&C, INSTR_TYPE &src1, int32_t &sx_idata)
// {
//     cerr << "BGEZ" << endl;
// }
// void i_type_instructions::BGEZAL(CPU *&C, INSTR_TYPE &src1, int32_t &sx_idata)
// {
//     cerr << "BGEZAL" << endl;
// }
// void i_type_instructions::BGTZ(CPU *&C, INSTR_TYPE &src1, INSTR_TYPE &dest, int32_t &sx_idata)
// {
//     cerr << "BGTZ" << endl;
// }
// void i_type_instructions::BLEZ(CPU *&C, INSTR_TYPE &src1, INSTR_TYPE &dest, int32_t &sx_idata)
// {
//     cerr << "BLEZ" << endl;
// }
// void i_type_instructions::BLTZ(CPU *&C, INSTR_TYPE &src1, int32_t &sx_idata)
// {
//     cerr << "BLTZ" << endl;
// }
// void i_type_instructions::BLTZAL(CPU *&C, INSTR_TYPE &src1, int32_t &sx_idata)
// {
//     cerr << "BLTZAL" << endl;
// }
// void i_type_instructions::BDECODER(CPU *&S, INSTR_TYPE &src1, INSTR_TYPE &dest, int32_t &sx_idata)
// {
//     cerr << "BDECODER" << endl;
// }
