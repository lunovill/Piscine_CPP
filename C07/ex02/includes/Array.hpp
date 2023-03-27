#ifndef ARRAY_TPP
# define ARRAY_TPP

# include <iostream>
# include "ansi.hpp"

template<typename T>
class	Array {

	private:

		T				*_array;
		unsigned int	_size;

	public:

		Array<T>(void);
		Array<T>(const unsigned int &n);
		Array<T>(const Array<T> &copy);
		~Array<T>(void);

		Array<T>	&operator=(const Array<T> &rhs);
		T			&operator[](const unsigned int index);

		class	InvalidIndex : public std::exception {
			public:
				virtual const char *what(void) const throw();
		};

		unsigned int	size(void) const;
};

template<typename T>
std::ostream	&operator<<(std::ostream &o, Array<T> &tab);

#include "Array.tpp"

#endif
