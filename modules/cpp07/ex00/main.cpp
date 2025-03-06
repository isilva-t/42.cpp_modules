#include "whatever.hpp"
#include <iostream>

int main( void )
{
	std::cout << "\n====== Subject main =======\n";
	{
		int a = 2;
		int b = 3;

		::swap( a, b );
		std::cout << "a = " << a << ", b = " << b << std::endl;
		std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
		std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;
		std::string c = "chaine1";
		std::string d = "chaine2";
		::swap(c, d);
		std::cout << "c = " << c << ", d = " << d << std::endl;
		std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
		std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;
	}
	std::cout << "\n======== More tests ========\n";
	{
		float f1 = 1.11f;
		float f2 = 2.22f;
		std::cout << "Declare floats: " << f1 << ", " << f2 << std::endl;
		::swap(f1, f2);
		std::cout << "Swapped floats: " << f1 << ", " << f2 << std::endl;

		char c1 = 'A';
		char c2 = 'Z';
		std::cout << "\nDeclare chars: " << c1 << ", " << c2 << std::endl;
		::swap(c1, c2);
		std::cout << "Swapped chars: " << c1 << ", " << c2 << std::endl;

		double d1 = 1.111111;
		double d2 = 2.202020;
		std::cout << "\nValues: " << d1 << ", " << d2 << std::endl;
		std::cout << "Min double: " << ::min(d1, d2) << std::endl;
		std::cout << "Max double: " << ::max(d1, d2) << std::endl;

		int x = 42;
		int y = 42;
		std::cout << "\nMax of equal values: " << ::max(x, y)
			<< std::endl << std::endl;
	}
	return 0;
}
