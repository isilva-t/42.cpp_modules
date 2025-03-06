#include "Fixed.hpp"

int main( void )
{
	std::cout << YELLOW 
			<< "#####################  Subject Example ###################" 
			RESET << std::endl;
	{
		Fixed a;
		Fixed const	b( Fixed( 5.05f ) * Fixed( 2 ) );

		std::cout << a << std::endl;
		std::cout << ++a << std::endl;
		std::cout << a << std::endl;
		std::cout << a++ << std::endl;
		std::cout << a << std::endl;
		std::cout << b << std::endl;

		std::cout << Fixed::max( a, b ) << std::endl;
	}

	std::cout << std::endl;
	{
		std::cout << YELLOW 
			<< "#####################  test comparisons ###################" 
			RESET << std::endl;
		Fixed a(1.23456789f);
		Fixed b(3.14f);
		Fixed c(3.14f);

		std::cout << a << " > " << b << " ?  " << (a > b) << std::endl;
		std::cout << b << " > " << a << " ?  " << (b > a) << std::endl;
		std::cout << a << " < " << b << " ?  " << (a < b) << std::endl;
		std::cout << b << " < " << a << " ?  " << (b < a) << std::endl;

		std::cout << std::endl;
		std::cout << a << " <= " << b << " ?  " << (a <= b) << std::endl;
		std::cout << b << " <= " << a << " ?  " << (b <= a) << std::endl;
		std::cout << b << " <= " << c << " ?  " << (b <= c) << std::endl;

		std::cout << std::endl;
		std::cout << a << " >= " << b << " ?  " << (a >= b) << std::endl;
		std::cout << b << " >= " << a << " ?  " << (b >= a) << std::endl;
		std::cout << b << " >= " << c << " ?  " << (b >= c) << std::endl;

		std::cout << std::endl;
		std::cout << a << " == " << b << " ?  " << (a == b) << std::endl;
		std::cout << b << " == " << c << " ?  " << (b == c) << std::endl;

		std::cout << std::endl;
		std::cout << a << " != " << b << " ?  " << (a != b) << std::endl;
		std::cout << b << " != " << c << " ?  " << (b != c) << std::endl;
	}

	std::cout << std::endl;
	{
		std::cout  << YELLOW 
			<< "#####################  test aritmetics ###################" 
			RESET << std::endl;
		Fixed a(9.5f);
		Fixed b(200);

		Fixed c;
		std::cout << "a equals to " << a << std::endl;
		std::cout << "b equals to " << b << std::endl;

		c = a + b;
		std::cout << "a + b = c equals to " << c << std::endl;
		std::cout << "        c toInt is: " << c.toInt() << std::endl;

		c = a - b;
		std::cout << "a - b = c equals to " << c << std::endl;
		std::cout << "        c toInt is: " << c.toInt() << std::endl;

		c = a * b;
		std::cout << "a * b = c equals to " << a * b << std::endl;
		std::cout << "        c toInt is: " << c.toInt() << std::endl;

		c = a / b;
		std::cout << "a / b = c equals to " << c << std::endl;
		std::cout << "        c toInt is: " << c.toInt() << std::endl;
	}

	std::cout << std::endl;
	{
		std::cout << YELLOW
			<< "################  test a++, ++a, --a , a-- ###################" 
			RESET << std::endl << std::endl;
		Fixed a(1.123456789f);

		std::cout << "a equals to " << a << " and raw is " << a.getRawBits()<< std::endl << std::endl;

		std::cout << "post increment a++ " << a++ << " and now raw is " << a.getRawBits() << std::endl;
		std::cout << "a equals to " << a << " and raw is " << a.getRawBits() << std::endl;

		std::cout << "a raw value is " << a.getRawBits()
			<< " and with pre increment ++a " << ++a
			<< " and raw is " << a.getRawBits() << std::endl;
		
		std::cout << std::endl << std::endl;


		std::cout << "a equals to " << a << " and raw is " << a.getRawBits()<< std::endl << std::endl;
	
		std::cout << "post decrement a-- " << a-- << " and now raw is " << a.getRawBits() << std::endl;
		std::cout << "a equals to " << a << " and raw is " << a.getRawBits() << std::endl;

		std::cout << "a raw value is " << a.getRawBits()
			<< " and with pre decrement --a " << --a
			<< " and raw is " << a.getRawBits() << std::endl;

		std::cout << std::endl;
		std::cout << "a equals to " << a << " and raw is " << a.getRawBits()<< std::endl;
	}	

	std::cout << std::endl;
	{
		std::cout << YELLOW 
			<< "####################  test max and min #####################" 
			RESET << std::endl;
		Fixed d(1.23456789f);
		Fixed e(3.14f);
		Fixed const f(1.23456789f);
		Fixed const h(3.14f);

		Fixed& minimum = Fixed::min( d , e );
		const Fixed&  minimum_const = Fixed::min( f, h );
		std::cout << "what is shorter " << d << " or " << e << "? " << minimum << std::endl;
		std::cout << "and const, what is shorter " << f << " or " << h << "? " 
			<< minimum_const << std::endl;

		Fixed& maximum = Fixed::max( d , e );
		const Fixed&  maximum_const = Fixed::max( f, h );
	
		std::cout << "what is bigger " << d << " or " << e << "? " << maximum << std::endl;
		std::cout << "and const, what is bigger " << f << " or " << h << "? " 
			<< maximum_const << std::endl;
	}
	return 0;
}

