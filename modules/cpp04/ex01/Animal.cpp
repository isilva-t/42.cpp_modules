#include "Animal.hpp"

Animal::Animal( void ) : type("Animal")
{
	std::cout << GREEN << "Animal default CONStructor called."
		<< RESET << std::endl;
}

Animal::Animal(const Animal& to_copy) : type(to_copy.type)
{	
	std::cout << GREEN << "Animal copy construtor called."
		<< RESET << std::endl;
}

Animal&	Animal::operator=(const Animal& to_copy)
{
	if (this != &to_copy)
		this->type = to_copy.type;
	std::cout << GREEN << "Animal copy assignment operator called."
		<< RESET << std::endl;
	return *this;
}

Animal::~Animal( void )
{
	std::cout << GREEN << "Animal default DEStructor called."
		<< RESET << std::endl;
}

std::string Animal::getType( void ) const
{
	return this->type;
}

void	Animal::makeSound( void ) const
{
	std::cout << GREEN << "( no sound reproduced )" << RESET << std::endl;
}
