#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

# include <iostream>
# include "IMateriaSource.hpp"

# define BACKUP_MAX 4

class	MateriaSource : public IMateriaSource {

	private:

		AMateria	*_backup[BACKUP_MAX];

	public:

		MateriaSource(void);
		MateriaSource(const MateriaSource &copy);
		virtual	~MateriaSource(void);

		MateriaSource	&operator=(const MateriaSource &rhs);

		virtual void		learnMateria(AMateria *m);
		virtual AMateria	*createMateria(const std::string &type);

		AMateria	*getBackupI(const int index) const;
};

#endif
