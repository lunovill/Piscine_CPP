#include "Fixed.hpp"

const int Fixed::_bits = 8;

Fixed::Fixed(void) : _rawBits(0) {
	std::cout << ansi((short[]){BOLD, GREEN}, 2) << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &copy) : _rawBits(copy.rawBits) {
	std::cout << ansi((short[]){BOLD, GREEN}, 2) << "Copy constructor called" << std::endl;
	return;
}

Fixed::~Fixed(void) {
	std::cout << ansi((short[]){BOLD, RED}, 2) << "Destructor called" << std::endl;
	return;
}

Fixed	&Fixed::operator=(const Fixed &other) {
	std::cout << ansi((short[]){BOLD, PURPLE}, 2) << "Copy assignment operator called" << std::endl;
	this->_rawBits = other.getRawBits();
	return *this;
}

int		Fixed::getRawBits(void) const {
	std::cout << ansi((short[]){BOLD, BLUE}, 2) << "getRawBits member function called" << ansi(NULL, 0) << std::endl;
	return this->_rawBits;
}

void	Fixed::setRawBits(const int raw) {
	std::cout << ansi((short[]){BOLD, CYAN}, 2) << "setRawBits member function called" << std::endl;
	this->_rawBits = raw;
	return;
}