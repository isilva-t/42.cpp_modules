#pragma once

#include <iostream>

#define RED "\e[1;3;31m"
#define GREEN "\e[1;3;32m"
#define YELLOW "\e[1;3;93m"
#define RESET "\e[0m"

#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal {

private :
	Brain* my_brain;	

public :
	Dog( void );
	Dog( const Dog& to_copy);
	Dog& operator=( const Dog& to_copy);
	~Dog( void );

	void	makeSound( void ) const;
	void	setIdea( int nb, std::string new_idea);
	std::string getIdea( int nb ) const;
} ;
	
