#include "ansi.hpp"

std::string	ansi(const short set[], short size)
{
	if (size > 10)
		throw std::invalid_argument("Error: ansi: size must be <= 10");
	std::ostringstream ansi;
	ansi << "\033[";
	for (int i = 0; i < size; i++)
	{
		if (!(set[i] >= 0 && set[i] <= 9) && !(set[i] >= 30 && set[i] <= 36))
    		throw std::invalid_argument("Error: ansi: set[] must contain a value between 0 and 9 or between 30 and 36");
	    ansi << set[i];
	    if (i != size - 1)
		ansi << ';';
	}
	ansi << 'm';
	return ansi.str();
}
