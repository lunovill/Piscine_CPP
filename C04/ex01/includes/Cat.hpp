#ifndef CAT_HPP
# define CAT_HPP

# include "Animal.hpp"
# include "Brain.hpp"

class	Cat : public Animal {

	private:

		Brain *_brain;

		void	_initBrain(void);

	public:

		Cat(void);
		Cat(const Cat &copy);
		virtual ~Cat(void);

		Cat	&operator=(const Cat &rhs);

		virtual void	makeSound(void) const;

		virtual std::string getType(void) const;
		Brain	*getBrain(void) const;
};

#endif
