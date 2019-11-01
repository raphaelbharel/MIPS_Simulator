// g++ -std=c++11 simulator_1.cpp -o simulator_1

#include <cstdlib>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <iterator>
#include <cmath>
#include "r_type_instructions.h"
#include "i_type_instructions.h"
#include "j_type_instructions.h"

#define ADDR_NULL 0x00000000
#define ADDR_INSTR 0x10000000
#define ADDR_DATA 0x20000000
#define ADDR_GETC 0x30000000
#define ADDR_PUTC 0x30000004

using namespace std;
typedef uint32_t INSTRUCTION_MEMORY_TYPE;
typedef char BUFFER_TYPE;
typedef uint32_t REGISTER_MEMORY_TYPE;

// const int binary_no_test = 0b101;
const int BUFFER_SIZE = 32;
const int OPCODE_SIZE = 6;
// const int SRC1_SIZE = 5;
// const int SRC2_SIZE = 5;
// const int DEST_SIZE = 5;
// const int SHIFT_SIZE = 5;
// const int FNCODE_SIZE = 6;
// const int I_ADATA_SIZE = 16;
// const int J_ADDRESS_SIZE = 26;

// const int INSTRUCTION_MEMORY_SIZE = 0x4000000;

// FUNCTION DECLARATIONS
void read_r_instr();
void read_i_instr();
void read_j_instr();
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
	vector<INSTRUCTION_MEMORY_TYPE> imem;
	vector<REGISTER_MEMORY_TYPE> registers(32, 0);
	vector<BUFFER_TYPE> buffer(BUFFER_SIZE, 0);

	//************************ BACKUP CODE ******************************************************************
	// binStream.seekg(0, ios::end);
	// streamsize size = binStream.tellg();
	// binStream.seekg(0, ios::beg);

	// vector<char> buffer(size);
	// if (binStream.read(buffer.data(), size))
	// {
	// 	cerr << "Successful read: " << size << endl;
	// }
	// int count = 31;
	// uint32_t binNo = 0;
	// // uint32_t aids = pow(2, 31);
	// // cout << hex << aids << endl;
	// for (auto it = buffer.begin(); it != buffer.end(); ++it, --count)
	// {
	// 	if (count >= 0)
	// 	{
	// 		if (*it == '1')
	// 		{
	// 			binNo += pow(2, count);
	// 		}
	// 	}
	// 	else
	// 	{
	// 		imem.push_back(binNo);
	// 		binNo = 0;
	// 		count = 31;
	// 	}
	// }
	// cout << hex << binNo << endl;
	//******************************************************************************************

	while (!binStream.eof())
	{
		binStream.read(buffer.data(), buffer.size()); // Reading 32 bits at a time, buffer.data() is a 32bit array
		streamsize s = binStream.gcount();			  // # of bits read
		cerr << "Streamsize: " << s << endl;
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

	// SANITY CHECK
	__vertical_print_vector<INSTRUCTION_MEMORY_TYPE>(imem);
	for (INSTRUCTION_MEMORY_TYPE i = 0; i < imem.size(); i++)
	{
		uint32_t opcode = 0;
		char instr_type = get_instruction_type(imem[i], opcode);
		cerr << "Opcode: " << hex << opcode << ", Type: " << instr_type << endl;
	}

	// __vertical_print_vector<REGISTER_MEMORY_TYPE>(registers);
	// check_opcode(imem[0]);
	// Execute instructions for all instructions in instruction memory
	// for (int i = 0; i < imem.size(); i++)
	// {
	// }

	return 0;
} // END OF MAIN
char get_instruction_type(uint32_t &instruction, uint32_t &opcode)
{
	opcode = (instruction & 0xFC000000) >> 26; // First 6 bits

	if (opcode == 0x3F) // r type instruction, 0b111111
	{
		return 'r';
	}
	else if (opcode == 0x2 || opcode == 0x3) // j type
	{
		return 'j';
	}
	else // i type
	{
		return 'i';
	}
}

void read_r_instr()
{
	cerr << "Executing r type instruction." << endl;
}

void read_i_instr()
{
	cerr << "Executing i type instruction." << endl;
}

void read_j_instr()
{
	cerr << "Executing j type instruction." << endl;
}

// HELPER FUNCTIONS

// Arbitrary type print function
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
