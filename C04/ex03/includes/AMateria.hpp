#ifndef AMATERIA_HPP
# define AMATERIA_HPP

# include "ICharacter.hpp"

class	ICharacter;

class	AMateria {

	protected:

		const std::string	_type;

	public:

		AMateria(const std::string &type);
		AMateria(const AMateria &copy);
		virtual	~AMateria(void);

		virtual AMateria	*clone(void) const = 0;
		virtual void		use(ICharacter& target);

		const std::string	&getType() const;
};

#endif
