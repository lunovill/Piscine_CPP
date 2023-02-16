#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <cstdlib>
# include <iostream>
# include "ansi.hpp"

class	Contact {

	private:

		std::string	_firstName;
		std::string	_lastName;
		std::string	_nickname;
		std::string	_phoneNumber;
		std::string	_darkestSecret;

	public:

		Contact();

		std::string getFirstName() const;
  		std::string getLastName() const;
    	std::string getNickname() const;
    	std::string getPhoneNumber() const;
    	std::string getDarkestSecret() const;


		bool		exist;

		static std::string	checkInput(std::string message);
		void				creatContact(void);
		void				printContact(void);

};

#endif