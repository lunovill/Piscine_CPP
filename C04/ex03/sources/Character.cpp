#include "Character.hpp"

/********************************************************************************/
/* ------------------------------- CONSTRUCTOR -------------------------------- */
/********************************************************************************/

// Character::Character(void) { return; }

Character::Character(std::string name) : _name(name) {
	std::cout << ansi((short[]){BOLD, GREEN}, 2) + "Constructor called for " + __func__ +  " named " + name + "." << std::endl;
		for (int i = 0; i < INVENTORY_MAX; i++)
			this->_inventory[i] = NULL;
	return;
}

Character::Character(const Character &copy) : _name(copy.getName()){
	std::cout << ansi((short[]){BOLD, GREEN}, 2) + "Copy constructor called for " + __func__ + " named " + this->_name + "." << std::endl;
	*this = copy;
	return;
}

/********************************************************************************/
/* -------------------------------- DESTRUCTOR -------------------------------- */
/********************************************************************************/

Character::~Character(void) {
	std::cout << ansi((short[]){BOLD, RED}, 2) + "Default constructor called for " + __func__ + "." << std::endl;
		for (int i = 0; i < INVENTORY_MAX; i++)
			delete this->_inventory[i];
	return;
}

/********************************************************************************/
/* --------------------------------- OVERLOAD --------------------------------- */
/********************************************************************************/

Character	&Character::operator=(const Character &rhs) {
	if (this != &rhs) {
		for (int i = 0; i < INVENTORY_MAX; i++) {
			if (this->_inventory[i])
				delete _inventory[i];
			if (rhs.getInventoryI(i))
				this->_inventory[i] = rhs.getInventoryI(i)->clone();
		}
	}
	return *this;
}

/********************************************************************************/
/* --------------------------------- METHODS ---------------------------------- */
/********************************************************************************/

void	Character::equip(AMateria *m) {
	if (m)
		for (int i = 0; i < INVENTORY_MAX; i++)
			if (!this->_inventory[i]) {
				this->_inventory[i] = m;
				break;
			}
	return;
}

void	Character::unequip(int idx) {
	if (idx >= 0 && idx < INVENTORY_MAX)
		this->_inventory[idx] = NULL;
	return;
}

void	Character::use(int idx, ICharacter& target) {
	if (idx >= 0 && idx <= INVENTORY_MAX && this->_inventory[idx])
			this->_inventory[idx]->use(target);
}

/********************************************************************************/
/* --------------------------------- ACCESSOR --------------------------------- */
/********************************************************************************/

const std::string	&Character::getName(void) const { return this->_name; }

AMateria	*Character::getInventoryI(const int index) const { return this->_inventory[index]; }

/********************************************************************************/
