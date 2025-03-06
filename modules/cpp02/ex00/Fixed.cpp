#include "Fixed.hpp"

const int	Fixed::_frac = 8;

Fixed::Fixed(void) : _nb(0)
{	
	std::cout << "Default constructor called" << std::endl;	} ;

Fixed::Fixed( const Fixed& to_copy )
{	
	std::cout << "Copy constructor called" << std::endl;
	*this = to_copy;
} ;

Fixed&	Fixed::operator=( const Fixed& to_copy)
{	
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &to_copy)
		this->_nb = to_copy.getRawBits();
	return *this;
} ;

Fixed::~Fixed(void) 
{	std::cout << "Destructor called" << std::endl;	} ;

//////////////////////////////////////////////////////////////////

int	Fixed::getRawBits(void) const
{	
	std::cout << "getRawBits member function called" << std::endl;
	return this->_nb;
} ;

void	Fixed::setRawBits( int const raw )
{	
	std::cout << "setRawBits member function called" << std::endl;
	this->_nb = raw;
} ;
