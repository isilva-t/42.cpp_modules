#pragma once

#include <iostream>

#define RED "\e[1;3;31m"
#define GREEN "\e[1;3;32m"
#define YELLOW "\e[1;3;93m"
#define RESET "\e[0m"


class Animal {

protected :
	std::string type;

public :
	Animal( void );
	Animal( const Animal& to_copy);
	Animal& operator=( const Animal& to_copy);
	virtual ~Animal( void );

	std::string	getType() const;
	virtual void	makeSound( void ) const;
} ;
