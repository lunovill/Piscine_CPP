#include <cstdlib>
#include <ctime>
//#include <string>
//#include <iomanip>
#include "ClapTrap.hpp"

unsigned int    randomDamage(void) {
	srand(time(NULL));
	int random = rand() % 100;
	if (random < 10)
		return 0;
	else if (random < 50)
		return 1;
	else if (random < 90)
		return 2;
	else
		return 3;    
}

int	clash(ClapTrap &attacker, ClapTrap &defender) {
	unsigned int	amount = randomDamage();

	if (attacker.getHitPoint() < 3) {
			attack.beRepaired(amount);
			std::cout << std::endl;
			std::cout << std::endl;
			return (attacker.getEnergyPoint() == 0) ? 0 : amount;
	} else {
		attacker.setAttackDamage(amount);
		attacker.attack(defender.getName());
		defender.takeDamage(amount);
		if (!amount)
			std::cout << ansi(NULL, 0) + defender.getName() << ansi((short[]){BLUE, ITALIC}, 2) + "dodges the attack !" << std::endl;
		else if (amount == 3)
			std::cout << ansi((short[]){BLUE, ITALIC}, 2) + "It's a critical hit !" << std::endl;
		else
			std::cout << std::endl;
		return (attacker.getEnergyPoint() == 0) ? 0 : -amount;
	}
}

void	printClash(ClapTrap &Judokrak, ClapTrap &Karaclee) {
	std::cout << ansi((short[]){BOLD}, 1);
	std::cout << "______________________________" << std::endl;
	std::cout << "=====  " + Judokrak.getName() + "  VS  " + Karaclee.getName() + "  =====" << std::endl;
	std::cout << "______________________________" << std::endl;
	std::cout << ansi((short[]]){HIGHLIGHT}, 1) << std::left << std::setw(10) << std::string(' ', Judokrak.getHitPoint());
	std::cout << ansi(NULL, 0) << std::internal << std::setw(10) << i;
	std::cout << ansi((short[]]){HIGHLIGHT}, 1) << std::right << std::setw(10) << std::string(' ', Karaclee.getHitPoint());
	std::cout << ansi((short[]){BOLD}, 1) << "HP";
	std::cout << (Judokrak.getHitPoint() <= 3) ? ansi((short[]]){RED}, 1) : (Judokrak.getHitPoint() <= 5) ? ansi((short[]]){YELLOW}, 1) : ansi((short[]]){GREEN}, 1);
	std::cout << std::right << std::setw(8) << Judokrak.getHitPoint();
	std::cout << std::string(' ', 10);
	std::cout << ansi((short[]){BOLD}, 1) << "HP";
	std::cout << (Karaclee.getHitPoint() <= 3) ? ansi((short[]]){RED}, 1) : (Karaclee.getHitPoint() <= 5) ? ansi((short[]]){YELLOW}, 1) : ansi((short[]]){GREEN}, 1);
	std::cout << std::right << std::setw(8) << Karaclee.getHitPoint();
	std::cout << ansi((short[]){BOLD}, 1) << "EP";
	std::cout << (Judokrak.getEnergyPoint() <= 3) ? ansi((short[]]){CYAN}, 1) : ansi((short[]]){BLUE}, 1);
	std::cout << std::right << std::setw(8) << Judokrak.getEnergyPoint();
	std::cout << std::string(' ', 10);
	std::cout << ansi((short[]){BOLD}, 1) << "EP";
	std::cout << (Karaclee.getEnergyPoint() <= 3) ? ansi((short[]]){CYAN}, 1) : ansi((short[]]){BLUE}, 1);
	std::cout << std::right << std::setw(8) << Karaclee.getEnergyPoint();
	std::cout << std::endl;
	return;
}

int    main(void) {
	ClapTrap Judokrak("Nageki");
	ClapTrap Karaclee("Dageki");

	for (unsigned int i = 0; Judokrak.getHitPoint() && Karaclee.getHitPoint(); ++i) {
		std::system("clear");
		std::cout << ansi((short[]){BOLD}, 1) + "===========COMMENTS===========" << std::endl;
		int amount = clash(Judokrak, Karaclee);
		std::cout << std::endl;
		printClash(Judokrak, Karaclee);
		std::cout << ansi(NULL, 0) + "__________          __________" << std::endl;
		std::cout << (amount < 0) ? ansi((short[]){RED}, 1) : (amount == 0) ? ansi(NULL, 0) : ansi((short[]){GREEN}, 1);
		std::cout << std::internal << std::setw(10) << std::showpos << amount;
		std::cout << ansi(NULL, 0) + "|        |    --    " << std::endl
		std::cout << ansi(NULL, 0) + "_________|          |_________" << std::endl;
		std::cout << std::endl;
		std::cout << ansi((short[]){NORMAL, ITALIC}, 2) + "Press ENTER to continue...";
		std::cin.get();
		std::system("clear");
		std::cout << ansi((short[]){BOLD}, 1) + "===========COMMENTS===========" << std::endl;
		int amount = clash(Karaclee, Judokrak);
		std::cout << std::endl;
		printClash(Judokrak, Karaclee);
		std::cout << ansi(NULL, 0) + "__________          __________" << std::endl;
		std::cout << ansi(NULL, 0) + "    --    |        |";
		std::cout << (amount < 0) ? ansi((short[]){RED}, 1) : (amount == 0) ? ansi(NULL, 0) : ansi((short[]){GREEN}, 1);
		std::cout << std::internal << std::setw(10) << std::showpos << amount << std::endl;
		std::cout << ansi(NULL, 0) + "__________|         |_________" << std::endl;
		std::cout << std::endl;
		std::cout << ansi((short[]){NORMAL, ITALIC}, 2) + "Press ENTER to continue...";
		std::cin.get();
		// Condition de sortie de la boucle
	}

	return 0;
}
