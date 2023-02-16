#include "Zombie.hpp"

Zombie::Zombie(std::string name) : _name(name) {
	std::cout << ansi((short[]){BOLD, GREEN}, 2) << this->_name << " : Constructor called." + ansi((short[]){NORMAL}, 1) << std::endl;
	return;
}

void	Zombie::announce(void) {
	std::cout << ansi((short[]){BOLD}, 1) << this->_name << " : " + ansi((short[]){NORMAL}, 1);
	std::cout << ansi((short[]){ITALIC}, 1) + "BraiiiiiiinnnzzzZ..." + ansi((short[]){NORMAL}, 1) << std::endl;
	return;
}

Zombie::~Zombie(void) {
	std::cout << ansi((short[]){BOLD, RED}, 2) << this->_name << " : Desturctor called." + ansi((short[]){NORMAL}, 1) << std::endl;
	return;
}