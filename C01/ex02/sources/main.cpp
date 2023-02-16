#include <iostream>

int		main(void) {
	std::string str = "HI THIS IS BRAIN";
	std::string *stringPTR = &str;
	std::string &stringREF = str;

	std::cout << "L’adresse de ma string    : " << &str << std::endl;
	std::cout << "L’adresse de mon pointeur : " << stringPTR << std::endl;
	std::cout << "L’adresse de ma reference : " << &stringREF << std::endl;
	std::cout << std::endl;
	std::cout << "Le contenue de ma string    : " << str << std::endl;
	std::cout << "Le contenue de mon pointeur : " << *stringPTR << std::endl;
	std::cout << "Le contenue de ma reference : " << stringREF << std::endl;
	return 0;
}
