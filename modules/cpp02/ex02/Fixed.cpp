#include "Fixed.hpp"

const int	Fixed::_frac = 8;

Fixed::Fixed(void) : _nb(0)
{ } ;


Fixed::Fixed( const Fixed& to_copy )
{	
	*this = to_copy;
} ;

Fixed&	Fixed::operator=( const Fixed& to_copy)
{
	if (this != &to_copy)
		this->_nb = to_copy.getRawBits();
	return *this;
} ;

Fixed::~Fixed(void) 
{ } ;

///////////////// int and float constructors//////////////////////	

Fixed::Fixed(int const n_int)
			: _nb( n_int << this->_frac )
{ } ;

Fixed::Fixed(float const n_float)
			: _nb(roundf( n_float * (1 << this->_frac)) )
{ } ;

/////////////////setters - getters ////////////////////////////

int	Fixed::getRawBits(void) const
{	return this->_nb;	} ;

void	Fixed::setRawBits( int const raw )
{	this->_nb = raw;	} ;

float	Fixed::toFloat( void ) const
{	return static_cast<float>(this->_nb) / (1 << this->_frac);	} ;

int		Fixed::toInt( void ) const
{	return roundf(static_cast<float>(this->_nb) / (1 << this->_frac));	} ;

std::ostream&	operator<<(std::ostream& os, const Fixed& my_object)
{	return (os << my_object.toFloat());	} ;

//// ex 02 requirements

bool	Fixed::operator>(const Fixed& other) const
{	return (this->getRawBits() > other.getRawBits());	} ;

bool	Fixed::operator<(const Fixed& other) const
{	return (this->getRawBits() < other.getRawBits());	} ;

bool	Fixed::operator>=(const Fixed& other) const
{	return (this->getRawBits() >= other.getRawBits());	} ;

bool	Fixed::operator<=(const Fixed& other) const
{	return (this->getRawBits() <= other.getRawBits());	} ;

bool	Fixed::operator==(const Fixed& other) const
{	return (this->getRawBits() == other.getRawBits());	} ;

bool	Fixed::operator!=(const Fixed& other) const
{	return (this->getRawBits() != other.getRawBits());	} ;


Fixed	Fixed::operator+(const Fixed& other)
{
	Fixed to_return;

	to_return.setRawBits(this->_nb + other._nb);
	return (to_return);	
} ;

Fixed	Fixed::operator-(const Fixed& other)
{
	Fixed to_return;

	to_return.setRawBits(this->_nb - other._nb);
	return to_return;
} ;

Fixed	Fixed::operator*(const Fixed& other)
{
	Fixed	to_return;

	to_return._nb = this->_nb * other._nb >> this->_frac;
	return to_return;
} ;

Fixed	Fixed::operator/(const Fixed& other)
{	
	Fixed to_return;

	to_return._nb = (this->_nb << this->_frac) / other._nb;
	return to_return;
} ;

Fixed&	Fixed::operator++( void )
{	
	this->_nb++;
	return *this ;
} ;

Fixed&	Fixed::operator--( void )
{
	this->_nb--;
	return *this ;
} ;

Fixed	Fixed::operator++(int unused)
{	(void)unused;

	Fixed	to_return;

	to_return = *this;
	this->_nb++;
	return to_return;
} ;

Fixed	Fixed::operator--( int unused )
{	(void)unused;
	
	Fixed	to_return;

	to_return = *this;
	this->_nb--;
	return to_return;
} ;


Fixed&	Fixed::min(Fixed& one, Fixed& two)
{
	if (one.getRawBits() <= two.getRawBits())
		return one;
	return two;
} ;

const Fixed&	Fixed::min(const Fixed& one, const Fixed& two)
{
	if (one.getRawBits() <= two.getRawBits())
		return one;
	return two;
} ;


Fixed&	Fixed::max(Fixed& one, Fixed& two)
{
	if (one.getRawBits() >= two.getRawBits())
		return one;
	return two;
} ;

const Fixed&	Fixed::max(const Fixed& one, const Fixed& two)
{
	if (one.getRawBits() >= two.getRawBits())
		return one;
	return two;
}

