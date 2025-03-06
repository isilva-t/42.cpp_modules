#pragma once

#include <iostream>
#include <iomanip>
#include "ClapTrap.hpp"

#define RED "\e[1;3;31m"
#define GREEN "\e[1;3;32m"
#define YELLOW "\e[1;3;93m"
#define RESET "\e[0m"

class FragTrap : public ClapTrap {

private :
	bool	_gate_keeper_mode;

public :
	FragTrap( void );
	FragTrap( const std::string);
	FragTrap( const FragTrap& to_copy );
	FragTrap& operator=( const FragTrap& to_copy ) ;
	~FragTrap();

	void	attack( const std::string& target );
	void	guardGate( void );

	void highFivesGuys( void );
} ;
