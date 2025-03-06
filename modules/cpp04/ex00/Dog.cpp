#include "Dog.hpp"

Dog::Dog( void ) {
	type = "Dog";
	std::cout << YELLOW << "Dog default CONStructor called."
		<< RESET << std::endl;
}

Dog::Dog(const Dog& to_copy) :Animal(to_copy)
{	
	std::cout << YELLOW << "Dog copy construtor called."
		<< RESET << std::endl;
}

Dog&	Dog::operator=(const Dog& to_copy)
{
	if (this != &to_copy)
		Animal::operator=(to_copy);
	std::cout << YELLOW << "Dog copy assignment operator called."
		<< RESET << std::endl;
	return *this;
}

Dog::~Dog( void )
{
	std::cout << YELLOW << "Dog default DEStructor called."
		<< RESET << std::endl;
}

void	Dog::makeSound( void ) const
{
	std::cout << YELLOW << "AUF! AU AU AUF! GRrrrrrr, AUF!" << RESET << std::endl;
}
