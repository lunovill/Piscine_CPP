#include "MutantStack.hpp"

/********************************************************************************/
/* ------------------------------- CONSTRUCTOR -------------------------------- */
/********************************************************************************/

template<typename T>
MutantStack<T>::MutantStack(void) : std::stack<T>() {
	std::cout << ansi((short[]){BOLD, GREEN}, 2) + "Default constructor called for " + __func__ + "." << std::endl;
	return;
}

template<typename T>
MutantStack<T>::MutantStack(const MutantStack &copy) : std::stack<T>(copy) {
	std::cout << ansi((short[]){BOLD, GREEN}, 2) + "Copy constructor called for " + __func__ + "." << std::endl;
	return;
}

/********************************************************************************/
/* -------------------------------- DESTRUCTOR -------------------------------- */
/********************************************************************************/

template<typename T>
MutantStack<T>::~MutantStack(void) {
	std::cout << ansi((short[]){BOLD, RED}, 2) + "Default constructor called for " + __func__ + "." << std::endl;
	return;
}

/********************************************************************************/
/* --------------------------------- OVERLOAD --------------------------------- */
/********************************************************************************/

template<typename T>
MutantStack<T>	&MutantStack<T>::operator=(const MutantStack<T> &rhs) {
	if (this != &rhs)
		this->c = rhs.c;
	return *this;
}

/********************************************************************************/
/* --------------------------------- METHODS ---------------------------------- */
/********************************************************************************/

template<typename T>
typename MutantStack<T>::iterator			MutantStack<T>::begin() { return this->c.begin(); }

template<typename T>
typename MutantStack<T>::iterator			MutantStack<T>::end() { return this->c.end(); }

template<typename T>
typename MutantStack<T>::reverse_iterator	MutantStack<T>::rbegin() { return this->c.rbegin(); }

template<typename T>
typename MutantStack<T>::reverse_iterator	MutantStack<T>::rend(){ return this->c.rend(); }

/********************************************************************************/

template<typename T>
std::ostream	&operator<<(std::ostream &o, MutantStack<T> &rhs) {
	o << "[";
	for (typename MutantStack<T>::iterator it = rhs.begin(); it != rhs.end(); it++)
		o << *it << ", ";
	o << "\033[2D]";
	return o;
}