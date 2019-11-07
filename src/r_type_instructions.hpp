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
    State *S;

    r_type_instructions(State &cpu_state)
    {
        S = &cpu_state;
    }

    void display()
    {
        std::cerr << "r_type_instruction state: " << std::endl;
        std::cerr << std::hex << "pc: " << S->pc << std::endl;
        std::cerr << std::hex << "npc: " << S->npc << std::endl;
        std::cerr << std::hex << "instr: " << S->instr << std::endl;
        std::cout << "code: " << std::bitset<CODE_SIZE>(code) << std::endl;
        std::cout << "src1: " << std::bitset<SRC1_SIZE>(src1) << std::endl;
        std::cout << "src2: " << std::bitset<SRC2_SIZE>(src2) << std::endl;
        std::cout << "dest: " << std::bitset<DEST_SIZE>(dest) << std::endl;
        std::cout << "shift: " << std::bitset<SHIFT_SIZE>(shift) << std::endl;
        std::cout << "funct: " << std::bitset<FUNC_SIZE>(func) << std::endl;
    }
    int execute();

    //COMPLEXITY 1
    void addu(State *&S, INSTR_TYPE &src1, INSTR_TYPE &src2, INSTR_TYPE &dest, INSTR_TYPE &shift, INSTR_TYPE &func);
    void and (State * &S, INSTR_TYPE &src1, INSTR_TYPE &src2, INSTR_TYPE &dest, INSTR_TYPE &shift, INSTR_TYPE &func);
    void jr(State *&S, INSTR_TYPE &src1, INSTR_TYPE &src2, INSTR_TYPE &dest, INSTR_TYPE &shift, INSTR_TYPE &func);
    void or (State * &S, INSTR_TYPE &src1, INSTR_TYPE &src2, INSTR_TYPE &dest, INSTR_TYPE &shift, INSTR_TYPE &func);
    void sltu(State *&S, INSTR_TYPE &src1, INSTR_TYPE &src2, INSTR_TYPE &dest, INSTR_TYPE &shift, INSTR_TYPE &func);
    void subu();
    //COMPLEXITY 2
    void xor ();
    void add(State *&S, INSTR_TYPE &src1, INSTR_TYPE &src2, INSTR_TYPE &dest, INSTR_TYPE &shift, INSTR_TYPE &func);
    void sll(State *&S, INSTR_TYPE &src1, INSTR_TYPE &src2, INSTR_TYPE &dest, INSTR_TYPE &shift, INSTR_TYPE &func);
    void slt(State *&S, INSTR_TYPE &src1, INSTR_TYPE &src2, INSTR_TYPE &dest, INSTR_TYPE &shift, INSTR_TYPE &func);
    void sra(State *&S, INSTR_TYPE &src1, INSTR_TYPE &src2, INSTR_TYPE &dest, INSTR_TYPE &shift, INSTR_TYPE &func);
    void srav(State *&S, INSTR_TYPE &src1, INSTR_TYPE &src2, INSTR_TYPE &dest, INSTR_TYPE &shift, INSTR_TYPE &func);
    void srl(State *&S, INSTR_TYPE &src1, INSTR_TYPE &src2, INSTR_TYPE &dest, INSTR_TYPE &shift, INSTR_TYPE &func);
    void sub(State *&S, INSTR_TYPE &src1, INSTR_TYPE &src2, INSTR_TYPE &dest, INSTR_TYPE &shift, INSTR_TYPE &func);
    //COMPLEXITY 3
    void mfhi(State *&S, INSTR_TYPE &src1, INSTR_TYPE &src2, INSTR_TYPE &dest, INSTR_TYPE &shift, INSTR_TYPE &func);
    void mflo(State *&S, INSTR_TYPE &src1, INSTR_TYPE &src2, INSTR_TYPE &dest, INSTR_TYPE &shift, INSTR_TYPE &func);
    void mthi(State *&S, INSTR_TYPE &src1, INSTR_TYPE &src2, INSTR_TYPE &dest, INSTR_TYPE &shift, INSTR_TYPE &func);
    void mtlo(State *&S, INSTR_TYPE &src1, INSTR_TYPE &src2, INSTR_TYPE &dest, INSTR_TYPE &shift, INSTR_TYPE &func);
    void sllv(State *&S, INSTR_TYPE &src1, INSTR_TYPE &src2, INSTR_TYPE &dest, INSTR_TYPE &shift, INSTR_TYPE &func);
    void srlv(State *&S, INSTR_TYPE &src1, INSTR_TYPE &src2, INSTR_TYPE &dest, INSTR_TYPE &shift, INSTR_TYPE &func);
    //COMPLEXITY 4
    void div(State *&S, INSTR_TYPE &src1, INSTR_TYPE &src2, INSTR_TYPE &dest, INSTR_TYPE &shift, INSTR_TYPE &func);
    void divu(State *&S, INSTR_TYPE &src1, INSTR_TYPE &src2, INSTR_TYPE &dest, INSTR_TYPE &shift, INSTR_TYPE &func);
    void jalr(State *&S, INSTR_TYPE &src1, INSTR_TYPE &src2, INSTR_TYPE &dest, INSTR_TYPE &shift, INSTR_TYPE &func);
    void mult(State *&S, INSTR_TYPE &src1, INSTR_TYPE &src2, INSTR_TYPE &dest, INSTR_TYPE &shift, INSTR_TYPE &func);
    void multu(State *&S, INSTR_TYPE &src1, INSTR_TYPE &src2, INSTR_TYPE &dest, INSTR_TYPE &shift, INSTR_TYPE &func);

private:
};

#endif