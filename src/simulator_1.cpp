#include <cstdlib>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(int argc /* argument count */, char *argv[] /* argument list */)
{
	/* argc (ARGument Count) is int and stores number of command-line arguments passed by the user including the name of the program. So if we pass a value to a program, value of argc would be 2 (one for argument and one for program name)
	The value of argc should be non negative.
	argv(ARGument Vector) is array of character pointers listing all the arguments.
	If argc is greater than zero,the array elements from argv[0] to argv[argc-1] will contain pointers to strings.
	Argv[0] is the name of the program , After that till argv[argc-1] every element is command -line arguments. 
	
	In the command line we would type:
		bin/mips_simulator file_name.bin
	to run the simulator on file_name.bin. argv[0] = bin/mips_simulator, argv[1] = file_name.bin
	
	*/

	string binName = argv[1]; // See above

	// // Print out args
	// for (int i = 1; i < argc; i++)
	// {
	// 	cerr << argv[i] << endl;
	// }

	cerr << binName;					  // For testing/debugging
	ifstream binStream;					  // Create binary stream object
	binStream.open(binName, ios::binary); // Load .bin file as a binary file
	u_int32_t imem[32] = {0};
	u_int32_t reg[32] = {0};
	char c;
	if (binStream.is_open())
	{
		while (binStream.get(c))
		{
			cerr << c << endl;
		}
		binStream.close();
	}

	return 0;
}
