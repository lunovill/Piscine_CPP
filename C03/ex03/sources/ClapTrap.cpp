#include "ClapTrap.hpp"

/********************************************************************************/
/* ------------------------------- CONSTRUCTOR -------------------------------- */
/********************************************************************************/

ClapTrap::ClapTrap(void) {return;}

ClapTrap::ClapTrap(std::string name) : _name(name), _hitPoint(10), _energyPoint(10), _attackDamage(0) {
	std::cout << ansi((short[]){BOLD, ITALIC, GREEN}, 3) + "ClapTrap constructor called." << std::endl;
	return;
}

ClapTrap::ClapTrap(const ClapTrap &copy) : _name(copy.getName()), _hitPoint(copy.getHitPoint()), _energyPoint(copy.getEnergyPoint()), _attackDamage(copy.getAttackDamage()) {
	std::cout << ansi((short[]){BOLD, ITALIC, GREEN}, 3) + "ClapTrap copy constructor called." << std::endl;
	return;
}


/********************************************************************************/
/* -------------------------------- DESTRUCTOR -------------------------------- */
/********************************************************************************/

ClapTrap::~ClapTrap(void) {
	std::cout << ansi((short[]){BOLD, ITALIC, RED}, 3) + "ClapTrap destructor called." << std::endl;
	return;
}


/********************************************************************************/
/* --------------------------------- OVERLOAD --------------------------------- */
/********************************************************************************/

ClapTrap	&ClapTrap::operator=(const ClapTrap &rhs) {
	if (this != &rhs) {
		this->_name = rhs.getName();
		this->_hitPoint = rhs.getHitPoint();
		this->_energyPoint = rhs.getEnergyPoint();
		this->_attackDamage = rhs.getAttackDamage();
	}
	return *this;
}

/********************************************************************************/
/* --------------------------------- METHODS ---------------------------------- */
/********************************************************************************/

void	ClapTrap::attack(const std::string &target) {
	if (!this->_hitPoint) {
		std::cout << ansi((short[]){RED, ITALIC}, 2) + "ClapTrap ";
		std::cout << ansi(NULL, 0) << this->_name << ansi((short[]){RED, ITALIC}, 2) + " has no hit point left." << std::endl;
	} else if (!this->_energyPoint) {
		std::cout << ansi((short[]){RED, ITALIC}, 2) + "ClapTrap ";
		std::cout << ansi(NULL, 0) << this->_name << ansi((short[]){RED, ITALIC}, 2) + " has no energy point left." << std::endl;
	} else {
		this->_energyPoint--;
		std::cout << ansi((short[]){RED, BOLD}, 2) + "ClapTrap ";
		std::cout << ansi(NULL, 0) << this->_name << ansi((short[]){RED, BOLD}, 2) + " attacks ";
		std::cout << ansi(NULL, 0) << target << ansi((short[]){RED, BOLD}, 2) + ", causing ";
		std::cout << ansi(NULL, 0) << this->_attackDamage << ansi((short[]){RED, BOLD}, 2) + " point(s) of damage!" << std::endl;
	}
	return;
}
void	ClapTrap::takeDamage(unsigned int amount) {
	if (!this->_hitPoint) {
		std::cout << ansi((short[]){YELLOW, ITALIC}, 2) + "ClapTrap ";
		std::cout << ansi(NULL, 0) << this->_name << ansi((short[]){YELLOW, ITALIC}, 2) + " has no hit point left." << std::endl;
	} else {
		amount = (amount > this->_hitPoint) ? this->_hitPoint : amount;
		this->_hitPoint -= amount;
		std::cout << ansi((short[]){YELLOW, BOLD}, 2) + "ClapTrap ";
		std::cout << ansi(NULL, 0) << this->_name << ansi((short[]){YELLOW, BOLD}, 2) + " takes ";
		std::cout << ansi(NULL, 0) << amount << ansi((short[]){YELLOW, BOLD}, 2) + " point(s) of damage." << std::endl;
	}
	return;
}
void	ClapTrap::beRepaired(unsigned int amount) {
	if (!this->_hitPoint) {
		std::cout << ansi((short[]){CYAN, ITALIC}, 2) + "ClapTrap ";
		std::cout << ansi(NULL, 0) << this->_name << ansi((short[]){CYAN, ITALIC}, 2) + " has no hit point left." << std::endl;
	} else if (!this->_energyPoint) {
		std::cout << ansi((short[]){CYAN, ITALIC}, 2) + "ClapTrap ";
		std::cout << ansi(NULL, 0) << this->_name << ansi((short[]){CYAN, ITALIC}, 2) + " has no energy point left." << std::endl;
	} else {
		this->_energyPoint--;
		this->_hitPoint += amount;
		std::cout << ansi((short[]){CYAN, BOLD}, 2) + "ClapTrap ";
		std::cout << ansi(NULL, 0) << this->_name << ansi((short[]){CYAN, BOLD}, 2) + " repairs hymself by ";
		std::cout << ansi(NULL, 0) << amount << ansi((short[]){CYAN, BOLD}, 2) + " health point(s)." << std::endl;
	}
	return;
}

/********************************************************************************/
/* --------------------------------- ACCESSOR --------------------------------- */
/********************************************************************************/

std::string		ClapTrap::getName(void) const {return this->_name;}
unsigned int	ClapTrap::getHitPoint(void) const {return this->_hitPoint;}
unsigned int	ClapTrap::getEnergyPoint(void) const {return this->_energyPoint;}
unsigned int	ClapTrap::getAttackDamage(void) const {return this->_attackDamage;}

void			ClapTrap::setAttackDamage(const unsigned int amount) {
	this->_attackDamage = amount;
	return;
}

/********************************************************************************/