#ifndef MYCLASS_HPP
# define MYCLASS_HPP

# include <iostream>
# include "ansi.hpp"

class	MyClass {

	private:

	public:

		MyClass(void);
		MyClass(const MyClass &copy);
		~MyClass(void);

		MyClass	&operator=(const MyClass &rhs);
};

#endif
