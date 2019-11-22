// This file contains the function definitions for I type instructions
#include "i_type_instructions.hpp"
using namespace std;

int i_type_instructions::execute()
{
    /* Opcode - 6 bits, Source 1 - 5 bits, Dest - 5 bits, Immediate constant - 16 bits */

    if (DEBUG)
    {
        cerr << ">> Executing I type instruction ";
    }
    code = (C->instr & 0xFC000000) >> 26;
    src1 = (C->instr & 0x3E00000) >> 21;
    dest = (C->instr & 0x1F0000) >> 16;
    idata = (C->instr & 0xFFFF);
    // Sign extend 16bit immediate
    sx_idata = sign_extend_int32(idata, 16);

    switch (code)
    {
    case 0x8:
        ADDI(C, src1, dest, sx_idata);
        return 1;
    case 0x9:
        ADDIU(C, src1, dest, sx_idata);
        return 1;
    case 0xC:
        ANDI(C, src1, dest, idata);
        return 1;
    case 0x4:
        BEQ(C, src1, dest, sx_idata);
        return 1;
    case 0x5:
        BNE(C, src1, dest, sx_idata);
        return 1;
    case 0x24:
        LBU(C, src1, dest, sx_idata);
        return 1;
    case 0x20:
        LB(C, src1, dest, sx_idata);
        return 1;
    case 0x25:
        LHU(C, src1, dest, sx_idata);
        return 1;
    case 0x21:
        LH(C, src1, dest, sx_idata);
        return 1;
    case 0xF:
        LUI(C, src1, dest, idata);
        return 1;
    case 0x23:
        LW(C, src1, dest, sx_idata);
        return 1;
    case 0x22:
        LWL(C, src1, dest, sx_idata);
        return 1;
    case 0x26:
        LWR(C, src1, dest, sx_idata);
        return 1;
    case 0x28:
        SB(C, src1, dest, sx_idata);
        return 1;
    case 0x29:
        SH(C, src1, dest, sx_idata);
        return 1;
    case 0x2B:
        SW(C, src1, dest, sx_idata);
        return 1;
    case 0xA:
        SLTI(C, src1, dest, sx_idata);
        return 1;
    case 0xB:
        SLTIU(C, src1, dest, sx_idata);
        return 1;
    case 0xE:
        XORI(C, src1, dest, idata);
        return 1;
    case 0xD:
        ORI(C, src1, dest, idata);
        return 1;
    case 0x7:
        BGTZ(C, src1, sx_idata);
        return 1;
    case 0x6:
        BLEZ(C, src1, sx_idata);
        return 1;
    case 0x1: // REGIMM, filter by dest reg
    {
        switch (dest)
        {
        case 0x0:
            BLTZ(C, src1, sx_idata);
            return 1;
        case 0x1:
            BGEZ(C, src1, sx_idata);
            return 1;
        case 0x10:
            BLTZAL(C, src1, sx_idata);
            return 1;
        case 0x11:
            BGEZAL(C, src1, sx_idata);
            return 1;
        default:
            throw(static_cast<int>(INSTRUCTION_EXIT_CODE));
        }
    }
        return 1;
    default:
        throw(static_cast<int>(INSTRUCTION_EXIT_CODE));
    }
}

void i_type_instructions::ADDI(CPU *&C, INSTR_TYPE &src1, INSTR_TYPE &dest, int32_t &sx_idata)
{
    if (DEBUG)
    {
        cerr << "ADDI" << endl;
    }
    if (((C->reg[src1] < 0) && (sx_idata < 0) && (C->reg[src1] + sx_idata >= 0)) ||
        ((C->reg[src1] > 0) && (sx_idata > 0) && (C->reg[src1] + sx_idata <= 0)))
    {
        throw(static_cast<int>(ARITHMETIC_EXIT_CODE));
    }
    else
    {
        C->reg[dest] = C->reg[src1] + sx_idata;
        C->npc = C->npc + 1;
    }
}

void i_type_instructions::ADDIU(CPU *&C, INSTR_TYPE &src1, INSTR_TYPE &dest, int32_t &sx_idata)
{
    if (DEBUG)
    {
        cerr << "ADDIU" << endl;
    }
    C->reg[dest] = static_cast<uint32_t>(static_cast<uint32_t>(C->reg[src1]) + sx_idata);
    C->npc = C->npc + 1;
}

void i_type_instructions::ANDI(CPU *&C, INSTR_TYPE &src1, INSTR_TYPE &dest, INSTR_TYPE &idata)
{
    if (DEBUG)
    {
        cerr << "ANDI" << endl;
    }
    C->reg[dest] = C->reg[src1] & idata;
    C->npc = C->npc + 1;
}

void i_type_instructions::BEQ(CPU *&C, INSTR_TYPE &src1, INSTR_TYPE &dest, int32_t &sx_idata)
{
    if (DEBUG)
    {
        cerr << "BEQ" << endl;
    }
    if (C->reg[src1] == C->reg[dest])
    {
        ADDR_TYPE mem_addr = C->npc + sx_idata;
        if(!within_memory_bounds(mem_addr, 'r')) {throw(MEMORY_EXIT_CODE);}
        C->npc = mem_addr;
    }
    else
    {
        C->npc = C->npc + 1;
    }
}
void i_type_instructions::BNE(CPU *&C, INSTR_TYPE &src1, INSTR_TYPE &dest, int32_t &sx_idata)
{
    if (DEBUG)
    {
        cerr << "BNE" << endl;
    }
    if (C->reg[src1] != C->reg[dest])
    {
        ADDR_TYPE mem_addr = C->npc + sx_idata;
        if(!within_memory_bounds(mem_addr, 'r')) {throw(MEMORY_EXIT_CODE);}
        C->npc = mem_addr;
    }
    else
    {
        C->npc = C->npc + 1;
    }
}
void i_type_instructions::LBU(CPU *&C, INSTR_TYPE &src1, INSTR_TYPE &dest, int32_t &sx_idata)
{
    if (DEBUG)
    {
        cerr << "LBU" << endl;
    }                                               // Load byte unsigned LBU $1 16bOFFSET($2)}
    ADDR_TYPE raw_mem_addr = sx_idata + C->reg[src1]; // 16b signed offset + base
    ADDR_TYPE mem_addr = raw_mem_addr / 4;
    if (DEBUG)
    {
        cerr << hex << ">> LBU Raw memory address: " << raw_mem_addr << "\n";
        cerr << hex << ">> LBU Effective memory address: " << mem_addr << "\n";
    }

    if (!within_memory_bounds(mem_addr, 'r')) 
    {
        throw(static_cast<int>(MEMORY_EXIT_CODE));
    }
    MEM_TYPE word_at_address = C->read_from_memory(mem_addr); // mem is a pointer to the memory block
    int byte_offset = raw_mem_addr % 4;
    switch (byte_offset)
    {
    case 0:
        C->reg[dest] = (0xFF000000 & word_at_address) >> 24;
        break;
    case 1:
        C->reg[dest] = (0xFF0000 & word_at_address) >> 16;
        break;
    case 2:
        C->reg[dest] = (0xFF00 & word_at_address) >> 8;
        break;
    case 3:
        C->reg[dest] = 0xFF & word_at_address;
        break;
    default:
        throw(static_cast<int>(MEMORY_EXIT_CODE));
        break;
    }
    C->npc = C->npc + 1;
}
void i_type_instructions::LB(CPU *&C, INSTR_TYPE &src1, INSTR_TYPE &dest, int32_t &sx_idata)
{
    if (DEBUG)
    {
        cerr << "LB" << endl;
    }
    ADDR_TYPE raw_mem_addr = sx_idata + C->reg[src1]; // 16b signed offset + base
    ADDR_TYPE mem_addr = raw_mem_addr / 4;
    if (DEBUG)
    {
        cerr << hex << ">> LB Raw memory address: " << raw_mem_addr << "\n";
        cerr << hex << ">> LB Effective memory address: " << mem_addr << "\n";
    }

    if (!within_memory_bounds(mem_addr, 'r')) 
    {
        throw(static_cast<int>(MEMORY_EXIT_CODE));
    }
    MEM_TYPE word_at_address = C->read_from_memory(mem_addr); // mem is a pointer to the memory block
    int byte_offset = raw_mem_addr % 4;
    MEM_TYPE pre_sx;
    switch (byte_offset)
    {
    case 0:
        pre_sx = (0xFF000000 & word_at_address) >> 24; // doesn't need to sign extend
        C->reg[dest] = sign_extend_int32(pre_sx, 8); 
        break;
    case 1:
        pre_sx = (0xFF0000 & word_at_address) >> 16;
        C->reg[dest] = sign_extend_int32(pre_sx, 8);
        break;
    case 2:
        pre_sx = (0xFF00 & word_at_address) >> 8;
        C->reg[dest] = sign_extend_int32(pre_sx, 8);
        break;
    case 3:
        pre_sx = 0xFF & word_at_address;
        C->reg[dest] = sign_extend_int32(pre_sx, 8);
        break;
    default:
        throw(static_cast<int>(MEMORY_EXIT_CODE));
        break;
    }

    C->npc = C->npc + 1;
}
void i_type_instructions::LHU(CPU *&C, INSTR_TYPE &src1, INSTR_TYPE &dest, int32_t &sx_idata)
{
    if (DEBUG)
    {
        cerr << "LHU" << endl;
    }
    ADDR_TYPE raw_mem_addr = sx_idata + C->reg[src1]; // 16b signed offset + base
    ADDR_TYPE mem_addr = raw_mem_addr / 4;
    if (DEBUG)
    {
        cerr << hex << ">> LBU Raw memory address: " << raw_mem_addr << "\n";
        cerr << hex << ">> LBU Effective memory address: " << mem_addr << "\n";
    }

    if ((mem_addr % 2 != 0) || !within_memory_bounds(mem_addr, 'r')) // LSB non zero i.e. not multiple of 2
    {
        throw(static_cast<int>(MEMORY_EXIT_CODE));
    }
    MEM_TYPE word_at_address = C->read_from_memory(mem_addr); // mem is a pointer to the memory block
    int byte_offset = raw_mem_addr % 4;
    switch (byte_offset)
    {
    case 0:
        C->reg[dest] = 0xFFFF0000 & word_at_address;
        break;
    case 2:
        C->reg[dest] = 0xFFFF & word_at_address;
        break;
    default:
        throw(static_cast<int>(MEMORY_EXIT_CODE));
        break;
    }
    C->npc = C->npc + 1;
}
void i_type_instructions::LH(CPU *&C, INSTR_TYPE &src1, INSTR_TYPE &dest, int32_t &sx_idata)
{
    if (DEBUG)
    {
        cerr << "LH" << endl;
    }
    ADDR_TYPE raw_mem_addr = sx_idata + C->reg[src1]; // 16b signed offset + base
    ADDR_TYPE mem_addr = raw_mem_addr / 4;
    if (DEBUG)
    {
        cerr << hex << ">> LH Raw memory address: " << raw_mem_addr << "\n";
        cerr << hex << ">> LH Effective memory address: " << mem_addr << "\n";
    }

    if ((mem_addr % 2 != 0) || !within_memory_bounds(mem_addr, 'r')) // LSB non zero i.e. not multiple of 2
    {
        throw(static_cast<int>(MEMORY_EXIT_CODE));
    }
    MEM_TYPE word_at_address = C->read_from_memory(mem_addr); // mem is a pointer to the memory block
    int byte_offset = raw_mem_addr % 4;
    MEM_TYPE pre_sx;
    switch (byte_offset)
    {
    case 0:
        C->reg[dest] = 0xFFFF0000 & word_at_address;
        break;
    case 2:
        pre_sx = 0xFFFF & word_at_address;
        C->reg[dest] = sign_extend_int32(pre_sx, 16);
        break;
    default:
        throw(static_cast<int>(MEMORY_EXIT_CODE));
        break;
    }
    C->npc = C->npc + 1;
}

void i_type_instructions::LUI(CPU *&C, INSTR_TYPE &src1, INSTR_TYPE &dest, INSTR_TYPE &idata)
{
    if (DEBUG)
    {
        cerr << "LUI" << endl;
    }
    //Shift IDATA by 16 bits, load into RT (DEST). Exceptions: none.
    if (src1 == 0)
    {
        idata = idata << 16;
        C->reg[dest] = idata;
    }
    else
    {
        cerr << "src1 != 0. Making LUI invalid. Error not yet thrown.";
    }

    C->npc = C->npc + 1;
}

void i_type_instructions::LW(CPU *&C, INSTR_TYPE &src1, INSTR_TYPE &dest, int32_t &sx_idata)
{
    if (DEBUG)
    {
        cerr << "LW" << endl;
    }
    ADDR_TYPE raw_mem_addr = sx_idata + C->reg[src1];
    ADDR_TYPE mem_addr = raw_mem_addr / 4;
    if (DEBUG)
    {
        cerr << hex << ">> LW Raw memory address: " << raw_mem_addr << "\n";
        cerr << hex << ">> LW Effective memory address: " << mem_addr << "\n";
    }

    if ((raw_mem_addr % 4 != 0) || !within_memory_bounds(mem_addr, 'r')) // Check natural alignment
    {
        throw(static_cast<int>(MEMORY_EXIT_CODE));
    }

    C->reg[dest] = C->read_from_memory(mem_addr); 
    C->npc = C->npc + 1;
}

void i_type_instructions::LWL(CPU *&C, INSTR_TYPE &src1, INSTR_TYPE &dest, int32_t &sx_idata)
{
    if (DEBUG)
    {
        cerr << "LWL" << endl;
    }
    ADDR_TYPE raw_mem_addr = sx_idata + C->reg[src1]; // 16b signed offset + base
    ADDR_TYPE mem_addr = raw_mem_addr / 4;
    if (DEBUG)
    {
        cerr << hex << ">> LWL Raw memory address: " << raw_mem_addr << "\n";
        cerr << hex << ">> LWL Effective memory address: " << mem_addr << "\n";
    }

    if (!within_memory_bounds(mem_addr, 'r')) 
    {
        throw(static_cast<int>(MEMORY_EXIT_CODE));
    }
    MEM_TYPE word_at_address = C->read_from_memory(mem_addr); // mem is a pointer to the memory block
    MEM_TYPE MSBytes;
    int byte_offset = raw_mem_addr % 4;
    switch (byte_offset)
    // Extract bytes starting from byte_offset to end of aligned word then left shift
    {
    case 0:
        C->reg[dest] = word_at_address; // Overwrite entire register
        break;
    case 1:
        MSBytes = (0xFFFFFF & word_at_address) << 8;
        C->reg[dest] = (C->reg[dest] & 0xFF) | MSBytes; // Merge contents
        break;
    case 2:
        MSBytes = (0xFFFF & word_at_address) << 16;
        C->reg[dest] = (C->reg[dest] & 0xFFFF) | MSBytes; // Merge contents
        break;
    case 3:
        MSBytes = (0xFF & word_at_address) << 24;
        C->reg[dest] = (C->reg[dest] & 0xFFFFFF) | MSBytes; // Merge contents
        break;
    default:
        throw(static_cast<int>(MEMORY_EXIT_CODE));
        break;
    }
    C->npc = C->npc + 1;
}

void i_type_instructions::LWR(CPU *&C, INSTR_TYPE &src1, INSTR_TYPE &dest, int32_t &sx_idata)
{
    if (DEBUG)
    {
        cerr << "LWR" << endl;
    }
    ADDR_TYPE raw_mem_addr = sx_idata + C->reg[src1]; // 16b signed offset + base
    ADDR_TYPE mem_addr = raw_mem_addr / 4;
    if (DEBUG)
    {
        cerr << hex << ">> LWR Raw memory address: " << raw_mem_addr << "\n";
        cerr << hex << ">> LWR Effective memory address: " << mem_addr << "\n";
    }

    //Throw error if not in Readable memory zone
    if (!within_memory_bounds(mem_addr, 'r')) // If either of the two LSB of address are non-zero then throw exception
    {
        throw(static_cast<int>(MEMORY_EXIT_CODE));
    }
    MEM_TYPE word_at_address = C->read_from_memory(mem_addr); // mem is a pointer to the memory block
    MEM_TYPE LSBytes;
    int byte_offset = raw_mem_addr % 4;
    switch (byte_offset)
    // Extract bytes starting from byte_offset to end of aligned word then left shift
    {
    case 0: // Aligned
        LSBytes = (0xFF000000 & word_at_address) >> 24;
        C->reg[dest] = (C->reg[dest] & 0xFFFFFF00) | LSBytes; // Merge contents
        break;
    case 1:
        LSBytes = (0xFFFF0000 & word_at_address) >> 16;
        C->reg[dest] = (C->reg[dest] & 0xFFFF0000) | LSBytes; // Merge contents
        break;
    case 2:
        LSBytes = (0xFFFFFF00 & word_at_address) >> 8;
        C->reg[dest] = (C->reg[dest] & 0xFF000000) | LSBytes; // Merge contents
        break;
    case 3:
        C->reg[dest] = word_at_address; // Overwrite entire register
        break;
    default:
        throw(static_cast<int>(MEMORY_EXIT_CODE));
        break;
    }
    C->npc = C->npc + 1;
}

void i_type_instructions::ORI(CPU *&C, INSTR_TYPE &src1, INSTR_TYPE &dest, INSTR_TYPE &idata)
{
    if (DEBUG)
    {
        cerr << "ORI" << endl;
    }
    C->reg[dest] = C->reg[src1] | idata;
    C->npc = C->npc + 1;
}
void i_type_instructions::XORI(CPU *&C, INSTR_TYPE &src1, INSTR_TYPE &dest, INSTR_TYPE &idata)
{
    if (DEBUG)
    {
        cerr << "XORI" << endl;
    }
    C->reg[dest] = C->reg[src1] ^ idata;
    C->npc = C->npc + 1;
}

void i_type_instructions::SLTI(CPU *&C, INSTR_TYPE &src1, INSTR_TYPE &dest, int32_t &sx_idata)
{
    if (DEBUG)
    {
        cerr << "SLTI" << endl;
    }
    if (C->reg[src1] < sx_idata)
    {
        C->reg[dest] = 1;
    }
    else
    {
        C->reg[dest] = 0;
    }
    C->npc = C->npc + 1;
}

void i_type_instructions::SLTIU(CPU *&C, INSTR_TYPE &src1, INSTR_TYPE &dest, int32_t &sx_idata)
{
    if (DEBUG)
    {
        cerr << "SLTIU" << endl;
    }
    if (static_cast<uint32_t>(C->reg[src1]) < static_cast<uint32_t>(sx_idata))
    {
        C->reg[dest] = 1;
    }
    else
    {
        C->reg[dest] = 0;
    }
    C->npc = C->npc + 1;
}

void i_type_instructions::SB(CPU *&C, INSTR_TYPE &src1, INSTR_TYPE &dest, int32_t &sx_idata)
{
    if (DEBUG)
    {
        cerr << "SB" << endl;
    }
    ADDR_TYPE raw_mem_addr = sx_idata + C->reg[src1];
    ADDR_TYPE mem_addr = raw_mem_addr / 4;
    ADDR_TYPE mem_offset = raw_mem_addr % 4;
    
    if (DEBUG)
    {
        cerr << hex << ">> SW Raw memory address: " << raw_mem_addr << "\n";
        cerr << hex << ">> SW Effective memory address: " << mem_addr << "\n";
        cerr << hex << ">> SB memory offset: " << mem_offset << "\n";
    }
    if (!within_memory_bounds(mem_addr, 'w'))
    {
        throw(static_cast<int>(MEMORY_EXIT_CODE));
    }
    C->write_to_memory(mem_addr, mem_offset, 'b', C->reg[dest]);
    C->npc = C->npc + 1;
}

void i_type_instructions::SH(CPU *&C, INSTR_TYPE &src1, INSTR_TYPE &dest, int32_t &sx_idata)
{
    if (DEBUG)
    {
        cerr << "SH" << endl;
    }
    ADDR_TYPE raw_mem_addr = sx_idata + C->reg[src1];
    ADDR_TYPE mem_addr = raw_mem_addr / 4;
    ADDR_TYPE mem_offset = raw_mem_addr % 4;
    if (DEBUG)
    {
        cerr << hex << ">> SH Raw memory address: " << raw_mem_addr << "\n";
        cerr << hex << ">> SH Effective memory address: " << mem_addr << "\n";
        cerr << hex << ">> SH memory offset: " << mem_offset << "\n";
    }
    if ((raw_mem_addr % 2 != 0) || !within_memory_bounds(mem_addr, 'w'))
    {
        throw(static_cast<int>(MEMORY_EXIT_CODE));
    }
    C->write_to_memory(mem_addr, mem_offset, 'h', C->reg[dest] & 0xFFFF);
    C->npc = C->npc + 1;
}

void i_type_instructions::SW(CPU *&C, INSTR_TYPE &src1, INSTR_TYPE &dest, int32_t &sx_idata)
{
    if (DEBUG)
    {
        cerr << "SW" << endl;
    }
    ADDR_TYPE raw_mem_addr = sx_idata + C->reg[src1];
    ADDR_TYPE mem_addr = raw_mem_addr / 4;
    ADDR_TYPE mem_offset = raw_mem_addr % 4;
    if (DEBUG)
    {
        cerr << hex << ">> SW Raw memory address: " << raw_mem_addr << "\n";
        cerr << hex << ">> SW Effective memory address: " << mem_addr << "\n";
        cerr << hex << ">> SW memory offset: " << mem_offset << "\n";
    }

    if ((raw_mem_addr % 4 != 0) || !within_memory_bounds(mem_addr, 'w')) // If either of the two LSB of address are non-zero then throw exception
    {
        throw(static_cast<int>(MEMORY_EXIT_CODE));
    }
    else // Normal SW
    {
        C->write_to_memory(mem_addr, 0, 'w', C->reg[dest]); // mem is a pointer to the memory block
    }
    C->npc = C->npc + 1;
}

void i_type_instructions::BGTZ(CPU *&C, INSTR_TYPE &src1, int32_t &sx_idata)
{
    if (DEBUG)
    {
        cerr << "BGTZ" << endl;
    }
    if (C->reg[src1] > 0)
    {
        ADDR_TYPE mem_addr = C->npc + sx_idata;
        if(!within_memory_bounds(mem_addr, 'r')) {throw(MEMORY_EXIT_CODE);}
        C->npc = mem_addr;
    }
    else
    {
        C->npc = C->npc + 1;
    }
}

void i_type_instructions::BGEZ(CPU *&C, INSTR_TYPE &src1, int32_t &sx_idata)
{
    if (DEBUG)
    {
        cerr << "BGEZ" << endl;
    }
    if (C->reg[src1] >= 0)
    {
        ADDR_TYPE mem_addr = C->npc + sx_idata;
        if(!within_memory_bounds(mem_addr, 'r')) {throw(MEMORY_EXIT_CODE);}
        C->npc = mem_addr;
    }
    else
    {
        C->npc = C->npc + 1;
    }
}
void i_type_instructions::BGEZAL(CPU *&C, INSTR_TYPE &src1, int32_t &sx_idata)
{
    if (DEBUG)
    {
        cerr << "BGEZAL" << endl;
    }
    
    C->reg[31] = (C->npc+1)*4;       // Storing return address of npc into $31
    
    if (C->reg[src1] >= 0)
    {
        ADDR_TYPE mem_addr = C->npc + sx_idata;
        if(!within_memory_bounds(mem_addr, 'x')) {throw(MEMORY_EXIT_CODE);}
        C->npc = mem_addr;
    }
    else
    {
        C->npc = C->npc + 1;
    }
}

void i_type_instructions::BLEZ(CPU *&C, INSTR_TYPE &src1, int32_t &sx_idata)
{
    if (DEBUG)
    {
        cerr << "BLEZ" << endl;
    }
    if (C->reg[src1] <= 0)
    {
        ADDR_TYPE mem_addr = C->npc + sx_idata;
        if(!within_memory_bounds(mem_addr, 'r')) {throw(MEMORY_EXIT_CODE);}
        C->npc = mem_addr;   
    } 
    else
    {
        C->npc = C->npc + 1;
    }
}

void i_type_instructions::BLTZ(CPU *&C, INSTR_TYPE &src1, int32_t &sx_idata)
{
    if (DEBUG)
    {
        cerr << "BLTZ" << endl;
    }
    if (C->reg[src1] < 0)
    {
        ADDR_TYPE mem_addr = C->npc + sx_idata;
        if(!within_memory_bounds(mem_addr, 'r')) {throw(MEMORY_EXIT_CODE);}
        C->npc = mem_addr;
    }
    else
    {
        C->npc = C->npc + 1;
    }
}

void i_type_instructions::BLTZAL(CPU *&C, INSTR_TYPE &src1, int32_t &sx_idata)
{
    if (DEBUG)
    {
        cerr << "BLTZAL" << endl;
    }
    
    C->reg[31] = (C->npc+1)*4;  // Storing return address of npc into $31
    
    if (C->reg[src1] < 0)
    {
        ADDR_TYPE mem_addr = C->npc + sx_idata;
        if(!within_memory_bounds(mem_addr, 'r')) {throw(MEMORY_EXIT_CODE);}
        C->npc = mem_addr; // Supposedly 16bit shifted left (x4) but since our memory space is divided by 4, don't need to shift
    }
    else
    {
        C->npc = C->npc + 1;
    }
}
