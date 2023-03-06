#ifndef CHARACTER_HPP
# define CHARACTER_HPP

# include <iostream>
# include "ICharacter.hpp"

# define INVENTORY_MAX 4

class	Character : public ICharacter {

	private:

		const std::string	_name;
		AMateria			*_inventory[INVENTORY_MAX];

		Character(void);

	public:

		Character(const std::string name);
		Character(const Character &copy);
		virtual	~Character(void);

		Character	&operator=(const Character &rhs);

		virtual void	equip(AMateria *m);
		virtual void	unequip(int idx);
		virtual void	use(int idx, ICharacter& target);

		virtual const std::string	&getName(void) const;
		AMateria					*getInventoryI(const int index) const;
};

#endif
