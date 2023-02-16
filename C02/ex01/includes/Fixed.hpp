#ifndef FIXED_HPP
# define FIXED_HPP

#include <cmath>
#include <iostream>
#include "ansi.hpp"

class	Fixed {

    private:

    int	_rawBits;
    static const int	_bits;  

    public:

	Fixed(void);
	Fixed(const int raw);
	Fixed(const float raw);
	Fixed(const Fixed &copy);
	~Fixed(void);

	Fixed	&operator=(const Fixed &other);

	int		getRawBits(void) const;
	void	setRawBits(const int raw);

	float	toFloat(void) const;
	int		toInt(void) const;
};


std::ostream	&operator<<(std::ostream &output, const Fixed &print);

#endif