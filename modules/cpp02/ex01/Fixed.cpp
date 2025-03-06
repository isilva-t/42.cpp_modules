#include "Fixed.hpp"

const int	Fixed::_frac = 8;

Fixed::Fixed(void) : _nb(0)
{	std::cout << "Default constructor called" << std::endl;	} ;


Fixed::Fixed( const Fixed& to_copy )
{	std::cout << "Copy constructor called" << std::endl;
	*this = to_copy;
} ;

Fixed&	Fixed::operator=( const Fixed& to_copy)
{	
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &to_copy)
		this->_nb = to_copy.getRawBits();
	return *this;
}

Fixed::~Fixed(void) 
{	std::cout << "Destructor called" << std::endl;	} ;

/////////////////////////////////////////////////////////

Fixed::Fixed(int const n_int)
			: _nb( n_int << this->_frac )
{
	std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(float const n_float)
			: _nb( roundf( n_float * (1 << this->_frac)) )
{
	std::cout << "Float constructor called" << std::endl;
} ;

//////////////////////////////////////////////////////////

int	Fixed::getRawBits(void) const
{	
	return this->_nb;	
} ;

void	Fixed::setRawBits( int const raw )
{	
	this->_nb = raw;	
} ;


float	Fixed::toFloat( void ) const
{
	return static_cast<float>(this->_nb) / (1 << this->_frac);
} ;

int		Fixed::toInt( void ) const
{	
	return roundf(
		static_cast<float>(this->_nb) / (1 << this->_frac) );	
} ;



std::ostream&	operator<<(std::ostream& os, const Fixed& my_object)
{
	return (os << my_object.toFloat());
} ;

