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
    void addi(State *&S, INSTR_TYPE &src1, INSTR_TYPE &dest, INSTR_TYPE &sx_idata);
    void addiu(State *&S, INSTR_TYPE &src1, INSTR_TYPE &dest, INSTR_TYPE &sx_idata);
    void andi(State *&S, INSTR_TYPE &src1, INSTR_TYPE &dest, INSTR_TYPE &idata);
    void beq(State *&S, INSTR_TYPE &src1, INSTR_TYPE &dest, INSTR_TYPE &sx_idata);
    void bne(State *&S, INSTR_TYPE &src1, INSTR_TYPE &dest, INSTR_TYPE &sx_idata);
    void lbu(State *&S, INSTR_TYPE &src1, INSTR_TYPE &dest, INSTR_TYPE &sx_idata);
    void lb(State *&S, INSTR_TYPE &src1, INSTR_TYPE &dest, INSTR_TYPE &sx_idata);
    void lhu(State *&S, INSTR_TYPE &src1, INSTR_TYPE &dest, INSTR_TYPE &sx_idata);
    void lh(State *&S, INSTR_TYPE &src1, INSTR_TYPE &dest, INSTR_TYPE &sx_idata);
    void lui(State *&S, INSTR_TYPE &src1, INSTR_TYPE &dest, INSTR_TYPE &idata);
    void lw(State *&S, INSTR_TYPE &src1, INSTR_TYPE &dest, INSTR_TYPE &sx_idata);
    void lwl(State *&S, INSTR_TYPE &src1, INSTR_TYPE &dest, INSTR_TYPE &sx_idata);
    void lwr(State *&S, INSTR_TYPE &src1, INSTR_TYPE &dest, INSTR_TYPE &sx_idata);
    void ori(State *&S, INSTR_TYPE &src1, INSTR_TYPE &dest, INSTR_TYPE &idata);
    void xori(State *&S, INSTR_TYPE &src1, INSTR_TYPE &dest, INSTR_TYPE &idata);
    void slti(State *&S, INSTR_TYPE &src1, INSTR_TYPE &dest, INSTR_TYPE &sx_idata);
    void sltiu(State *&S, INSTR_TYPE &src1, INSTR_TYPE &dest, INSTR_TYPE &sx_idata);
    void sb(State *&S, INSTR_TYPE &src1, INSTR_TYPE &dest, INSTR_TYPE &sx_idata);
    void sh(State *&S, INSTR_TYPE &src1, INSTR_TYPE &dest, INSTR_TYPE &sx_idata);
    void sw(State *&S, INSTR_TYPE &src1, INSTR_TYPE &dest, INSTR_TYPE &sx_idata);
    void bgez(State *&S, INSTR_TYPE &src1, INSTR_TYPE &sx_idata);
    void bgezal(State *&S, INSTR_TYPE &src1, INSTR_TYPE &sx_idata);
    void bgtz(State *&S, INSTR_TYPE &src1, INSTR_TYPE &dest, INSTR_TYPE &sx_idata);
    void blez(State *&S, INSTR_TYPE &src1, INSTR_TYPE &dest, INSTR_TYPE &sx_idata);
    void bltz(State *&S, INSTR_TYPE &src1, INSTR_TYPE &sx_idata);
    void bltzal(State *&S, INSTR_TYPE &src1, INSTR_TYPE &sx_idata);
    void bdecoder(State *&S, INSTR_TYPE &src1, INSTR_TYPE &dest, INSTR_TYPE &sx_idata);

private:
};

#endif
