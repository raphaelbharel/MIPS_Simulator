#include "headers.hpp"

using namespace std;

int main(int argc /* argument count */, char *argv[] /* argument list */)
{
	try
	{
		if (argc != 2)
		{
			cerr << "Error: Incorrect number of arguments: " << endl;
			return 1;
		}
		string binName = argv[1]; // Reading second argument from command line
		ifstream binStream;		  // Create binary stream object

		binStream.open(binName, ios::binary); // Load .bin file as a binary file
		if (!binStream.is_open())
		{
			cerr << "Error: Cannot open binary file." << endl;
			return 1;
		}

		// Initialize CPU and instruction classes
		CPU C;
		i_type_instructions i_instruction(C);
		r_type_instructions r_instruction(C);
		j_type_instructions j_instruction(C);

		// Fill instruction memory
		char buffer[4];  //to hold 4 bytes
		int address = 0; //starting from base 0x4000000
		while (!binStream.eof())
		{
			binStream.read(buffer, 4);
			binStream.peek(); // Check for eof on the next byte
			MEM_TYPE binNo = (static_cast<unsigned char>(buffer[0]) << 24) | (static_cast<unsigned char>(buffer[1]) << 16) | (static_cast<unsigned char>(buffer[2]) << 8) | static_cast<unsigned char>(buffer[3]);
			C.instruction_mem[address] = binNo;
			address++;
		}

		// Executing instructions
		C.instr = C.instruction_mem[0];
		int executions = 0;
		ADDR_TYPE next_instruction;

		for (; C.pc >= ADDR_INSTR_OFFSET && C.pc < ADDR_INSTR_OFFSET + ADDR_INSTR_LENGTH && C.pc != ADDR_NULL;)
		{
			C.reg[0] = 0;			  // $0 is always 0 on every clock cycle
			next_instruction = C.npc; //The preserved next instruction enables a branch delay
			C.instr = C.read_from_memory(C.pc);
			char instr_type = read_instruction(C.instr);
			switch (instr_type)
			{
			case 'r':
				r_instruction.execute();
				break;
			case 'i':
				i_instruction.execute();
				break;
			case 'j':
				j_instruction.execute();
				break;
			default:
				throw(static_cast<int>(INSTRUCTION_EXIT_CODE));
			}
			executions++;
			C.pc = next_instruction;
		}

		if (!within_memory_bounds(C.pc, 'x')) // If the PC has gone outside the executable zone
		{
			throw(static_cast<int>(MEMORY_EXIT_CODE));
		}

		//Successful termination/completion = return low 8-bits of the value in register $2.
		INSTR_TYPE SUCCESSFUL_EXIT_CODE = C.reg[2] & 0xFF;
		exit(static_cast<int>(SUCCESSFUL_EXIT_CODE));
	}
	catch (const int EXIT_CODE) // Exception handling
	{
		switch (EXIT_CODE)
		{
		case static_cast<int>(ARITHMETIC_EXIT_CODE):
			exit(static_cast<int>(ARITHMETIC_EXIT_CODE));
		case static_cast<int>(MEMORY_EXIT_CODE):
			exit(static_cast<int>(MEMORY_EXIT_CODE));
		case static_cast<int>(INSTRUCTION_EXIT_CODE):
			exit(static_cast<int>(INSTRUCTION_EXIT_CODE));
		case static_cast<int>(IO_EXIT_CODE):
			exit(static_cast<int>(IO_EXIT_CODE));
		default:;
		}
	}
	catch (...) // Unknown error
	{
		exit(static_cast<int>(INTERNAL_EXIT_CODE));
	}
	return 0;
}
