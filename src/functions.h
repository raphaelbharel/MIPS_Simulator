// This file contains the function declarations for R type instructions
#ifndef FUNCTIONS_H
#define FUNCTIONS_H

void read_r_instr(INSTR_TYPE &instruction);
void read_i_instr(INSTR_TYPE &instruction);
void read_j_instr(INSTR_TYPE &instruction);
char get_instruction_type(INSTR_TYPE &instruction, INSTR_TYPE &opcode);

#endif