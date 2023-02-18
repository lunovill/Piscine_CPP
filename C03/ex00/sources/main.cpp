#include <cstdlib>
#include <ctime>
#include <iomanip>
#include "ClapTrap.hpp"

# define HP_SIZE 10
# define EP_SIZE 10

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
		return b ? 3 : 5;    
}

int	clash(ClapTrap &attacker, ClapTrap &defender) {

	if (attacker.getHitPoint() < 3) {
		unsigned int	amount = randomDamage(1);
		unsigned int	tmp = (!attacker.getEnergyPoint() || !attacker.getHitPoint()) ? 0 : amount;
		attacker.beRepaired(amount);
		if (!tmp)
			std::cout << ansi(NULL, 0) + attacker.getName() << ansi((short[]){PURPLE, ITALIC}, 2) + " was not able to heal himself." << std::endl;
		else
			std::cout << std::endl;
		std::cout << std::endl;
		return tmp;
	} else {
		unsigned int	amount = randomDamage(0);
		unsigned int	tmp = (attacker.getEnergyPoint() == 0 || !attacker.getHitPoint()) ? 0 : -amount;
		attacker.setAttackDamage(amount);
		attacker.attack(defender.getName());
		defender.takeDamage(amount);
		if (!amount)
			std::cout << ansi(NULL, 0) + defender.getName() << ansi((short[]){PURPLE, ITALIC}, 2) + " dodges the attack !" << std::endl;
		else if (amount == 5)
			std::cout << ansi((short[]){PURPLE, ITALIC}, 2) + "It's a critical hit !" << std::endl;
		else
			std::cout << std::endl;
		return tmp;
	}
}

void	printClash(ClapTrap &Judokrak, ClapTrap &Karaclee, unsigned int i) {
	// Versus case
	std::cout << ansi((short[]){BOLD}, 1);
	std::cout << std::string(HP_SIZE * 3, '_') << std::endl;
	std::cout << std::string(HP_SIZE * 3, ' ') << std::endl;
	size_t	size = HP_SIZE + HP_SIZE / 2 - Judokrak.getName().length() - 3;
	std::cout << std::left << std::setw(size) << std::string(size - 1, '=');
	std::cout << Judokrak.getName() + "  VS  " + Karaclee.getName();
	size = HP_SIZE + HP_SIZE / 2 - Karaclee.getName().length() - 3;
	std::cout << std::right << std::setw(size) << std::string(size - 1, '=') << std::endl;
	std::cout << std::string(HP_SIZE * 3, '_') << std::endl;

	// Hit Point Bar
	std::cout << ((Judokrak.getHitPoint() <= HP_SIZE / 4) ? ansi((short[]){HIGHLIGHT, RED}, 2) : (Judokrak.getHitPoint() <= HP_SIZE / 2) ? ansi((short[]){HIGHLIGHT, YELLOW}, 2) : ansi((short[]){HIGHLIGHT, GREEN}, 2));
	std::cout << std::string(Judokrak.getHitPoint(), ' ');
	std::cout << ansi(NULL, 0) << std::string(HP_SIZE - Judokrak.getHitPoint(), ' ');
	std::cout << ansi(NULL, 0) << std::right << std::setw(HP_SIZE / 2) << 'R' << i << std::string(HP_SIZE / 2 - 1, ' ');
	std::cout << ansi(NULL, 0) << std::string(HP_SIZE - Karaclee.getHitPoint(), ' ');
	std::cout << ((Karaclee.getHitPoint() <= HP_SIZE / 4) ? ansi((short[]){HIGHLIGHT, RED}, 2) : (Karaclee.getHitPoint() <= HP_SIZE / 2) ? ansi((short[]){HIGHLIGHT, YELLOW}, 2) : ansi((short[]){HIGHLIGHT, GREEN}, 2));
	std::cout  << std::string(Karaclee.getHitPoint(), ' ') << std::endl;

	// Stats
	std::cout << ansi((short[]){BOLD}, 1) << "HP";
	std::cout << ((Judokrak.getHitPoint() <= HP_SIZE / 4) ? ansi((short[]){RED}, 1) : (Judokrak.getHitPoint() <= HP_SIZE / 2) ? ansi((short[]){YELLOW}, 1) : ansi((short[]){GREEN}, 1));
	std::cout << std::right << std::setw(HP_SIZE - 2) << Judokrak.getHitPoint();
	std::cout << std::string(HP_SIZE, ' ');
	std::cout << ansi((short[]){BOLD}, 1) << "HP";
	std::cout << ((Karaclee.getHitPoint() <= HP_SIZE / 4) ? ansi((short[]){RED}, 1) : (Karaclee.getHitPoint() <= HP_SIZE / 2) ? ansi((short[]){YELLOW}, 1) : ansi((short[]){GREEN}, 1));
	std::cout << std::right << std::setw(HP_SIZE - 2) << Karaclee.getHitPoint() << std::endl;
	std::cout << ansi((short[]){BOLD}, 1) << "EP";
	std::cout << ((Judokrak.getEnergyPoint() <= EP_SIZE / 4) ? ansi((short[]){PURPLE}, 1) : ansi((short[]){CYAN}, 1));
	std::cout << std::right << std::setw(HP_SIZE - 2) << Judokrak.getEnergyPoint();
	std::cout << std::string(HP_SIZE, ' ');
	std::cout << ansi((short[]){BOLD}, 1) << "EP";
	std::cout << ((Karaclee.getEnergyPoint() <= EP_SIZE / 4) ? ansi((short[]){PURPLE}, 1) : ansi((short[]){CYAN}, 1));
	std::cout << std::right << std::setw(HP_SIZE - 2) << Karaclee.getEnergyPoint() << std::endl;
	std::cout << std::endl;
	return;
}

int    main(void) {
	// Let's Fight
	std::system("clear");
	std::cout << ansi((short[]){BOLD}, 1) + std::string(HP_SIZE + HP_SIZE / 2 - 4, '=') + "COMMENTS" + std::string(HP_SIZE + HP_SIZE / 2 - 4, '=') << std::endl;
	ClapTrap Judokrak("Nageki");
	ClapTrap Karaclee("Dageki");
	std::cout << std::endl;
	std::cout << ansi((short[]){BOLD, GREEN}, 2) << "Let's fight!" << std::endl;
	printClash(Judokrak, Karaclee, 0);
	std::cout << ansi(NULL, 0) + std::string(HP_SIZE, '_') + std::string(HP_SIZE, ' ') + std::string(HP_SIZE, '_') << std::endl;
	std::cout << ansi(NULL, 0) + std::string(HP_SIZE, ' ') + '|' + std::string(HP_SIZE - 2, ' ') + '|' + std::string(HP_SIZE, ' ') << std::endl;
	std::cout << ansi(NULL, 0) + std::string(HP_SIZE / 2 - 1, ' ') + "--" + std::string(HP_SIZE / 2 - 1, ' ') + '|' + std::string(HP_SIZE - 2, ' ') + '|' + std::string(HP_SIZE / 2 - 1, ' ') + "--" + std::string(HP_SIZE / 2 - 1, ' ') << std::endl;
	std::cout << ansi(NULL, 0) + std::string(HP_SIZE, '_') + '|' + std::string(HP_SIZE - 2, ' ') + '|' + std::string(HP_SIZE, '_') << std::endl;
	std::cout << std::endl;
	std::cout << ansi((short[]){NORMAL, ITALIC}, 2) + "Press ENTER to continue...";
	std::cin.get();

	for (unsigned int i = 0; Judokrak.getEnergyPoint() && Karaclee.getHitPoint() && Karaclee.getEnergyPoint(); ++i) {
		std::system("clear");
		std::cout << ansi((short[]){BOLD}, 1) + std::string(HP_SIZE + HP_SIZE / 2 - 4, '=') + "COMMENTS" + std::string(HP_SIZE + HP_SIZE / 2 - 4, '=') << std::endl;
		int amount = clash(Judokrak, Karaclee);
		if (!Judokrak.getHitPoint())
			std::cout << ansi(NULL, 0) + Judokrak.getName() << ansi((short[]){BOLD, BLUE}, 2) +  " is K.O" << std::endl;
		else
			std::cout << std::endl;
		printClash(Judokrak, Karaclee, i);
	
		// Attack case
		std::cout << ansi(NULL, 0) + std::string(HP_SIZE, '_') + std::string(HP_SIZE, ' ') + std::string(HP_SIZE, '_') << std::endl;
		std::cout << ansi(NULL, 0) + std::string(HP_SIZE, ' ') + '|' + std::string(HP_SIZE - 2, ' ') + '|' + std::string(HP_SIZE, ' ') << std::endl;
		std::cout << ((amount < 0) ? ansi((short[]){RED}, 1) : (amount == 0) ? ansi(NULL, 0) : ansi((short[]){GREEN}, 1));
		std::cout << std::string(HP_SIZE / 2 - 1, ' ') << std::showpos << amount << std::string(HP_SIZE / 2 - 1, ' ');
		std::cout << ansi(NULL, 0) + '|' + std::string(HP_SIZE - 2, ' ') + '|' + std::string(HP_SIZE / 2 - 1, ' ') + "--" + std::string(HP_SIZE / 2 - 1, ' ') << std::endl;
		std::cout << ansi(NULL, 0) + std::string(HP_SIZE, '_') + '|' + std::string(HP_SIZE - 2, ' ') + '|' + std::string(HP_SIZE, '_') << std::endl;
		std::cout << std::endl;

		std::cout << ansi((short[]){NORMAL, ITALIC}, 2) + "Press ENTER to continue...";
		std::cin.get();
		if (!Judokrak.getHitPoint())
			break;

		std::system("clear");
		std::cout << ansi((short[]){BOLD}, 1) + std::string(HP_SIZE + HP_SIZE / 2 - 4, '=') + "COMMENTS" + std::string(HP_SIZE + HP_SIZE / 2 - 4, '=') << std::endl;
		amount = clash(Karaclee, Judokrak);
		if (!Karaclee.getHitPoint())
			std::cout << ansi(NULL, 0) + Karaclee.getName() << ansi((short[]){BOLD, RED}, 2) +  " is K.O." << std::endl;
		else if (!Judokrak.getEnergyPoint() && !Karaclee.getEnergyPoint())
			std::cout << ansi((short[]){BOLD, BLUE}, 2) +  "The two ClapTraps are exhausted. Draw!" << std::endl;
		else
			std::cout << std::endl;
		printClash(Judokrak, Karaclee, i);

		// Attack case
		std::cout << ansi(NULL, 0) + std::string(HP_SIZE, '_') + std::string(HP_SIZE, ' ') + std::string(HP_SIZE, '_') << std::endl;
		std::cout << ansi(NULL, 0) + std::string(HP_SIZE, ' ') + '|' + std::string(HP_SIZE - 2, ' ') + '|' + std::string(HP_SIZE, ' ') << std::endl;
		std::cout << ansi(NULL, 0) + std::string(HP_SIZE / 2 - 1, ' ') + "--" + std::string(HP_SIZE / 2 - 1, ' ') + '|' + std::string(HP_SIZE - 2, ' ') + '|';
		std::cout << ((amount < 0) ? ansi((short[]){RED}, 1) : (amount == 0) ? ansi(NULL, 0) : ansi((short[]){GREEN}, 1));
		std::cout << std::string(HP_SIZE / 2 - 1, ' ') << std::showpos << amount << std::string(HP_SIZE / 2 - 1, ' ') << std::endl;
		std::cout << ansi(NULL, 0) + std::string(HP_SIZE, '_') + '|' + std::string(HP_SIZE - 2, ' ') + '|' + std::string(HP_SIZE, '_') << std::endl;
		std::cout << std::endl;
		std::cout << ansi((short[]){NORMAL, ITALIC}, 2) + "Press ENTER to continue...";
		std::cin.get();
	}
	return 0;
}
