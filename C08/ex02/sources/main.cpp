#include "MutantStack.tpp"

int main(void) {
	MutantStack<int>	mutant;
	mutant.push(0);
	mutant.push(1);
	mutant.push(1);
	mutant.push(2);
	mutant.push(5);
	mutant.push(8);
	mutant.push(13);
	mutant.push(21);

	std::cout << ansi(NULL, 0) <<"      J'utilie iterator sur mutant: ";
	std::cout << "[";
	for (MutantStack<int>::iterator it = mutant.begin(); it != mutant.end(); ++it)
		std::cout << *it << ", ";
	std::cout << "\033[2D]" << std::endl;

	MutantStack<int>	copy(mutant);

	std::cout << ansi(NULL, 0) <<"J'utilie reverse_iterator sur copy: ";
	std::cout << "[";
	for (MutantStack<int>::reverse_iterator rit = mutant.rbegin(); rit != mutant.rend(); ++rit)
		std::cout << *rit << ", ";
	std::cout << "\033[2D]" << std::endl;

	MutantStack<int>	mutant2;
	mutant2.push(0);
	mutant2.push(-1);
	mutant2.push(-1);
	mutant2.push(-2);
	mutant2.push(-5);
	mutant2.push(-8);
	mutant2.push(-13);
	mutant2.push(-21);

	std::cout << ansi(NULL, 0) << "                           mutant = mutant2" << std::endl;
	mutant = mutant2;
	std::cout << mutant << " = " << mutant2 << std::endl;
	return 0;
}