// g++ -std=c++11 simulator_1.cpp -o simulator_1

#include <cstdlib>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <iterator>
#include <cmath>
#include <map>
#include <bitset>
// #include "r_type_instructions.h"
// #include "i_type_instructions.h"
// #include "j_type_instructions.h"

#define ADDR_NULL 0x00000000
#define ADDR_INSTR 0x10000000
#define ADDR_DATA 0x20000000
#define ADDR_GETC 0x30000000
#define ADDR_PUTC 0x30000004
#define BUFFER_SIZE 32
#define REGISTER_SIZE 32
#define CODE_SIZE 6
#define SRC1_SIZE 5
#define SRC2_SIZE 5
#define DEST_SIZE 5
#define SHIFT_SIZE 5
#define FUNC_SIZE 6
#define I_ADATA_SIZE 16
#define J_ADDRESS_SIZE 26
#define IMEM_SIZE 0x4000000

using namespace std;
typedef uint32_t INSTR_TYPE;
typedef char BUFFER_TYPE;
typedef uint32_t RMEM_TYPE;
typedef pair<INSTR_TYPE, uint32_t> IMEM_TYPE;


// FUNCTION DECLARATIONS
void read_r_instr(uint32_t &instruction);
void read_i_instr(uint32_t &instruction);
void read_j_instr(uint32_t &instruction);
char get_instruction_type(uint32_t &instruction, uint32_t &opcode);
template <typename T>
void __vertical_print_vector(const vector<T> &v);

// MAIN
int main(int argc /* argument count */, char *argv[] /* argument list */)
{
	if (argc != 2)
	{
		cerr << "Incorrect number of arguments."
			 << "\n";
		return 1;
	}

	string binName = argv[1];						// Reading second argument from command line
	ifstream binStream;								// Create binary stream object
	binStream.open(binName, ios::binary | ios::in); // Load .bin file as a binary file
	if (!binStream.is_open())
	{
		cerr << "Error opening binary file." << endl;
		return 1;
	}
	vector<IMEM_TYPE> imem; // Nx2 matrix of instruction, address pairs
	vector<BUFFER_TYPE> buffer(BUFFER_SIZE, 0);
	map<RMEM_TYPE, RMEM_TYPE> registers;

	while (!binStream.eof())
	{
		binStream.read(buffer.data(), buffer.size()); // Reading 32 bits at a time, buffer.data() is a 32bit array
		streamsize s = binStream.gcount();			  // # of bits read
		// cerr << "Streamsize: " << s << endl;
		if (s == 0)
		{
			break; // Ensures stream size 0 reads do not get converted to memory (reached end of bitStream)
		}
		uint32_t binNo = 0;
		int weight = s - 1;
		for (auto it = buffer.begin(); it != buffer.end(); ++it, --weight)
		{
			if (*it == '1') // IMPORTANT: iterator is a pointer to a char so it must be verfied with a char ''
			{
				binNo += pow(2, weight);
			}
		}
		imem.push_back(binNo); // Inserting binary string to instruction memory
	}

	// Initialize registers to 0
	int reg_id = 0;
	for (int i = 0; i < REGISTER_SIZE; i++)
	{
		registers.emplace(reg_id, 0);
		reg_id++;
	}
	// // Print registers
	// for (auto& it : registers) {
	// 	cout << it.first << ":" << it.second << endl;
	// }

	// SANITY CHECK
	__vertical_print_vector<IMEM_TYPE>(imem);

	// Executing instructions
	for (IMEM_TYPE i = 0; i < imem.size(); i++)
	{
		INSTR_TYPE opcode = 0;
		INSTR_TYPE instruction = imem[i];
		char instr_type = get_instruction_type(instruction, opcode);
		cerr << "Opcode: " << hex << opcode << ", Type: " << instr_type << endl;
		switch (instr_type)
		{
		case 'r':
			read_r_instr(instruction);
			break;
		case 'i':
			read_i_instr(instruction);
			break;
		case 'j':
			read_j_instr(instruction);
			break;
		default:
			cerr << "ERROR: FAILED TO READ INSTRUCTION." << endl;
			exit(-10);
		}
	}

	// __vertical_print_vector<RMEM_TYPE>(registers);
	

	return 0;
} // END OF MAIN


// FUNCTION DEFINITIONS
char get_instruction_type(INSTR_TYPE &instruction, INSTR_TYPE &opcode)
{
	opcode = (instruction & 0xFC000000) >> 26; // First 6 bits
	switch(opcode){
		case 0:
			return 'r';
		case 0x2:
		case 0x3:
			return 'j';
		default:
			return 'i';
	}
}

void read_r_instr(INSTR_TYPE &instruction)
{
	cerr << ">> Executing r type instruction." << endl;
	/* 
	R-type instruction structure:
	Opcode - 6 bits
	Source 1 - 5 bits
	Source 2 - 5 bits
	Dest - 5 bits
	Shift - 5 bits
	Function - 6 bits
	*/

	uint32_t code = 0;
	uint32_t src1 = (instruction & 0x3E00000) >> 21;
	uint32_t src2 = (instruction & 0x1F0000) >> 16;
	uint32_t dest = (instruction & 0xF800) >> 11;
	uint32_t func = (instruction & 0x3F);

	cout << "code: " << bitset<CODE_SIZE>(code) << endl;
	cout << "src1: " << bitset<SRC1_SIZE>(src1) << endl;
	cout << "src2: " << bitset<SRC2_SIZE>(src2) << endl;
	cout << "dest: " << bitset<DEST_SIZE>(dest) << endl;
	cout << "func: " << bitset<FUNC_SIZE>(func) << endl;

}


void read_i_instr(INSTR_TYPE &instruction)
{
	cerr << ">> Executing i type instruction." << endl;
	/*
	Opcode - 6 bits
	Source 1 - 5 bits
	Dest - 5 bits
	Immediate constant - 16 bits
	*/
	uint32_t code = (instruction & 0xFC000000) >> 26;
	uint32_t src1 = (instruction & 0x3E00000) >> 21;
	uint32_t dest = (instruction & 0x1F0000) >> 16;
	uint32_t adata = (instruction & 0xFFFF);

	cout << "code: " << bitset<CODE_SIZE>(code) << endl;
	cout << "src1: " << bitset<SRC1_SIZE>(src1) << endl;
	cout << "dest: " << bitset<DEST_SIZE>(dest) << endl;
	cout << "adata: " << bitset<I_ADATA_SIZE>(adata) << endl;
}

void read_j_instr(INSTR_TYPE &instruction)
{
	cerr << ">> Executing j type instruction." << endl;
	/*
	Opcode - 6 bits
	Jump memory location - 26 bits
	*/
	uint32_t code = (instruction & 0xFC000000) >> 26;
	uint32_t addr = (instruction & 0x3FFFFFF);

	cout << "code: " << bitset<CODE_SIZE>(code) << endl;
	cout << "addr: " << bitset<J_ADDRESS_SIZE>(addr) << endl;

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
