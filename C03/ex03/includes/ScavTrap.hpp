#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include "ClapTrap.hpp"

class ScavTrap : virtual public ClapTrap {

	protected:

		ScavTrap(void);

	public:

		ScavTrap(std::string name);
		ScavTrap(const ScavTrap &copy);
		~ScavTrap();

		ScavTrap	&operator=(const ScavTrap &rhs);

		void	attack(const std::string &target);
		void	guardGate(void);
};

#endif