#include <iostream>
#include "ansi.hpp"

int	main(int argc, char **argv)
{
	std::cout << ansi((short[]){BOLD}, 1);
	if (argc == 1) {
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	} else {
		for (unsigned int i = 1; argv[i]; i++)
			for (unsigned int j = 0; argv[i][j]; j++)
				std::cout << (char)toupper(argv[i][j]);
	}
	std::cout << std::endl;
	return 0;
}