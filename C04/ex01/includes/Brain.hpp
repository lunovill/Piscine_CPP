#ifndef BRAIN_HPP
# define BRAIN_HPP

# include <iostream>
# include "ansi.hpp"

class	Brain {

	private:

		std::string	_ideas[100];

	public:

		Brain(void);
		Brain(const Brain &copy);
		~Brain(void);

		Brain	&operator=(const Brain &rhs);

		std::string	getIdea(int i) const;
		void		setIdea(int i, std::string idea);
};

#endif
