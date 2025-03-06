#pragma once

#include <iostream>

class Fixed {

private :
	int	_nb;
	static const int	_frac;


public :
	Fixed();
	Fixed( const Fixed& to_copy );
	Fixed& operator=( const Fixed& to_copy ) ;
	~Fixed();
	
	int	getRawBits(void ) const ;
	void	setRawBits( int const raw ) ; 
} ;
