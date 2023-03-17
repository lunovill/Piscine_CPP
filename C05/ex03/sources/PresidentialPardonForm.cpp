#include "PresidentialPardonForm.hpp"

/********************************************************************************/
/* ------------------------------- CONSTRUCTOR -------------------------------- */
/********************************************************************************/

PresidentialPardonForm::PresidentialPardonForm(const std::string &target) : AForm("PresidentialPardonForm", 25, 5), _target(target) {
	std::cout << ansi((short[]){BOLD, GREEN}, 2) + "Constructor called for " + __func__ + " nammed " + this->_name + "." << std::endl;
	return;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &copy) : AForm("Shrubbery ", 145, 137), _target(copy._target) {
	std::cout << ansi((short[]){BOLD, GREEN}, 2) + "Copy constructor called for " + __func__ + " nammed " + this->_name + "." << std::endl;
	return;
}

/********************************************************************************/
/* -------------------------------- DESTRUCTOR -------------------------------- */
/********************************************************************************/

PresidentialPardonForm::~PresidentialPardonForm(void) {
	std::cout << ansi((short[]){BOLD, RED}, 2) + "Default constructor called for " + __func__ + " nammed " + this->_name + "." << std::endl;
	return;
}

/********************************************************************************/
/* --------------------------------- OVERLOAD --------------------------------- */
/********************************************************************************/

PresidentialPardonForm	&PresidentialPardonForm::operator=(const PresidentialPardonForm &) { return *this; }

/********************************************************************************/
/* --------------------------------- METHODS ---------------------------------- */
/********************************************************************************/

void	PresidentialPardonForm::execute(const Bureaucrat &executor) const {
	if (this->_executeGrade < executor.getGrade()) throw GradeTooLowException();
	if (!this->_isSigned) throw FormNoSigned();

	std::cout << ansi((short[]){ITALIC, BLUE}, 2) << "Good people of the galaxy," << std::endl;
	std::cout << std::endl;
	std::cout << ansi((short[]){ITALIC, BLUE}, 2) << "I stand before you today with an important announcement. After much consideration and discussion with my fellow beings, me, " << ansi((short[]){BOLD, BLUE}, 2) << "Zaphod Beeblebrox" << ansi((short[]){ITALIC, BLUE}, 2) << ", your president, take the decision to pardon " << ansi(NULL, 0) << this->_target << ansi((short[]){ITALIC, BLUE}, 2) << "." << std::endl;
	std::cout << std::endl;
	std::cout << ansi((short[]){ITALIC, BLUE}, 2) << "Yes, " << ansi(NULL, 0) << this->_target << ansi((short[]){ITALIC, BLUE}, 2) << " has made mistakes in the past. But who among us has not? We are all imperfect createures, living in an imperfect universe." << std::endl;
	std::cout << std::endl;
	std::cout << ansi((short[]){ITALIC, BLUE}, 2) << "However, it is not the mistakes of the past that define us. It is what we do with the lessons we have learned, and how we move forward." << std::endl;
	std::cout << std::endl;
	std::cout << ansi((short[]){ITALIC, BLUE}, 2) << "" << ansi(NULL, 0) << this->_target << ansi((short[]){ITALIC, BLUE}, 2) << " has shown remorse for their actions and has taken steps towards making amends. It is my belief that they deserve a second chance." << std::endl;
	std::cout << std::endl;
	std::cout << ansi((short[]){ITALIC, BLUE}, 2) << "I know there will be those who disagree with this decision. But I ask you to have faith in the power of forgiveness and the potential for growth and change." << std::endl;
	std::cout << std::endl;
	std::cout << ansi((short[]){ITALIC, BLUE}, 2) << "Let us all move forward with a renewed commitment to compassion, understanding, and unity." << std::endl;
	std::cout << std::endl;
	std::cout << ansi((short[]){ITALIC, BLUE}, 2) << "Thank you." << std::endl;

	return;
}

/********************************************************************************/
/* --------------------------------- ACCESSOR --------------------------------- */
/********************************************************************************/

const std::string	PresidentialPardonForm::getTarget(void) const { return this->_target; }

/********************************************************************************/
