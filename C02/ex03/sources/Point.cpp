#include "Point.hpp"

Point::Point(void) : _x(0), _y(0) {}

Point::Point(const Point &copy) : _x(copy.getX()), _y(copy.getY()) {}

Point::Point(const Fixed x, const Fixed y) : _x(x), _y(y) {}

Point::~Point(void) {}

Point	&Point::operator=(Point &other) {
	return other;
}

Fixed	Point::getX(void) const {
	return this->_x;
}

Fixed	Point::getY(void) const {
	return this->_y;
}
