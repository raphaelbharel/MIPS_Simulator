typedef uint32_t TYPE;

class Instruction{
    public:
        // Constructor
        TYPE val;
        TYPE opcode;
        Instruction(TYPE &input_bin){
            val = input_bin;
            opcode = (input_bin & 0xFC000000) >> 26;
        } 
};
