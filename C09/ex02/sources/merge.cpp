#include "PmergeMe.hpp"

void	merge(std::deque<unsigned int> &sequence, std::deque<unsigned int> &left, std::deque<unsigned int> &right) {
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

void	merge(std::list<unsigned int> &sequence, std::list<unsigned int> &left, std::list<unsigned int> &right) {
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