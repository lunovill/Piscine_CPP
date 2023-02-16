#include "Zombie.hpp"

int		main(void) {
	Zombie *adam = newZombie("Adam");

	randomChump("Manu");
	adam->announce();
	delete adam;
	return 0;
}
