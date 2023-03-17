#include <cstdlib>
#include <ctime>
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base    *generate(void) {
	int random = rand() % 3;
	switch (random) {
		case 0:
			return new A;
		case 1:
			return new B;
		case 2:
			return new C;
		default:
			return NULL;
	}
}

void	identify(Base* p) {
	if (dynamic_cast<A *>(p))
		std::cout << ansi(NULL, 0) + "The Base ptr identify is " << ansi((short[]){ITALIC, CYAN}, 2) + "A" << std::endl;
	else if (dynamic_cast<B *>(p))
		std::cout << ansi(NULL, 0) + "The Base ptr identify is " << ansi((short[]){ITALIC, YELLOW}, 2) +"B" << std::endl;
	else if (dynamic_cast<C *>(p))
		std::cout << ansi(NULL, 0) + "The Base ptr identify is " << ansi((short[]){ITALIC, BLUE}, 2) + "C" << std::endl;
	return;
}

void identify(Base& p) {
	try {
		p = dynamic_cast<A &>(p);
		std::cout << ansi(NULL, 0) + "The Base ref identify is " << ansi((short[]){ITALIC, DARK, CYAN}, 3) + "A" << std::endl;
	} catch (std::exception) {
		try {
			p = dynamic_cast<B &>(p);
			std::cout << ansi(NULL, 0) + "The Base ref identify is " << ansi((short[]){ITALIC, DARK, YELLOW}, 3) + "B" << std::endl;
		} catch (std::exception) {
			try {
				p = dynamic_cast<C &>(p);
				std::cout << ansi(NULL, 0) + "The Base ref identify is " << ansi((short[]){ITALIC, DARK, BLUE}, 3) + "C" << std::endl;
			} catch (std::exception) {
				std::cerr <<  ansi((short[]){BOLD, RED}, 2) << "Error" << std::endl;
			}
		}
	}
	return;
}

int	main(void) {
	srand(time(NULL));
	Base *ptr;

	ptr = generate();
	identify(ptr);
	identify(*ptr);

	delete ptr;
	return 0;
}
