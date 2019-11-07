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
	// string binName = "src/test4.bin";				// Reading second argument from command line
	ifstream binStream;								// Create binary stream object
	binStream.open(binName, ios::binary | ios::in); // Load .bin file as a binary file
	if (!binStream.is_open())
	{
		cerr << "ERROR: Cannot open binary file." << endl;
		return 1;
	}
	vector<BUFFER_TYPE> buffer(BUFFER_SIZE, 0);
	vector<MEM_TYPE> mem_block; // vector of uint32_t holding memory
	mem_block.resize(MEM_SIZE, 0);

	// Fill instruction memory
	ADDR_TYPE address = ADDR_INSTR_OFFSET; //starting from 0x4000000
	while (!binStream.eof())
	{
		binStream.read(buffer.data(), buffer.size()); // Reading 32 bits at a time, buffer.data() is a 32bit array
		streamsize s = binStream.gcount();			  // # of bits read
		// cerr << "Streamsize: " << s << endl;
		if (s == 0)
		{
			break; // Ensures stream size 0 reads do not get converted to memory (reached end of bitStream)
		}
		MEM_TYPE binNo = 0;
		int weight = s - 1;
		for (auto it = buffer.begin(); it != buffer.end(); ++it, --weight)
		{
			if (*it == '1') // IMPORTANT: iterator is a pointer to a char so it must be verfied with a char ''
			{
				binNo += (1 << weight);
			}
		}
		mem_block[address] = binNo;
		address += 1;
	}

	// Initialize state and instruction classes
	State S(mem_block);
	i_type_instructions i_instruction(S);
	r_type_instructions r_instruction(S);
	j_type_instructions j_instruction(S);

	// Executing instructions
	int executions = 0;
	for (int address = ADDR_INSTR_OFFSET; (address < ADDR_INSTR_OFFSET + ADDR_INSTR_LENGTH) && (mem_block[S.pc] != 0); /*address++*/)
	{
		S.pc = S.npc; //currently the PC is offset from 0. Calibrate it to base.
		S.instr = mem_block[S.pc];
		if (!S.instr) // If instruction is just 0 ie empty
		{
			break;
		}

		char instr_type = read_instruction(S.instr);
		switch (instr_type)
		{
		case 'r':
			r_instruction.execute();
			// r_instruction.display();

			break;
		case 'i':
			i_instruction.display();
			i_instruction.execute();
			break;
		case 'j':
			j_instruction.execute();
			// j_instruction.display();
			break;
		default:
			cerr << "ERROR: FAILED TO READ INSTRUCTION." << endl;
			exit(-10);
		}
		S.view_regs();
		executions++;
	}
	cerr << "Executions: " << executions << endl;
	__print_memory_specific(mem_block, ADDR_INSTR_OFFSET, ADDR_INSTR_OFFSET + executions);

	return 0;
} // END OF MAIN

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

void __print_memory(const vector<MEM_TYPE> &v, const int &start_index, const int &end_index)
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