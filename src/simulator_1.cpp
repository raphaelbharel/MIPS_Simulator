#include <cstdlib>
#include <ifstream>
#include <iostream>
#include <string>

int main(int argc, char *argv[])
{
	std::string binName = argv[1];
	std::cerr << binName;
	std::ifstream binSteam(argv[1], std::ios::binary);
	return 0;
}
