#ifndef Bureaucrat_HPP
# define Bureaucrat_HPP

# include <iostream>
# include "ansi.hpp"

class	Bureaucrat {

	private:

		const std::string	_name;
		int 				_grade;

		Bureaucrat(void);
	
		void	_tryGrade(void) const;

	public:

		Bureaucrat(const std::string name, int grade);
		Bureaucrat(const Bureaucrat &copy);
		~Bureaucrat(void);

		Bureaucrat		&operator=(const Bureaucrat &rhs);

		class	GradeTooHighException : public std::exception {

			public:

				virtual const char *what(void) const throw();
		};

		class	GradeTooLowException : public std::exception {

			public:

				virtual const char *what(void) const throw();
		};

		void	promoted(void);
		void	demoted(void);

		const std::string	getName(void) const;
		int					getGrade(void) const;
};

std::ostream	&operator<<(std::ostream &o, const Bureaucrat &rhs);

#endif
