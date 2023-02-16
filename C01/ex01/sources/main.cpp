#include "Zombie.hpp"

int		main(void) {
	Zombie *brice = zombieHorde(4, "Brice");

	for (int i = 0; i < 4; i++)
		brice[i].announce();

	Zombie *dave = zombieHorde(2, "dave");

	for (int i = 0; i < 2; i++)
		dave[i].announce();
	delete [] brice;
	delete [] dave;
	return 0;
}
