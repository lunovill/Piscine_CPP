#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include "ClapTrap.hpp"

class ScavTrap : public ClapTrap {
	private:

		ScavTrap(void);

	public:

		ScavTrap(std::string name);
		ScavTrap(const ScavTrap& other);
		~ScavTrap();

		ScavTrap&	operator=(const ScavTrap& other);

		void	attack(std::string const & target);
		void	guardGate(void);
};

#endif