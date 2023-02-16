#include <fstream>
#include <iostream>
#include "ansi.hpp"

int	main(int ac, char *av[]) {

	if (ac !=  4) {
		std::cerr << ansi((short[]){NORMAL, BOLD, RED}, 3) << "Usage: " << ansi((short[]){NORMAL, RED}, 2) << av[0] << " <filename> <s1> <s2>" << std::endl;
		return 1;
	}

	std::string	infile = av[1];
	std::ifstream	input;
	input.open(infile.c_str());
	if (!input.is_open()) {
		std::cerr << ansi((short[]){NORMAL, BOLD, RED}, 3) << "Error:" <<  ansi((short[]){NORMAL, RED}, 2) << " failed to open input file" << std::endl;
		return 1;
	}

	std::string	outfile = av[1] + (std::string)".replace";
	std::ofstream	output;
	output.open(outfile.c_str());
	if (!output.is_open()) {
		std::cerr << ansi((short[]){NORMAL, BOLD, RED}, 3) << "Error:" <<  ansi((short[]){NORMAL, RED}, 2) << " failed to open output file" << std::endl;
		return 1;
	}

	std::string line;
	std::string s1 = av[2];
	std::string s2 = av[3];
	while (getline(input, line)) {
		std::size_t	index = 0;

		if (!s1.empty() && !s2.empty())
			while ((index = line.find(s1, index)) != std::string::npos) {
				line.erase(index, s1.length());
				line.insert(index, s2);
				index += s2.length();
			}
		output << line << std::endl;
	}

	input.close();
	output.close();
	return 0;
}