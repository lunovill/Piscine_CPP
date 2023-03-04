#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <iostream>
# include "ansi.hpp"

class	AAnimal {

	protected:

		std::string	_type;
	
	public:

		AAnimal(void);
		AAnimal(std::string type);
		AAnimal(AAnimal &copy);
		virtual ~AAnimal(void);

		AAnimal	&operator=(const AAnimal &rhs);

		virtual void	makeSound(void) const = 0;

		virtual std::string getType(void) const;
};

#endif
