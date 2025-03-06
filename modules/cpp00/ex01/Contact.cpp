#include "Contact.hpp"

// constructors and destructor
Contact::Contact(void) :
		_first_name(""),
		_last_name(""),
		_nickname(""),
		_phone_number(""),
		_darkest_secret("") {
	
		if (PRINT_C)
			std::cout << YELLOW << "default c " << RESET;	
	} ;

Contact::Contact(const std::string &first,
			const std::string &last,
			const std::string &nick,
		 	const std::string &phone,
		 	const std::string &darkest) :

	_first_name(first),
	_last_name(last),
	_nickname(nick),
	_phone_number(phone),
	_darkest_secret(darkest) {
		
		if (PRINT_C)
			std::cout << YELLOW << "Contact created! " << RESET << std::endl;	
	}

Contact::~Contact(void)	{
	
	if (PRINT_C)
		std::cout << YELLOW 
			<< "contact destroyed!" << RESET << std::endl;	
	} ;

/* GETTERS *///////////////////////////////////

std::string Contact::get_first_name(void) const	{ 
	return this->_first_name ; 
}

std::string Contact::get_last_name(void) const	{ 
	return this->_last_name ; 
}

std::string Contact::get_nickname(void) const	{ 
	return this->_nickname ; 
}

std::string Contact::get_phone_number(void) const	{ 
	return this->_phone_number ; 
}

std::string Contact::get_darkest_secret(void) const	{ 
	return this->_darkest_secret ; 
}

void	Contact::print_contact(void)	const	{

	std::cout 
		<< std::left << std::setw(16) 
		<< "First Name: " << Contact::get_first_name() << std::endl
		<< std::left << std::setw(16) 
		<< "Last Name: " << Contact::get_last_name() << std::endl
		<< std::left << std::setw(16) 
		<< "Nickname: " << Contact::get_nickname() << std::endl
		<< std::left << std::setw(16) 
		<< "Phone Number: " << Contact::get_phone_number() << std::endl
		<< std::left << std::setw(16) 
		<< "Darkest Secret: " << Contact::get_darkest_secret() 
		<< std::endl;
}
