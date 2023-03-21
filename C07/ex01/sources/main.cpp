#include <iostream>
#include "ansi.hpp"
#include "Iter.hpp"

template<typename T>
void	display(size_t &index, T &arg) { std::cout << ansi(NULL, 0) + "Case " << index << ": " << ansi((short[]){ITALIC, CYAN}, 2) << arg << std::endl; }

int main(void) {
		int intTab[5] = {5, 7, 6, 3, 4};
		iter(intTab, 5, &display);
		std::cout  << std::endl;

		std::string strTab[4] = {"I", "am", "a", "string"};
		iter(strTab, 4, &display);
	return 0;
}