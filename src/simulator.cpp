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
const int binary_no_test = 0b101;
const int BUFFER_SIZE = 32;
const int INSTRUCTION_MEMORY_SIZE = 0x4000000;

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

int main(int argc /* argument count */, char *argv[] /* argument list */)
{
	/* argc (ARGument Count) is int and stores number of command-line arguments passed by the user including the name of the program. So if we pass a value to a program, value of argc would be 2 (one for argument and one for program name)
	The value of argc should be non negative.
	argv(ARGument Vector) is array of character pointers listing all the arguments.
	If argc is greater than zero,the array elements from argv[0] to argv[argc-1] will contain pointers to strings.
	Argv[0] is the name of the program , After that till argv[argc-1] every element is command -line arguments. 
	
	In the command line we would type:
		bin/mips_simulator file_name.bin
	to run the simulator on file_name.bin. argv[0] = bin/mips_simulator, argv[1] = file_name.bin	*/
	if (argc != 2)
	{
		cerr << "Incorrect number of arguments."
			 << "\n";
		return 1;
	}

	string binName = argv[1]; // See above

	cerr << "Binary File name: " << binName << endl; // For testing/debugging
	ifstream binStream;								 // Create binary stream object
	binStream.open(binName, ios::binary | ios::in);  // Load .bin file as a binary file
	// binStream.seekg(0, ios::end);
	// const streamsize BUFFER_SIZE = binStream.tellg();
	// binStream.seekg(0, ios::beg);

	// vector<char> buffer(BUFFER_SIZE);
	// if (binStream.read(buffer.data(), BUFFER_SIZE))
	// {
	// 	cerr << "> Successful writing to buffer" << endl;
	// 	cout << "Streamsize: " << BUFFER_SIZE << endl;
	// 	cout << "Buffer size: " << buffer.size() << endl;
	// 	cout << "Chars read: " << binStream.gcount() << endl;
	// }
	// binStream.close();

	// //Printing all of instruction memory, from first register to last
	// cerr << "Printing buffer string:" for (int i = 0; i < buffer.size(); i++)
	// {
	// 	cout << buffer[i] << " ";
	// }
	// cout << "\n";
	vector<INSTRUCTION_MEMORY_TYPE> imem;
	vector<BUFFER_TYPE> buffer(BUFFER_SIZE, 0);
	while (!binStream.eof())
	{
		binStream.read(buffer.data(), buffer.size()); // Reading 32 bits at a time -> buffer.data() is a 32bit array
		streamsize s = binStream.gcount();			  // # of bits read
		cerr << "Stream size: " << s << "\n";
		cerr << buffer.data() << endl;
		string binString = "";
		for (auto &c : buffer) // Creating binary string
		{
			binString += c;
		}
		imem.push_back(binString); // Inserting binary string to instruction memory
		cerr << binString << endl;
		binString.clear();
	}

	// SANITY CHECK
	__vertical_print_vector<string>(imem);

		return 0;
}
