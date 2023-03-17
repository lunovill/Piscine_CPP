#ifndef DATA_HPP
# define DATA_HPP

# include <iostream>
# include "ansi.hpp"

class	Data {

	public:

		Data(void);
		Data(const Data &copy);
		~Data(void);

		Data	&operator=(const Data &);

		int	value;
};

#endif
