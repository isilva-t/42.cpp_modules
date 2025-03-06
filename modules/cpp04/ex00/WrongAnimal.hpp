#pragma once

#include <iostream>

#define RED "\e[1;3;31m"
#define GREEN "\e[1;3;32m"
#define YELLOW "\e[1;3;93m"
#define RESET "\e[0m"


class WrongAnimal {

protected :
	std::string type;

public :
	WrongAnimal( void );
	WrongAnimal( const WrongAnimal& to_copy);
	WrongAnimal& operator=( const WrongAnimal& to_copy);
	virtual ~WrongAnimal( void );

	std::string	getType() const;
	void	makeSound( void ) const;
} ;
