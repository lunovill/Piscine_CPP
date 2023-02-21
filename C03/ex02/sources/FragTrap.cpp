#include "FragTrap.hpp"

/********************************************************************************/
/* ------------------------------- CONSTRUCTOR -------------------------------- */
/********************************************************************************/

FragTrap::FragTrap(void) {return;}

FragTrap::FragTrap(std::string name) : ClapTrap(name) {
	this->_hitPoint = 100;
	this->_energyPoint = 100;
	this->_attackDamage = 30;
	std::cout << ansi((short[]){BOLD, ITALIC, GREEN}, 3) + "FragTrap constructor called for " << name << "." << std::endl;
	return;
}

FragTrap::FragTrap(const FragTrap &copy) : ClapTrap(copy.getName()) {
	this->_hitPoint = copy.getHitPoint();
	this->_energyPoint = copy.getEnergyPoint();
	this->_attackDamage = copy.getAttackDamage();
	std::cout << ansi((short[]){BOLD, ITALIC, GREEN}, 3) + "FragTrap copy constructor called." << std::endl;
	return;
}

/********************************************************************************/
/* -------------------------------- DESTRUCTOR -------------------------------- */
/********************************************************************************/

FragTrap::~FragTrap() {
	std::cout << ansi((short[]){BOLD, ITALIC, RED}, 3) + "FragTrap destructor called for " << this->_name << "." << std::endl;
	return;
}

/********************************************************************************/
/* --------------------------------- OVERLOAD --------------------------------- */
/********************************************************************************/

FragTrap	&FragTrap::operator=(const FragTrap &rhs) {
	if (this != &rhs)
		ClapTrap::operator=(rhs);
	return *this;
}

/********************************************************************************/
/* --------------------------------- METHODS ---------------------------------- */
/********************************************************************************/

void	FragTrap::highFivesGuys(void) {
	std::cout << ansi(NULL, 0) + this->_name;
	std::cout << ansi((short[]){BLUE, BOLD}, 2) +  " : Hey guys, let's give me some high fives!" << std::endl;
	return;
}

/********************************************************************************/
