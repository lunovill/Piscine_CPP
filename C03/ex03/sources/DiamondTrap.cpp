#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name + "_clap_name"), ScavTrap(name), FragTrap(name) {
	this->_name = name;
	this->_hitPoint = FragTrap::_hitPoint;
	this->_energyPoint = ScavTrap::_energyPoint;
	this->_attackDamage = FragTrap::_attackDamage;
	std::cout << ansi((short[]){BOLD, ITALIC, GREEN}, 3) + "DiamondTrap constructor called for " << name << "." << std::endl;
	return;
}

DiamondTrap::DiamondTrap(const DiamondTrap &copy) : ClapTrap(copy.ClapTrap::getName()) {
	this->_name = copy.getName();
	this->_hitPoint = copy.getHitPoint();
	this->_energyPoint = copy.getEnergyPoint();
	this->_attackDamage = copy.getAttackDamage();
	std::cout << ansi((short[]){BOLD, ITALIC, GREEN}, 3) + "DiamondTrap copy constructor called." << std::endl;
	return;
}

DiamondTrap::~DiamondTrap() {
	std::cout << ansi((short[]){BOLD, ITALIC, RED}, 3) + "DiamondTrap destructor called for " << this->_name << "." << std::endl;
	return;
}

DiamondTrap	&DiamondTrap::operator=(const DiamondTrap &rhs) {
	if (this != &rhs) {
		ClapTrap::operator=(rhs);
		this->_name = rhs.getName();
	}
	return *this;
}

void	DiamondTrap::whoAmI() {
	std::cout << "I am DiamondTrap " << this->_name << " and my ClapTrap component is named " << this->ClapTrap::_name << "." << std::endl;
}

std::string		DiamondTrap::getName(void) const {return this->_name;}
