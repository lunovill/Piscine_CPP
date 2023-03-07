#include <cstdlib>
#include "Bureaucrat.hpp"

int main(void) {
	std::system("clear");

	try {
		Bureaucrat bob("Bob", 1);
		std::cout << bob << std::endl;
		bob.promoted(); // Impossible, le code s'arrete
		std::cout << bob << std::endl;
		bob.demoted();
		std::cout << bob << std::endl;
	} catch (Bureaucrat::GradeTooHighException &e) {
		std::cerr << ansi((short[]){UNDERLINE, DARK}, 2) + "error: throw:" << ansi(NULL, 0) + " " + e.what() << std::endl;
	} catch (Bureaucrat::GradeTooLowException &e) {
		std::cerr << ansi((short[]){UNDERLINE, DARK}, 2) + "error: throw:" << ansi(NULL, 0) + " " + e.what() << std::endl;
	}

	std::cout << ansi((short[]){BOLD}, 1) << std::string(30, '-') << std::endl;

	try {
		Bureaucrat steve("Steve", 150);
		std::cout << steve << std::endl;
		steve.promoted();
		std::cout << steve << std::endl;
		steve.demoted(); // Je le remets a 150
		steve.demoted(); // Impossible, le code s'arrete
		std::cout << steve << std::endl;
	} catch (Bureaucrat::GradeTooHighException &e) {
		std::cerr << ansi((short[]){UNDERLINE, DARK}, 2) + "error: throw:" << ansi(NULL, 0) + " " + e.what() << std::endl;
	} catch (Bureaucrat::GradeTooLowException &e) {
		std::cerr << ansi((short[]){UNDERLINE, DARK}, 2) + "error: throw:" << ansi(NULL, 0) + " " + e.what() << std::endl;
	}

	std::cout << ansi((short[]){BOLD}, 1) << std::string(30, '-') << std::endl;

	try {
		std::cout << Bureaucrat("Greg", 0) << std::endl; // Impossible, le code s'arrete
	} catch (Bureaucrat::GradeTooHighException &e) {
		std::cerr << ansi((short[]){UNDERLINE, DARK}, 2) + "error: throw:" << ansi(NULL, 0) + " " + e.what() << std::endl;
	} catch (Bureaucrat::GradeTooLowException &e) {
		std::cerr << ansi((short[]){UNDERLINE, DARK}, 2) + "error: throw:" << ansi(NULL, 0) + " " + e.what() << std::endl;
	}

	std::cout << ansi((short[]){BOLD}, 1) << std::string(30, '-') << std::endl;

	try {
		std::cout << Bureaucrat("David", 151) << std::endl; // Impossible, le code s'arrete
	} catch (Bureaucrat::GradeTooHighException &e) {
		std::cerr << ansi((short[]){UNDERLINE, DARK}, 2) + "error: throw:" << ansi(NULL, 0) + " " + e.what() << std::endl;
	} catch (Bureaucrat::GradeTooLowException &e) {
		std::cerr << ansi((short[]){UNDERLINE, DARK}, 2) + "error: throw:" << ansi(NULL, 0) + " " + e.what() << std::endl;
	}
	return 0;
}