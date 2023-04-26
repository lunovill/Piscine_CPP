#include "RPN.hpp"

int	main(int argc, char *argv[]) {
	if (argc != 2) {
		std::cerr << ansi((short[]){UNDERLINE, DARK}, 2) + "Usage:" << ansi((short[]){DARK}, 1) + " " + argv[0] << " <operation>" << std::endl;
		return 1;
	}

	std::string	operation(argv[1]);
	std::size_t	found = operation.find_first_not_of("0123456789 +-*/");
	if (found != std::string::npos) {
		std::cerr << ansi((short[]){UNDERLINE, DARK}, 2) << "Error:" << ansi((short[]){DARK, ITALIC}, 2) << " invalid character `" << operation[found] << "'" << std::endl;
		return 1;
	}

	return RPN(operation);
}