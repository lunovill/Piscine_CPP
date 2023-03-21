#include "Array.hpp"

/********************************************************************************/
/* ------------------------------- CONSTRUCTOR -------------------------------- */
/********************************************************************************/

template<typename T>
Array<T>::Array(void) : _size(0), _array(NULL) {
	std::cout << ansi((short[]){BOLD, GREEN}, 2) + "Default constructor called for " + __func__ + "." << std::endl;
	return;
}

template<typename T>
Array<T>::Array(const unsigned int &n) : _size(n) {
	std::cout << ansi((short[]){BOLD, GREEN}, 2) + "Constructor called for " + __func__ + "." << std::endl;
	_array = new T[this->_size];
	for (unsigned int i = 0; i < this->_size; i++)
		this->_array[i] = T();
	return;
}

template<typename T>
Array<T>::Array(const Array<T> &copy) : _size(copy._size) {
	std::cout << ansi((short[]){BOLD, GREEN}, 2) + "Copy constructor called for " + __func__ + "." << std::endl;
	this->_array = new T[this->_size];
	this = copy;
	return;
}

/********************************************************************************/
/* -------------------------------- DESTRUCTOR -------------------------------- */
/********************************************************************************/

template<typename T>
Array<T>::~Array(void) {
	std::cout << ansi((short[]){BOLD, RED}, 2) + "Default constructor called for " + __func__ + "." << std::endl;
	delete [] this->_array;
	return;
}

/********************************************************************************/
/* --------------------------------- OVERLOAD --------------------------------- */
/********************************************************************************/

template<typename T>
Array<T>	&Array<T>::operator=(const Array<T> &rhs) {
	if (this != &rhs)
		for (unsigned int i = 0; i < this->_szie; i++)
			this->_array[i] = rhs._array[i];
	return *this;
}

/********************************************************************************/
/* --------------------------------- METHODS ---------------------------------- */
/********************************************************************************/

template<typename T>
const char		*Array<T>::InvalidIndex::what(void) const throw() { return "Invalid index"; }

template<typename T>
unsigned int	Array<T>::size(void) const { return this->_size;}

/********************************************************************************/
/* --------------------------------- ACCESSOR --------------------------------- */
/********************************************************************************/

template<typename T>
T		Array<T>::getArray(const unsigned int index) const {
	if (this->_size <= index)
		throw InvalidIndex();
	return this->_array[index];
}

template<typename T>
void	Array<T>::setArray(const unsigned int index, T cell) {
	if (this->_size <= index)
		throw InvalidIndex();
	this->_array[index] = cell;
}

/********************************************************************************/
