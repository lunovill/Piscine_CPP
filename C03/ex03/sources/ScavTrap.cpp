#include "ScavTrap.hpp"

/********************************************************************************/
/* ------------------------------- CONSTRUCTOR -------------------------------- */
/********************************************************************************/

ScavTrap::ScavTrap(void) {return;}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name) {
	this->_hitPoint = 100;
	this->_energyPoint = 50;
	this->_attackDamage = 20;
	std::cout << ansi((short[]){BOLD, ITALIC, GREEN}, 3) + "ScavTrap constructor called for " << name << "." << std::endl;
	return;
}

ScavTrap::ScavTrap(const ScavTrap &copy) : ClapTrap(copy.getName()) {
	this->_hitPoint = copy.getHitPoint();
	this->_energyPoint = copy.getEnergyPoint();
	this->_attackDamage = copy.getAttackDamage();
	std::cout << ansi((short[]){BOLD, ITALIC, GREEN}, 3) + "ScavTrap copy constructor called." << std::endl;
	return;
}

/********************************************************************************/
/* -------------------------------- DESTRUCTOR -------------------------------- */
/********************************************************************************/

ScavTrap::~ScavTrap() {
	std::cout << ansi((short[]){BOLD, ITALIC, RED}, 3) + "ScavTrap destructor called for " << this->_name << "." << std::endl;
	return;
}

/********************************************************************************/
/* --------------------------------- OVERLOAD --------------------------------- */
/********************************************************************************/

ScavTrap	&ScavTrap::operator=(const ScavTrap &rhs) {
	if (this != &rhs)
		ClapTrap::operator=(rhs);
	return *this;
}

/********************************************************************************/
/* --------------------------------- METHODS ---------------------------------- */
/********************************************************************************/

void	ScavTrap::attack(const std::string &target) {
	if (!this->_hitPoint) {
		std::cout << ansi((short[]){RED, ITALIC}, 2) + "ScavTrap ";
		std::cout << ansi(NULL, 0) << this->_name << ansi((short[]){RED, ITALIC}, 2) + " has no hit point left." << std::endl;
	} else if (!this->_energyPoint) {
		std::cout << ansi((short[]){RED, ITALIC}, 2) + "ScavTrap ";
		std::cout << ansi(NULL, 0) << this->_name << ansi((short[]){RED, ITALIC}, 2) + " has no energy point left." << std::endl;
	} else {
		this->_energyPoint--;
		std::cout << ansi((short[]){RED, BOLD}, 2) + "ScavTrap ";
		std::cout << ansi(NULL, 0) << this->_name << ansi((short[]){RED, BOLD}, 2) + " attacks ";
		std::cout << ansi(NULL, 0) << target << ansi((short[]){RED, BOLD}, 2) + ", causing ";
		std::cout << ansi(NULL, 0) << this->_attackDamage << ansi((short[]){RED, BOLD}, 2) + " point(s) of damage!" << std::endl;
	}
	return;
}

void	ScavTrap::guardGate(void) {
	std::cout << "ScavTrap ";
	std::cout << ansi(NULL, 0) + this->_name;
	std::cout << ansi((short[]){BLUE, BOLD}, 2) + " is now in Gate keeper mode." << std::endl;
	return;
}

/********************************************************************************/
