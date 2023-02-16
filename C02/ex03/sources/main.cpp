#include "Point.hpp"

int	main(void) {
	Point	a(-5, 5);
	Point	b(5, 2);
	Point	c(-1, -1);

	{
		Point	point(1, 1);

		std::cout << ansi(NULL, 0) + "  .(-5, 5)       " << std::endl;
		std::cout << ansi(NULL, 0) + "                 " << std::endl;
		std::cout << ansi(NULL, 0) + "                 " << std::endl;
		std::cout << ansi(NULL, 0) + "          .(5, 2)" << std::endl;
		std::cout << ansi((short[]){CYAN}, 1) + "  (1, 1)+        " << std::endl;
		std::cout << ansi(NULL, 0) + "                 " << std::endl;
		std::cout << ansi(NULL, 0) + "      .(-1, -1)  " << std::endl;
		std::cout << std::endl;
		std::cout << ansi((short[]){CYAN}, 1) + "My point is in this triangle ? ";
		if(bsp(a, b, c, point))
			std::cout << ansi((short[]){BOLD, GREEN}, 2) + "true" << std::endl;
		else
			std::cout << ansi((short[]){BOLD, RED}, 2) + "false" << std::endl;
	}
	std::cout << std::endl;
	std::cout << ansi((short[]){BOLD, PURPLE}, 2) + "----------------------------------------------" + ansi(NULL, 0) << std::endl;
	std::cout << std::endl;
	{
		Point	point(6, 4);

		std::cout << ansi(NULL, 0) + "  .(-5, 5)       " << std::endl;
		std::cout << ansi((short[]){CYAN}, 1) + "        (6, 4)+  " << std::endl;
		std::cout << ansi(NULL, 0) + "                 " << std::endl;
		std::cout << ansi(NULL, 0) + "          .(5, 2)" << std::endl;
		std::cout << ansi(NULL, 0) + "                 " << std::endl;
		std::cout << ansi(NULL, 0) + "                 " << std::endl;
		std::cout << ansi(NULL, 0) + "      .(-1, -1)  " << std::endl;
		std::cout << std::endl;
		std::cout << ansi((short[]){CYAN}, 1) + "My point is in this triangle ? ";
		if(bsp(a, b, c, point))
			std::cout << ansi((short[]){BOLD, GREEN}, 2) + "true" << std::endl;
		else
			std::cout << ansi((short[]){BOLD, RED}, 2) + "false" << std::endl;
	}
	return 0;
}
