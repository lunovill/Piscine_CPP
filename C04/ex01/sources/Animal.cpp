#include "Animal.hpp"

/********************************************************************************/
/* ------------------------------- CONSTRUCTOR -------------------------------- */
/********************************************************************************/

Animal::Animal(void) {
	std::cout << ansi((short[]){BOLD, GREEN}, 2) + "Default constructor called for " + __func__ + "." << std::endl;
	return ;
}

Animal::Animal(std::string type) : _type(type) {
	std::cout << ansi((short[]){BOLD, GREEN}, 2) + "Constructor called for " + __func__ + " of type " + type + "." << std::endl;
	return ;
}

Animal::Animal(const Animal &copy) : _type(copy.getType()) {
	std::cout << ansi((short[]){BOLD, GREEN}, 2) + "Copy constructor called for " + __func__ + " of type " + this->_type + "." << std::endl;
	return ;
}

/********************************************************************************/
/* -------------------------------- DESTRUCTOR -------------------------------- */
/********************************************************************************/

Animal::~Animal(void) {
	std::cout << ansi((short[]){BOLD, RED}, 2) + "Default constructor called for " + __func__ + "." << std::endl;
	return ;
}

/********************************************************************************/
/* --------------------------------- OVERLOAD --------------------------------- */
/********************************************************************************/

Animal	&Animal::operator=(const Animal &rhs) {
	if (this != &rhs)
		this->_type = rhs.getType();
	return *this;
}

/********************************************************************************/
/* --------------------------------- METHODS ---------------------------------- */
/********************************************************************************/

void	Animal::makeSound(void) const {
	std::cout << ansi((short[]){HIGHLIGHT, ITALIC}, 2) + "* No sound *";
	return ;
}

/********************************************************************************/
/* --------------------------------- ACCESSOR --------------------------------- */
/********************************************************************************/

std::string	Animal::getType(void) const { return ansi((short[]){BOLD, ITALIC}, 2) + this->_type; }

/********************************************************************************/
