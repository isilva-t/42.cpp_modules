#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

#include <iostream>
#include <iomanip>
#include <exception>

#include <cstdlib>
#include <ctime>

Base * generate(void)
{
	int choice = std::rand() % 3;

	switch(choice)
	{
		case 0 : return new A();
		case 1 : return new B();
		default : return new C();
	}
}

void identify(Base* p)
{
	if(dynamic_cast<A*>(p))
		std::cout << "Pointer A";
	else if (dynamic_cast<B*>(p))
		std::cout << "Pointer B";
	else if (dynamic_cast<C*>(p))
		std::cout << "Pointer C";
}

void identify(Base& p)
{
	try
	{
		A a = dynamic_cast<A&>(p);
		std::cout << "A Reference";
		(void)a;
		return;
	}
	catch (std::exception& e) {}
	
	try
	{
		B b = dynamic_cast<B&>(p);
		std::cout << "B Reference";
		(void)b;
		return;
	}
	catch (std::exception& e) {}

	try
	{
		C c = dynamic_cast<C&>(p);
		std::cout << "C Reference";
		(void)c;
		return;
	}
	catch (std::exception& e) 
	{
		std::cout << "Impossible!" << std::endl;
	}
}

int main(void)
{
	std::srand(std::time(NULL));
	
	Base* test_1 = generate();
	Base* test_2 = generate();
	Base* test_3 = generate();

	std::cout << std::left << std::setw(11) 
		<<"Pointer" << "|  " 
		<< std::setw(11) 
		<< "Reference" << std::endl;

	std::cout << std::setw(11);
	identify(test_1);
	std::cout << "|  ";
	identify(*test_1);
	std::cout << std::endl;

	std::cout << std::setw(11);
	identify(test_2);
	std::cout << "|  ";
	identify(*test_2);
	std::cout << std::endl;

	std::cout << std::setw(11);
	identify(test_3);
	std::cout << "|  ";
	identify(*test_3);
	std::cout << std::endl;

	delete test_1;
	delete test_2;
	delete test_3;

	return 0;
}
