#include "MateriaSource.hpp"

/********************************************************************************/
/* ------------------------------- CONSTRUCTOR -------------------------------- */
/********************************************************************************/

MateriaSource::MateriaSource(void) {
	std::cout << ansi((short[]){BOLD, GREEN}, 2) + "Default constructor called for " + __func__ + "." << std::endl;
	for (int i = 0; i < BACKUP_MAX; i++)
		this->_backup[i] = NULL;
	return;
}

MateriaSource::MateriaSource(const MateriaSource &copy) {
	std::cout << ansi((short[]){BOLD, GREEN}, 2) + "Copy constructor called for " + __func__ + "." << std::endl;
	*this = copy;
	return;
}

/********************************************************************************/
/* -------------------------------- DESTRUCTOR -------------------------------- */
/********************************************************************************/

MateriaSource::~MateriaSource(void) {
	std::cout << ansi((short[]){BOLD, RED}, 2) + "Default constructor called for " + __func__ + "." << std::endl;
	for (int i = 0; i < BACKUP_MAX; i++)
		delete this->_backup[i];
	return;
}

/********************************************************************************/
/* --------------------------------- OVERLOAD --------------------------------- */
/********************************************************************************/

MateriaSource	&MateriaSource::operator=(const MateriaSource &rhs) {
	if (this != &rhs)
		for (int i = 0; i < BACKUP_MAX; i++) {
			if (this->_backup[i])
				delete _backup[i];
			if (rhs.getBackupI(i))
				this->_backup[i] = rhs.getBackupI(i)->clone();
		}
	return *this;
}

/********************************************************************************/
/* --------------------------------- METHODS ---------------------------------- */
/********************************************************************************/


void		MateriaSource::learnMateria(AMateria *m) {
	if (m)
		for (int i = 0; i < BACKUP_MAX; i++)
			if (!this->_backup[i]) {
				this->_backup[i] = m;
				return;
			}
	delete m;
	return;
}

AMateria	*MateriaSource::createMateria(const std::string &type) {
	for (int i = BACKUP_MAX - 1; i >= 0; i--)
		if (this->_backup[i] && this->_backup[i]->getType() == type)
			return this->_backup[i]->clone();
	return 0;
}

/********************************************************************************/
/* --------------------------------- ACCESSOR --------------------------------- */
/********************************************************************************/

AMateria	*MateriaSource::getBackupI(const int index) const { return this->_backup[index]; }

/********************************************************************************/
