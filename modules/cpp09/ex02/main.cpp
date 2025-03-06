#include "PmergeMe.hpp"
#include <exception>
#include <iostream>

int main(int ac, char **av)
{
	try
	{
		if(ac < 2)
			throw std::exception();
		PmergeMe pm;
		bool	print_subject = true;
		pm.sort(ac - 1, av + 1, print_subject);
	}
	catch (std::exception& e)
	{
		(void)e;
		std::cout << "Error" << std::endl;
		return 1;
	}
	return 0;
}
