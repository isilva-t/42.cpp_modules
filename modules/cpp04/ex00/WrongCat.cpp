#include "WrongCat.hpp"

WrongCat::WrongCat( void ) {
	type = "WrongCat";
	std::cout << RED << "WrongCat default CONStructor called."
		<< RESET << std::endl;
}

WrongCat::WrongCat(const WrongCat& to_copy) : WrongAnimal(to_copy)
{	
	std::cout << RED << "WrongCat copy construtor called."
		<< RESET << std::endl;
}

WrongCat&	WrongCat::operator=(const WrongCat& to_copy)
{
	if (this != &to_copy)
		WrongAnimal::operator=(to_copy);
	std::cout << RED << "WrongCat copy assignment operator called."
		<< RESET << std::endl;
	return *this;
}

WrongCat::~WrongCat( void )
{
	std::cout << RED << "WrongCat default DEStructor called."
		<< RESET << std::endl;
}

void	WrongCat::makeSound( void ) const
{
	std::cout << RED << "WRONG UUUUAAAAIIIIMMMMMM" << RESET << std::endl;
}
