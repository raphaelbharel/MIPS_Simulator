// This file contains the function declarations for I type instructions
#ifndef I_TYPE_INSTRUCTIONS
#define I_TYPE_INSTRUCTIONS
#include "headers.hpp"

class i_type_instructions
{
public:
    uint32_t code = 0;
    uint32_t src1 = 0;
    uint32_t dest = 0;
    uint32_t idata = 0;
    int32_t sx_idata = 0;
    CPU *C;

    i_type_instructions(CPU &cpu_state)
    {
        C = &cpu_state;
    }

    void execute();
    void ADDI(CPU *&C, INSTR_TYPE &src1, INSTR_TYPE &dest, int32_t &sx_idata);
    void ADDIU(CPU *&C, INSTR_TYPE &src1, INSTR_TYPE &dest, int32_t &sx_idata);
    void ANDI(CPU *&C, INSTR_TYPE &src1, INSTR_TYPE &dest, INSTR_TYPE &idata);
    void BEQ(CPU *&C, INSTR_TYPE &src1, INSTR_TYPE &dest, int32_t &sx_idata);
    void BNE(CPU *&C, INSTR_TYPE &src1, INSTR_TYPE &dest, int32_t &sx_idata);
    void LBU(CPU *&C, INSTR_TYPE &src1, INSTR_TYPE &dest, int32_t &sx_idata);
    void LB(CPU *&C, INSTR_TYPE &src1, INSTR_TYPE &dest, int32_t &sx_idata);
    void LHU(CPU *&C, INSTR_TYPE &src1, INSTR_TYPE &dest, int32_t &sx_idata);
    void LH(CPU *&C, INSTR_TYPE &src1, INSTR_TYPE &dest, int32_t &sx_idata);
    void LUI(CPU *&C, INSTR_TYPE &src1, INSTR_TYPE &dest, INSTR_TYPE &idata);
    void LW(CPU *&C, INSTR_TYPE &src1, INSTR_TYPE &dest, int32_t &sx_idata);
    void LWL(CPU *&C, INSTR_TYPE &src1, INSTR_TYPE &dest, int32_t &sx_idata);
    void LWR(CPU *&C, INSTR_TYPE &src1, INSTR_TYPE &dest, int32_t &sx_idata);
    void ORI(CPU *&C, INSTR_TYPE &src1, INSTR_TYPE &dest, INSTR_TYPE &idata);
    void XORI(CPU *&C, INSTR_TYPE &src1, INSTR_TYPE &dest, INSTR_TYPE &idata);
    void SLTI(CPU *&C, INSTR_TYPE &src1, INSTR_TYPE &dest, int32_t &sx_idata);
    void SLTIU(CPU *&C, INSTR_TYPE &src1, INSTR_TYPE &dest, int32_t &sx_idata);
    void SB(CPU *&C, INSTR_TYPE &src1, INSTR_TYPE &dest, int32_t &sx_idata);
    void SH(CPU *&C, INSTR_TYPE &src1, INSTR_TYPE &dest, int32_t &sx_idata);
    void SW(CPU *&C, INSTR_TYPE &src1, INSTR_TYPE &dest, int32_t &sx_idata);
    void BGTZ(CPU *&C, INSTR_TYPE &src1, int32_t &sx_idata);
    void BLEZ(CPU *&C, INSTR_TYPE &src1, int32_t &sx_idata);
    void BGEZ(CPU *&C, INSTR_TYPE &src1, int32_t &sx_idata);
    void BGEZAL(CPU *&C, INSTR_TYPE &src1, int32_t &sx_idata);
    void BLTZ(CPU *&C, INSTR_TYPE &src1, int32_t &sx_idata);
    void BLTZAL(CPU *&C, INSTR_TYPE &src1, int32_t &sx_idata);

private:
};

#endif
