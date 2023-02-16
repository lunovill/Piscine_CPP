#ifndef POINT_HPP
# define POINT_HPP

# include "Fixed.hpp"

class	Point {

	private:

	const Fixed	_x;
	const Fixed	_y;

	public:

	Point(void);
	Point(const Point &copy);
	Point(const Fixed x, const Fixed y);
	~Point(void);


	Point	&operator=(Point&other);

	Fixed	getX(void) const;
	Fixed	getY(void) const;
};

Fixed	dotPoint(const Point &a, const Point &b, const Point &c);
bool	bsp(Point const a, Point const b, Point const c, Point const point);

#endif