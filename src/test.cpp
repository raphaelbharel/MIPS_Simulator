#include <iostream>
#include <cstdlib>
#include "instruction_class.h"
#include "r_type_instruction.h"
#include <map>
#define ADDR_INSTR 0x10000000
#define ADDR_INSTR_LENGTH 0x1000000
using namespace std;
char get_instruction_type(uint32_t &instruction);

int main() {
    
    uint32_t testbinary = 0b00000010101010101111100000101010;
    map<int, pair<Instruction, uint32_t>> imem;
    
    char instr_type = get_instruction_type(testbinary);
    cerr << "Type: " << instr_type << endl;
    if (instr_type == 'r')
    {
        R_type_instruction instruction(testbinary);
        pair<Instruction, uint32_t> testpair (instruction, 0xFFFFFFFF);
        imem.emplace(1, testpair);
    }
    else if (instr_type == 'i')
    {
        /* code */
    }
    else if (instr_type == 'j')
    {
        /* code */
    } else {
        exit(-10);
    }
    
    for (auto it : imem) {
        uint32_t reg_id = it.first;
        pair<Instruction, uint32_t> contents = it.second;
        cout << "Reg ID: " << it.first << endl;
        cout << "Instruction details:'\n'" << contents.first.details() << endl;
        cout << "Memory address: " << contents.second << endl;
    }
    return 0;
}

char get_instruction_type(uint32_t &instruction)
{
	uint32_t opcode = (instruction & 0xFC000000) >> 26; // First 6 bits
	switch(opcode){
		case 0:
			return 'r';
		case 0x2:
		case 0x3:
			return 'j';
		default:
			return 'i';
	}
}
