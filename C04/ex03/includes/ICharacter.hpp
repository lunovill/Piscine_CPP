#ifndef ICHARACTER_HPP
# define ICHARACTER_HPP

# include <iostream>
# include "ansi.hpp"
# include "AMateria.hpp"

class	AMateria;

class	ICharacter {

	public:

		virtual	~ICharacter(void) { return; }

		virtual void	equip(AMateria *m) = 0;
		virtual void	unequip(int idx) = 0;
		virtual void	use(int idx, ICharacter& target) = 0;

		virtual const std::string	&getName(void) const = 0;
};

#endif
