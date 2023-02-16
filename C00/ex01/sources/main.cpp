#include "PhoneBook.hpp"
#include "ansi.hpp"

int	main(void) {
	PhoneBook	directory;
	std::string	option;

	std::system("clear");
	while (true) {
		option = Contact::checkInput(ansi((short[]){NORMAL, BOLD}, 1) + "Enter an option between " + ansi((short[]){BOLD, GREEN}, 2) + "ADD" + "\033[1;0m, " + ansi((short[]){BOLD, CYAN}, 2) + "SEARCH" + "\033[1;0m, " + ansi((short[]){BOLD, RED}, 2) + "EXIT" + "\033[1;0m: ");
		if (option == "ADD")
			directory.add();
		else if (option == "SEARCH")
			directory.search();
		else if (option == "EXIT")
			directory.exit();
	}
	return 0;
}