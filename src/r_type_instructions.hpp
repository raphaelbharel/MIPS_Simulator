// This file contains the function declarations for R type instructions
#ifndef R_TYPE_INSTRUCTIONS
#define R_TYPE_INSTRUCTIONS
#include "headers.hpp"

class r_type_instructions
{
public:
    uint32_t code = 0;
    uint32_t src1 = 0;
    uint32_t src2 = 0;
    uint32_t dest = 0;
    uint32_t shift = 0;
    uint32_t func = 0;
    CPU *C;

    r_type_instructions(CPU &cpu_state)
    {
        C = &cpu_state;
    }

    void execute();
    void ADDU(CPU *&C, INSTR_TYPE &src1, INSTR_TYPE &src2, INSTR_TYPE &dest);
    void AND(CPU *&C, INSTR_TYPE &src1, INSTR_TYPE &src2, INSTR_TYPE &dest);
    void JR(CPU *&C, INSTR_TYPE &src1);
    void OR(CPU *&C, INSTR_TYPE &src1, INSTR_TYPE &src2, INSTR_TYPE &dest);
    void SLTU(CPU *&C, INSTR_TYPE &src1, INSTR_TYPE &src2, INSTR_TYPE &dest);
    void SUBU(CPU *&C, INSTR_TYPE &src1, INSTR_TYPE &src2, INSTR_TYPE &dest);
    void XOR(CPU *&C, INSTR_TYPE &src1, INSTR_TYPE &src2, INSTR_TYPE &dest);
    void ADD(CPU *&C, INSTR_TYPE &src1, INSTR_TYPE &src2, INSTR_TYPE &dest);
    void SLL(CPU *&C, INSTR_TYPE &src2, INSTR_TYPE &dest, INSTR_TYPE &shift);
    void SLT(CPU *&C, INSTR_TYPE &src1, INSTR_TYPE &src2, INSTR_TYPE &dest);
    void SRA(CPU *&C, INSTR_TYPE &src2, INSTR_TYPE &dest, INSTR_TYPE &shift);
    void SRAV(CPU *&C, INSTR_TYPE &src1, INSTR_TYPE &src2, INSTR_TYPE &dest);
    void SRL(CPU *&C, INSTR_TYPE &src2, INSTR_TYPE &dest);
    void SUB(CPU *&C, INSTR_TYPE &src1, INSTR_TYPE &src2, INSTR_TYPE &dest);
    void MFHI(CPU *&C, INSTR_TYPE &dest);
    void MFLO(CPU *&C, INSTR_TYPE &dest);
    void MTHI(CPU *&C, INSTR_TYPE &src1);
    void MTLO(CPU *&C, INSTR_TYPE &src1);
    void SLLV(CPU *&C, INSTR_TYPE &src1, INSTR_TYPE &src2, INSTR_TYPE &dest);
    void SRLV(CPU *&C, INSTR_TYPE &src1, INSTR_TYPE &src2, INSTR_TYPE &dest);
    void DIV(CPU *&C, INSTR_TYPE &src1, INSTR_TYPE &src2);
    void DIVU(CPU *&C, INSTR_TYPE &src1, INSTR_TYPE &src2);
    void MULT(CPU *&C, INSTR_TYPE &src1, INSTR_TYPE &src2);
    void MULTU(CPU *&C, INSTR_TYPE &src1, INSTR_TYPE &src2);
    void JALR(CPU *&C, INSTR_TYPE &src1, INSTR_TYPE &dest);

private:
};

#endif