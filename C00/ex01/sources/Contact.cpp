#include "Contact.hpp"

Contact::Contact() {
    this->exist = false;
}


std::string Contact::getFirstName() const {
	return this->_firstName;
}
std::string Contact::getLastName() const {
	return this->_lastName;
}

std::string Contact::getNickname() const {
	return this->_nickname;
}

std::string Contact::getPhoneNumber() const {
	return this->_phoneNumber;
}

std::string Contact::getDarkestSecret() const {
	return this->_darkestSecret;
}

std::string	Contact::checkInput(std::string message) {
	std::string	input;

	while (input.empty())
	{
		std::cout << message;
		getline(std::cin, input);
		if (std::cin.eof())
			exit(EXIT_FAILURE);
	}
	return (input);
}

void	Contact::creatContact(void) {
	std::string	choice;
	bool		checkChoice = false;

	while (!checkChoice) {
		std::system("clear");
		std::cout << ansi((short[]){BOLD, GREEN}, 2) + "________________NEW CONTACT________________" << std::endl;
		std::cout << std::endl;
		this->_firstName = Contact::checkInput(ansi((short[]){BOLD, GREEN}, 2) + "          First name : " + ansi((short[]){NORMAL}, 1));
		this->_lastName = Contact::checkInput(ansi((short[]){BOLD, GREEN}, 2) + "           Last name : " + ansi((short[]){NORMAL}, 1));
		this->_nickname = Contact::checkInput(ansi((short[]){BOLD, GREEN}, 2) + "            Nickname : " + ansi((short[]){NORMAL}, 1));
		this->_phoneNumber = Contact::checkInput(ansi((short[]){BOLD, GREEN}, 2) + "        Phone number : " + ansi((short[]){NORMAL}, 1));
		this->_darkestSecret = Contact::checkInput(ansi((short[]){BOLD, GREEN}, 2) + "      Darkest secret : " + ansi((short[]){NORMAL}, 1));
		std::cout << std::endl;
		while (!checkChoice) {
			choice = Contact::checkInput(ansi((short[]){BOLD, YELLOW}, 2) + "Are you sure ? [y/n] : " + ansi((short[]){NORMAL}, 1));
			if (choice == "y" || choice == "yes")
				checkChoice = true;
			else if (choice == "n" || choice == "no")
				break;
		}
		this->exist = 1;
	}
	return;
}

void	Contact::printContact(void)
{
	std::system("clear");
	std::cout << ansi((short[]){BOLD, CYAN}, 2) + "__________________CONTACT__________________\n" << std::endl;
	std::cout << ansi((short[]){BOLD, CYAN}, 2) + "          First name : " + ansi((short[]){NORMAL}, 1) + this->_firstName << std::endl;
	std::cout << ansi((short[]){BOLD, CYAN}, 2) + "           Last name : " + ansi((short[]){NORMAL}, 1) + this->_lastName << std::endl;
	std::cout << ansi((short[]){BOLD, CYAN}, 2) + "            Nickname : " + ansi((short[]){NORMAL}, 1) + this->_nickname << std::endl;
	std::cout << ansi((short[]){BOLD, CYAN}, 2) + "        Phone number : " + ansi((short[]){NORMAL}, 1) + this->_phoneNumber << std::endl;
	std::cout << ansi((short[]){BOLD, CYAN}, 2) + "      Darkest secret : " + ansi((short[]){NORMAL}, 1) + this->_darkestSecret << std::endl;
	std::cout << std::endl;
	return;
}