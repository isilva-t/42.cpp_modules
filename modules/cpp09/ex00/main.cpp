#include "BitcoinExchange.hpp"

int main(int ac, char **av)
{
	try
	{
		if(ac != 2)
		{
			throw BitcoinExchange::Error("Error: could not open file.");
		}
		BitcoinExchange	exch;
		exch.readUserFile(av[1]);
	}
	catch (BitcoinExchange::Error& e)
	{
		std::cout << e.what() << std::endl;
		return 1 ;
	}
	return 0 ;
}
