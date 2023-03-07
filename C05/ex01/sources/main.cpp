#include <cstdlib>
#include "Bureaucrat.hpp"

int main(void) {
	std::system("clear");

	try {
		std::cout << Form("page", 151, 42) << std::endl; // Impossible, le code s'arrete
	} catch (Form::GradeTooHighException &e) {
		std::cerr << ansi((short[]){UNDERLINE, DARK}, 2) + "error: throw:" << ansi(NULL, 0) + " " + e.what() << std::endl;
	} catch (Form::GradeTooLowException &e) {
		std::cerr << ansi((short[]){UNDERLINE, DARK}, 2) + "error: throw:" << ansi(NULL, 0) + " " + e.what() << std::endl;
	}

	std::cout << ansi((short[]){BOLD}, 1) << std::string(30, '-') << std::endl;

	try {
		std::cout << Form("note", 42, 0) << std::endl; // Impossible, le code s'arrete
	} catch (Form::GradeTooHighException &e) {
		std::cerr << ansi((short[]){UNDERLINE, DARK}, 2) + "error: throw:" << ansi(NULL, 0) + " " + e.what() << std::endl;
	} catch (Form::GradeTooLowException &e) {
		std::cerr << ansi((short[]){UNDERLINE, DARK}, 2) + "error: throw:" << ansi(NULL, 0) + " " + e.what() << std::endl;
	}

	std::cout << ansi((short[]){BOLD}, 1) << std::string(30, '-') << std::endl;

	try {
		Bureaucrat	david("David", 42);
		Form		invoice("a invoice", 84, 150);
		Form		contract("a contract", 21, 150);
		std::cout << ansi((short[]){BOLD}, 1) << "There is " << david << ansi((short[]){BOLD}, 1) << " And " << invoice << ansi((short[]){BOLD}, 1) << " And also " << contract << std::endl;
		david.signForm(invoice);
		david.signForm(contract);
	} catch (Bureaucrat::GradeTooHighException &e) {
		std::cerr << ansi((short[]){UNDERLINE, DARK}, 2) + "error: throw:" << ansi(NULL, 0) + " " + e.what() << std::endl;
	} catch (Bureaucrat::GradeTooLowException &e) {
		std::cerr << ansi((short[]){UNDERLINE, DARK}, 2) + "error: throw:" << ansi(NULL, 0) + " " + e.what() << std::endl;
	}
	return 0;
}