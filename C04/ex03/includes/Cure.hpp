#ifndef CURE_HPP
# define CURE_HPP

# include <iostream>
# include "ansi.hpp"
# include "Character.hpp"

class	Cure : public AMateria {

	public:

		Cure(void);
		Cure(const Cure &copy);
		virtual	~Cure(void);

		Cure	&operator=(const Cure &);

		virtual Cure	*clone(void) const;
		virtual void	use(ICharacter &target);
};

#endif
