#include "Harl.hpp"

Harl::Harl(void)
{} ;

Harl::~Harl(void)
{} ;

void	Harl::debug( void )
{
	std::cout << "I love having extra bacon for my "
		<< "7XL-double-cheese-triple-pickle-special-ketchup burger. "
		<< "I really do!" << std::endl << std::endl;
}

void	Harl::info( void )
{
	std::cout << "I cannot believe adding extra bacon costs "
		<< "more money. You didn’t put enough bacon in my burger! "
		<< "If you did, I wouldn’t be asking for more!" << std::endl << std::endl;
}

void	Harl::warning( void )
{
	std::cout << "I think I deserve to have some extra bacon for free. "
		<< "I’ve been coming for years whereas you "
		<< "started working here since last month." << std::endl << std::endl;
}

void	Harl::error( void )
{
	std::cout << "his is unacceptable! I want to speak to the manager now."
		<< std::endl << std::endl;
}

void	Harl::complain( std::string level )
{
	void (Harl::*fun[])() = { &Harl::debug, &Harl::info, &Harl::warning, &Harl::error };

	std::string levels[] = { "DEBUG", "INFO", "WARNING", "ERROR"};

	int choice;
	for (choice = 0; choice < 4 && level != levels[choice]; choice++) {}

	choice < 4 ? 
		(this->*fun[choice])() 
		: void(std::cout << "Invalid Level!" << std::endl << std::endl);
}
