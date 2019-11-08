#include <iostream>
#include <cstdlib>
#include <vector>
#define ADDR_INSTR 0x10000000
#define ADDR_INSTR_LENGTH 0x1000000
using namespace std;
char get_instruction_type(uint32_t &instruction);

int main()
{

    uint32_t testbinary = 0b00000010101010101111100000101010;
    vector<int32_t> reg;
    reg.resize(32, 0);
    // LOAD REGISTERS
    reg[1] = 0x9FFFFFFF;
    reg[2] = 0x9FFFFFFF;
    int32_t temp = reg[1] + reg[2];
    // OPERATION
    cout << reg[1] << " + " << reg[2] << endl;
    cout << "OUTPUT: " << temp << endl;
}

char get_instruction_type(uint32_t &instruction)
{
    uint32_t opcode = (instruction & 0xFC000000) >> 26; // First 6 bits
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
