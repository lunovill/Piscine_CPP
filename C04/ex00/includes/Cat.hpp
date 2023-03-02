#ifndef CAT_HPP
# define CAT_HPP

# include "Animal.hpp"

class	Cat : public Animal {

	public:

		Cat(void);
		Cat(Cat &copy);
		virtual ~Cat(void);

		Cat	&operator=(const Cat &rhs);

		virtual void	makeSound(void) const;

		virtual std::string getType(void) const;
};

#endif
