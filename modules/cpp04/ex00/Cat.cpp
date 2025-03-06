#include "Cat.hpp"

Cat::Cat( void ) {
	type = "Cat";
	std::cout << RED << "Cat default CONStructor called."
		<< RESET << std::endl;
}

Cat::Cat(const Cat& to_copy) : Animal(to_copy)
{	
	std::cout << RED << "Cat copy construtor called."
		<< RESET << std::endl;
}

Cat&	Cat::operator=(const Cat& to_copy)
{
	if (this != &to_copy)
		Animal::operator=(to_copy);
	std::cout << RED << "Cat copy assignment operator called."
		<< RESET << std::endl;
	return *this;
}

Cat::~Cat( void )
{
	std::cout << RED << "Cat default DEStructor called."
		<< RESET << std::endl;
}

void	Cat::makeSound( void ) const
{
	std::cout << RED << "MIAAAUUUUuuuuUUuuu" << RESET << std::endl;
}
