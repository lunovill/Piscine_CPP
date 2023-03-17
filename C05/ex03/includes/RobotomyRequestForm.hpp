#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

# include <iostream>
# include "ansi.hpp"
# include "AForm.hpp"

class	RobotomyRequestForm : public AForm {

	private:

		const std::string	_target;

		RobotomyRequestForm(void);

	public:

		RobotomyRequestForm(const std::string &target);
		RobotomyRequestForm(const RobotomyRequestForm &copy);
		virtual ~RobotomyRequestForm(void);

		RobotomyRequestForm		&operator=(const RobotomyRequestForm &);

		virtual void	execute(const Bureaucrat &executor) const;

		const std::string	getTarget(void) const;
};

#endif
