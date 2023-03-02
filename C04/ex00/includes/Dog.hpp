#ifndef DOG_HPP
# define DOG_HPP

# include "Animal.hpp"

class	Dog : public Animal {

	public:

		Dog(void);
		Dog(Dog &copy);
		virtual ~Dog(void);

		Dog	&operator=(const Dog &rhs);

		virtual void	makeSound(void) const;

		virtual std::string getType(void) const;
};

#endif
