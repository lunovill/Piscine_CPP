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
		DiamondTrap(const DiamondTrap &copy);
		~DiamondTrap();

		DiamondTrap	&operator=(const DiamondTrap &rhs);

		void whoAmI(void);

		std::string	getName(void) const;
};

#endif