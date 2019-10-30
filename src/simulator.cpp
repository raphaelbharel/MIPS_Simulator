// g++ -std=c++11 simulator_1.cpp -o simulator_1

#include <cstdlib>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <iterator>
#include "r_type_instructions.h"
#include "i_type_instructions.h"
#include "j_type_instructions.h"

using namespace std;
typedef string INSTRUCTION_MEMORY_TYPE;
typedef char BUFFER_TYPE;
// const int binary_no_test = 0b101;
const int BUFFER_SIZE = 32;
const int OPCODE_SIZE = 6;
const int SRC1_SIZE = 5;
const int SRC2_SIZE = 5;
const int DEST_SIZE = 5;
const int SHIFT_SIZE = 5;
const int FNCODE_SIZE = 6;
const int I_ADATA_SIZE = 16;
const int J_ADDRESS_SIZE = 26;

// const int INSTRUCTION_MEMORY_SIZE = 0x4000000;

// FUNCTION DECLARATIONS
void read_r_instr();
void read_i_instr();
void read_j_instr();
void check_opcode(string &instruction);
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
	vector<u_int32_t> registers(32, 0);
	vector<BUFFER_TYPE> buffer(BUFFER_SIZE, 0);
	while (!binStream.eof())
	{
		binStream.read(buffer.data(), buffer.size()); // Reading 32 bits at a time, buffer.data() is a 32bit array
		streamsize s = binStream.gcount();			  // # of bits read
		// cerr << "Stream size: " << s << "\n";
		// cerr << buffer.data() << endl;
		if (s == 0)
		{
			break; // Ensures stream size 0 reads do not get converted to memory (reached end of bitStream)
		}

		string binString = "";
		for (auto &c : buffer) // Creating binary string
		{
			binString += c;
		}
		imem.push_back(binString); // Inserting binary string to instruction memory
		// cerr << binString << endl;
		binString.clear(); // Reset the string
	}

	// SANITY CHECK
	__vertical_print_vector<INSTRUCTION_MEMORY_TYPE>(imem);
	__vertical_print_vector<u_int32_t>(registers);
	check_opcode(imem[0]);
	// Execute instructions for all instructions in instruction memory
	// for (int i = 0; i < imem.size(); i++)
	// {
	// }

	return 0;
}
void check_opcode(string &instruction)
{
	string opcode = instruction.substr(0, OPCODE_SIZE);
	if (opcode == "000000") // r type
	{
		/* code */
	}
	else if (opcode == "000010" || opcode == "000011") // j type
	{
		/* code */
	}
	else // i type
	{
		/* code */
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
	cerr << "Printing vector:\nSTART " << endl;
	for (auto &elem : v)
	{
		cerr << elem << "\n";
	}
	cerr << "END" << endl;
}
