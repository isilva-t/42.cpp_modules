#include "RPN.hpp"
#include <exception>
#include <iostream>

int main(int ac, char **av)
{
	try
	{
		if(ac != 2)
			throw std::exception();
		RPN	rpn;
		rpn.calc(av[1]);
	}
	catch (std::exception& e)
	{
		(void)e;
		std::cout << "Error" << std::endl;
		return 1;
	}
	return 0;
}
