#include "AAnimal.hpp"

AAnimal::AAnimal( void ) : type("AAnimal")
{
	std::cout << GREEN << "AAnimal default CONStructor called."
		<< RESET << std::endl;
}

AAnimal::AAnimal(const AAnimal& to_copy) : type(to_copy.type)
{	
	std::cout << GREEN << "AAnimal copy construtor called."
		<< RESET << std::endl;
}

AAnimal&	AAnimal::operator=(const AAnimal& to_copy)
{
	if (this != &to_copy)
		this->type = to_copy.type;
	std::cout << GREEN << "AAnimal copy assignment operator called."
		<< RESET << std::endl;
	return *this;
}

AAnimal::~AAnimal( void )
{
	std::cout << GREEN << "AAnimal default DEStructor called."
		<< RESET << std::endl;
}

std::string AAnimal::getType( void ) const
{
	return this->type;
}

void	AAnimal::makeSound( void ) const
{
	std::cout << GREEN << "( no sound reproduced )" << RESET << std::endl;
}
