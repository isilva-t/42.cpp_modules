#include <iostream>

int	main(void)
{
	//Write a program that contains:

	std::string	str_variable = "HI THIS IS BRAIN";

	std::string *stringPTR = &str_variable;

	std::string &stringREF = str_variable;

	//Your program has to print:
	
	std::cout << &str_variable << std::endl;

	std::cout << stringPTR << std::endl;

	std::cout << &stringREF << std ::endl;

	//And then:

	std::cout << str_variable << std::endl;

	std::cout << *stringPTR << std::endl;

	std::cout << stringREF << std::endl;

	return (0);
}
