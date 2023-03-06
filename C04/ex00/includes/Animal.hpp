#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <iostream>
# include "ansi.hpp"

class	Animal {

	protected:

		std::string	_type;
	
	public:

		Animal(void);
		Animal(std::string type);
		Animal(const Animal &copy);
		virtual ~Animal(void);

		Animal	&operator=(const Animal &rhs);

		virtual void	makeSound(void) const;

		virtual std::string getType(void) const;
};

#endif
