#include "Fixed.hpp"

int main( void ) {
	std::cout << ansi((short[]){BOLD, CYAN}, 2) + "_________________Default Main_________________" + ansi(NULL, 0) << std::endl;
	std::cout << std::endl;
	{
		Fixed a;
		Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );

		std::cout << a << std::endl;
		std::cout << ++a << std::endl;
		std::cout << a << std::endl;
		std::cout << a++ << std::endl;
		std::cout << a << std::endl;
		std::cout << b << std::endl;
		std::cout << Fixed::max( a, b ) << std::endl;
	}
	std::cout << std::endl;
	std::cout << ansi((short[]){BOLD, CYAN}, 2) + "_________________Personal Main_________________" + ansi(NULL, 0) << std::endl;
	std::cout << std::endl;
	{
		Fixed a(10);
		Fixed b(0.05f);
		Fixed c(42.42f);
		Fixed d(a);

		std::cout << ansi((short[]){BOLD, YELLOW}, 2) + "=> TEST : \">\"" << std::endl;
		std::cout << ansi(NULL, 0) << a << " > " << b << " is ";
		(a > b) ? (std::cout << ansi((short[]){BOLD, GREEN}, 2) + "true") : (std::cout << ansi((short[]){BOLD, RED}, 2) + "false");
		std::cout << std::endl;
		std::cout << ansi(NULL, 0) << a << " > " << c << " is ";
		(a > c) ? (std::cout << ansi((short[]){BOLD, GREEN}, 2) + "true") : (std::cout << ansi((short[]){BOLD, RED}, 2) + "false");
		std::cout << std::endl;
		std::cout << ansi(NULL, 0) << a << " > " << d << " is ";
		(a > d) ? (std::cout << ansi((short[]){BOLD, GREEN}, 2) + "true") : (std::cout << ansi((short[]){BOLD, RED}, 2) + "false");
		std::cout << std::endl;
		std::cout << std::endl;
		std::cout << ansi((short[]){BOLD, YELLOW}, 2) + "=> TEST : \"<\"" << std::endl;
		std::cout << ansi(NULL, 0) << a << " < " << b << " is ";
		(a < b) ? (std::cout << ansi((short[]){BOLD, GREEN}, 2) + "true") : (std::cout << ansi((short[]){BOLD, RED}, 2) + "false");
		std::cout << std::endl;
		std::cout << ansi(NULL, 0) << a << " < " << c << " is ";
		(a < c) ? (std::cout << ansi((short[]){BOLD, GREEN}, 2) + "true") : (std::cout << ansi((short[]){BOLD, RED}, 2) + "false");
		std::cout << std::endl;
		std::cout << ansi(NULL, 0) << a << " < " << d << " is ";
		(a < d) ? (std::cout << ansi((short[]){BOLD, GREEN}, 2) + "true") : (std::cout << ansi((short[]){BOLD, RED}, 2) + "false");
		std::cout << std::endl;
		std::cout << std::endl;
		std::cout << ansi((short[]){BOLD, YELLOW}, 2) + "=> TEST : \">=\"" << std::endl;
		std::cout << ansi(NULL, 0) << a << " >= " << b << " is ";
		(a >= b) ? (std::cout << ansi((short[]){BOLD, GREEN}, 2) + "true") : (std::cout << ansi((short[]){BOLD, RED}, 2) + "false");
		std::cout << std::endl;
		std::cout << ansi(NULL, 0) << a << " >= " << c << " is ";
		(a >= c) ? (std::cout << ansi((short[]){BOLD, GREEN}, 2) + "true") : (std::cout << ansi((short[]){BOLD, RED}, 2) + "false");
		std::cout << std::endl;
		std::cout << ansi(NULL, 0) << a << " >= " << d << " is ";
		(a >= d) ? (std::cout << ansi((short[]){BOLD, GREEN}, 2) + "true") : (std::cout << ansi((short[]){BOLD, RED}, 2) + "false");
		std::cout << std::endl;
		std::cout << std::endl;
		std::cout << ansi((short[]){BOLD, YELLOW}, 2) + "=> TEST : \"<=\"" << std::endl;
		std::cout << ansi(NULL, 0) << a << " <= " << b << " is ";
		(a <= b) ? (std::cout << ansi((short[]){BOLD, GREEN}, 2) + "true") : (std::cout << ansi((short[]){BOLD, RED}, 2) + "false");
		std::cout << std::endl;
		std::cout << ansi(NULL, 0) << a << " <= " << c << " is ";
		(a <= c) ? (std::cout << ansi((short[]){BOLD, GREEN}, 2) + "true") : (std::cout << ansi((short[]){BOLD, RED}, 2) + "false");
		std::cout << std::endl;
		std::cout << ansi(NULL, 0) << a << " <= " << d << " is ";
		(a <= d) ? (std::cout << ansi((short[]){BOLD, GREEN}, 2) + "true") : (std::cout << ansi((short[]){BOLD, RED}, 2) + "false");
		std::cout << std::endl;
		std::cout << std::endl;
		std::cout << ansi((short[]){BOLD, YELLOW}, 2) + "=> TEST : \"==\"" << std::endl;
		std::cout << ansi(NULL, 0) << a << " == " << b << " is ";
		(a == b) ? (std::cout << ansi((short[]){BOLD, GREEN}, 2) + "true") : (std::cout << ansi((short[]){BOLD, RED}, 2) + "false");
		std::cout << std::endl;
		std::cout << ansi(NULL, 0) << a << " == " << c << " is ";
		(a == c) ? (std::cout << ansi((short[]){BOLD, GREEN}, 2) + "true") : (std::cout << ansi((short[]){BOLD, RED}, 2) + "false");
		std::cout << std::endl;
		std::cout << ansi(NULL, 0) << a << " == " << d << " is ";
		(a == d) ? (std::cout << ansi((short[]){BOLD, GREEN}, 2) + "true") : (std::cout << ansi((short[]){BOLD, RED}, 2) + "false");
		std::cout << std::endl;
		std::cout << std::endl;
		std::cout << ansi((short[]){BOLD, YELLOW}, 2) + "=> TEST : \"!=\"" << std::endl;
		std::cout << ansi(NULL, 0) << a << " != " << b << " is ";
		(a != b) ? (std::cout << ansi((short[]){BOLD, GREEN}, 2) + "true") : (std::cout << ansi((short[]){BOLD, RED}, 2) + "false");
		std::cout << std::endl;
		std::cout << ansi(NULL, 0) << a << " != " << c << " is ";
		(a != c) ? (std::cout << ansi((short[]){BOLD, GREEN}, 2) + "true") : (std::cout << ansi((short[]){BOLD, RED}, 2) + "false");
		std::cout << std::endl;
		std::cout << ansi(NULL, 0) << a << " != " << d << " is ";
		(a != d) ? (std::cout << ansi((short[]){BOLD, GREEN}, 2) + "true") : (std::cout << ansi((short[]){BOLD, RED}, 2) + "false");
		std::cout << std::endl;
		std::cout << std::endl;
	}
	std::cout << ansi((short[]){BOLD, PURPLE}, 2) + "----------------------------------------------" + ansi(NULL, 0) << std::endl;
	std::cout << std::endl;
	{
		Fixed a(4);
		Fixed b(2);
		Fixed c(0.5f);

		std::cout << ansi((short[]){BOLD, YELLOW}, 2) + "=> TEST : \"+\"" << std::endl;
		std::cout << ansi(NULL, 0) << a << " + " << b << " + " << c << " = " << a + b + c << std::endl;
		std::cout << std::endl;
		std::cout << ansi((short[]){BOLD, YELLOW}, 2) + "=> TEST : \"-\"" << std::endl;
		std::cout << ansi(NULL, 0) << a << " - " << b << " - " << c << " = " << a - b - c << std::endl;
		std::cout << std::endl;
		std::cout << ansi((short[]){BOLD, YELLOW}, 2) + "=> TEST : \"*\"" << std::endl;
		std::cout << ansi(NULL, 0) << a << " * " << b << " * " << c << " = " << a * b * c << std::endl;
		std::cout << std::endl;
		std::cout << ansi((short[]){BOLD, YELLOW}, 2) + "=> TEST : \"/\"" << std::endl;
		std::cout << ansi(NULL, 0) << a << " / " << b << " / " << c << " = " << a / b / c << std::endl;
		std::cout << std::endl;
	}
	std::cout << ansi((short[]){BOLD, PURPLE}, 2) + "----------------------------------------------" + ansi(NULL, 0) << std::endl;
	std::cout << std::endl;
	{
		Fixed	a(0);
		Fixed	b(0);

		std::cout << ansi((short[]){BOLD, YELLOW}, 2) + "=> TEST : \"++\"" << std::endl;
		std::cout << ansi(NULL, 0) << "a = " << a << " | I a++ (" << a++ << ") :" << std::endl;
		std::cout << ansi(NULL, 0) << a << std::endl;
		std::cout << ansi(NULL, 0) << "b = " << b << " | I ++b (" << ++b << ") :" << std::endl;
		std::cout << ansi(NULL, 0) << b << std::endl;
		std::cout << std::endl;
		std::cout << ansi((short[]){BOLD, YELLOW}, 2) + "=> TEST : \"--\"" << std::endl;
		std::cout << ansi(NULL, 0) << "a = " << a << " | I a-- (" << a-- << ") :" << std::endl;
		std::cout << ansi(NULL, 0) << a << std::endl;
		std::cout << ansi(NULL, 0) << "b = " << b << " | I --b (" << --b << ") :" << std::endl;
		std::cout << ansi(NULL, 0) << b << std::endl;
		std::cout << std::endl;
	}
	std::cout << ansi((short[]){BOLD, PURPLE}, 2) + "----------------------------------------------" + ansi(NULL, 0) << std::endl;
	std::cout << std::endl;
	{
		Fixed	a(8);
		Fixed	b(4.42f);
		const Fixed	c(2.42f);
		const Fixed	d(1);

		std::cout << ansi((short[]){BOLD, YELLOW}, 2) + "=> TEST : \"min\"" << std::endl;
		std::cout << ansi(NULL, 0) << "Between " << a << " et " << b << " ,min is " << Fixed::min(a, b) << std::endl;
		std::cout << ansi(NULL, 0) << "Between " << c << " et " << d << " ,min is " << Fixed::min(c, d) << std::endl;
		std::cout << std::endl;
		std::cout << ansi((short[]){BOLD, YELLOW}, 2) + "=> TEST : \"max\"" << std::endl;
		std::cout << ansi(NULL, 0) << "Between " << a << " et " << b << " ,max is " << Fixed::max(a, b) << std::endl;
		std::cout << ansi(NULL, 0) << "Between " << c << " et " << d << " ,max is " << Fixed::max(c, d) << std::endl;
		std::cout << std::endl;
	}
return 0;
}
