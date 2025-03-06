#pragma once

#include <iostream>
#include <iomanip>

#define RED "\e[1;3;31m"
#define GREEN "\e[1;3;32m"
#define YELLOW "\e[1;3;93m"
#define RESET "\e[0m"

class ClapTrap	{

protected :
	std::string	_name;
	unsigned int	_hit;
	unsigned int	_energy;
	unsigned int	_attack_damage;

public :
	ClapTrap( void );
	ClapTrap(const std::string);
	ClapTrap( const ClapTrap& to_copy );
	ClapTrap& operator=( const ClapTrap& to_copy ) ;
	~ClapTrap();

	bool	canWork( int ) const ;
	bool	showStatus( void ) const ;

	void	attack( const std::string& target );
	void	takeDamage( unsigned int	amount );
	void	beRepaired( unsigned int	amount );
} ;
