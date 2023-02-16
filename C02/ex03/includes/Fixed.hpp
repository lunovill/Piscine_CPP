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
	bool	operator>(const Fixed &other) const;
	bool	operator<(const Fixed &other) const;
	bool	operator>=(const Fixed &other) const;
	bool	operator<=(const Fixed &other) const;
	bool	operator==(const Fixed &other) const;
	bool	operator!=(const Fixed &other) const;
	Fixed	operator+(const Fixed &other) const;
	Fixed	operator-(const Fixed &other) const;
	Fixed	operator*(const Fixed &other) const;
	Fixed	operator/(const Fixed &other) const;
	Fixed	operator++(int);
	Fixed	&operator++(void);
	Fixed	operator--(int);
	Fixed	&operator--(void);

	int		getRawBits(void) const;
	void	setRawBits(const int raw);

	float	toFloat(void) const;
	int		toInt(void) const;
	static Fixed		&min(Fixed &a, Fixed &b);
	static const Fixed	&min(const Fixed &a, const Fixed &b);
	static Fixed		&max(Fixed &a, Fixed &b);
	static const Fixed	&max(const Fixed &a, const Fixed &b);

};


std::ostream	&operator<<(std::ostream &output, const Fixed &print);

#endif