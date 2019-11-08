// This file contains the function definitions for J type instructions
#include "j_type_instructions.hpp"
using namespace std;

int j_type_instructions::execute()
{
    /*
	Opcode - 6 bits
	Address data - 26 bits
	*/

    cerr << ">> Executing J type instruction ";
    code = (C->instr & 0xFC000000) >> 26;
    jdata = (C->instr & 0x3EFFFFF);

    // // Sign extend 16bit immediate-> TODO for J instr?
    // INSTR_TYPE sx_adata;
    // if (adata >> 15)
    // {
    //     sx_adata = adata | 0xFFFF0000;
    // }
    // else
    // {
    //     sx_adata = adata;
    // }

    switch (code)
    {
    case 0x2:
        // J(C, jdata);
        return 1;
    case 0x3:
        //JAL(C, jdata);
        return 1;
    default:
        return -12;
    }
}

// void j_type_instructions::J(CPU *&C, INSTR_TYPE &jdata)
// {
//     cerr << "J" << endl;
// }

// void j_type_instructions::JAL(CPU *&C, INSTR_TYPE &jdata)
// {
//     cerr << "JAL" << endl;
// }