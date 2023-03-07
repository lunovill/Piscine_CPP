#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

# include <iostream>
# include <fstream>
# include "ansi.hpp"
# include "AForm.hpp"

class	ShrubberyCreationForm : public AForm {

	private:

		const std::string	_target;

		ShrubberyCreationForm(void);

	public:

		ShrubberyCreationForm(const std::string target);
		ShrubberyCreationForm(const ShrubberyCreationForm &copy);
		virtual ~ShrubberyCreationForm(void);

		ShrubberyCreationForm		&operator=(const ShrubberyCreationForm &);

		virtual void	execute(const Bureaucrat &executor) const;

		const std::string	getTarget(void) const;
};

#endif
