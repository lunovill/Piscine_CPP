#ifndef AFORM_HPP
# define AFORM_HPP

# include <iostream>
# include "ansi.hpp"
# include "Bureaucrat.hpp"

class	Bureaucrat;

class	AForm {

	protected:

		const std::string	_name;
		bool				_isSigned;
		const int 			_signGrade;
		const int 			_executeGrade;

		AForm(void);
	
		void	_tryGrade(void) const;

	public:

		AForm(const std::string name, const int signGrade, const int executeGrade);
		AForm(const AForm &copy);
		virtual ~AForm(void);

		AForm		&operator=(const AForm &);

		class	GradeTooHighException : public std::exception {

			public:

				virtual const char *what(void) const throw();
		};

		class	GradeTooLowException : public std::exception {

			public:

				virtual const char *what(void) const throw();
		};

		class	FormNoSigned : public std::exception {

			public:

				virtual const char *what(void) const throw();
		};

		void			beSigned(const Bureaucrat &b);
		virtual void	execute(const Bureaucrat &executor) const = 0;

		const std::string	getName(void) const;
		int					getSignGrade(void) const;
		int					getExecuteGrade(void) const;
};

std::ostream	&operator<<(std::ostream &o, const AForm &rhs);

#endif
