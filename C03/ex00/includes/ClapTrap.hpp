#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <iostream>
#include "ansi.hpp"

class ClapTrap {

	private:

		std::string		_name;
		unsigned int	_hitPoint;
		unsigned int	_energyPoint;
		unsigned int	_attackDamage;

		ClapTrap(void);

	public:

		ClapTrap(std::string name);
		ClapTrap(const ClapTrap &src);
		~ClapTrap(void);

		ClapTrap	&operator=( ClapTrap const &rhs);

		void	attack(const std::string& target);
		void	takeDamage(unsigned int amount);
		void	beRepaired(unsigned int amount);

		std::string		getName(void) const;
		unsigned int	getHitPoint(void) const;
		unsigned int	getEnergyPoint(void) const;
		unsigned int	getAttackDamage(void) const;

		void			setAttackDamage(const unsigned int amount);
};

#endif