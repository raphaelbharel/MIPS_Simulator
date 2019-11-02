typedef uint32_t TYPE;

class R_type_instruction: public Instruction {
    public:
        TYPE src1;
        TYPE src2;
        TYPE dest;
        TYPE func;
        // Constructor
        R_type_instruction(TYPE &input_bin): Instruction(input_bin) {
            std::cout << ">> Initializing R instruction." << std::endl;
            
            src1 = (val & 0x3E00000) >> 21;
            src2 = (val & 0x1F0000) >> 16;
            dest = (val & 0xF800) >> 11;
            func = (val & 0x3F);
        }
        void details() {
            std::cout << "value: " << std::bitset<32>(val) << std::endl;
            std::cout << "code: " << std::bitset<6>(opcode) << std::endl;
            std::cout << "src1: " << std::bitset<5>(src1) << std::endl;
            std::cout << "src2: " << std::bitset<5>(src2) << std::endl;
            std::cout << "dest: " << std::bitset<5>(dest) << std::endl;
            std::cout << "func: " << std::bitset<6>(func) << std::endl;
        }

    private:

};