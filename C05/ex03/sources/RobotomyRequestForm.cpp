#include "RobotomyRequestForm.hpp"

/********************************************************************************/
/* ------------------------------- CONSTRUCTOR -------------------------------- */
/********************************************************************************/

RobotomyRequestForm::RobotomyRequestForm(const std::string &target) : AForm("RobotomyRequestForm", 72, 45), _target(target) {
	std::cout << ansi((short[]){BOLD, GREEN}, 2) + "Constructor called for " + __func__ + " nammed " + this->_name + "." << std::endl;
	return;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &copy) : AForm("Shrubbery ", 145, 137), _target(copy._target) {
	std::cout << ansi((short[]){BOLD, GREEN}, 2) + "Copy constructor called for " + __func__ + " nammed " + this->_name + "." << std::endl;
	return;
}

/********************************************************************************/
/* -------------------------------- DESTRUCTOR -------------------------------- */
/********************************************************************************/

RobotomyRequestForm::~RobotomyRequestForm(void) {
	std::cout << ansi((short[]){BOLD, RED}, 2) + "Default constructor called for " + __func__ + " nammed " + this->_name + "." << std::endl;
	return;
}

/********************************************************************************/
/* --------------------------------- OVERLOAD --------------------------------- */
/********************************************************************************/

RobotomyRequestForm	&RobotomyRequestForm::operator=(const RobotomyRequestForm &) { return *this; }

/********************************************************************************/
/* --------------------------------- METHODS ---------------------------------- */
/********************************************************************************/

void	RobotomyRequestForm::execute(const Bureaucrat &executor) const {
	if (this->_executeGrade < executor.getGrade()) {
		std::cout << ansi((short[]){ITALIC, YELLOW}, 2) << "Hello, we are sorry to inform you that the operation has failed." << std::endl;
		throw GradeTooLowException();
	}
	if (!this->_isSigned) {
		std::cout << ansi((short[]){ITALIC, YELLOW}, 2) << "Hello, we are sorry to inform you that the operation has failed." << std::endl;
		throw FormNoSigned();
	}

	std::cout << ansi((short[]){BOLD, DARK, YELLOW}, 3) << "BIZZZZZZZZZZzzzzz..." << std::endl;
	std::cout << "BIZZZZZzzzz..." << std::endl;
	std::cout << "BIZzzz..." << std::endl;
	std::cout << "BIZZZZZzzzzz... BIZZZzz.. Bizzz" << std::endl;
	std::cout << ansi((short[]){ITALIC, YELLOW}, 2) << "Hello, I inform you that " << ansi(NULL, 0) << this->_target << ansi((short[]){ITALIC, YELLOW}, 2) << " has been successfully robotized to 50%." << std::endl;
	return;
}

/********************************************************************************/
/* --------------------------------- ACCESSOR --------------------------------- */
/********************************************************************************/

const std::string	RobotomyRequestForm::getTarget(void) const { return this->_target; }

/********************************************************************************/
