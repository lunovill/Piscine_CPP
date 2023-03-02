#include <cstdlib>
#include "Cat.hpp"
#include "Dog.hpp"

int	main(void) {
	std::system("clear");
	Animal *x = new Animal("random");
	Animal *felix = new Cat();
	Animal *rex = new Dog();
	std::cout << ansi((short[]){BOLD}, 1) + std::string(50, '-') << std::endl;

	std::cout << ansi((short[]){CYAN}, 1) + "Il était une fois une famille qui avait un " + felix->getType() + ansi((short[]){CYAN}, 1) + " nommé Felix et un " + rex->getType() + ansi((short[]){CYAN}, 1) + " nommé Rex. Ils aimaient tous les deux jouer et courir dans le jardin. Un jour, ils ont invité un nouvel ami à se joindre à eux, un animal " + x->getType() + ansi((short[]){CYAN}, 1) + " qui faisait ";
	x->makeSound();
	std::cout << ansi((short[]){CYAN}, 1) + ". Personne ne savait ce qu'était cet animal, mais il avait des yeux doux et une fourrure douce et soyeuse. Felix dit ";
	felix->makeSound();
	std::cout << ansi((short[]){CYAN}, 1) + " comme pour dire bonjour, Rex suivit avec un ";
	rex->makeSound();
	std::cout << ansi((short[]){CYAN}, 1) + " enthousiaste et l'animal " + x->getType() + ansi((short[]){CYAN}, 1) + " s'est simplement assis et les a observés." << std::endl;
	std::cout << std::endl;
	std::cout << ansi((short[]){CYAN}, 1) + "Plus tard, alors que Felix se prélassait au soleil et que Rex jouait avec une balle, l'animal " + x->getType() + ansi((short[]){CYAN}, 1) + " restait tranquillement assis. Soudain, il s'est levé et a commencé à courir à travers le jardin. Felix et Rex ont été surpris et se sont précipités pour le suivre. Au bout d'un moment, l'animal " + x->getType() + ansi((short[]){CYAN}, 1) + " s'est arrêté et a commencé à sautiller joyeusement. Finalement, l'animal " + x->getType() + ansi((short[]){CYAN}, 1) + " s'est assis à nouveau, heureux de s'etre fait de nouveaux amis." << std::endl;
	std::cout << std::endl;
	std::cout << ansi((short[]){CYAN}, 1) + "Et même s'il ne faisait ";
	x->makeSound();
	std::cout << ansi((short[]){CYAN}, 1) + ", l'animal " + x->getType() + ansi((short[]){CYAN}, 1) + " était tout aussi aimé que Felix et Rex. Chacun avait sa propre personnalité unique, mais tous les trois étaient des amis inséparables" << std::endl;

	std::cout << ansi((short[]){BOLD}, 1) + std::string(50, '-') << std::endl;
	delete rex;
	delete felix;
	delete x;
	return 0;
}
