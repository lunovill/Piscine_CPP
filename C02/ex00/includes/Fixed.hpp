#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>
#include "ansi.hpp"

class	Fixed {

    private:

    int	_rawBits;
    static const int	_bits;  

    public:

	Fixed(void);
	Fixed(const Fixed &copy);
	~Fixed(void);

	Fixed	&operator=(const Fixed &other);

	int		getRawBits(void) const;
	void	setRawBits(const int raw);
};

#endif