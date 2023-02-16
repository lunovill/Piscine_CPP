#include "Harl.hpp"

int	main(int ac, char *av[]) {
	if (ac != 2) {
		std::cerr << ansi((short[]){NORMAL, BOLD, RED}, 3) << "Usage: " << ansi((short[]){NORMAL, RED}, 2) << av[0] << " <message>" << std::endl;
		return 1;
	}

	Harl message;
	message.complain(av[1]);
	return 0;
}
