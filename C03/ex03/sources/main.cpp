#include <cstdlib>
#include <ctime>
#include <iomanip>
#include "DiamondTrap.hpp"

# define SIZE 20
# define HP_SIZE 100
# define EP_SIZE 50

static unsigned int    randomNumber(bool b) {
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

static int	clash(DiamondTrap &attacker, DiamondTrap &defender) {

	if (attacker.getHitPoint() < 20) {
		unsigned int	amount = randomNumber(1) * 5 + 25;
		unsigned int	tmp = (!attacker.getEnergyPoint() || !attacker.getHitPoint()) ? 0 : amount;
		attacker.beRepaired(amount);
		if (!tmp)
			std::cout << ansi(NULL, 0) + attacker.getName() << ansi((short[]){PURPLE, ITALIC}, 2) + " was not able to heal himself." << std::endl;
		else
			std::cout << std::endl;
		std::cout << std::endl;
		std::cout << std::endl;
		std::cout << std::endl;
		std::cout << std::endl;
		std::cout << std::endl;
		std::cout << std::endl;
		return tmp;
	} else {
		unsigned int	amount = attacker.getAttackDamage();
		unsigned int	tmp = (attacker.getEnergyPoint() == 0 || !attacker.getHitPoint()) ? 0 : -amount;
		unsigned int gate = randomNumber(1);
		attacker.attack(defender.getName());
		if (randomNumber(0) == 0) {
			attacker.highFivesGuys();
			if (randomNumber(0) == 0) {
				attacker.setAttackDamage(100);
				std::cout << ansi(NULL, 0) + defender.getName() << ansi((short[]){PURPLE, ITALIC}, 2) + " explodes after accepting, don't trust strangers ^^" << std::endl;
				defender.takeDamage(100);
			} else {
				std::cout << ansi(NULL, 0) + defender.getName() << ansi((short[]){PURPLE, ITALIC}, 2) + " doesn't trust his opponent." << std::endl;
				std::cout << std::endl;
			}
		} else if (gate == 1) {
			defender.takeDamage(amount);
			std::cout << ansi((short[]){PURPLE, ITALIC}, 2) + "It's a critical hit !" << std::endl;
			std::cout << std::endl;
		} else {
			attacker.guardGate();
			amount -= (randomNumber(1) + 1) * 5 ;
			defender.takeDamage(amount);
			if (!amount) 
				std::cout << ansi(NULL, 0) + defender.getName() << ansi((short[]){PURPLE, ITALIC}, 2) + " dodges the attack !" << std::endl;
			else
				std::cout << std::endl;
			tmp = tmp ? -amount : tmp;
		}
		std::cout << std::endl;
		std::cout << std::endl;
		std::cout << std::endl;
		std::cout << std::endl;
		return tmp;
	}
}

static void	printClash(DiamondTrap &robotXV, DiamondTrap &robotXK, unsigned int i) {
	// Versus case
	std::cout << ansi((short[]){BOLD}, 1);
	std::cout << std::string(SIZE * 3, '_') << std::endl;
	std::cout << std::string(SIZE * 3, ' ') << std::endl;
	size_t	size = SIZE + SIZE / 2 - robotXV.getName().length() - 3;
	std::cout << std::left << std::setw(size) << std::string(size - 1, '=');
	std::cout << robotXV.getName() + "  VS  " + robotXK.getName();
	size = SIZE + SIZE / 2 - robotXK.getName().length() - 3;
	std::cout << std::right << std::setw(size) << std::string(size - 1, '=') << std::endl;
	std::cout << std::string(SIZE * 3, '_') << std::endl;

	// Hit Point Bar
	std::cout << ((robotXV.getHitPoint() <= HP_SIZE / 4) ? ansi((short[]){HIGHLIGHT, RED}, 2) : (robotXV.getHitPoint() <= HP_SIZE / 2) ? ansi((short[]){HIGHLIGHT, YELLOW}, 2) : ansi((short[]){HIGHLIGHT, GREEN}, 2));
	std::cout << std::string(robotXV.getHitPoint() / 5, ' ');
	std::cout << ansi(NULL, 0) << std::string(SIZE - robotXV.getHitPoint() / 5, ' ');
	std::cout << ansi(NULL, 0) << std::right << std::setw(SIZE / 2) << 'R' << std::left << std::setw(SIZE / 2) << i;
	std::cout << ansi(NULL, 0) << std::string(SIZE - robotXK.getHitPoint() / 5, ' ');
	std::cout << ((robotXK.getHitPoint() <= HP_SIZE / 4) ? ansi((short[]){HIGHLIGHT, RED}, 2) : (robotXK.getHitPoint() <= HP_SIZE / 2) ? ansi((short[]){HIGHLIGHT, YELLOW}, 2) : ansi((short[]){HIGHLIGHT, GREEN}, 2));
	std::cout  << std::string(robotXK.getHitPoint() / 5, ' ') << std::endl;

	// Stats
	std::cout << ansi((short[]){BOLD}, 1) << "HP";
	std::cout << ((robotXV.getHitPoint() <= HP_SIZE / 4) ? ansi((short[]){RED}, 1) : (robotXV.getHitPoint() <= HP_SIZE / 2) ? ansi((short[]){YELLOW}, 1) : ansi((short[]){GREEN}, 1));
	std::cout << std::right << std::setw(SIZE - 2) << robotXV.getHitPoint();
	std::cout << std::string(SIZE, ' ');
	std::cout << ansi((short[]){BOLD}, 1) << "HP";
	std::cout << ((robotXK.getHitPoint() <= HP_SIZE / 4) ? ansi((short[]){RED}, 1) : (robotXK.getHitPoint() <= HP_SIZE / 2) ? ansi((short[]){YELLOW}, 1) : ansi((short[]){GREEN}, 1));
	std::cout << std::right << std::setw(SIZE - 2) << robotXK.getHitPoint() << std::endl;
	std::cout << ansi((short[]){BOLD}, 1) << "EP";
	std::cout << ((robotXV.getEnergyPoint() <= EP_SIZE / 4) ? ansi((short[]){PURPLE}, 1) : ansi((short[]){CYAN}, 1));
	std::cout << std::right << std::setw(SIZE - 2) << robotXV.getEnergyPoint();
	std::cout << std::string(SIZE, ' ');
	std::cout << ansi((short[]){BOLD}, 1) << "EP";
	std::cout << ((robotXK.getEnergyPoint() <= EP_SIZE / 4) ? ansi((short[]){PURPLE}, 1) : ansi((short[]){CYAN}, 1));
	std::cout << std::right << std::setw(SIZE - 2) << robotXK.getEnergyPoint() << std::endl;
	std::cout << std::endl;
	return;
}

int    main(void) {
	// Let's Fight
	std::system("clear");
	std::cout << ansi((short[]){BOLD}, 1) + std::string(SIZE + SIZE / 2 - 4, '=') + "COMMENTS" + std::string(SIZE + SIZE / 2 - 4, '=') << std::endl;
	DiamondTrap robotXV("XV01ST");
	DiamondTrap robotXK("XK01ST");
	std::cout << ansi((short[]){BOLD, GREEN}, 2) << "Let's fight!" << std::endl;
	printClash(robotXV, robotXK, 0);
	std::cout << ansi(NULL, 0) + std::string(SIZE, '_') + std::string(SIZE, ' ') + std::string(SIZE, '_') << std::endl;
	std::cout << ansi(NULL, 0) + std::string(SIZE, ' ') + '|' + std::string(SIZE - 2, ' ') + '|' + std::string(SIZE, ' ') << std::endl;
	std::cout << ansi(NULL, 0) + std::string(SIZE / 2 - 1, ' ') + "--" + std::string(SIZE / 2 - 1, ' ') + '|' + std::string(SIZE - 2, ' ') + '|' + std::string(SIZE / 2 - 1, ' ') + "--" + std::string(SIZE / 2 - 1, ' ') << std::endl;
	std::cout << ansi(NULL, 0) + std::string(SIZE, '_') + '|' + std::string(SIZE - 2, ' ') + '|' + std::string(SIZE, '_') << std::endl;
	std::cout << std::endl;
	std::cout << ansi((short[]){NORMAL, ITALIC}, 2) + "Press ENTER to continue..." << std::endl;
	std::cin.get();
	if (std::cin.eof())
		return 0;

	for (unsigned int i = 0; robotXV.getEnergyPoint() && robotXK.getHitPoint() && robotXK.getEnergyPoint(); ++i) {
		std::system("clear");
		std::cout << ansi((short[]){BOLD}, 1) + std::string(SIZE + SIZE / 2 - 4, '=') + "COMMENTS" + std::string(SIZE + SIZE / 2 - 4, '=') << std::endl;
		int amount = clash(robotXV, robotXK);
		if (!robotXV.getHitPoint())
			std::cout << ansi(NULL, 0) + robotXV.getName() << ansi((short[]){BOLD, RED}, 2) +  " is K.O" << std::endl;
		else
			std::cout << std::endl;
		printClash(robotXV, robotXK, i);
	
		// Attack case
		std::cout << ansi(NULL, 0) + std::string(SIZE, '_') + std::string(SIZE, ' ') + std::string(SIZE, '_') << std::endl;
		std::cout << ansi(NULL, 0) + std::string(SIZE, ' ') + '|' + std::string(SIZE - 2, ' ') + '|' + std::string(SIZE, ' ') << std::endl;
		std::cout << ((amount < 0) ? ansi((short[]){RED}, 1) : (amount == 0) ? ansi(NULL, 0) : ansi((short[]){GREEN}, 1));
		std::cout << std::right << std::setw(SIZE / 2 + 1) << std::showpos << amount << std::string(SIZE / 2 - 1, ' ');
		std::cout << ansi(NULL, 0) + '|' + std::string(SIZE - 2, ' ') + '|' + std::string(SIZE / 2 - 1, ' ') + "--" + std::string(SIZE / 2 - 1, ' ') << std::endl;
		std::cout << ansi(NULL, 0) + std::string(SIZE, '_') + '|' + std::string(SIZE - 2, ' ') + '|' + std::string(SIZE, '_') << std::endl;
		std::cout << std::endl;

		std::cout << ansi((short[]){NORMAL, ITALIC}, 2) + "Press ENTER to continue..." << std::endl;
		std::cin.get();
		if (std::cin.eof())
			break;
		if (!robotXV.getHitPoint())
			break;

		std::system("clear");
		std::cout << ansi((short[]){BOLD}, 1) + std::string(SIZE + SIZE / 2 - 4, '=') + "COMMENTS" + std::string(SIZE + SIZE / 2 - 4, '=') << std::endl;
		amount = clash(robotXK, robotXV);
		if (!robotXK.getHitPoint())
			std::cout << ansi(NULL, 0) + robotXK.getName() << ansi((short[]){BOLD, RED}, 2) +  " is K.O." << std::endl;
		else if (!robotXV.getEnergyPoint() && !robotXK.getEnergyPoint())
			std::cout << ansi((short[]){BOLD, BLUE}, 2) +  "The two Scavtrap are exhausted. Draw!" << std::endl;
		else
			std::cout << std::endl;
		printClash(robotXV, robotXK, i);

		// Attack case
		std::cout << ansi(NULL, 0) + std::string(SIZE, '_') + std::string(SIZE, ' ') + std::string(SIZE, '_') << std::endl;
		std::cout << ansi(NULL, 0) + std::string(SIZE, ' ') + '|' + std::string(SIZE - 2, ' ') + '|' + std::string(SIZE, ' ') << std::endl;
		std::cout << ansi(NULL, 0) + std::string(SIZE / 2 - 1, ' ') + "--" + std::string(SIZE / 2 - 1, ' ') + '|' + std::string(SIZE - 2, ' ') + '|';
		std::cout << ((amount < 0) ? ansi((short[]){RED}, 1) : (amount == 0) ? ansi(NULL, 0) : ansi((short[]){GREEN}, 1));
		std::cout << std::string(SIZE / 2 - 1, ' ') << std::showpos << amount << std::string(SIZE / 2 - 1, ' ') << std::endl;
		std::cout << ansi(NULL, 0) + std::string(SIZE, '_') + '|' + std::string(SIZE - 2, ' ') + '|' + std::string(SIZE, '_') << std::endl;
		std::cout << std::endl;
		std::cout << ansi((short[]){NORMAL, ITALIC}, 2) + "Press ENTER to continue..." << std::endl;
		std::cin.get();
		if (std::cin.eof())
			break;
	}
	return 0;
}
