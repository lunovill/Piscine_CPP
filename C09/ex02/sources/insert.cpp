#include "PmergeMe.hpp"

static  std::list<unsigned int>::iterator	prevIt(std::list<unsigned int>::iterator it) { return --it; }

void	insert(std::deque<unsigned int> &sequence) {
	for (unsigned int i = 0; i < sequence.size(); ++i) {
		unsigned int	n = sequence[i];
		unsigned int	j;
		for (j = i; j > 0 && sequence[j - 1] > n; --j)
			sequence[j] = sequence[j - 1];
		sequence[j] = n;
	}
	return;
}

void    insert(std::list<unsigned int> &sequence) {
	for (std::list<unsigned int>::iterator it = sequence.begin(); it != sequence.end(); ++it) {
		unsigned int n = *it;
		std::list<unsigned int>::iterator itSwap;
		for	(itSwap = it; itSwap != sequence.begin() && *prevIt(itSwap) > n; --itSwap)
			*itSwap = *prevIt(itSwap);
		*itSwap = n;
	}
}