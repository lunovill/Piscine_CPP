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

		class	InvalidIndex : public std::exception {
			public:
				virtual const char *what(void) const throw();
		};

		unsigned int	size(void) const;

		T				getArray(const unsigned int index) const;
		void			setArray(const unsigned int index, T cell);
};

#include "Array.tpp"

#endif
