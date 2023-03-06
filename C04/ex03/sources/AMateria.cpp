#include "AMateria.hpp"

/********************************************************************************/
/* ------------------------------- CONSTRUCTOR -------------------------------- */
/********************************************************************************/

AMateria::AMateria(const std::string &type) : _type(type) {
	std::cout << ansi((short[]){BOLD, GREEN}, 2) + "Constructor called for " + __func__ + "." << std::endl;
}

AMateria::AMateria(const AMateria &copy) : _type(copy.getType()) {
	std::cout << ansi((short[]){BOLD, GREEN}, 2) + "Copy constructor called for " + __func__ + "." << std::endl;
	return;
}

/********************************************************************************/
/* -------------------------------- DESTRUCTOR -------------------------------- */
/********************************************************************************/

AMateria::~AMateria(void) {
	std::cout << ansi((short[]){BOLD, RED}, 2) + "Default constructor called for " + __func__ + "." << std::endl;
	return;
}

/********************************************************************************/
/* --------------------------------- METHODS ---------------------------------- */
/********************************************************************************/

void	AMateria::use(ICharacter& target) { 
	// if (this->_type == "ice")
	// 	std::cout << "* shoots an ice bolt at " + target.getName() +  " *" << std::endl;
	// else if (this->_type == "cure")
	// 	std::cout << "* heals " + target.getName() +  "'s wounds *" << std::endl;
	std::cout << ansi(NULL, 0) << "* default message for " + target.getName() + " *" << std::endl;
	return;
}

/********************************************************************************/
/* --------------------------------- ACCESSOR --------------------------------- */
/********************************************************************************/

const std::string	&AMateria::getType(void) const { return this->_type; }

/********************************************************************************/
