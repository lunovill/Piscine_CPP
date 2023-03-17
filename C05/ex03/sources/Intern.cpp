#include "Intern.hpp"

const std::string	Intern::_formName[] = {
	"ShrubberyCreationForm",
	"RobotomyRequestForm",
	"PresidentialPardonForm"
};

/********************************************************************************/
/* ------------------------------- CONSTRUCTOR -------------------------------- */
/********************************************************************************/

Intern::Intern(void) {
	std::cout << ansi((short[]){BOLD, GREEN}, 2) + "Default constructor called for " + __func__ + "." << std::endl;
	this->_formPtr[0] = &Intern::_createSCF;
	this->_formPtr[1] = &Intern::_createRRF;
    this->_formPtr[2] = &Intern::_createPPF;
	return;
}

Intern::Intern(const Intern &copy) {
	std::cout << ansi((short[]){BOLD, GREEN}, 2) + "Copy constructor called for " + __func__ + "." << std::endl;
	this->_formPtr[0] = copy._formPtr[0];
	this->_formPtr[1] = copy._formPtr[1];
    this->_formPtr[2] = copy._formPtr[2];
	return;
}

/********************************************************************************/
/* -------------------------------- DESTRUCTOR -------------------------------- */
/********************************************************************************/

Intern::~Intern(void) {
	std::cout << ansi((short[]){BOLD, RED}, 2) + "Default constructor called for " + __func__ + "." << std::endl;
	return;
}

/********************************************************************************/
/* --------------------------------- OVERLOAD --------------------------------- */
/********************************************************************************/

Intern	&Intern::operator=(const Intern &) { return *this; }

/********************************************************************************/
/* --------------------------------- METHODS ---------------------------------- */
/********************************************************************************/

const char	*Intern::InexistantNameForm::what(void) const throw() { return "\033[0;2mForm name doesn't exist."; }

AForm	*Intern::_createSCF(const std::string &target) { return new ShrubberyCreationForm(target); }

AForm	*Intern::_createRRF(const std::string &target) { return new RobotomyRequestForm(target); }

AForm	*Intern::_createPPF(const std::string &target) { return new PresidentialPardonForm(target); }

AForm	*Intern::makeForm(const std::string &name, const std::string &target) {
	for (int i = 0; i < NB_FORM; i++) {
		if (name == Intern::_formName[i]) {
			std::cout << "Intern creates " << name << "." << std::endl;
			return (this->*_formPtr[i])(target);
		}
	}
	throw InexistantNameForm();
	return NULL;
}

/********************************************************************************/
