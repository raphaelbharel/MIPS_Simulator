// This file contains the function definitions for J type instructions
#include "j_type_instructions.h"
using namespace std;


int j_type_instructions::execute()
{
    /*
	Opcode - 6 bits
	Address data - 26 bits
	*/

    cerr << ">> Executing J type instruction ";
    code = (S->instr & 0xFC000000) >> 26;
    jdata = (S->instr & 0x3EFFFFF);
    
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
    
    switch (code) {
        case 0x2:
            j(S, jdata);
            return 1;
        case 0x3:
            jal(S, jdata);
            return 1;
        default:
            return -12;
    }
}