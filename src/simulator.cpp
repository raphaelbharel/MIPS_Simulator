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

/* argc (ARGument Count) is int and stores number of command-line arguments passed by the user including the name of the program. So if we pass a value to a program, value of argc would be 2 (one for argument and one for program name)
	The value of argc should be non negative.
	argv(ARGument Vector) is array of character pointers listing all the arguments.
	If argc is greater than zero,the array elements from argv[0] to argv[argc-1] will contain pointers to strings.
	Argv[0] is the name of the program , After that till argv[argc-1] every element is command -line arguments. 
	
	In the command line we would type:
		bin/mips_simulator file_name.bin
	to run the simulator on file_name.bin. argv[0] = bin/mips_simulator, argv[1] = file_name.bin
	
	*/

int main(int argc /* argument count */, char *argv[] /* argument list */)
{
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
	binStream.seekg(0, ios::end);
	const streamsize BUFFER_SIZE = binStream.tellg();
	binStream.seekg(0, ios::beg);

	vector<char> buffer(BUFFER_SIZE);
	if (binStream.read(buffer.data(), BUFFER_SIZE))
	{
		cerr << "> Successful writing to buffer" << endl;
		cout << "Streamsize: " << BUFFER_SIZE << endl;
		cout << "Buffer size: " << buffer.size() << endl;
		cout << "Chars read: " << binStream.gcount() << endl;
	}
	binStream.close();

	//Printing all of instruction memory, from first register to last
	cerr << "Printing buffer string:" for (int i = 0; i < buffer.size(); i++)
	{
		cout << buffer[i] << " ";
	}
	cout << "\n";

	vector<u_int32_t> imem;
	for (char &c : buffer)
	{
		imem.push_back(static_cast<byte>(c));
	}
	// This is a test piece of code from the develop branch!

	return 0;
}
