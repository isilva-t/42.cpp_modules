#include "ScalarConverter.hpp"

int main(int ac, char **av)
{
	if (ac == 2)
		ScalarConverter::convert(av[1]);
	else
		std::cout << "You need only one argument, after program name!" 
			<< std::endl;
	return 0;
}
