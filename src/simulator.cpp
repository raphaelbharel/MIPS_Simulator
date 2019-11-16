// g++ -std=c++11 simulator_1.cpp -o simulator_1
#include "headers.hpp"

using namespace std;

// FUNCTION DECLARATIONS
template <typename T>
void __vertical_print_vector(const vector<T> &v);
void __print_memory(const vector<MEM_TYPE> &v);
char read_instruction(INSTR_TYPE &instruction);
void __print_memory_specific(const vector<MEM_TYPE> &v, const int &start_index, const int &end_index);

// MAIN
int main(int argc /* argument count */, char *argv[] /* argument list */)
{
	if (argc != 2)
	{
		cerr << "ERROR: Incorrect number of arguments: " << endl;
		cerr << argv[0] << ":" << argv[1] << endl;
		return 1;
	}

	string binName = argv[1]; // Reading second argument from command line
	ifstream binStream;		  // Create binary stream object

	binStream.open(binName, ios::binary); // Load .bin file as a binary file
	if (!binStream.is_open())
	{
		cerr << "ERROR: Cannot open binary file." << endl;
		return 1;
	}

	char buffer[4];				//to hold 4 bytes
	vector<MEM_TYPE> mem_block; // vector of uint32_t holding memory

	mem_block.resize(MEM_SIZE); //or , 0xFC000000

	// Fill instruction memory
	ADDR_TYPE address = ADDR_INSTR_OFFSET; //starting from 0x4000000
	while (!binStream.eof())
	{
		binStream.read(buffer, 4);
		binStream.peek(); // Check for eof on the next byte

		MEM_TYPE binNo = (static_cast<unsigned char>(buffer[0]) << 24) | (static_cast<unsigned char>(buffer[1]) << 16) | (static_cast<unsigned char>(buffer[2]) << 8) | static_cast<unsigned char>(buffer[3]);

		cerr << hex << binNo << endl;

		mem_block[address] = binNo;
		address += 1;
	}

	// Initialize state and instruction classes
	CPU C(mem_block);
	i_type_instructions i_instruction(C);
	r_type_instructions r_instruction(C);
	j_type_instructions j_instruction(C);

	// Executing instructions
	int executions = 0;
	ADDR_TYPE next_instruction;

	for (; C.pc >= ADDR_INSTR_OFFSET && C.pc < ADDR_INSTR_OFFSET + ADDR_INSTR_LENGTH; /*&& (mem_block[C.pc] != 0); address++*/)
	{
		C.reg[0] = 0;			  // $0 is always 0 on every clock cycle
		next_instruction = C.npc; //The preserved next instruction enables a branch delay

		C.instr = mem_block[C.pc];

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
			cerr << "ERROR: INVALID INSTRUCTION." << endl;
			exit(-12);
		}
		C.display();
		C.view_regs();

		executions++;
		C.pc = next_instruction;
	}
	cerr << "Executions: " << executions << endl;
	//__print_memory(mem_block);
	//__print_memory_specific(mem_block, ADDR_INSTR_OFFSET, ADDR_INSTR_OFFSET + 10 /*executions*/);

	//Successful termination/completion = return low 8-bits of the value in register $2.
	INSTR_TYPE exit_code = C.reg[2] & 0xFF;
	cout << "Return code: " << exit_code << endl;
	exit(exit_code);

	return 0;
} // END OF	MAIN

// FUNCTION DEFINITIONS
char read_instruction(INSTR_TYPE &instruction)
{
	INSTR_TYPE opcode = (instruction & 0xFC000000) >> 26; // First 6 bits
	switch (opcode)
	{
	case 0:
		return 'r';
	case 0x2:
	case 0x3:
		return 'j';
	default:
		return 'i';
	}
}

int get_index_from_addr(const uint32_t &addr, vector<pair<uint32_t, uint32_t>> &v)
{
	for (size_t i = 0; i < v.size(); i++)
	{
		if (addr == v[i].first)
		{
			return i;
		}
	}
	cerr << "ERROR: Invalid memory address in memory block." << endl;
	exit(-10); // Could not find address
}

// HELPER FUNCTIONS
// Arbitrary type print vector function
template <typename T>
void __vertical_print_vector(const vector<T> &v)
{
	cerr << "Printing vector of size " << v.size() << ":\nSTART [" << endl;
	for (auto &elem : v)
	{
		cerr << hex << elem << "\n";
	}
	cerr << "] END" << endl;
}

void __print_memory(const vector<MEM_TYPE> &v)
{
	cerr << "Printing vector of size " << v.size() << ":\nSTART [" << endl;
	for (int index = 0; index < MEM_SIZE; index++)
	{
		cerr << hex << index << ":" << v[index] << "\n";
	}
	cerr << "] END" << endl;
}
void __print_memory_specific(const vector<MEM_TYPE> &v, const int &start_index, const int &end_index)
{
	cerr << "Printing vector of size " << v.size() << ":\nSTART [" << endl;
	for (int index = start_index; index < end_index; index++)
	{
		cerr << hex << index << ":" << v[index] << "\n";
	}
	cerr << "] END" << endl;
}