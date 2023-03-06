#include "Character.hpp"
#include "Cure.hpp"
#include "Ice.hpp"
#include "MateriaSource.hpp"

int main(void) {
	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	ICharacter* me = new Character("me");
	AMateria* tmp;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);
	ICharacter* bob = new Character("bob");
	std::cout << ansi((short[]){BOLD}, 1) << std::string(30, '-') << std::endl;
	me->use(0, *bob);
	me->use(1, *bob);
	std::cout << ansi((short[]){BOLD}, 1) << std::string(30, '-') << std::endl;
	delete bob;
	delete me;
	delete src;
	return 0;
}