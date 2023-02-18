#include <cstdlib>
#include <ctime>
#include <iomanip>
#include "ScavTrap.hpp"

# define SIZE 20
# define HP_SIZE 100
# define EP_SIZE 50

unsigned int    randomDamage(bool b) {
	srand(time(NULL));
	int random = rand() % 100;
	if (random < 10)
		return b ? 1 : 0;
	else if (random < 45)
		return 1;
	else if (random < 70)
		return b ? 1 : 2;
	else if (random < 90)
		return b ? 2 : 3;
	else
		return b ? 3 : 4;    
}

int	clash(ScavTrap &attacker, ScavTrap &defender) {

	if (attacker.getHitPoint() < 20) {
		unsigned int	amount = randomDamage(1) * 5 + 25;
		unsigned int	tmp = (!attacker.getEnergyPoint() || !attacker.getHitPoint()) ? 0 : amount;
		attacker.beRepaired(amount);
		if (!tmp)
			std::cout << ansi(NULL, 0) + attacker.getName() << ansi((short[]){PURPLE, ITALIC}, 2) + " was not able to heal himself." << std::endl;
		else
			std::cout << std::endl;
		std::cout << std::endl;
		std::cout << std::endl;
		return tmp;
	} else {
		unsigned int	amount = 20;
		unsigned int	tmp = (attacker.getEnergyPoint() == 0 || !attacker.getHitPoint()) ? 0 : -amount;
		unsigned int gate = randomDamage(1);
		attacker.attack(defender.getName());
		if (gate == 1) {
			defender.takeDamage(amount);
			std::cout << ansi((short[]){PURPLE, ITALIC}, 2) + "It's a critical hit !" << std::endl;
			std::cout << std::endl;
		} else {
			attacker.guardGate();
			amount -= (randomDamage(1) + 1) * 5 ;
			defender.takeDamage(amount);
			if (!amount) 
				std::cout << ansi(NULL, 0) + defender.getName() << ansi((short[]){PURPLE, ITALIC}, 2) + " dodges the attack !" << std::endl;
			else
				std::cout << std::endl;
			tmp = tmp ? -amount : tmp;
		}
		return tmp;
	}
}

void	printClash(ScavTrap &Judokrak, ScavTrap &Karaclee, unsigned int i) {
	// Versus case
	std::cout << ansi((short[]){BOLD}, 1);
	std::cout << std::string(SIZE * 3, '_') << std::endl;
	std::cout << std::string(SIZE * 3, ' ') << std::endl;
	size_t	size = SIZE + SIZE / 2 - Judokrak.getName().length() - 3;
	std::cout << std::left << std::setw(size) << std::string(size - 1, '=');
	std::cout << Judokrak.getName() + "  VS  " + Karaclee.getName();
	size = SIZE + SIZE / 2 - Karaclee.getName().length() - 3;
	std::cout << std::right << std::setw(size) << std::string(size - 1, '=') << std::endl;
	std::cout << std::string(SIZE * 3, '_') << std::endl;

	// Hit Point Bar
	std::cout << ((Judokrak.getHitPoint() <= HP_SIZE / 4) ? ansi((short[]){HIGHLIGHT, RED}, 2) : (Judokrak.getHitPoint() <= HP_SIZE / 2) ? ansi((short[]){HIGHLIGHT, YELLOW}, 2) : ansi((short[]){HIGHLIGHT, GREEN}, 2));
	std::cout << std::string(Judokrak.getHitPoint() / 5, ' ');
	std::cout << ansi(NULL, 0) << std::string(SIZE - Judokrak.getHitPoint() / 5, ' ');
	std::cout << ansi(NULL, 0) << std::right << std::setw(SIZE / 2) << 'R' << std::left << std::setw(SIZE / 2) << i;
	std::cout << ansi(NULL, 0) << std::string(SIZE - Karaclee.getHitPoint() / 5, ' ');
	std::cout << ((Karaclee.getHitPoint() <= HP_SIZE / 4) ? ansi((short[]){HIGHLIGHT, RED}, 2) : (Karaclee.getHitPoint() <= HP_SIZE / 2) ? ansi((short[]){HIGHLIGHT, YELLOW}, 2) : ansi((short[]){HIGHLIGHT, GREEN}, 2));
	std::cout  << std::string(Karaclee.getHitPoint() / 5, ' ') << std::endl;

	// Stats
	std::cout << ansi((short[]){BOLD}, 1) << "HP";
	std::cout << ((Judokrak.getHitPoint() <= HP_SIZE / 4) ? ansi((short[]){RED}, 1) : (Judokrak.getHitPoint() <= HP_SIZE / 2) ? ansi((short[]){YELLOW}, 1) : ansi((short[]){GREEN}, 1));
	std::cout << std::right << std::setw(SIZE - 2) << Judokrak.getHitPoint();
	std::cout << std::string(SIZE, ' ');
	std::cout << ansi((short[]){BOLD}, 1) << "HP";
	std::cout << ((Karaclee.getHitPoint() <= HP_SIZE / 4) ? ansi((short[]){RED}, 1) : (Karaclee.getHitPoint() <= HP_SIZE / 2) ? ansi((short[]){YELLOW}, 1) : ansi((short[]){GREEN}, 1));
	std::cout << std::right << std::setw(SIZE - 2) << Karaclee.getHitPoint() << std::endl;
	std::cout << ansi((short[]){BOLD}, 1) << "EP";
	std::cout << ((Judokrak.getEnergyPoint() <= EP_SIZE / 4) ? ansi((short[]){PURPLE}, 1) : ansi((short[]){CYAN}, 1));
	std::cout << std::right << std::setw(SIZE - 2) << Judokrak.getEnergyPoint();
	std::cout << std::string(SIZE, ' ');
	std::cout << ansi((short[]){BOLD}, 1) << "EP";
	std::cout << ((Karaclee.getEnergyPoint() <= EP_SIZE / 4) ? ansi((short[]){PURPLE}, 1) : ansi((short[]){CYAN}, 1));
	std::cout << std::right << std::setw(SIZE - 2) << Karaclee.getEnergyPoint() << std::endl;
	std::cout << std::endl;
	return;
}

int    main(void) {
	// Let's Fight
	std::system("clear");
	std::cout << ansi((short[]){BOLD}, 1) + std::string(SIZE + SIZE / 2 - 4, '=') + "COMMENTS" + std::string(SIZE + SIZE / 2 - 4, '=') << std::endl;
	ScavTrap Judokrak("Nageki");
	ScavTrap Karaclee("Dageki");
	std::cout << ansi((short[]){BOLD, GREEN}, 2) << "Let's fight!" << std::endl;
	printClash(Judokrak, Karaclee, 0);
	std::cout << ansi(NULL, 0) + std::string(SIZE, '_') + std::string(SIZE, ' ') + std::string(SIZE, '_') << std::endl;
	std::cout << ansi(NULL, 0) + std::string(SIZE, ' ') + '|' + std::string(SIZE - 2, ' ') + '|' + std::string(SIZE, ' ') << std::endl;
	std::cout << ansi(NULL, 0) + std::string(SIZE / 2 - 1, ' ') + "--" + std::string(SIZE / 2 - 1, ' ') + '|' + std::string(SIZE - 2, ' ') + '|' + std::string(SIZE / 2 - 1, ' ') + "--" + std::string(SIZE / 2 - 1, ' ') << std::endl;
	std::cout << ansi(NULL, 0) + std::string(SIZE, '_') + '|' + std::string(SIZE - 2, ' ') + '|' + std::string(SIZE, '_') << std::endl;
	std::cout << std::endl;
	std::cout << ansi((short[]){NORMAL, ITALIC}, 2) + "Press ENTER to continue...";
	std::cin.get();

	for (unsigned int i = 0; Judokrak.getEnergyPoint() && Karaclee.getHitPoint() && Karaclee.getEnergyPoint(); ++i) {
		std::system("clear");
		std::cout << ansi((short[]){BOLD}, 1) + std::string(SIZE + SIZE / 2 - 4, '=') + "COMMENTS" + std::string(SIZE + SIZE / 2 - 4, '=') << std::endl;
		int amount = clash(Judokrak, Karaclee);
		if (!Judokrak.getHitPoint())
			std::cout << ansi(NULL, 0) + Judokrak.getName() << ansi((short[]){BOLD, BLUE}, 2) +  " is K.O" << std::endl;
		else
			std::cout << std::endl;
		printClash(Judokrak, Karaclee, i);
	
		// Attack case
		std::cout << ansi(NULL, 0) + std::string(SIZE, '_') + std::string(SIZE, ' ') + std::string(SIZE, '_') << std::endl;
		std::cout << ansi(NULL, 0) + std::string(SIZE, ' ') + '|' + std::string(SIZE - 2, ' ') + '|' + std::string(SIZE, ' ') << std::endl;
		std::cout << ((amount < 0) ? ansi((short[]){RED}, 1) : (amount == 0) ? ansi(NULL, 0) : ansi((short[]){GREEN}, 1));
		std::cout << std::right << std::setw(SIZE / 2 + 1) << std::showpos << amount << std::string(SIZE / 2 - 1, ' ');
		std::cout << ansi(NULL, 0) + '|' + std::string(SIZE - 2, ' ') + '|' + std::string(SIZE / 2 - 1, ' ') + "--" + std::string(SIZE / 2 - 1, ' ') << std::endl;
		std::cout << ansi(NULL, 0) + std::string(SIZE, '_') + '|' + std::string(SIZE - 2, ' ') + '|' + std::string(SIZE, '_') << std::endl;
		std::cout << std::endl;

		std::cout << ansi((short[]){NORMAL, ITALIC}, 2) + "Press ENTER to continue...";
		std::cin.get();
		if (!Judokrak.getHitPoint())
			break;

		std::system("clear");
		std::cout << ansi((short[]){BOLD}, 1) + std::string(SIZE + SIZE / 2 - 4, '=') + "COMMENTS" + std::string(SIZE + SIZE / 2 - 4, '=') << std::endl;
		amount = clash(Karaclee, Judokrak);
		if (!Karaclee.getHitPoint())
			std::cout << ansi(NULL, 0) + Karaclee.getName() << ansi((short[]){BOLD, RED}, 2) +  " is K.O." << std::endl;
		else if (!Judokrak.getEnergyPoint() && !Karaclee.getEnergyPoint())
			std::cout << ansi((short[]){BOLD, BLUE}, 2) +  "The two Scavtrap are exhausted. Draw!" << std::endl;
		else
			std::cout << std::endl;
		printClash(Judokrak, Karaclee, i);

		// Attack case
		std::cout << ansi(NULL, 0) + std::string(SIZE, '_') + std::string(SIZE, ' ') + std::string(SIZE, '_') << std::endl;
		std::cout << ansi(NULL, 0) + std::string(SIZE, ' ') + '|' + std::string(SIZE - 2, ' ') + '|' + std::string(SIZE, ' ') << std::endl;
		std::cout << ansi(NULL, 0) + std::string(SIZE / 2 - 1, ' ') + "--" + std::string(SIZE / 2 - 1, ' ') + '|' + std::string(SIZE - 2, ' ') + '|';
		std::cout << ((amount < 0) ? ansi((short[]){RED}, 1) : (amount == 0) ? ansi(NULL, 0) : ansi((short[]){GREEN}, 1));
		std::cout << std::string(SIZE / 2 - 1, ' ') << std::showpos << amount << std::string(SIZE / 2 - 1, ' ') << std::endl;
		std::cout << ansi(NULL, 0) + std::string(SIZE, '_') + '|' + std::string(SIZE - 2, ' ') + '|' + std::string(SIZE, '_') << std::endl;
		std::cout << std::endl;
		std::cout << ansi((short[]){NORMAL, ITALIC}, 2) + "Press ENTER to continue...";
		std::cin.get();
	}
	return 0;
}
