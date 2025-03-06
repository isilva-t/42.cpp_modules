#include <iostream>
#include <string>

int	main(int ac, char **av)
{
	if (ac > 1)
	{
		for (int i = 1; i < ac; i++)
		{
			std::string str(av[i]);
			for (size_t j = 0; j < str.size(); j++)
				str[j] = static_cast<char>(std::toupper(static_cast<char>(str[j])));
			std::cout << str;
		}
	}
	else
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	}
	std::cout << std::endl;
	return (0);
}
