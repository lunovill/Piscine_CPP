#ifndef IMATERIASOURCE_HPP
# define IMATERIASOURCE_HPP

# include <iostream>
# include "AMateria.hpp"

class	IMateriaSource {

	public:

		virtual	~IMateriaSource(void) { return; }

		virtual void		learnMateria(AMateria*) = 0;
		virtual AMateria	*createMateria(const std::string &type) = 0;
};

#endif
