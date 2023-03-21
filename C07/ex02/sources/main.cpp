#include "Array.hpp"

int	main(void) {
	try {
		Array<std::string> a(5);
		std::cout << a.getArray(4) << std::endl;
		std::cout << a.getArray(5) << std::endl;
	} catch (Array<std::string>::InvalidIndex &e)
	{
		std::cerr << e.what() << std::endl;
	}
	return 0;
}