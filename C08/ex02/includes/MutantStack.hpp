#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# include <iostream>
# include <iterator>
# include <stack>
# include "ansi.hpp"

template<typename T>
class	MutantStack : public std::stack<T> {

	public:

		MutantStack<T>(void);
		MutantStack<T>(const MutantStack<T> &copy);
		virtual	~MutantStack<T>(void);

		MutantStack<T>	&operator=(const MutantStack<T> &rhs);

		typedef typename std::deque<T>::iterator			iterator;
        typedef typename std::deque<T>::reverse_iterator	reverse_iterator;

        iterator			begin();
        iterator			end();
        reverse_iterator	rbegin();
        reverse_iterator	rend();
};

template<typename T>
std::ostream	&operator<<(std::ostream &o, const MutantStack<T> &rhs);

#endif
