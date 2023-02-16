#ifndef HARL_HPP
# define HARL_HPP

#include <iostream>
#include "ansi.hpp"

class	Harl {

	private:

		void	_debug(void);
		void	_info(void);
		void	_warning(void);
		void	_error(void);

	public:

		Harl(void);

		std::string	input[4];
		void		(Harl::*function[4])(void);

		void		complain(std::string level);
};

#endif