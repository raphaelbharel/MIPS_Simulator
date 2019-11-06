// g++ -std=c++11 simulator_1.cpp -o simulator_1

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

	
	const ADDR_INSTR_OFFSET = 0x10000000; //PC offset
	const ADDR_INSTR_LENGTH = 0x1000000; //PC length
	//Make a pointer to ADDR_INSTR_OFFSET
	//Then keep moving up while less than ADDR_INSTR_LENGTH?


	string binName = argv[1]; // See above

	// // Print out args
	// for (int i = 1; i < argc; i++)
	// {
	// 	cerr << argv[i] << endl;
	// }
	
	cerr << "Binary File name: " << binName << endl;		// For testing/debugging
	ifstream binStream;										// Create binary stream object
	binStream.open(binName, ios::binary); // Load .bin file as a binary file

	char c;
	int i = 0; //Counter to ensure register = 32 bits
	std::vector<int> single_register; //vector of single register.
	std::vector<vector<int>> instruction_memory; //instruction memory (vector of registers). 


	if (binStream.is_open())
	{
		while (binStream.get(c))
		{
			//cerr << c << endl;
			if(c==48){ //48 is the ASCII code for digit 0
				single_register.push_back(0);
			}
			else if(c==49){ //49 is the ASCII code for digit 1
				single_register.push_back(1);
			}
			else {
				std::cout<< "error" << std::endl;
			}

			if(i==31){ // if the register filled up
				instruction_memory.push_back(single_register); // place into instruction memory
				single_register.clear(); //reset the register
				i = 0;
			}
			else{
				i++;
			}

	//Initialize memory
	// Initialize instruction memory
	ADDR_TYPE address = ADDR_INSTR;
	while (!binStream.eof())
	{
		binStream.read(buffer.data(), buffer.size()); // Reading 32 bits at a time, buffer.data() is a 32bit array
		streamsize s = binStream.gcount();			  // # of bits read
		// cerr << "Streamsize: " << s << endl;
		if (s == 0)
		{
			break; // Ensures stream size 0 reads do not get converted to memory (reached end of bitStream)
		}
		INSTR_TYPE binNo = 0;
		int weight = s - 1;
		for (auto it = buffer.begin(); it != buffer.end(); ++it, --weight)
		{
			if (*it == '1') // IMPORTANT: iterator is a pointer to a char so it must be verfied with a char ''
			{
				binNo += pow(2, weight);
			}
		}
		imem[address]= binNo; // Inserting binary string to instruction memory
		address += 1;
	}

		}
	}
	binStream.close();

	//Printing all of instruction memory, from first register to last
	for(int i = 0; i<instruction_memory.size(); i++) {
		for(int j = 0; j<32; j++) {
		cout << instruction_memory[i][j];
	}
	cout << "\n";
	}


	return 0;
}
