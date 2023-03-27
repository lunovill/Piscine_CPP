#include "Span.hpp"

/********************************************************************************/
/* ------------------------------- CONSTRUCTOR -------------------------------- */
/********************************************************************************/

Span::Span(unsigned int size) : _size(size) {
	std::cout << ansi((short[]){BOLD, GREEN}, 2) + "Constructor called for " + __func__ + "." << std::endl;
	return;
}

Span::Span(const Span &copy) : _size(copy._size), _array(copy._array) {
	std::cout << ansi((short[]){BOLD, GREEN}, 2) + "Copy constructor called for " + __func__ + "." << std::endl;
	return;
}

/********************************************************************************/
/* -------------------------------- DESTRUCTOR -------------------------------- */
/********************************************************************************/

Span::~Span(void) {
	std::cout << ansi((short[]){BOLD, RED}, 2) + "Default constructor called for " + __func__ + "." << std::endl;
	return;
}

/********************************************************************************/
/* --------------------------------- OVERLOAD --------------------------------- */
/********************************************************************************/

Span	&Span::operator=(const Span &rhs) {
	if (this != &rhs) {
		this->_size = rhs._size;
		this->_array = rhs._array;
	}
	return *this;
}

/********************************************************************************/
/* --------------------------------- METHODS ---------------------------------- */
/********************************************************************************/

const char	*Span::ArrayIsFull::what(void) const throw() { return "\033[0;2;3mSpan is full"; }

const char	*Span::NotEnoughValue::what(void) const throw() { return "\033[0;2;3mNot enough value"; }

void		Span::addNumber(int value) {
	if (this->_array.size() == _size) throw ArrayIsFull();
	this->_array.push_back(value);
	return;
}

void		Span::addRange(int range[], unsigned int size) {
	if (this->_size < this->_array.size() + size) throw ArrayIsFull();
	for (unsigned int i = 0; i < size; i++)
		this->_array.push_back(range[i]);
	return;
}

int			Span::shortestSpan(void) const {
	if (this->_array.size() < 2) throw NotEnoughValue();
	std::vector<int>	array = this->_array;
	std::sort(array.begin(), array.end());
	int shortest = std::abs(array[1] - array[0]);
	for (unsigned int i = 1; i < array.size(); ++i)
		if (std::abs(array[i] - array[i - 1]) < shortest) shortest = std::abs(array[i] - array[i - 1]);
	return shortest;
}

int			Span::longestSpan(void) const {
	if (this->_array.size() < 2) throw NotEnoughValue();
	return std::abs(*std::max_element(this->_array.begin(), this->_array.end()) - *std::min_element(this->_array.begin(), this->_array.end()));
}

/********************************************************************************/
/* --------------------------------- ACCESSOR --------------------------------- */
/********************************************************************************/

std::vector<int>	Span::getArray(void) const { return this->_array; }

/********************************************************************************/

std::ostream	&operator<<(std::ostream &o, const Span &rhs) {
	std::vector<int> array = rhs.getArray();
	o << "[";
	for (unsigned int i = 0; i < array.size(); i++)
		o << array[i] << ", ";
	o << "\033[2D]";
	return o;
}
