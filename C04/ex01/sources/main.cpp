#include <cstdlib>
#include <ctime>
#include "Cat.hpp"
#include "Dog.hpp"

int	main(void) {
	std::system("clear");
	Animal *zoo[50];
	for (int i = 0; i < 25; i++)
		zoo[i] = new Cat();
	for (int i = 25; i < 50; i++)
		zoo[i] = new Dog();
	std::cout << ansi((short[]){BOLD}, 1) + std::string(50, '-') << std::endl;

	for (int i = 0; i < 25; i++) {
		srand(time(NULL));
		int random = rand() % 100;
		std::cout << zoo[i]->getBrain().getIdea(i);
	}

	std::cout << ansi((short[]){BOLD}, 1) + std::string(50, '-') << std::endl;
	delete [] *zoo;
	return 0;
}
