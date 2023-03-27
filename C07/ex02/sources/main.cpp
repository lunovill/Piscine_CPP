#include "Array.hpp"

int	main(void) {
	try {
		Array<std::string> a(5);
		a[0] = "Je";
		a[1] = "suis";
		a[2] = "un";
		a[3] = "test";
		a[4] = "!";
		std::cout << a;
		a[5];
	} catch (Array<std::string>::InvalidIndex &e)
	{
		std::cerr << ansi((short[]){UNDERLINE, DARK}, 2) + "Error: throw:" << ansi(NULL, 0) + " " + e.what() << std::endl;
	}
	try {
		Array<short> a(5);
		a[0] = 4;
		a[1] = 2;
		std::cout << a;
		a[-1];
	} catch (Array<short>::InvalidIndex &e)
	{
		std::cerr << ansi((short[]){UNDERLINE, DARK}, 2) + "Error: throw:" << ansi(NULL, 0) + " " + e.what() << std::endl;
	}
	return 0;
}