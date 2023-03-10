#include "WrongCat.hpp"

/********************************************************************************/
/* ------------------------------- CONSTRUCTOR -------------------------------- */
/********************************************************************************/

WrongCat::WrongCat(void) : WrongAnimal("WrongCat") {
	std::cout << ansi((short[]){BOLD, GREEN}, 2) + "Default constructor called for " + __func__ + " of type " + this->_type + "." << std::endl;
	return ;
}

WrongCat::WrongCat(const WrongCat &copy) : WrongAnimal(copy) {
	std::cout << ansi((short[]){BOLD, GREEN}, 2) + "Copy constructor called for " + __func__ + " of type " + this->_type + "." << std::endl;
	return ;
}

/********************************************************************************/
/* -------------------------------- DESTRUCTOR -------------------------------- */
/********************************************************************************/

WrongCat::~WrongCat(void) {
	std::cout << ansi((short[]){BOLD, RED}, 2) + "Default constructor called for " + __func__ + "." << std::endl;
	return ;
}

/********************************************************************************/
/* --------------------------------- OVERLOAD --------------------------------- */
/********************************************************************************/

WrongCat	&WrongCat::operator=(const WrongCat &rhs) {
	if (this != &rhs)
		WrongAnimal::operator=(rhs);
	return *this;
}

/********************************************************************************/
/* --------------------------------- METHODS ---------------------------------- */
/********************************************************************************/

void	WrongCat::makeSound(void) const {
	std::cout << ansi((short[]){HIGHLIGHT, ITALIC, BLUE}, 3) + "\"Grrrrr!\"";
	return ;
}

/********************************************************************************/
/* --------------------------------- ACCESSOR --------------------------------- */
/********************************************************************************/

std::string	WrongCat::getType(void) const { return ansi((short[]){BOLD, ITALIC, BLUE}, 3) + this->_type; }

/********************************************************************************/
