#include "Dog.hpp"

Dog::Dog( void ) :  my_brain(new(Brain))
{
	type = "Dog";
	std::cout << YELLOW << "Dog default CONStructor called."
		<< RESET << std::endl;
}

Dog::Dog(const Dog& cpy) : Animal(cpy), my_brain(new Brain(*cpy.my_brain))
{	
	std::cout << YELLOW << "Dog copy construtor called."
		<< RESET << std::endl;
}

Dog&	Dog::operator=(const Dog& to_copy)
{
	if (this != &to_copy)
	{
		Animal::operator=(to_copy);
		delete my_brain;
		this->my_brain = new Brain(*to_copy.my_brain);
	}
	std::cout << YELLOW << "Dog copy assignment operator called."
		<< RESET << std::endl;
	return *this;
}

Dog::~Dog( void )
{
	delete my_brain;
	std::cout << YELLOW << "Dog default DEStructor called."
		<< RESET << std::endl;
}

void	Dog::makeSound( void ) const
{
	std::cout << YELLOW << "AUF! AU AU AUF! GRrrrrrr, AUF!" << RESET << std::endl;
}

std::string	Dog::getIdea( int nb ) const
{
	if (nb >= 1 && nb <= 100)
		return(this->my_brain->ideas[nb - 1]);
	std::cout << "Error getter: you tried -> " << nb 
		<< std::endl <<"Dog Idea number must be between 1 and 100." << std::endl;
	return "";
}

void	Dog::setIdea( int nb, std::string new_idea)
{
	if (nb >= 1 && nb <= 100 && !new_idea.empty())
		this->my_brain->ideas[nb - 1] = new_idea;
	else
		std::cout << "Error setter: you tried -> " << nb
			<< " with idea \"" << new_idea << "\""
			<< std::endl << "Dog Idea number must be between 1 and 100"
			<<" and must pass a non-empty idea" << std::endl;
}
