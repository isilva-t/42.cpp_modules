#pragma once

#include <iostream>
#include <iomanip>
#include "ClapTrap.hpp"

#define RED "\e[1;3;31m"
#define GREEN "\e[1;3;32m"
#define YELLOW "\e[1;3;93m"
#define RESET "\e[0m"

class ScavTrap : public ClapTrap	{

private :
	bool	_gate_keeper_mode;

public :
	ScavTrap( void );
	ScavTrap( const ScavTrap& to_copy );
	ScavTrap& operator=( const ScavTrap& to_copy ) ;
	~ScavTrap();
	ScavTrap(const std::string);

	void	attack( const std::string& target );
	void	guardGate( void );
} ;
