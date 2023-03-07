#include "Form.hpp"

/********************************************************************************/
/* ------------------------------- CONSTRUCTOR -------------------------------- */
/********************************************************************************/

Form::Form(const std::string name, const int signGrade, const int executeGrade) : _name(name), _isSigned(false), _signGrade(signGrade), _executeGrade(executeGrade) {
	std::cout << ansi((short[]){BOLD, GREEN}, 2) + "Constructor called for " + __func__ + " nammed " + this->_name + "." << std::endl;
	this->_tryGrade();
	return;
}

Form::Form(const Form &copy) : _name(copy._name), _isSigned(copy._isSigned), _signGrade(copy._signGrade), _executeGrade(copy._executeGrade) {
	std::cout << ansi((short[]){BOLD, GREEN}, 2) + "Copy constructor called for " + __func__ + " nammed " + this->_name + "." << std::endl;
	return;
}

/********************************************************************************/
/* -------------------------------- DESTRUCTOR -------------------------------- */
/********************************************************************************/

Form::~Form(void) {
	std::cout << ansi((short[]){BOLD, RED}, 2) + "Default constructor called for " + __func__ + " nammed " + this->_name + "." << std::endl;
	return;
}

/********************************************************************************/
/* --------------------------------- OVERLOAD --------------------------------- */
/********************************************************************************/

Form	&Form::operator=(const Form &) { return *this; }

/********************************************************************************/
/* --------------------------------- METHODS ---------------------------------- */
/********************************************************************************/

void	Form::_tryGrade(void) const {
	if (this->_signGrade < 1 || this->_executeGrade < 1) throw GradeTooHighException();
	if (this->_signGrade > 150 || this->_executeGrade > 150) throw GradeTooLowException();
	return;
}

const char	*Form::GradeTooHighException::what(void) const throw() { return "\033[0;2mGrade too high"; }

const char	*Form::GradeTooLowException::what(void) const throw() { return "\033[0;2mGrade too low"; }

void	Form::beSigned(const Bureaucrat &b) {
	if (this->_signGrade < b.getGrade()) throw GradeTooLowException();
	this->_isSigned = true;
	return;
}

/********************************************************************************/
/* --------------------------------- ACCESSOR --------------------------------- */
/********************************************************************************/

const std::string	Form::getName(void) const { return this->_name; }

int					Form::getSignGrade(void) const { return this->_signGrade; }

int					Form::getExecuteGrade(void) const { return this->_executeGrade; }

/********************************************************************************/

std::ostream	&operator<<(std::ostream &o, const Form &rhs) {
	o << ansi((short[]){ITALIC}, 1) << rhs.getName() << ", form signing grade " << rhs.getSignGrade() << " and form execution grade " << rhs.getExecuteGrade() << ".";
	return o;
}
