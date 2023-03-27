#ifndef SPAN_HPP
# define SPAN_HPP

# include <algorithm>
# include <iostream>
# include <vector>
# include "ansi.hpp"

class	Span {

	private:

		unsigned int		_size;
		std::vector<int>	_array;

		Span(void);

	public:

		Span(unsigned int size);
		Span(const Span &copy);
		~Span(void);

		Span	&operator=(const Span &rhs);

		class	ArrayIsFull : public std::exception {
			public:
				virtual const char	*what(void) const throw();
		};
		class	NotEnoughValue : public std::exception {
			public:
				virtual const char	*what(void) const throw();
		};

		void	addNumber(int value);
		void	addRange(int range[], unsigned int size);
		int		shortestSpan(void) const;
		int		longestSpan(void) const;

		std::vector<int>	getArray(void) const;
};

std::ostream	&operator<<(std::ostream &o, const Span &rhs);

#endif
