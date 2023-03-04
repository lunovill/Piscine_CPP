#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

# include <iostream>
# include "ansi.hpp"

class	WrongAnimal {

	protected:

		std::string	_type;
	
	public:

		WrongAnimal(void);
		WrongAnimal(std::string type);
		WrongAnimal(WrongAnimal &copy);
		~WrongAnimal(void);

		WrongAnimal	&operator=(const WrongAnimal &rhs);

		void	makeSound(void) const;

		std::string getType(void) const;
};

#endif
