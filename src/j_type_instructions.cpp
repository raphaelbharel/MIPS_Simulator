// This file contains the function definitions for J type instructions
#include "j_type_instructions.hpp"
using namespace std;

int j_type_instructions::execute()
{
    /* Opcode - 6 bits, Address data - 26 bits */

    cerr << ">> Executing J type instruction ";
    code = (C->instr & 0xFC000000) >> 26;
    jdata = (C->instr & 0x3EFFFFF);

    switch (code)
    {
    case 0x2:
        J(C, jdata);
        return 1;
    case 0x3:
        JAL(C, jdata);
        return 1;
    default:
        throw(static_cast<int>(INSTRUCTION_EXIT_CODE));
    }
}

void j_type_instructions::J(CPU *&C, INSTR_TYPE &jdata)
{
    cerr << "J" << endl;
    C->npc = (C->npc & 0xF0000000) | C->reg[jdata];
}

void j_type_instructions::JAL(CPU *&C, INSTR_TYPE &jdata)
{
    cerr << "JAL" << endl;
    C->reg[31] = C->npc; // Store return address in dest reg
    C->npc = (C->npc & 0xF0000000) | C->reg[jdata];
}