#pragma once

#include <iostream>
#include <string>

#define RED "\e[1;3;31m"
#define GREEN "\e[1;3;32m"
#define YELLOW "\e[1;3;93m"
#define RESET "\e[0m"


class AAnimal {

protected :
	std::string type;

public :
	AAnimal( void );
	AAnimal( const AAnimal& to_copy);
	AAnimal& operator=( const AAnimal& to_copy);
	virtual ~AAnimal( void );

	std::string	getType() const;
	virtual void	makeSound( void ) const = 0;
} ;
