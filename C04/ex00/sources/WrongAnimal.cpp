#include "WrongAnimal.hpp"

/********************************************************************************/
/* ------------------------------- CONSTRUCTOR -------------------------------- */
/********************************************************************************/

WrongAnimal::WrongAnimal(void) {
	std::cout << ansi((short[]){BOLD, GREEN}, 2) + "Default constructor called for " + __func__ + "." << std::endl;
	return ;
}

WrongAnimal::WrongAnimal(std::string type) : _type(type) {
	std::cout << ansi((short[]){BOLD, GREEN}, 2) + "Constructor called for " + __func__ + " of type " + type + "." << std::endl;
	return ;
}

WrongAnimal::WrongAnimal(WrongAnimal &copy) : _type(copy.getType()) {
	std::cout << ansi((short[]){BOLD, GREEN}, 2) + "Copy constructor called for " + __func__ + " of type " + this->_type + "." << std::endl;
	return ;
}

/********************************************************************************/
/* -------------------------------- DESTRUCTOR -------------------------------- */
/********************************************************************************/

WrongAnimal::~WrongAnimal(void) {
	std::cout << ansi((short[]){BOLD, RED}, 2) + "Default constructor called for " + __func__ + "." << std::endl;
	return ;
}

/********************************************************************************/
/* --------------------------------- OVERLOAD --------------------------------- */
/********************************************************************************/

WrongAnimal	&WrongAnimal::operator=(const WrongAnimal &rhs) {
	if (this != &rhs)
		this->_type = rhs.getType();
	return *this;
}

/********************************************************************************/
/* --------------------------------- METHODS ---------------------------------- */
/********************************************************************************/

void	WrongAnimal::makeSound(void) const {
	std::cout << ansi((short[]){HIGHLIGHT, ITALIC}, 2) + "* No sound *";
	return ;
}

/********************************************************************************/
/* --------------------------------- ACCESSOR --------------------------------- */
/********************************************************************************/

std::string	WrongAnimal::getType(void) const { return ansi((short[]){BOLD, ITALIC}, 2) + this->_type; }

/********************************************************************************/
