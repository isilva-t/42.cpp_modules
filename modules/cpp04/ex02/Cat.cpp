#include "Cat.hpp"

Cat::Cat( void ) : my_brain(new(Brain))
{
	type = "Cat";
	std::cout << RED << "Cat default CONStructor called."
		<< RESET << std::endl;
}

Cat::Cat(const Cat& to_copy) : AAnimal(), my_brain(new Brain(*to_copy.my_brain))
{	
	std::cout << RED << "Cat copy construtor called."
		<< RESET << std::endl;
}

Cat&	Cat::operator=(const Cat& to_copy)
{
	if (this != &to_copy)
	{
		AAnimal::operator=(to_copy);
		delete my_brain;
		this->my_brain = new Brain(*to_copy.my_brain);
	}
	std::cout << RED << "Cat copy assignment operator called."
		<< RESET << std::endl;
	return *this;
}

Cat::~Cat( void )
{
	delete my_brain;
	std::cout << RED << "Cat default DEStructor called."
		<< RESET << std::endl;
}

void	Cat::makeSound( void ) const
{
	std::cout << RED << "MIAAAUUUUuuuuUUuuu" << RESET << std::endl;
}

std::string	Cat::getIdea( int nb ) const
{
	if (nb >= 1 && nb <= 100)
		return(this->my_brain->ideas[nb - 1]);
	std::cout << "Error getter: you tried -> " << nb 
		<< std::endl <<"Cat Idea number must be between 1 and 100." << std::endl;
	return "";
}

void	Cat::setIdea( int nb, std::string new_idea)
{
	if (nb >= 1 && nb <= 100 && !new_idea.empty())
		this->my_brain->ideas[nb - 1] = new_idea;
	else
		std::cout << "Error setter: you tried -> " << nb
			<< " with idea \"" << new_idea << "\""
			<< std::endl << "Cat Idea number must be between 1 and 100"
			<<" and must pass a non-empty idea" << std::endl;
}
