#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

# include <iostream>
# include "ansi.hpp"
# include "AForm.hpp"

class	PresidentialPardonForm : public AForm {

	private:

		const std::string	_target;

		PresidentialPardonForm(void);

	public:

		PresidentialPardonForm(const std::string target);
		PresidentialPardonForm(const PresidentialPardonForm &copy);
		virtual ~PresidentialPardonForm(void);

		PresidentialPardonForm		&operator=(const PresidentialPardonForm &);

		virtual void	execute(const Bureaucrat &executor) const;

		const std::string	getTarget(void) const;
};

#endif
