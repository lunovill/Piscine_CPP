#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name + "_clap_name"), FragTrap(name), ScavTrap(name), _name(name), _hitPoint(FragTrap::_hitPoint), _energyPoint(ScavTrap::_energyPoint), _attackDamage(FragTrap::_attackDamage) {
	std::cout << ansi((short[]){BOLD, ITALIC, GREEN}, 3) + "DiamondTrap constructor called for " << name << "." << std::endl;
	return;
}

DiamondTrap::DiamondTrap(const DiamondTrap &copy) : ClapTrap(copy) {
	std::cout << ansi((short[]){BOLD, ITALIC, GREEN}, 3) + "DiamondTrap copy constructor called" << std::endl;
	return;
}

DiamondTrap::~DiamondTrap() {
	std::cout << ansi((short[]){BOLD, ITALIC, RED}, 3) + "DiamondTrap destructor called" << std::endl;
	return;
}

DiamondTrap	&DiamondTrap::operator=(const FragTrap &rhs) {
	if (this != &rhs)
		ClapTrap::operator=(rhs);
	return *this;
}

void	DiamondTrap::whoAmI() {
	std::cout << "I am DiamondTrap " << _name << " and my ClapTrap component is named " << ClapTrap::_name << "." << std::endl;
}
