#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon &weapon) : _name(name), _weapon(weapon) {}

void	HumanA::attack(void) {
	std::cout << ansi((short[]){NORMAL, ITALIC, CYAN}, 3) << this->_name;
	std::cout << ansi((short[]){NORMAL, BOLD, RED}, 3) + " attacks with their ";
	std::cout << ansi((short[]){NORMAL, ITALIC, CYAN}, 3) <<  this->_weapon.getType() << std::endl;
	return;
}