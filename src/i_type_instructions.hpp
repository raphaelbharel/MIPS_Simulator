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
    uint32_t sx_idata = 0;
    State *S;

    i_type_instructions(State &cpu_state)
    {
        S = &cpu_state;
    }

    void display()
    {
        std::cerr << "__i_type_instruction state__ " << std::endl;
        std::cerr << std::hex << "pc: " << S->pc << std::endl;
        std::cerr << std::hex << "npc: " << S->npc << std::endl;
        std::cerr << std::hex << "instr: " << S->instr << std::endl;
        std::cout << "code: " << std::bitset<CODE_SIZE>(code) << std::endl;
        std::cout << "src1: " << std::bitset<SRC1_SIZE>(src1) << std::endl;
        std::cout << "dest: " << std::bitset<DEST_SIZE>(dest) << std::endl;
        std::cout << "idata: " << std::bitset<I_ADATA_SIZE>(idata) << std::endl;
    }
    int execute();
    void ADDI(State *&S, INSTR_TYPE &src1, INSTR_TYPE &dest, INSTR_TYPE &sx_idata);
    void ADDIU(State *&S, INSTR_TYPE &src1, INSTR_TYPE &dest, INSTR_TYPE &sx_idata);
    void ANDI(State *&S, INSTR_TYPE &src1, INSTR_TYPE &dest, INSTR_TYPE &idata);
    void BEQ(State *&S, INSTR_TYPE &src1, INSTR_TYPE &dest, INSTR_TYPE &sx_idata);
    void BNE(State *&S, INSTR_TYPE &src1, INSTR_TYPE &dest, INSTR_TYPE &sx_idata);
    void LBU(State *&S, INSTR_TYPE &src1, INSTR_TYPE &dest, INSTR_TYPE &sx_idata);
    void LB(State *&S, INSTR_TYPE &src1, INSTR_TYPE &dest, INSTR_TYPE &sx_idata);
    void LHU(State *&S, INSTR_TYPE &src1, INSTR_TYPE &dest, INSTR_TYPE &sx_idata);
    void LH(State *&S, INSTR_TYPE &src1, INSTR_TYPE &dest, INSTR_TYPE &sx_idata);
    void LUI(State *&S, INSTR_TYPE &src1, INSTR_TYPE &dest, INSTR_TYPE &idata);
    void LW(State *&S, INSTR_TYPE &src1, INSTR_TYPE &dest, INSTR_TYPE &sx_idata);
    void LWL(State *&S, INSTR_TYPE &src1, INSTR_TYPE &dest, INSTR_TYPE &sx_idata);
    void LWR(State *&S, INSTR_TYPE &src1, INSTR_TYPE &dest, INSTR_TYPE &sx_idata);
    void ORI(State *&S, INSTR_TYPE &src1, INSTR_TYPE &dest, INSTR_TYPE &idata);
    void XORI(State *&S, INSTR_TYPE &src1, INSTR_TYPE &dest, INSTR_TYPE &idata);
    void SLTI(State *&S, INSTR_TYPE &src1, INSTR_TYPE &dest, INSTR_TYPE &sx_idata);
    void SLTIU(State *&S, INSTR_TYPE &src1, INSTR_TYPE &dest, INSTR_TYPE &sx_idata);
    void SB(State *&S, INSTR_TYPE &src1, INSTR_TYPE &dest, INSTR_TYPE &sx_idata);
    void SH(State *&S, INSTR_TYPE &src1, INSTR_TYPE &dest, INSTR_TYPE &sx_idata);
    void SW(State *&S, INSTR_TYPE &src1, INSTR_TYPE &dest, INSTR_TYPE &sx_idata);
    void BGEZ(State *&S, INSTR_TYPE &src1, INSTR_TYPE &sx_idata);
    void BGEZAL(State *&S, INSTR_TYPE &src1, INSTR_TYPE &sx_idata);
    void BGTZ(State *&S, INSTR_TYPE &src1, INSTR_TYPE &dest, INSTR_TYPE &sx_idata);
    void BLEZ(State *&S, INSTR_TYPE &src1, INSTR_TYPE &dest, INSTR_TYPE &sx_idata);
    void BLTZ(State *&S, INSTR_TYPE &src1, INSTR_TYPE &sx_idata);
    void BLTZAL(State *&S, INSTR_TYPE &src1, INSTR_TYPE &sx_idata);
    void BDECODER(State *&S, INSTR_TYPE &src1, INSTR_TYPE &dest, INSTR_TYPE &sx_idata);

private:
};

#endif
