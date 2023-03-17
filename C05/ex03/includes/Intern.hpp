#ifndef INTERN_HPP
# define INTERN_HPP

# include <iostream>
# include "ansi.hpp"
# include "ShrubberyCreationForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "PresidentialPardonForm.hpp"

# define NB_FORM 3

class	Intern {

	private:

		static const std::string	_formName[NB_FORM];

		AForm 	*(Intern::*_formPtr[NB_FORM])(const std::string &);
		AForm	*_createSCF(const std::string &target);
		AForm	*_createRRF(const std::string &target);
		AForm	*_createPPF(const std::string &target);
	
	public:

		Intern(void);
		Intern(const Intern &copy);
		~Intern(void);

		Intern	&operator=(const Intern &);

		class InexistantNameForm : public std::exception {

        	public:
         	   virtual const char* what() const throw();
		};

		AForm	*makeForm(const std::string &name, const std::string &target);
};

#endif
