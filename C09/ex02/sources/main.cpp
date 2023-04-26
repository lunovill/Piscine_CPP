#include <ctime>
#include <iostream>
#include <limits>
#include "ansi.hpp"
#include "PmergeMe.hpp"

std::ostream	&operator<<(std::ostream &output, std::deque<unsigned int> &sequence) {
	for (unsigned int i = 0; i < sequence.size(); ++i)
		output << " " << sequence[i];
	return output;
}

std::ostream	&operator<<(std::ostream &output, std::list<unsigned int> &sequence) {
	for (std::list<unsigned int>::iterator it = sequence.begin(); it != sequence.end(); ++it)
		output << " " << *it;
	return output;
}

static unsigned int	findQ(unsigned int n) {
	int	t = n;
	while (t >= 10) { t /= 10; }
	return n / t;
}

int	main(int argc, char *argv[]) {
	if (argc < 2) {
		std::cerr << ansi((short[]){UNDERLINE, DARK}, 2) + "Usage:" << ansi((short[]){DARK}, 1) + " " + argv[0] << "<number1> <number2>..." << std::endl;
		return 1;
	}
	std::deque<unsigned int>	sequenceDQE;
	std::list<unsigned int>		sequenceLST;
	for (int i = 1; i < argc; ++i) {
		std::size_t	found = std::string(argv[i]).find_first_not_of("0123456789");
		if (found != std::string::npos) {
			std::cerr << ansi((short[]){UNDERLINE, DARK}, 2) << "Error:" << ansi((short[]){DARK, ITALIC}, 2) << " invalid character: `" << argv[i][found] << "'" << std::endl;
			return 1;
		}
		std::istringstream iss(argv[i]);
		unsigned long		value;
		iss >> value;
		if (value >= static_cast<unsigned long>(std::numeric_limits<unsigned int>::max())) {
			std::cerr << ansi((short[]){UNDERLINE, DARK}, 2) << "Error:" << ansi((short[]){DARK, ITALIC}, 2) << " too large a number: " << argv[i] << std::endl;
			return 1;
		}
		sequenceDQE.push_back(value);
		sequenceLST.push_back(value);
	}
	unsigned int	threshold = sequenceDQE.size() / findQ(sequenceDQE.size());
	std::cout << "Befor:\t" << sequenceDQE << std::endl;

	std::clock_t start = std::clock();
	merge_insert(sequenceDQE, threshold);
	std::clock_t end = std::clock();
	double elapsed_time = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000.0;
	std::cout << "After:\t" << sequenceDQE << std::endl;
	std::cout << "Time to process a range of " << sequenceDQE.size() << " elements with std::deque : " << elapsed_time << " ms" << std::endl;

	start = std::clock();
	merge_insert(sequenceLST, threshold);
	end = std::clock();
	elapsed_time = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000.0;
	std::cout << "Time to process a range of " << sequenceLST.size() << " elements with std::list : " << elapsed_time << " ms" << std::endl;

	return 0;
}
