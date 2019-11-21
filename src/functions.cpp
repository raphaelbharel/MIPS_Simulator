// This file contains the function definitions for the main
#include "init.hpp"
using namespace std;

// Primary functions
char read_char()
{
    char in = getchar();
    if (cin.eof())
    {
        return 0xFF; // Return -1 if EOF
    }
    if (!cin.good())
    {
        throw(static_cast<int>(IO_EXIT_CODE)); // Throw if error
    }
    return in;
}

char read_instruction(INSTR_TYPE &instruction)
{
    INSTR_TYPE opcode = (instruction & 0xFC000000) >> 26; // First 6 bits
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

bool within_memory_bounds(const ADDR_TYPE &mem_addr, const char &mode)
{
    if (mode == 'r')
    {
        return (mem_addr >= ADDR_INSTR_OFFSET && mem_addr < (ADDR_INSTR_OFFSET + ADDR_INSTR_LENGTH)) ||
               (mem_addr >= ADDR_DATA_OFFSET && mem_addr < (ADDR_DATA_OFFSET + ADDR_DATA_LENGTH)) ||
               (mem_addr == ADDR_GETC);
    }
    else if (mode == 'w')
    {
        return (mem_addr >= ADDR_DATA_OFFSET && mem_addr < (ADDR_DATA_OFFSET + ADDR_DATA_LENGTH)) ||
               (mem_addr == ADDR_PUTC);
    }
    else if (mode == 'x')
    {
        return (mem_addr >= ADDR_INSTR_OFFSET && mem_addr < (ADDR_INSTR_OFFSET + ADDR_INSTR_LENGTH)) ||
               (mem_addr == ADDR_NULL);
    }
    throw(INTERNAL_EXIT_CODE);
}

// Helper functions
void __print_memory(const std::vector<MEM_TYPE> &v)
{
    cerr << "__MEMORY_BLOCK__" << v.size() << "\n";
    for (int index = 0; index < MEM_SIZE; index++)
    {
        cerr << hex << "| " << index << "\t" << v[index] << "\n";
    }
    cerr << "] END" << endl;
}
void __print_memory_specific(const std::vector<MEM_TYPE> &v, const int &start_index, const int &end_index)
{
    cerr << "__MEMORY_BLOCK__" << v.size() << "\n";
    for (int index = start_index; index < end_index; index++)
    {
        cerr << hex << "| " << index << "\t" << v[index] << "\n";
    }
    cerr << "----------------" << endl;
}
