#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP

# include "ScavTrap.hpp"
# include "FragTrap.hpp"

class DiamondTrap : public ScavTrap, public FragTrap {
	private:
		std::string	_name;

		DiamondTrap(void);

	public:

		DiamondTrap(std::string name);
		~DiamondTrap();

		DiamondTrap	&operator=(const FragTrap &rhs);

		void whoAmI();
};

#endif