#include "Fixed.hpp"

const int Fixed::_bits = 8;

Fixed::Fixed(void) : _rawBits(0) {
	std::cout << ansi((short[]){BOLD, GREEN}, 2) + "Default constructor called" + ansi(NULL, 0) << std::endl;
}

Fixed::Fixed(const Fixed &copy) {
	std::cout << ansi((short[]){BOLD, GREEN}, 2) << "Copy constructor called" + ansi(NULL, 0) << std::endl;
	*this = copy;
	return;
}

Fixed::Fixed(const int raw) : _rawBits(raw << this->_bits) {
	std::cout << ansi((short[]){BOLD, GREEN}, 2) << "Int constructor called" + ansi(NULL, 0) << std::endl;
}

Fixed::Fixed(const float raw) :_rawBits(roundf(raw * (1 << this->_bits))) {
	std::cout << ansi((short[]){BOLD, GREEN}, 2) << "Float constructor called" + ansi(NULL, 0) << std::endl;
}

Fixed::~Fixed(void) {
	std::cout << ansi((short[]){BOLD, RED}, 2) << "Destructor called" << std::endl;
	return;
}

Fixed	&Fixed::operator=(const Fixed &other) {
	std::cout << ansi((short[]){BOLD, PURPLE}, 2) << "Copy assignment operator called" + ansi(NULL, 0) << std::endl;
	this->_rawBits = other.getRawBits();
	return *this;
}

std::ostream	&operator<<(std::ostream &output, const Fixed &print) {
	output << print.toFloat();
	return output;
}

int		Fixed::getRawBits(void) const {
	return this->_rawBits;
}

void	Fixed::setRawBits(const int raw) {
	this->_rawBits = raw;
	return;
}

int		Fixed::toInt(void) const {
	return this->_rawBits >> this->_bits;
}

float		Fixed::toFloat(void) const {
	return (float)this->_rawBits / (float)(1 << this->_bits);
}