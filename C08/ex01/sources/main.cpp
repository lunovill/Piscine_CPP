#include "Span.hpp"

int	main(void) {
	Span fibonacci(10);
	fibonacci.addNumber(0);
	std::cout << ansi(NULL, 0) << "fibinacci: " << fibonacci << std::endl;
	try {
		std::cout << ansi((short[]){DARK, CYAN}, 2) << "Shortest Span: " << fibonacci.shortestSpan() << std::endl;
	} catch (Span::NotEnoughValue &e) {
		std::cerr << ansi((short[]){UNDERLINE, DARK}, 2) + "error: throw:" << ansi(NULL, 0) + " " << e.what() << std::endl;
	}
	try {
		std::cout << ansi((short[]){DARK, CYAN}, 2) << "Longest Span: " << fibonacci.longestSpan() << std::endl;
	} catch (Span::NotEnoughValue &e) {
		std::cerr << ansi((short[]){UNDERLINE, DARK}, 2) + "error: throw:" << ansi(NULL, 0) + " " << e.what() << std::endl;
	}
	try {
		fibonacci.addRange((int[]){1, 1, 2, 3, 4, 5, 8, 13, 21}, 9);
		std::cout << ansi(NULL, 0) << "fibinacci: " << fibonacci << std::endl;
		std::cout << ansi(NULL, 0) << "Add number 34..." << std::endl;
		fibonacci.addNumber(34);
		std::cout << ansi(NULL, 0) << "fibinacci: " << fibonacci << std::endl;
	} catch (Span::ArrayIsFull &e) {
		std::cerr << ansi((short[]){UNDERLINE, DARK}, 2) + "error: throw:" << ansi(NULL, 0) + " " << e.what() << std::endl;
	}
	try {
		std::cout << ansi((short[]){DARK, CYAN}, 2) << "Shortest Span: " << fibonacci.shortestSpan() << std::endl;
	} catch (Span::NotEnoughValue &e) {
		std::cerr << ansi((short[]){UNDERLINE, DARK}, 2) + "error: throw:" << ansi(NULL, 0) + " " << e.what() << std::endl;
	}
	try {
		std::cout << ansi((short[]){DARK, CYAN}, 2) << "Longest Span: " << fibonacci.longestSpan() << std::endl;
	} catch (Span::NotEnoughValue &e) {
		std::cerr << ansi((short[]){UNDERLINE, DARK}, 2) + "error: throw:" << ansi(NULL, 0) + " " << e.what() << std::endl;
	}
	return 0;
}