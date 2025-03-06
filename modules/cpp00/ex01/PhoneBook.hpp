#ifndef PHONE_BOOK_HPP
# define PHONE_BOOK_HPP

#include <iomanip>
#include <cctype>
#include <cstring>

#define YELLOW "\e[1;3;93m"
#define RESET "\e[0m"
const int MAX_ID = 8;
const int PRINT_P = 0;

#include "Contact.hpp"

class PhoneBook {

public:

	PhoneBook(void) ;
	~PhoneBook(void) ;

	void	set_contact(
		std::string const first,
		std::string const last,
		std::string const nick,
		std::string const phone,
		std::string const darkest) ;

	void		increment_i(void);
	bool		is_full(void) const;
	bool		is_empty(void) const;
	int			get_book_size(void) const;

	void		print_contact(int) const;
	void		add_contact(void)	;
	void		handle_search(std::string)	const	;

	void		print_list_contacts(void)	;
	void		print_head_table(void)	const	;
	
	void		print_short_contact(int)	;
	std::string	format_str(const	std::string&)	;

private:

	int		_i;
	bool	_full;
	Contact _Cont[MAX_ID];

} ;

bool	is_valid_input(std::string& str, char type) ;
void 	clear_spaces(std::string& input) ;
bool	ctrl_d(void);

#endif
