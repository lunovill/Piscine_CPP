#include "PmergeMe.hpp"

void	merge_insert(std::deque<unsigned int> &sequence, unsigned int threshold) {
	if (sequence.size() == 1) { return; }
	if (sequence.size() <= threshold) {
		insert(sequence);
	} else {
		unsigned int				middle = sequence.size() / 2;
		std::deque<unsigned int>	left(sequence.begin(), sequence.begin() + middle);
		std::deque<unsigned int>	right(sequence.begin() + middle, sequence.end());
		merge_insert(left, threshold);
		merge_insert(right, threshold);
		merge(sequence, left, right);
	}
	return;
}

static std::list<unsigned int>::iterator itN(std::list<unsigned int> &sequence, unsigned int n) {
    std::list<unsigned int>::iterator it = sequence.begin();
    for (unsigned int i = 0; i < n; ++i) {
        it++;
    }
	return it;
}

void	merge_insert(std::list<unsigned int> &sequence, unsigned int threshold) {
	if (sequence.size() == 1) { return; }
	if (sequence.size() <= threshold) {
		insert(sequence);
	} else {
    	std::list<unsigned int>::iterator middle = itN(sequence, sequence.size()  / 2);
		std::list<unsigned int>	left(sequence.begin(), middle);
		std::list<unsigned int>	right(middle, sequence.end());
		merge_insert(left, threshold);
		merge_insert(right, threshold);
		merge(sequence, left, right);
	}
	return;
}