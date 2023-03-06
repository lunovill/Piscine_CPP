#include "AAnimal.hpp"

/********************************************************************************/
/* ------------------------------- CONSTRUCTOR -------------------------------- */
/********************************************************************************/

AAnimal::AAnimal(void) {
	std::cout << ansi((short[]){BOLD, GREEN}, 2) + "Default constructor called for " + __func__ + "." << std::endl;
	return ;
}

AAnimal::AAnimal(std::string type) : _type(type) {
	std::cout << ansi((short[]){BOLD, GREEN}, 2) + "Constructor called for " + __func__ + " of type " + type + "." << std::endl;
	return ;
}

AAnimal::AAnimal(const AAnimal &copy) : _type(copy.getType()) {
	std::cout << ansi((short[]){BOLD, GREEN}, 2) + "Copy constructor called for " + __func__ + " of type " + this->_type + "." << std::endl;
	return ;
}

/********************************************************************************/
/* -------------------------------- DESTRUCTOR -------------------------------- */
/********************************************************************************/

AAnimal::~AAnimal(void) {
	std::cout << ansi((short[]){BOLD, RED}, 2) + "Default constructor called for " + __func__ + "." << std::endl;
	return ;
}

/********************************************************************************/
/* --------------------------------- OVERLOAD --------------------------------- */
/********************************************************************************/

AAnimal	&AAnimal::operator=(const AAnimal &rhs) {
	if (this != &rhs)
		this->_type = rhs.getType();
	return *this;
}

/********************************************************************************/
/* --------------------------------- ACCESSOR --------------------------------- */
/********************************************************************************/

std::string	AAnimal::getType(void) const { return ansi((short[]){BOLD, ITALIC}, 2) + this->_type; }

/********************************************************************************/
