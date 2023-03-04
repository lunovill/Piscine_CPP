#include <cstdlib>
#include <ctime>
#include <iomanip>
#include "Cat.hpp"
#include "Dog.hpp"


#define	SIZE 50
#define WIDTH 100

static void	printIdea(std::string type, int index, std::string idea, std::string color, size_t size) {

	if (idea.length() < WIDTH / 2) {
		std::cout << std::string(size + 1, ' ') << color << std::string(idea.length() + 2, '_') << ' ' << std::endl;
		std::cout << std::string(size, ' ') << color << "| " << std::string(idea.length(), ' ') << " |" << std::endl;
		std::cout << std::string(size, ' ') << color << "| " << idea << " |" << std::endl;
		std::cout << std::string(size, ' ') << color << "|" << std::string(idea.length() + 2, '_') << "|" << std::endl;
	} else 	{
		size = (size != 0) ? WIDTH / 2 : size;
		std::cout << std::string(size + 1, ' ') << color << std::string(WIDTH / 2 + 2, '_') << ' ' << std::endl;
		std::cout << std::string(size, ' ') << color << "| " << std::string(WIDTH / 2, ' ') << " |" << std::endl;
		for (size_t i = 0; i < idea.length(); i += WIDTH / 2) {
			std::cout << std::string(size, ' ') << color << "| " << std::left << std::setw(50) << idea.substr(i, WIDTH / 2) << " |" << std::endl;
		}
		std::cout << std::string(size, ' ') << color << "|" << std::string(WIDTH / 2 + 2, '_') << "|" << std::endl;
	}
	std::cout << std::string(size + 1, ' ') << color << type << " " << index << std::endl;
	return ; 
}

int	main(void) {
	std::system("clear");
	Animal *zoo[SIZE];
	for (int i = 0; i < SIZE / 2; i++) {
		zoo[i] = new Cat();
		zoo[SIZE / 2 + i] = new Dog();
	}

	std::cout << ansi((short[]){BOLD}, 1) + std::string(SIZE, '-') << std::endl;
	for (int i = 0; i < SIZE / 2; i++) {
		srand(time(NULL));
		int random = rand() % 100;
	
		Cat *cookie = dynamic_cast<Cat *>(zoo[i]);
		printIdea(cookie->getType(), i + 1, cookie->getBrain()->getIdea(random), ansi((short[]){ITALIC, BLUE}, 2), 0);
		// Cat	cookie(*dynamic_cast<Cat *>(zoo[i]));
		// printIdea(cookie.getType(), i + 1, cookie.getBrain()->getIdea(random), ansi((short[]){ITALIC, BLUE}, 2), 0);
		Dog *cake = dynamic_cast<Dog *>(zoo[SIZE / 2 + i]);
		printIdea(cake->getType(), i + 1, cake->getBrain()->getIdea(random), ansi((short[]){ITALIC, YELLOW}, 2), WIDTH - cake->getBrain()->getIdea(random).length());
		std::cout << ansi((short[]){ITALIC}, 1) + "Press ENTER to continue...";
		std::cin.get();
		if (std::cin.eof())
			break;
		std::cout << "\033[A";
	}
	std::cout << ansi((short[]){BOLD}, 1) + std::string(SIZE, '-') << std::endl;

	for (int i = 0; i < SIZE / 2; i++) {
		delete zoo[i];
		zoo[i] = NULL;
	}
	for (int i = SIZE / 2; i < SIZE; i++) {
		delete zoo[i];
		zoo[i] = NULL;
	}
	return 0;
}