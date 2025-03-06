#pragma once

#include <iostream>

#define MAGENTA "\033[0;35m" 
#define RESET "\e[0m"

class Brain {

public:
	Brain( void );
	Brain( const Brain& cpy);
	Brain& operator=( const Brain& cpy);
	~Brain( void );

	std::string ideas[100];

} ;
