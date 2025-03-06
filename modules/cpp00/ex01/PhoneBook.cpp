#include "PhoneBook.hpp"

PhoneBook::PhoneBook(void) : _i(0), _full(false) 	{

	for (int i = 0; i < MAX_ID; ++i)	{
		_Cont[i] = Contact();
	}

	std::cout << std::endl << YELLOW
		<< "---------------------------------" << std::endl
		<< "------Hello from phonebook!------" << std::endl
		<< "---------------------------------" << RESET << std::endl;
}

PhoneBook::~PhoneBook(void) {

	if (PRINT_P)
		std::cout << std::endl 
			<< YELLOW "PhoneBook Destroyed!" RESET << std::endl;
} 

///////////////////////////////////////////
void	PhoneBook::increment_i(void)	{

	this->_i++;
	if(this->_i == MAX_ID)
	{
		this->_full = true;
		this->_i = 0;
	}
}

bool	PhoneBook::is_full(void) const	{	return (this->_full)	;	}

bool	PhoneBook::is_empty(void) const	{

	if (this->_full == false && this->_i == 0)
		return (true);
	else
		return (false);
}	

int	PhoneBook::get_book_size(void) const	{

	if (PhoneBook::is_full() == true)
		return (MAX_ID);
	else
		return (this->_i);
}

void	PhoneBook::set_contact(
				  std::string const first,
				  std::string const last,
				  std::string const nick,
				  std::string const phone,
				  std::string const darkest) 	{

	Contact NewContact(first, last, nick, phone, darkest);
	_Cont[this->_i] = NewContact;
	PhoneBook::increment_i();
}

void	PhoneBook::print_contact(int id) const	{

	_Cont[id].print_contact();
}

void	PhoneBook::add_contact(void)	{

	std::string first, last, nick, phone, darkest;
	while (first.empty() && !ctrl_d())
	{
		std::cout << std::left << std::setw(16) 
			<<  "First name: ";
		std::getline(std::cin, first);
		clear_spaces(first);
		if (!is_valid_input(first, 'n'))
			first.clear();
	}
	while (last.empty() && !ctrl_d())
	{
		std::cout << std::left << std::setw(16) 
			<<  "Last name: ";	
		std::getline(std::cin, last);
		clear_spaces(last);
		if (!is_valid_input(last, 'n'))
			last.clear();
	}
	while (nick.empty() && !ctrl_d())
	{
		std::cout << std::left << std::setw(16) 
			<<  "Nickname: ";	
		std::getline(std::cin, nick);
		clear_spaces(nick);
		if (!is_valid_input(nick, 'o'))
			nick.clear();
	}
	while (phone.empty() && !ctrl_d())
	{
		std::cout << std::left << std::setw(16) 
			<<  "Phone Number: ";	
		std::getline(std::cin, phone);
		clear_spaces(phone);
		if (!is_valid_input(phone, 'p'))
			phone.clear();
	}
	while (darkest.empty() && !ctrl_d())
	{
		std::cout << std::left << std::setw(16) 
			<< "Darkest Secret: ";	
		std::getline(std::cin, darkest);
		clear_spaces(darkest);
		if (!is_valid_input(darkest, 'o'))
			darkest.clear();
	}
	PhoneBook::set_contact(first, last, nick, phone, darkest);
}

void	PhoneBook::handle_search(std::string input)	const	{

	if ((input[0] < '1' 
	 || input[0] > PhoneBook::get_book_size() + '0' 
	 || input.size() > 1) && !ctrl_d())
	{
		std::cout << "Invalid index!" << std::endl;
		return ;
	}
	else if (!ctrl_d())
		PhoneBook::print_contact((int)input[0] - '1');
}
////////////////////////////////////////////////////////////////
void	PhoneBook::print_list_contacts(void)	{

	int	size_book = PhoneBook::get_book_size();\

	PhoneBook::print_head_table();

	for(int i = 0; i < size_book; i++)
		PhoneBook::print_short_contact(i);
}

void	PhoneBook::print_head_table(void)	const	{

	std::cout << std::right 
		<< std::setw(10) << "index" << "|"
		<< std::setw(10) << "first name" << "|"
		<< std::setw(10) << "last name" << "|"
		<< std::setw(10) << "nickname" << "|"
		<< std::endl;
}

void	PhoneBook::print_short_contact(int id)	{

	std::cout << std::right 
		<< std::setw(10) << id + 1 << "|"
		<< std::setw(10) << PhoneBook::format_str(_Cont[id].get_first_name()) << "|"
		<< std::setw(10) << PhoneBook::format_str(_Cont[id].get_last_name()) << "|"
		<< std::setw(10) << PhoneBook::format_str(_Cont[id].get_nickname()) << "|"
		<< std::endl;
}

std::string	PhoneBook::format_str(const std::string& data)	{

	std::string	format = data;

	if (format.length() > 10)
		format = format.substr(0, 9) + ".";
	return (format);
}

	// type received for validation
	// 'n' stands for name
	// 'p' stands for phone
	// 'o' stands for other
bool	is_valid_input(std::string& str, char type)
{
	char valid[] = "() +-";
	for (size_t i = 0; i < str.size(); i++)
	{
		if (type == 'n' && (!(isalpha(str[i]) || str[i] == ' ')))
		{
			std::cout << YELLOW << "invalid input! "
				<< "Only allowed alpha or space."
				<< RESET << std::endl;
			return (false);
		}
		else if (type == 'p' && !(isdigit(str[i]) || strchr(valid, str[i])))
		{
			std::cout << YELLOW << "Invalid Phone Number! "
				<< "Only allowed decimal digits, \"+\", \"-\", parenthesis or space."
				<< RESET << std::endl;
			return (false);
		}
		else if	(type == 'o' && !(isprint(str[i]) || strchr(valid, str[i])))
		{
			std::cout << YELLOW << "Invalid characters for this section! "
				<< "Only allowed printables or space."
				<< RESET << std::endl;
			return (false);
		}
	}
	return (true);
}

void clear_spaces(std::string& input) 	{

    input.erase(0, input.find_first_not_of("\t\n\v\f\r "));
    input.erase(input.find_last_not_of("\t\n\v\f\r ") + 1);
}

bool	ctrl_d(void)
{
	if(std::cin.eof() || std::cin.fail())
	{ 
		return (true);
	}
	return (false);
}
