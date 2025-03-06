#include "Helper.hpp"

void	Helper::displayChar(char c)
{
	if (isprint(c))
		std::cout << "char: '" << c << "'";
	else
		std::cout << "char: Non displayable";
	std::cout << std::endl;
}

void	Helper::displayInt(int i)
{
	std::cout << "int: " << i << std::endl;
}

void	Helper::displayFloat(float f)
{
	std::cout << "float: " << f;
	if (f == static_cast<int>(f))
		std::cout << ".0";
	std::cout << "f" << std::endl;
}

void	Helper::displayDouble(double d)
{
	std::cout << "double: " << d;
	if (d == static_cast<int>(d))
		std::cout << ".0";
	std::cout << std::endl;
}

void	Helper::clear_edge_spaces(std::string& input) 	
{
    input.erase(0, input.find_first_not_of("\t\n\v\f\r "));
    input.erase(input.find_last_not_of("\t\n\v\f\r ") + 1);
}
