#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal( void ) : type("WrongAnimal")
{
	std::cout << GREEN << "WrongAnimal default CONStructor called."
		<< RESET << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal& to_copy) : type(to_copy.type)
{	
	std::cout << GREEN << "WrongAnimal copy construtor called."
		<< RESET << std::endl;
}

WrongAnimal&	WrongAnimal::operator=(const WrongAnimal& to_copy)
{
	if (this != &to_copy)
		this->type = to_copy.type;
	std::cout << GREEN << "WrongAnimal copy assignment operator called."
		<< RESET << std::endl;
	return *this;
}

WrongAnimal::~WrongAnimal( void )
{
	std::cout << GREEN << "WrongAnimal default DEStructor called."
		<< RESET << std::endl;
}

std::string WrongAnimal::getType( void ) const
{
	return this->type;
}

void	WrongAnimal::makeSound( void ) const
{
	std::cout << GREEN << "( WRONG, no sound reproduced )" << RESET << std::endl;
}
