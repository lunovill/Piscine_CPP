#include "Bureaucrat.hpp"

/********************************************************************************/
/* ------------------------------- CONSTRUCTOR -------------------------------- */
/********************************************************************************/

Bureaucrat::Bureaucrat(const std::string name, int grade) : _name(name), _grade(grade) {
	std::cout << ansi((short[]){BOLD, GREEN}, 2) + "Constructor called for " + __func__ + " nammed " + this->_name + "." << std::endl;
	this->_tryGrade();
	return;
}

Bureaucrat::Bureaucrat(const Bureaucrat &copy) : _name(copy._name), _grade(copy._grade) {
	std::cout << ansi((short[]){BOLD, GREEN}, 2) + "Copy constructor called for " + __func__ + " nammed " + this->_name + "." << std::endl;
	return;
}

/********************************************************************************/
/* -------------------------------- DESTRUCTOR -------------------------------- */
/********************************************************************************/

Bureaucrat::~Bureaucrat(void) {
	std::cout << ansi((short[]){BOLD, RED}, 2) + "Default constructor called for " + __func__ + " nammed " + this->_name + "." << std::endl;
	return;
}

/********************************************************************************/
/* --------------------------------- OVERLOAD --------------------------------- */
/********************************************************************************/

Bureaucrat	&Bureaucrat::operator=(const Bureaucrat &rhs) {
	if (this != &rhs)
		this->_grade = rhs._grade;
	return *this;
}

/********************************************************************************/
/* --------------------------------- METHODS ---------------------------------- */
/********************************************************************************/

void	Bureaucrat::_tryGrade(void) const {
	if (this->_grade < 1) throw GradeTooHighException();
	if (this->_grade > 150)	throw GradeTooLowException();
	return;
}

const char	*Bureaucrat::GradeTooHighException::what(void) const throw() { return "\033[0;2mGrade too high"; }

const char	*Bureaucrat::GradeTooLowException::what(void) const throw() { return "\033[0;2mGrade too low"; }

void	Bureaucrat::promoted(void) {
	this->_grade--;
	this->_tryGrade();
	return;
}

void	Bureaucrat::demoted(void) {
	this->_grade++;
	this->_tryGrade();
	return;
}

void	Bureaucrat::signForm(Form &f) const {
	try {
		f.beSigned(*this);
		std::cout << ansi((short[]){ITALIC, CYAN}, 2) << this->_name << " signed " << f.getName() << "." << std::endl;
	} catch (Form::GradeTooLowException &e) {
		std::cout << ansi((short[]){ITALIC, CYAN}, 2) << this->_name << " couldn't sign " << f.getName() << " because " << e.what() << "." << std::endl;
	}
	return;
}

/********************************************************************************/
/* --------------------------------- ACCESSOR --------------------------------- */
/********************************************************************************/

const std::string	Bureaucrat::getName(void) const { return this->_name; }
int					Bureaucrat::getGrade(void) const { return this->_grade; }

/********************************************************************************/

std::ostream	&operator<<(std::ostream &o, const Bureaucrat &rhs) {
	o << ansi((short[]){ITALIC}, 1) << rhs.getName() << ", bureaucrat grade " << rhs.getGrade() << ".";
	return o;
}
