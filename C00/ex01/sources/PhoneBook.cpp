#include "PhoneBook.hpp"

void	PhoneBook::_printInfo(std::string info) {
	std::cout << ansi((short[]){NORMAL}, 1);
	if (info.length() > PRINT_MAX)
		std::cout << info.substr(0, PRINT_MAX - 1) + ".";
	else
		std::cout << info.substr(0, PRINT_MAX) ;
			for(short i = PRINT_MAX - info.length(); i > 0; i--)
				std::cout << " ";
	return;
}

void	PhoneBook::add(void) {
	short i = 0;	
	if (this->_contact[CONTACT_MAX - 1].exist) {
		for (i = 0; i < CONTACT_MAX - 1; i++)
			this->_contact[i] = this->_contact[i + 1];
	} else {
		for (i = 0; this->_contact[i].exist && i < CONTACT_MAX; i++);
	}
	this->_contact[i].creatContact();
	std::cout << ansi((short[]){BOLD, BLINK}, 2) + _contact[i].getNickname() + ansi((short[]){NORMAL, BOLD, GREEN}, 3) + " has been successfully added to your contacts." << std::endl;
	std::cout << std::endl;
	return;
}

void	PhoneBook::search(void) {
	std::string choice;
	bool		checkChoice = false;
	short		i;

	while (!checkChoice) {
		std::system("clear");
		std::cout << ansi((short[]){BOLD, CYAN}, 2) +  "_________________PHONEBOOK_________________" << std::endl;
		std::cout << std::endl;
		std::cout << "Index     |First Name|Last Name |Nickname  " << std::endl;
		std::cout << "----------|----------|----------|----------" << std::endl;
		for (i = 0; this->_contact[i].exist == true; i++) {
			std::ostringstream	index;
			index << i + 1;
			this->_printInfo(index.str());
			std::cout << ansi((short[]){BOLD, CYAN}, 2) + "|";
			this->_printInfo(this->_contact[i].getFirstName());
			std::cout << ansi((short[]){BOLD, CYAN}, 2) + "|";
			this->_printInfo(this->_contact[i].getLastName());
			std::cout << ansi((short[]){BOLD, CYAN}, 2) + "|";
			this->_printInfo(this->_contact[i].getNickname());
			std::cout << std::endl;
		}
		std::cout << std::endl;
		while (!checkChoice) {
			choice = Contact::checkInput(ansi((short[]){NORMAL, BOLD}, 2) + "Enter the index for all informations or enter an other option between " + ansi((short[]){BOLD, GREEN}, 2) + "ADD" + "\033[1;0m, " + ansi((short[]){BOLD, CYAN}, 2) + "SEARCH" + "\033[1;0m, " + ansi((short[]){BOLD, RED}, 2) + "EXIT" + "\033[1;0m: ");
			i = atoi(choice.c_str());
			if (i > 0 && i <= PRINT_MAX && this->_contact[i - 1].exist == true) {
				this->_contact[i -1].printContact();
					checkChoice = true;
			} else if (choice == "ADD") {
				this->add();
				checkChoice = true;
			} else if (choice == "SEARCH") {
				break;
			} else if (choice ==  "EXIT") {
				this->exit();
			}
		}
	}
}

void	PhoneBook::exit(void) {
	std::cout << ansi((short[]){BOLD, RED}, 2) << "You have quit your directory." << ansi((short[]){NORMAL, BOLD, BLINK}, 3) << " See you soon !" << std::endl;
	std::cout << ansi((short[]){NORMAL, ITALIC}, 2) + "Press ENTER to continue...";
	std::cin.get();
	::exit (EXIT_SUCCESS);
	return;
}
