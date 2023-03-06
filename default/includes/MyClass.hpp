#ifndef MyClass_HPP
# define MyClass_HPP

# include <iostream>
# include "ansi.hpp"

class	MyClass {

	private:

	public:

		MyClass(void);
		MyClass(MyClass &copy);
		~MyClass(void);

		MyClass	&operator=(MyClass &rhs);
};

#endif
