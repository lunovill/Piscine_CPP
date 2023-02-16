#include "Harl.hpp"

Harl::Harl(void) {
	
	Harl::input[0] = "DEBUG";
	Harl::input[1] = "INFO";
	Harl::input[2] = "WARNING";
	Harl::input[3] = "ERROR";

	Harl::function[0] = &Harl::_debug;
	Harl::function[1] = &Harl::_info;
	Harl::function[2] = &Harl::_warning;
	Harl::function[3] = &Harl::_error;
	return;
}

void	Harl::_debug(void) {
	std::cout << ansi((short[]){NORMAL, BOLD}, 2) + "[ DEBUG ]" << std::endl;
	std::cout << ansi((short[]){NORMAL}, 1) + "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do !" << std::endl;
	return;
}
void	Harl::_info(void) {
	std::cout << ansi((short[]){NORMAL, BOLD, GREEN}, 3) + "[ INFO ]" << std::endl;
	std::cout << ansi((short[]){NORMAL, GREEN}, 2) + "I cannot believe adding extra bacon costs more money. You didn't put enough bacon in my burger ! If you did, I wouldn't be asking for more !" << std::endl;
	return;
}
void	Harl::_warning(void) {
	std::cout << ansi((short[]){NORMAL, BOLD, YELLOW}, 3) + "[ WRANING ]" << std::endl;
	std::cout << ansi((short[]){NORMAL, YELLOW}, 2) + "I think I deserve to have some extra bacon for free. I've been coming for years whereas you started working here since last month." << std::endl;
	return;
}
void	Harl::_error(void) {
	std::cout << ansi((short[]){NORMAL, BOLD, RED}, 3) + "[ ERROR ]" << std::endl;
	std::cout << ansi((short[]){NORMAL, RED}, 2) + "This is unacceptable ! I want to speak to the manager now." << std::endl;
	return;
}
void	Harl::complain(std::string level) {
	for (int i = 0; i < 4; i++)
	{
		if (this->input[i] == level)
			return (this->*function[i])();
	}
	std::cout << ansi((short[]){NORMAL, BOLD, RED}, 3) + "Error:" << ansi((short[]){NORMAL, RED}, 2) + " Invalid message" << std::endl;
	return;
}