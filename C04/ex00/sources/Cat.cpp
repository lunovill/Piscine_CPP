#include "Cat.hpp"

/********************************************************************************/
/* ------------------------------- CONSTRUCTOR -------------------------------- */
/********************************************************************************/

Cat::Cat(void) : Animal("Cat") {
	std::cout << ansi((short[]){BOLD, GREEN}, 2) + "Default constructor called for " + __func__ + " of type " + this->_type + "." << std::endl;
	return ;
}

Cat::Cat(Cat &copy) : Animal(copy) {
	std::cout << ansi((short[]){BOLD, GREEN}, 2) + "Copy constructor called for " + __func__ + " of type " + this->_type + "." << std::endl;
	return ;
}

/********************************************************************************/
/* -------------------------------- DESTRUCTOR -------------------------------- */
/********************************************************************************/

Cat::~Cat(void) {
	std::cout << ansi((short[]){BOLD, RED}, 2) + "Default constructor called for " + __func__ + "." << std::endl;
	return ;
}

/********************************************************************************/
/* --------------------------------- OVERLOAD --------------------------------- */
/********************************************************************************/

Cat	&Cat::operator=(const Cat &rhs) {
	if (this != &rhs)
		Animal::operator=(rhs);
	return *this;
}

/********************************************************************************/
/* --------------------------------- METHODS ---------------------------------- */
/********************************************************************************/

void	Cat::makeSound(void) const {
	std::cout << ansi((short[]){HIGHLIGHT, ITALIC, BLUE}, 3) + "\"Miaou!\"";
	return ;
}

/********************************************************************************/
/* --------------------------------- ACCESSOR --------------------------------- */
/********************************************************************************/

std::string	Cat::getType(void) const { return ansi((short[]){BOLD, ITALIC, BLUE}, 3) + this->_type; }

/********************************************************************************/
