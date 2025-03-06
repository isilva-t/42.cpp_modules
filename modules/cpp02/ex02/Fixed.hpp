#pragma once

#include <iostream>
#include <cmath>

#define RED "\e[1;3;31m"
#define GREEN "\e[1;3;32m"
#define YELLOW "\e[1;3;93m"
#define RESET "\e[0m"

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


	bool	operator>(const Fixed& other) const;	
	bool	operator<(const Fixed& other) const;	
	bool	operator>=(const Fixed& other) const;	
	bool	operator<=(const Fixed& other) const;	
	bool	operator==(const Fixed& other) const;	
	bool	operator!=(const Fixed& other) const;	

	Fixed	operator+(const Fixed& other);
	Fixed	operator-(const Fixed& other);
	Fixed	operator*(const Fixed& other);
	Fixed	operator/(const Fixed& other);

	Fixed& operator++( void );
	Fixed& operator--( void );

	Fixed	operator++( int );
	Fixed	operator--( int );

	static Fixed& min(Fixed& one, Fixed& two);
	static const Fixed& min(const Fixed& one, const Fixed& two);
	
	static Fixed& max(Fixed& one, Fixed& two);
	static const Fixed& max(const Fixed& one, const Fixed& two);

	int	getRawBits(void ) const ;
	void	setRawBits( int const raw ) ; 
	float	toFloat( void ) const;
	int	toInt( void ) const;
} ;

std::ostream& operator<<(std::ostream& os, const Fixed& my_object);
