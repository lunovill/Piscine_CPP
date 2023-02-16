#include "Fixed.hpp"

const int Fixed::_bits = 8;

Fixed::Fixed(void) : _rawBits(0) {}

Fixed::Fixed(const Fixed &copy) : _rawBits(copy.getRawBits()) {}

Fixed::Fixed(const int raw) : _rawBits(raw << this->_bits) {}

Fixed::Fixed(const float raw) :_rawBits(roundf(raw * (1 << this->_bits))) {}

Fixed::~Fixed(void) {}

Fixed	&Fixed::operator=(const Fixed &other) {
		this->_rawBits = other.getRawBits();
	return *this;
}

bool	Fixed::operator>(const Fixed &other) const {
	return (this->_rawBits > other.getRawBits());
}

bool	Fixed::operator<(const Fixed &other) const {
	return (this->_rawBits < other.getRawBits());
}

bool	Fixed::operator>=(const Fixed &other) const {
	return (this->_rawBits >= other.getRawBits());
}

bool	Fixed::operator<=(const Fixed &other) const {
	return (this->_rawBits <= other.getRawBits());
}

bool	Fixed::operator==(const Fixed &other) const {
	return (this->_rawBits == other.getRawBits());
}

bool	Fixed::operator!=(const Fixed &other) const {
	return (this->_rawBits != other.getRawBits());
}

Fixed	Fixed::operator+(const Fixed &other) const {
	Fixed	result;

	result.setRawBits(this->_rawBits + other.getRawBits());
	return result;
}

Fixed	Fixed::operator-(const Fixed &other) const {
	Fixed	result;

	result.setRawBits(this->_rawBits - other.getRawBits());
	return result;
}

Fixed	Fixed::operator*(const Fixed &other) const {
	Fixed    result;

    result._rawBits = roundf((this->toFloat() * other.toFloat())* (1 << this->_bits));
    return result;
}

Fixed	Fixed::operator/(const Fixed &other) const {
	Fixed    result;

    result._rawBits = roundf((this->toFloat() / other.toFloat())* (1 << this->_bits));
    return result;
}

Fixed	Fixed::operator++(int) {
	Fixed tmp(*this);

	this->_rawBits++;
	return tmp;
}

Fixed	&Fixed::operator++(void) {
	++this->_rawBits;
	return *this;
}

Fixed	Fixed::operator--(int) {
	Fixed tmp(*this);
	this->_rawBits--;
	return tmp;
}

Fixed	&Fixed::operator--(void) {
	--this->_rawBits;
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

Fixed	&Fixed::min(Fixed &a, Fixed &b) {
	return (a <= b) ? a : b;
}

const Fixed	&Fixed::min(const Fixed &a, const Fixed &b) {
	return (a <= b) ? a : b;
}

Fixed	&Fixed::max(Fixed &a, Fixed &b) {
	return (a >= b) ? a : b;
}

const Fixed	&Fixed::max(const Fixed &a, const Fixed &b) {
	return (a >= b) ? a : b;
}
