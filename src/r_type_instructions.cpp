// This file contains the function definitions for R type instructions
#include "r_type_instructions.hpp"
using namespace std;

int r_type_instructions::execute()
{
    /* Opcode - 6 bits, Source 1 - 5 bits, Source 2 - 5 bits, Dest - 5 bits - 5 bitstion - 6 bits */

    if (DEBUG)
    {
        cerr << ">> Executing R type instruction ";
    }
    code = (C->instr & 0xFC000000) >> 26; //right shift 26
    src1 = (C->instr & 0x3E00000) >> 21;
    src2 = (C->instr & 0x1F0000) >> 16;
    dest = (C->instr & 0xF800) >> 11;
    shift = (C->instr & 0x7C0) >> 6;
    func = (C->instr & 0x3F);
    switch (func)
    {
    case 0x21:
        ADDU(C, src1, src2, dest);
        return 1;
    case 0x24:
        AND(C, src1, src2, dest);
        return 1;
    case 0x8:
        JR(C, src1);
        return 1;
    case 0x25:
        OR(C, src1, src2, dest);
        return 1;
    case 0x2B:
        SLTU(C, src1, src2, dest);
        return 1;
    case 0x23:
        SUBU(C, src1, src2, dest);
        return 1;
    case 0x26:
        XOR(C, src1, src2, dest);
        return 1;
    case 0x20:
        ADD(C, src1, src2, dest);
        return 1;
    case 0x0:
        SLL(C, src2, dest, shift);
        return 1;
    case 0x2A:
        SLT(C, src1, src2, dest);
        return 1;
    case 0x3:
        SRA(C, src2, dest, shift);
        return 1;
    case 0x7:
        SRAV(C, src1, src2, dest);
        return 1;
    case 0x2:
        SRL(C, src2, dest);
        return 1;
    case 0x22:
        SUB(C, src1, src2, dest);
        return 1;
    case 0x10:
        MFHI(C, dest);
        return 1;
    case 0x12:
        MFLO(C, dest);
        return 1;
    case 0x11:
        MTHI(C, src1);
        return 1;
    case 0x13:
        MTLO(C, src1);
        return 1;
    case 0x4:
        SLLV(C, src1, src2, dest);
        return 1;
    case 0x6:
        SRLV(C, src1, src2, dest);
        return 1;
    case 0x1A:
        DIV(C, src1, src2);
        return 1;
    case 0x1B:
        DIVU(C, src1, src2);
        return 1;
    case 0x9:
        JALR(C, src1, dest);
        return 1;
    case 0x18:
        MULT(C, src1, src2);
        return 1;
    case 0x19:
        MULTU(C, src1, src2);
        return 1;
    default:
        throw(static_cast<int>(INSTRUCTION_EXIT_CODE));
    }
    return 0;
}

void r_type_instructions::ADDU(CPU *&C, INSTR_TYPE &src1, INSTR_TYPE &src2, INSTR_TYPE &dest)
{
    if (DEBUG)
    {
        cerr << "ADDU" << endl;
    }
    C->reg[dest] = static_cast<uint32_t>(static_cast<uint32_t>(C->reg[src1]) + static_cast<uint32_t>(C->reg[src2]));
    C->npc = C->npc + 1;
}

void r_type_instructions::AND(CPU *&C, INSTR_TYPE &src1, INSTR_TYPE &src2, INSTR_TYPE &dest)
{
    if (DEBUG)
    {
        cerr << "AND" << endl;
    }
    C->reg[dest] = C->reg[src1] & C->reg[src2];
    C->npc = C->npc + 1;
}

void r_type_instructions::OR(CPU *&C, INSTR_TYPE &src1, INSTR_TYPE &src2, INSTR_TYPE &dest)
{
    if (DEBUG)
    {
        cerr << "OR" << endl;
    }
    C->reg[dest] = C->reg[src1] | C->reg[src2];
    C->npc = C->npc + 1;
}

void r_type_instructions::JR(CPU *&C, INSTR_TYPE &src1)
{
    if (DEBUG)
    {
        cerr << "JR" << endl;
    }
    if (C->reg[src1] % 4 != 0)
    {
        throw(static_cast<int>(MEMORY_EXIT_CODE));
    }
    else
    {
        C->npc = C->reg[src1] >> 2;
    }
}

void r_type_instructions::SLL(CPU *&C, INSTR_TYPE &src2, INSTR_TYPE &dest, INSTR_TYPE &shift)
{
    if (DEBUG)
    {
        cerr << "SLL" << endl;
    }
    C->reg[dest] = C->reg[src2] << shift;
    C->npc = C->npc + 1;
}

void r_type_instructions::SLTU(CPU *&C, INSTR_TYPE &src1, INSTR_TYPE &src2, INSTR_TYPE &dest)
{
    if (DEBUG)
    {
        cerr << "SLTU" << endl;
    }
    if (static_cast<uint32_t>(C->reg[src1]) < static_cast<uint32_t>(C->reg[src2]))
    {
        C->reg[dest] = 1;
    }
    else
    {
        C->reg[dest] = 0;
    }
    C->npc = C->npc + 1;
}

void r_type_instructions::SUBU(CPU *&C, INSTR_TYPE &src1, INSTR_TYPE &src2, INSTR_TYPE &dest)
{
    if (DEBUG)
    {
        cerr << "SUBU" << endl;
    }
    C->reg[dest] = static_cast<uint32_t>(static_cast<uint32_t>(C->reg[src1]) - static_cast<uint32_t>(C->reg[src2]));
    C->npc = C->npc + 1;
}

void r_type_instructions::XOR(CPU *&C, INSTR_TYPE &src1, INSTR_TYPE &src2, INSTR_TYPE &dest)
{
    if (DEBUG)
    {
        cerr << "XOR" << endl;
    }
    C->reg[dest] = C->reg[src1] ^ C->reg[src2];
    C->npc = C->npc + 1;
}

void r_type_instructions::ADD(CPU *&C, INSTR_TYPE &src1, INSTR_TYPE &src2, INSTR_TYPE &dest)
{
    if (DEBUG)
    {
        cerr << "ADD" << endl;
    }
    if (((C->reg[src1] < 0) && (C->reg[src2] < 0) && (C->reg[src1] + C->reg[src2] >= 0)) ||
        ((C->reg[src1] > 0) && (C->reg[src2] > 0) && (C->reg[src1] + C->reg[src2] <= 0)))
    {
        throw(static_cast<int>(ARITHMETIC_EXIT_CODE));
    }
    else
    {
        C->reg[dest] = C->reg[src1] + C->reg[src2];
        C->npc = C->npc + 1;
    }
}

void r_type_instructions::SLT(CPU *&C, INSTR_TYPE &src1, INSTR_TYPE &src2, INSTR_TYPE &dest)
{
    if (DEBUG)
    {
        cerr << "SLT" << endl;
    }
    if (C->reg[src1] < C->reg[src2])
    {
        C->reg[dest] = 1;
    }
    else
    {
        C->reg[dest] = 0;
    }
    C->npc = C->npc + 1;
}

void r_type_instructions::SRA(CPU *&C, INSTR_TYPE &src2, INSTR_TYPE &dest, INSTR_TYPE &shift)
{
    if (DEBUG)
    {
        cerr << "SRA" << endl;
        cerr << "SHIFT:" << shift << endl;
    }
    C->reg[dest] = static_cast<int32_t>(C->reg[src2]) >> shift;
    C->npc = C->npc + 1;
}
void r_type_instructions::SRAV(CPU *&C, INSTR_TYPE &src1, INSTR_TYPE &src2, INSTR_TYPE &dest)
{
    if (DEBUG)
    {
        cerr << "SRAV" << endl;
    }
    C->reg[dest] = static_cast<int32_t>(C->reg[src2]) >> (C->reg[src1] & 0x1F); // Shift by low order 5 bits
    C->npc = C->npc + 1;
}

void r_type_instructions::SRL(CPU *&C, INSTR_TYPE &src2, INSTR_TYPE &dest)
{
    if (DEBUG)
    {
        cerr << "SRL" << endl;
    }
    C->reg[dest] = static_cast<uint32_t>(C->reg[src2]) >> shift; // Casting as uint32
    C->npc = C->npc + 1;
}
void r_type_instructions::SUB(CPU *&C, INSTR_TYPE &src1, INSTR_TYPE &src2, INSTR_TYPE &dest)
{
    if (DEBUG)
    {
        cerr << "SUB" << endl;
    }
    // if +ve - -ve => -ve or -ve - +ve => +ve gives arithmetic overflow
    if (((C->reg[src1] >= 0) && (C->reg[src2] < 0) && (C->reg[src1] - C->reg[src2] <= 0)) ||
        ((C->reg[src1] <= 0) && (C->reg[src2] > 0) && (C->reg[src1] - C->reg[src2] >= 0)))
    {
        throw(static_cast<int>(ARITHMETIC_EXIT_CODE));
    }
    else
    {
        C->reg[dest] = C->reg[src1] - C->reg[src2];
        C->npc = C->npc + 1;
    }
}

void r_type_instructions::MFHI(CPU *&C, INSTR_TYPE &dest)
{
    if (DEBUG)
    {
        cerr << "MFHI" << endl;
    }
    C->reg[dest] = C->regHI;
    C->npc = C->npc + 1;
}
void r_type_instructions::MFLO(CPU *&C, INSTR_TYPE &dest)
{
    if (DEBUG)
    {
        cerr << "MFLO" << endl;
    }
    C->reg[dest] = C->regLO;
    C->npc = C->npc + 1;
}
void r_type_instructions::MTHI(CPU *&C, INSTR_TYPE &src1)
{
    if (DEBUG)
    {
        cerr << "MTHI" << endl;
    }
    C->regHI = C->reg[src1];
    C->npc = C->npc + 1;
}
void r_type_instructions::MTLO(CPU *&C, INSTR_TYPE &src1)
{
    if (DEBUG)
    {
        cerr << "MTLO" << endl;
    }
    C->regLO = C->reg[src1];
    C->npc = C->npc + 1;
}
void r_type_instructions::SLLV(CPU *&C, INSTR_TYPE &src1, INSTR_TYPE &src2, INSTR_TYPE &dest)
{
    if (DEBUG)
    {
        cerr << "SLLV" << endl;
    }
    C->reg[dest] = C->reg[src2] << (C->reg[src1] & 0x1F); // Shifted by low order 5 bits
    C->npc = C->npc + 1;
}

void r_type_instructions::SRLV(CPU *&C, INSTR_TYPE &src1, INSTR_TYPE &src2, INSTR_TYPE &dest)
{
    if (DEBUG)
    {
        cerr << "SRLV" << endl;
    }
    C->reg[dest] = static_cast<uint32_t>(C->reg[src2]) >> (C->reg[src1] & 0x1F); // Casting as uint32, shift by low order 5 bits
    C->npc = C->npc + 1;
}

void r_type_instructions::DIV(CPU *&C, INSTR_TYPE &src1, INSTR_TYPE &src2)
{
    if (DEBUG)
    {
        cerr << "DIV" << endl;
    }
    if (!C->reg[src2]) { // Division by zero
        throw(ARITHMETIC_EXIT_CODE);
    }
    C->regLO = C->reg[src1] / C->reg[src2];
    C->regHI = C->reg[src1] % C->reg[src2];
    C->npc = C->npc + 1;
}

void r_type_instructions::DIVU(CPU *&C, INSTR_TYPE &src1, INSTR_TYPE &src2)
{
    if (DEBUG)
    {
        cerr << "DIVU" << endl;
    }
    if (!C->reg[src2]) { // Division by zero
        throw(ARITHMETIC_EXIT_CODE);
    }
    C->regLO = static_cast<uint32_t>(C->reg[src1]) / static_cast<uint32_t>(C->reg[src2]);
    C->regHI = static_cast<uint32_t>(C->reg[src1]) % static_cast<uint32_t>(C->reg[src2]);
    C->npc = C->npc + 1;
}

void r_type_instructions::MULT(CPU *&C, INSTR_TYPE &src1, INSTR_TYPE &src2)
{
    if (DEBUG)
    {
        cerr << "MULT" << endl;
    }
    int64_t product = static_cast<int64_t>(C->reg[src1]) * static_cast<int64_t>(C->reg[src2]);
    C->regLO = static_cast<MEM_TYPE>(product & 0xFFFFFFFF);
    C->regHI = static_cast<MEM_TYPE>(product >> 32);
    C->npc = C->npc + 1;
}
void r_type_instructions::MULTU(CPU *&C, INSTR_TYPE &src1, INSTR_TYPE &src2)
{
    if (DEBUG)
    {
        cerr << "MULTU" << endl;
    }

    uint64_t product = static_cast<uint64_t>(static_cast<uint32_t>(C->reg[src1])) * static_cast<uint64_t>(static_cast<uint32_t>(C->reg[src2]));
    C->regLO = static_cast<MEM_TYPE>(product & 0xFFFFFFFF);
    C->regHI = static_cast<MEM_TYPE>(product >> 32);
    C->npc = C->npc + 1;
}

void r_type_instructions::JALR(CPU *&C, INSTR_TYPE &src1, INSTR_TYPE &dest)
{
    if (DEBUG)
    {  
        cerr << "JALR" << endl;
    }
    C->reg[dest] = (C->npc*4)+4; // Store return address in dest reg
    if (C->reg[src1] % 4 != 0)
    {
        throw(static_cast<int>(MEMORY_EXIT_CODE));
    }
    else
    {
        C->npc = C->reg[src1] >> 2; // Add offset to npc
    }
}
