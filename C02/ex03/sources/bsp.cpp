#include "Point.hpp"

Fixed	dotPoint(const Point &a, const Point &b, const Point &c) {
	Fixed result;

	result = (b.getX() - a.getX()) * (c.getY() - a.getY()) - (b.getY() - a.getY()) * (c.getX() - a.getX());
	return result;
}

bool	bsp(const Point a, const Point b, const Point c, const Point point) {
	if (dotPoint(a, b, point) < 0) {
		if (dotPoint(b, c, point) < 0)
			if (dotPoint(c, a, point) < 0)
				return true;
	} else {
		if (dotPoint(b, c, point) >= 0)
			if (dotPoint(c, a, point) >= 0)
				return true;
	}
	return false;
}