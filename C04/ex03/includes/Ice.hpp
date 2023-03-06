#ifndef ICE_HPP
# define ICE_HPP

# include <iostream>
# include "ansi.hpp"
# include "Character.hpp"

class	Ice : public AMateria {

	public:

		Ice(void);
		Ice(const Ice &copy);
		virtual	~Ice(void);

		Ice	&operator=(const Ice &);

		virtual Ice		*clone(void) const;
		virtual void	use(ICharacter &target);
};

#endif
