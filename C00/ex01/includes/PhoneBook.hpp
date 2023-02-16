#ifndef PHONE_BOOK_HPP
# define PHONE_BOOK_HPP

# include "ansi.hpp"
# include "Contact.hpp"

# define CONTACT_MAX 8
# define PRINT_MAX 10

class	PhoneBook {

	private:

		Contact	_contact[CONTACT_MAX];

		void	_printInfo(std::string info);

	public:

		void	add(void);
		void	search(void);
		void	exit(void);
};

#endif