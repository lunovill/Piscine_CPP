#include "PmergeMe.hpp"

static void	insert(std::deque<unsigned int> &sequence) {
	for (unsigned int i = 0; i < sequence.size(); ++i) {
		unsigned int	n = sequence[i];
		unsigned int	j;
		for (j = i; j > 0 && sequence[j - 1] > n; --j)
			sequence[j] = sequence[j - 1];
		sequence[j] = n;
	}
	return;
}

static std::list<unsigned int>::iterator	prevIt(std::list<unsigned int>::iterator it) { return --it; }
static void    insert(std::list<unsigned int> &sequence) {
	for (std::list<unsigned int>::iterator it = sequence.begin(); it != sequence.end(); ++it) {
		unsigned int n = *it;
		std::list<unsigned int>::iterator itSwap;
		for	(itSwap = it; itSwap != sequence.begin() && *prevIt(itSwap) > n; --itSwap)
			*itSwap = *prevIt(itSwap);
		*itSwap = n;
	}
}

static void	merge(std::deque<unsigned int> &sequence, std::deque<unsigned int> &left, std::deque<unsigned int> &right) {
	std::deque<unsigned int>::iterator	it = sequence.begin();
	std::deque<unsigned int>::iterator	itLeft = left.begin();
	std::deque<unsigned int>::iterator	itRight = right.begin();

	while (itLeft != left.end() && itRight != right.end()) {
		if (*itLeft < *itRight) {
			*it = *itLeft;
			itLeft++;
		} else {
			*it = *itRight;
			itRight++;
		}
		it++;
	}
	std::copy(itLeft, left.end(), it);
	std::copy(itRight, right.end(), it);
	return;
}

static void	merge(std::list<unsigned int> &sequence, std::list<unsigned int> &left, std::list<unsigned int> &right) {
	std::list<unsigned int>::iterator	it = sequence.begin();
	std::list<unsigned int>::iterator	itLeft = left.begin();
	std::list<unsigned int>::iterator	itRight = right.begin();

	while (itLeft != left.end() && itRight != right.end()) {
		if (*itLeft < *itRight) {
			*it = *itLeft;
			itLeft++;
		} else {
			*it = *itRight;
			itRight++;
		}
		it++;
	}
	std::copy(itLeft, left.end(), it);
	std::copy(itRight, right.end(), it);
	return;
}

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