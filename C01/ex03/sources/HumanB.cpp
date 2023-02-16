#include "HumanB.hpp"

HumanB::HumanB(std::string name) : _name(name), _weapon(NULL) {}

void	HumanB::setWeapon(Weapon &weapon) {
	this->_weapon = &weapon;
	return;
}

void	HumanB::attack(void) {
	std::cout << ansi((short[]){NORMAL, ITALIC, YELLOW}, 3) << this->_name;
	std::cout << ansi((short[]){NORMAL, BOLD, RED}, 3) + " attacks with their ";
	if (this->_weapon)
		std::cout << ansi((short[]){NORMAL, ITALIC, YELLOW}, 3) <<  this->_weapon->getType() << std::endl;
	else
		std::cout << ansi((short[]){NORMAL, ITALIC, YELLOW}, 3) << "hands" << std::endl;
	return;
}
