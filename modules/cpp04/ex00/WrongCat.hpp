#pragma once

#include <iostream>

#define RED "\e[1;3;31m"
#define GREEN "\e[1;3;32m"
#define YELLOW "\e[1;3;93m"
#define RESET "\e[0m"

#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal {


public :
	WrongCat( void );
	WrongCat( const WrongCat& to_copy);
	WrongCat& operator=( const WrongCat& to_copy);
	~WrongCat( void );

	void	makeSound( void ) const;
} ;
	
