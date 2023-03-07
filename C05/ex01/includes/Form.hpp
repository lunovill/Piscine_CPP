#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>
# include "ansi.hpp"
# include "Bureaucrat.hpp"

class	Bureaucrat;

class	Form {

	private:

		const std::string	_name;
		bool				_isSigned;
		const int 			_signGrade;
		const int 			_executeGrade;

		Form(void);
	
		void	_tryGrade(void) const;

	public:

		Form(const std::string name, const int signGrade, const int executeGrade);
		Form(const Form &copy);
		~Form(void);

		Form		&operator=(const Form &);

		class	GradeTooHighException : public std::exception {

			public:

				virtual const char *what(void) const throw();
		};

		class	GradeTooLowException : public std::exception {

			public:

				virtual const char *what(void) const throw();
		};

		void	beSigned(const Bureaucrat &b);

		const std::string	getName(void) const;
		int					getSignGrade(void) const;
		int					getExecuteGrade(void) const;
};

std::ostream	&operator<<(std::ostream &o, const Form &rhs);

#endif
