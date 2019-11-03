// This file contains the function definitions for main functions
#include "functions.h"
#include "headers.h"
using namespace std;

char get_instruction_type(INSTR_TYPE &instruction, INSTR_TYPE &opcode)
{
    opcode = (instruction & 0xFC000000) >> 26; // First 6 bits
    switch (opcode)
    {
    case 0:
        return 'r';
    case 0x2:
    case 0x3:
        return 'j';
    default:
        return 'i';
    }
}

void read_r_instr(INSTR_TYPE &instruction)
{
    cerr << ">> Executing r type instruction." << endl;
    /* 
	R-type instruction structure:
	Opcode - 6 bits
	Source 1 - 5 bits
	Source 2 - 5 bits
	Dest - 5 bits
	Shift - 5 bits
	Function - 6 bits
	*/

    uint32_t code = 0;
    uint32_t src1 = (instruction & 0x3E00000) >> 21;
    uint32_t src2 = (instruction & 0x1F0000) >> 16;
    uint32_t dest = (instruction & 0xF800) >> 11;
    uint32_t func = (instruction & 0x3F);

    cout << "code: " << bitset<CODE_SIZE>(code) << endl;
    cout << "src1: " << bitset<SRC1_SIZE>(src1) << endl;
    cout << "src2: " << bitset<SRC2_SIZE>(src2) << endl;
    cout << "dest: " << bitset<DEST_SIZE>(dest) << endl;
    cout << "func: " << bitset<FUNC_SIZE>(func) << endl;
}

void read_i_instr(INSTR_TYPE &instruction)
{
    cerr << ">> Executing i type instruction." << endl;
    /*
	Opcode - 6 bits
	Source 1 - 5 bits
	Dest - 5 bits
	Immediate constant - 16 bits
	*/
    uint32_t code = (instruction & 0xFC000000) >> 26;
    uint32_t src1 = (instruction & 0x3E00000) >> 21;
    uint32_t dest = (instruction & 0x1F0000) >> 16;
    uint32_t adata = (instruction & 0xFFFF);

    cout << "code: " << bitset<CODE_SIZE>(code) << endl;
    cout << "src1: " << bitset<SRC1_SIZE>(src1) << endl;
    cout << "dest: " << bitset<DEST_SIZE>(dest) << endl;
    cout << "adata: " << bitset<I_ADATA_SIZE>(adata) << endl;
}

void read_j_instr(INSTR_TYPE &instruction)
{
    cerr << ">> Executing j type instruction." << endl;
    /*
	Opcode - 6 bits
	Jump memory location - 26 bits
	*/
    uint32_t code = (instruction & 0xFC000000) >> 26;
    uint32_t addr = (instruction & 0x3FFFFFF);

    cout << "code: " << bitset<CODE_SIZE>(code) << endl;
    cout << "addr: " << bitset<J_ADDRESS_SIZE>(addr) << endl;
}
