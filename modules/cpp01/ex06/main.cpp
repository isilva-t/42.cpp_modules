#include "Harl.hpp"

int main(int ac, char **av)
{
	if (ac != 2)
		return 1;

	Harl	harl;
	std::string choice(av[1]);

	harl.complain(choice);

	return 0 ;
}
