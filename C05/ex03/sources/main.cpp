#include <cstdlib>
#include "Intern.hpp"

int main(void) {
	try {
		std::system("clear");
		{
			Bureaucrat	jane("Jane", 1);
			Bureaucrat	nike("Nike", 140);
			Intern		intern;
			AForm	*form = intern.makeForm("ShrubberyCreationForm", "Tree");
			std::cout << ansi((short[]){BOLD}, 1) << std::string(30, '-') << std::endl;
			std::cout << ansi((short[]){BOLD}, 1) << "There is " << jane << std::endl;
			std::cout << ansi((short[]){BOLD}, 1) << "There is also " << nike << std::endl;
			std::cout << ansi((short[]){BOLD}, 1) << "There is " << *form << std::endl;
			nike.executeForm(*form);
			jane.executeForm(*form);
			nike.signForm(*form);
			jane.executeForm(*form);
			std::cout << ansi((short[]){BOLD}, 1) << std::string(30, '-') << std::endl;
			delete form;
		}

		std::cout << ansi((short[]){ITALIC}, 1) + "Press ENTER to continue...";
		std::cin.get();
		if (std::cin.eof())
			return 0;

		std::system("clear");
		{
			Bureaucrat	jane("Jane", 1);
			Bureaucrat	nike("Nike", 50);
			Intern		intern;
			AForm	*form = intern.makeForm("RobotomyRequestForm", nike.getName());
			std::cout << ansi((short[]){BOLD}, 1) << std::string(30, '-') << std::endl;
			std::cout << ansi((short[]){BOLD}, 1) << "There is " << jane << std::endl;
			std::cout << ansi((short[]){BOLD}, 1) << "There is also " << nike << std::endl;
			std::cout << ansi((short[]){BOLD}, 1) << "There is " << *form << std::endl;
			nike.executeForm(*form);
			jane.executeForm(*form);
			nike.signForm(*form);
			jane.executeForm(*form);
			std::cout << ansi((short[]){BOLD}, 1) << std::string(30, '-') << std::endl;
			delete form;
		}

		std::cout << ansi((short[]){ITALIC}, 1) + "Press ENTER to continue...";
		std::cin.get();
		if (std::cin.eof())
			return 0;

		std::system("clear");
		{
			Bureaucrat	jane("Jane", 1);
			Bureaucrat	nike("Nike", 20);
			Intern		intern;
			AForm	*form = intern.makeForm("PresidentialPardonForm", jane.getName());
			std::cout << ansi((short[]){BOLD}, 1) << std::string(30, '-') << std::endl;
			std::cout << ansi((short[]){BOLD}, 1) << "There is " << jane << std::endl;
			std::cout << ansi((short[]){BOLD}, 1) << "There is also " << nike << std::endl;
			std::cout << ansi((short[]){BOLD}, 1) << "There is " << *form << std::endl;
			nike.executeForm(*form);
			jane.executeForm(*form);
			nike.signForm(*form);
			jane.executeForm(*form);
			std::cout << ansi((short[]){BOLD}, 1) << std::string(30, '-') << std::endl;
			delete form;
		}

		std::cout << ansi((short[]){ITALIC}, 1) + "Press ENTER to continue...";
		std::cin.get();
		if (std::cin.eof())
			return 0;

		std::system("clear");
		{
			Intern		intern;
			AForm	*form = intern.makeForm("No exist", "Form");
			std::cout << ansi((short[]){BOLD}, 1) << "There is " << *form << std::endl;
			delete form;
		}

	} catch (std::exception &e) {
		std::cerr << ansi((short[]){UNDERLINE, DARK}, 2) + "error: throw:" << ansi(NULL, 0) + " " << e.what() << std::endl;
	}
	return 0;
}