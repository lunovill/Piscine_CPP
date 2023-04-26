#include "BitcoinExchange.hpp"

int	main(int argc, char *argv[]) {
	if (argc != 2) {
		std::cerr << ansi((short[]){UNDERLINE, DARK}, 2) + "Usage:" << ansi((short[]){DARK}, 1) + " " + argv[0] << " <filename>" << std::endl;
		return 1;
	}
	std::ifstream input;
	input.open(argv[1]);
	if (!input.is_open()) {
		std::cerr << ansi((short[]){UNDERLINE, DARK}, 2) + "Error:" << ansi((short[]){DARK}, 1) + " open:" << ansi((short[]){ITALIC, DARK}, 2) +  " could not open file " + argv[1] + "." << std::endl;
		return 1;
	}
	std::ifstream dataFile;
	dataFile.open(DATA_PATH);
	if (!dataFile.is_open()) {
		std::cerr << ansi((short[]){UNDERLINE, DARK}, 2) + "Error:" << ansi((short[]){DARK}, 1) + " open:" << ansi((short[]){ITALIC, DARK}, 2) +  " could not open file " + DATA_PATH + "." << std::endl;
		return 1;
	}
	btc(dataFile, input);
	return 0;
}