#include <cstdlib>
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main(void) {
	std::system("clear");
	{
		Bureaucrat	jane("Jane", 1);
		Bureaucrat	nike("Nike", 140);
		ShrubberyCreationForm	form("Tree");
		std::cout << ansi((short[]){BOLD}, 1) << std::string(30, '-') << std::endl;
		std::cout << ansi((short[]){BOLD}, 1) << "There is " << jane << std::endl;
		std::cout << ansi((short[]){BOLD}, 1) << "There is also " << nike << std::endl;
		std::cout << ansi((short[]){BOLD}, 1) << "There is " << form << std::endl;
		nike.executeForm(form);
		jane.executeForm(form);
		nike.signForm(form);
		jane.executeForm(form);
		std::cout << ansi((short[]){BOLD}, 1) << std::string(30, '-') << std::endl;
		
	}

	std::cout << ansi((short[]){ITALIC}, 1) + "Press ENTER to continue...";
	std::cin.get();
	if (std::cin.eof())
		return 0;

	std::system("clear");
	{
		Bureaucrat	jane("Jane", 1);
		Bureaucrat	nike("Nike", 50);
		RobotomyRequestForm	form(nike.getName());
		std::cout << ansi((short[]){BOLD}, 1) << std::string(30, '-') << std::endl;
		std::cout << ansi((short[]){BOLD}, 1) << "There is " << jane << std::endl;
		std::cout << ansi((short[]){BOLD}, 1) << "There is also " << nike << std::endl;
		std::cout << ansi((short[]){BOLD}, 1) << "There is " << form << std::endl;
		nike.executeForm(form);
		jane.executeForm(form);
		nike.signForm(form);
		jane.executeForm(form);
		std::cout << ansi((short[]){BOLD}, 1) << std::string(30, '-') << std::endl;
	}

	std::cout << ansi((short[]){ITALIC}, 1) + "Press ENTER to continue...";
	std::cin.get();
	if (std::cin.eof())
		return 0;

	std::system("clear");
	{
		Bureaucrat	jane("Jane", 1);
		Bureaucrat	nike("Nike", 20);
		PresidentialPardonForm	form(jane.getName());
		std::cout << ansi((short[]){BOLD}, 1) << std::string(30, '-') << std::endl;
		std::cout << ansi((short[]){BOLD}, 1) << "There is " << jane << std::endl;
		std::cout << ansi((short[]){BOLD}, 1) << "There is also " << nike << std::endl;
		std::cout << ansi((short[]){BOLD}, 1) << "There is " << form << std::endl;
		nike.executeForm(form);
		jane.executeForm(form);
		nike.signForm(form);
		jane.executeForm(form);
		std::cout << ansi((short[]){BOLD}, 1) << std::string(30, '-') << std::endl;
	}

	std::cout << ansi((short[]){ITALIC}, 1) + "Press ENTER to continue...";
	std::cin.get();
	if (std::cin.eof())
		return 0;

	return 0;
}