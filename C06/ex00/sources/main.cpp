#include <cctype>
#include <cstdlib>
#include <iostream>
#include <limits>
#include <string>
#include "ansi.hpp"

static void	fromChar(const std::string &str) {
	char	c = str[0];
	std::cout << ansi((short[]){BOLD, YELLOW}, 2) + "     Char : " << ansi(NULL, 0) << c << std::endl;
	std::cout << ansi((short[]){BOLD, CYAN}, 2) + "      Int : " << ansi(NULL, 0) << static_cast<int>(c) << std::endl;
	std::cout << ansi((short[]){BOLD, BLUE}, 2) + "    Float : " << ansi(NULL, 0) << static_cast<float>(c) << ".0f" << std::endl;
	std::cout << ansi((short[]){BOLD, GREEN}, 2) + "   Double : " << ansi(NULL, 0) << static_cast<double>(c) << ".0" << std::endl;
	return;
}

static void	fromInt(const std::string &str) {
	int	n = atoi(str.c_str());
	if (n < 255 && isprint(n)) std::cout << ansi((short[]){BOLD, YELLOW}, 2) + "     Char : " << ansi(NULL, 0) << static_cast<char>(n) << std::endl;
	else std::cout << ansi((short[]){BOLD, YELLOW}, 2) + "     Char : " << ansi((short[]){ITALIC, DARK}, 2) + "Non displayable" << std::endl;
	std::cout << ansi((short[]){BOLD, CYAN}, 2) + "      Int : " << ansi(NULL, 0) << n << std::endl;
	std::cout << ansi((short[]){BOLD, BLUE}, 2) + "    Float : " << ansi(NULL, 0) << static_cast<float>(n) << ".0f" << std::endl;
	std::cout << ansi((short[]){BOLD, GREEN}, 2) + "   Double : " << ansi(NULL, 0) << static_cast<double>(n) << ".0" << std::endl;
	return;
}

static void	fromFloat(const std::string &str) {
	float f = static_cast<float>(atof(str.c_str()));
	if (str == "nanf" || str.substr(1) == "inff") {
		std::cout << ansi((short[]){BOLD, YELLOW}, 2) + "     Char : " << ansi((short[]){ITALIC, DARK}, 2) + "Impossible" << std::endl;
		std::cout << ansi((short[]){BOLD, CYAN}, 2) + "      Int : " << ansi((short[]){ITALIC, DARK}, 2) + "Impossible" << std::endl;
		std::cout << ansi((short[]){BOLD, BLUE}, 2) + "    Float : " << ansi(NULL, 0) << str << std::endl;
		if (str == "nanf") std::cout << ansi((short[]){BOLD, GREEN}, 2) + "   Double : " << ansi(NULL, 0) <<  str.substr(0, str.length() - 1) << std::endl;
		else std::cout << ansi((short[]){BOLD, GREEN}, 2) + "   Double : " << ansi(NULL, 0) << ((str[0] == '-') ? std::numeric_limits<float>::min() : std::numeric_limits<float>::max()) << std::endl;
	} else {
		if (f < 255 && isprint(static_cast<char>(f))) std::cout << ansi((short[]){BOLD, YELLOW}, 2) + "     Char : " << ansi(NULL, 0) << static_cast<char>(f) << std::endl;
		else std::cout << ansi((short[]){BOLD, YELLOW}, 2) + "     Char : " << ansi((short[]){ITALIC, DARK}, 2) + "Non displayable" << std::endl;
		if (std::numeric_limits<int>::min() <= f && f <= std::numeric_limits<int>::max()) std::cout << ansi((short[]){BOLD, CYAN}, 2) + "      Int : " << ansi(NULL, 0) << static_cast<int>(f) << std::endl;
		else std::cout << ansi((short[]){BOLD, CYAN}, 2) + "      Int : " << ansi((short[]){ITALIC, DARK}, 2) + "Non displayable" << std::endl;
		if (f == static_cast<long long int>(f)) {
			std::cout << ansi((short[]){BOLD, BLUE}, 2) + "    Float : " << ansi(NULL, 0) << f << ".0f" << std::endl;
			std::cout << ansi((short[]){BOLD, BLUE}, 2) + "   Double : " << ansi(NULL, 0) << static_cast<double>(f) << ".0" << std::endl;
		} else {
			std::cout << ansi((short[]){BOLD, BLUE}, 2) + "    Float : " << ansi(NULL, 0) << f << "f" << std::endl;
			std::cout << ansi((short[]){BOLD, GREEN}, 2) + "   Double : " << ansi(NULL, 0) << atof(str.c_str()) << std::endl;
		}
	}
	return;
}

static void	fromDouble(std::string &str) {
	double d = static_cast<double>(atof(str.c_str()));
	if (str == "nan" || str.substr(1) == "inf") {
		std::cout << ansi((short[]){BOLD, YELLOW}, 2) + "     Char : " << ansi((short[]){ITALIC, DARK}, 2) + "Impossible" << std::endl;
		std::cout << ansi((short[]){BOLD, CYAN}, 2) + "      Int : " << ansi((short[]){ITALIC, DARK}, 2) + "Impossible" << std::endl;
		std::cout << ansi((short[]){BOLD, BLUE}, 2) + "    Float : " << ansi(NULL, 0) << str + 'f' << std::endl;
		std::cout << ansi((short[]){BOLD, GREEN}, 2) + "   Double : " << ansi(NULL, 0) <<  str << std::endl;
	} else {
		if (d < 255 && isprint(static_cast<char>(d))) std::cout << ansi((short[]){BOLD, YELLOW}, 2) + "     Char : " << ansi(NULL, 0) << static_cast<char>(d) << std::endl;
		else std::cout << ansi((short[]){BOLD, YELLOW}, 2) + "     Char : " << ansi((short[]){ITALIC, DARK}, 2) + "Non displayable" << std::endl;
		if (std::numeric_limits<int>::min() <= d && d <= std::numeric_limits<int>::max()) std::cout << ansi((short[]){BOLD, CYAN}, 2) + "      Int : " << ansi(NULL, 0) << static_cast<int>(d) << std::endl;
		else std::cout << ansi((short[]){BOLD, CYAN}, 2) + "      Int : " << ansi((short[]){ITALIC, DARK}, 2) + "Non displayable" << std::endl;
		if (d == static_cast<long long int>(d)) {
			std::cout << ansi((short[]){BOLD, BLUE}, 2) + "    Float : " << ansi(NULL, 0) <<  static_cast<float>(d) << ".0f" << std::endl;
			std::cout << ansi((short[]){BOLD, BLUE}, 2) + "   Double : " << ansi(NULL, 0) << d << ".0" << std::endl;
		} else {
			std::cout << ansi((short[]){BOLD, BLUE}, 2) + "    Float : " << ansi(NULL, 0) << static_cast<float>(d) << "f" << std::endl;
			std::cout << ansi((short[]){BOLD, GREEN}, 2) + "   Double : " << ansi(NULL, 0) << d << std::endl;
		}
	}
}

int	main(int argc, char *argv[]) {
	if (argc != 2) {
		std::cerr << "Usage: " << argv[0] << " [char | int | float | double]" << std::endl;
		return 1;
	}

	std::string	type(argv[1]);
	int point = 0;
	if (type.length() == 1 && !isdigit(type[0])) {
		fromChar(type);
		return 0;
	} else if (type == "nan" || type == "nanf") {
		(type[type.length() - 1] == 'f') ? fromFloat(type) : fromDouble(type);
		return 0;
	} else {
		for (size_t i = 0; i < type.length(); i++) {
			if (!i && (type[i] == '-' || type[i] == '+')) {
				if (type.substr(1) == "inf" || type.substr(1) == "inff") {
					(type[type.length() - 2] == 'f') ? fromFloat(type) : fromDouble(type);
					return 0;
				}
				continue;
			} else if (type[i] == '.') {
				if (++point > 1) {
					std::cerr << "error: c" << i << ": " << type[i] << std::endl;
					return 1;
				}
				continue;
			} else if (i >= 2 && point && i == type.length() - 1 && type[i] == 'f') {
				continue;
			} else if (!isdigit(type[i])) {
				std::cerr << "error: c" << i << ": " << type[i] << std::endl;
				return 1;
			}
		}
	}
	double number = static_cast<double>(atof(type.c_str()));
	if (!point && std::numeric_limits<int>::min() < number && number < std::numeric_limits<int>::max())
		fromInt(type);
	else if (type[type.length() - 1] == 'f')
		fromFloat(type);
	else
		fromDouble(type);
	return 0;
}