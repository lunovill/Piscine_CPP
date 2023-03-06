#ifndef DOG_HPP
# define DOG_HPP

# include "Animal.hpp"
# include "Brain.hpp"

class	Dog : public Animal {

	private:

		Brain *_brain;

		void	_initBrain(void);

	public:

		Dog(void);
		Dog(const Dog &copy);
		virtual ~Dog(void);

		Dog	&operator=(const Dog &rhs);

		virtual void	makeSound(void) const;

		virtual std::string getType(void) const;
		Brain	*getBrain(void) const;
};

#endif
