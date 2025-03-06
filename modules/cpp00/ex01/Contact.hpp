#ifndef CONTACT_HPP
# define CONTACT_HPP

#include <iostream>
#include <iomanip>

#define YELLOW "\e[1;3;93m"
#define RESET "\e[0m"
const int PRINT_C = 0;

class Contact {

public :

	Contact(void);

	Contact(const std::string &first,
			const std::string &last,
			const std::string &nick,
		 	const std::string &phone,
		 	const std::string &darkest) ;

	~Contact(void) ;

	std::string get_first_name(void) const	;
	std::string get_last_name(void) const	;
	std::string get_nickname(void) const	;
	std::string get_phone_number(void) const	;
	std::string get_darkest_secret(void) const	;

	void		print_contact(void) const	;

private :

	std::string _first_name;
	std::string	_last_name;
	std::string _nickname;
	std::string _phone_number;
	std::string _darkest_secret;
	
} ;

#endif
