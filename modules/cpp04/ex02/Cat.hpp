#pragma once

#include <iostream>

#define RED "\e[1;3;31m"
#define GREEN "\e[1;3;32m"
#define YELLOW "\e[1;3;93m"
#define RESET "\e[0m"

#include "AAnimal.hpp"
#include "Brain.hpp"

class Cat : public AAnimal {

private :
	Brain* my_brain;	

public :
	Cat( void );
	Cat( const Cat& to_copy);
	Cat& operator=( const Cat& to_copy);
	~Cat( void );

	void	makeSound( void ) const;
	void	setIdea( int nb, std::string new_idea);
	std::string getIdea( int nb ) const;
} ;
	
