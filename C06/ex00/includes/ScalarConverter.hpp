#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <cstdlib>
# include <iostream>
# include <limits>
# include "ansi.hpp"

class	ScalarConverter {

	private:

		static void	_fromChar(const std::string &str);
		static void	_fromInt(const std::string &str);
		static void	_fromFloat(const std::string &str);
		static void	_fromDouble(const std::string &str);

		ScalarConverter(void);

	public:

		static void	convert(const std::string &type);
};

#endif