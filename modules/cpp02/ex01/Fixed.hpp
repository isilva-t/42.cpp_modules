#pragma once

#include <iostream>
#include <cmath>

class Fixed {

private :
	int	_nb;
	static const int	_frac;

public :
	Fixed();
	Fixed( const Fixed& to_copy );
	Fixed& operator=( const Fixed& to_copy ) ;
	~Fixed();

	Fixed( const int n);
	Fixed( const float n);

	int	getRawBits(void ) const ;
	void	setRawBits( int const raw ) ; 
	float	toFloat( void ) const;
	int	toInt( void ) const;
} ;

std::ostream& operator<<(std::ostream& os, const Fixed& my_object);
