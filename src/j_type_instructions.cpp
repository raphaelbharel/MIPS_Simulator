// This file contains the function definitions for J type instructions
#include "j_type_instructions.hpp"
using namespace std;

int j_type_instructions::execute()
{
    /* Opcode - 6 bits, Address data - 26 bits */

    if (DEBUG) {cerr << ">> Executing J type instruction ";}
    code = (C->instr & 0xFC000000) >> 26; //Opcode
    jdata = (C->instr & 0x03FFFFFF); //Target

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
    if (DEBUG) {
        cerr << "J" << endl;
        cerr << "Jdata"<< hex << jdata<<endl;
        cerr << "Jdata*4"<< hex << jdata*4<<endl;
        cerr << "Next PC"<< hex << C->npc<<endl;
        cerr << "Next PC/4"<< hex << ((C->npc)*4)<<endl;
        }
    
    MEM_TYPE upper_bits = (C->npc) & 0x3C000000;
    MEM_TYPE lower_bits = jdata;
    MEM_TYPE instr_address = upper_bits | lower_bits;

    C->npc = instr_address;
}

void j_type_instructions::JAL(CPU *&C, INSTR_TYPE &jdata)
{
    if (DEBUG) {cerr << "JAL" << endl;}
    C->reg[31] = (C->npc)*4 + 4; // Store return address in dest reg (x4 as 32 bits)
    MEM_TYPE upper_bits = (C->npc) & 0x3C000000;
    MEM_TYPE lower_bits = jdata;
    MEM_TYPE instr_address = upper_bits | lower_bits;

    C->npc = instr_address;
}