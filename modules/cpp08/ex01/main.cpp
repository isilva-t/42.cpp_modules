#include "Span.hpp"

#include <iostream>
#include <cstdlib>
#include <ctime>

#include <vector>
#include <list>
#include <deque>

void	main_subject()
{
	std::cout << "\n==> main subject:\n";
	Span sp = Span(5);

	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);

	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;
}

template <typename C>
void genRandomNumbers(C& container, unsigned int quantity)
{
	for (unsigned int i = 0; i < quantity; i++)
	{
		int new_nb = std::rand() - (RAND_MAX / 2);
		container.push_back(new_nb);
	}
}

template <typename C>
void	my_test( C& container,
	     const std::string& type,
	     unsigned int rand_size,
	     unsigned int span_size )
{
	std::cout << "\n==> " << type 
		<< ", rand_size: " << rand_size 
		<< ", span_size: " << span_size << std::endl;
	genRandomNumbers(container, rand_size);
	Span sp(span_size);

	try {
		sp.addMultipleNumbers(container.begin(), container.end());
	}
	catch(std::exception& e) {
		std::cout << "What? -> " << e.what() << std::endl;
	}
	std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
	std::cout << "Longest span: " << sp.longestSpan() << std::endl;
}

void	basic_test()
{
	std::cout << "\n==> basic test:\n";
	Span sp = Span(5);
	try {
	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);
	sp.addNumber(20); //fail here
	}
	catch (std::exception& e)
	{	std::cout << e.what() << std::endl;	}

	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;
}

int main()
{
	std::srand(static_cast<unsigned int>(std::time(NULL)));

	main_subject();
	
	basic_test();

	std::vector<int> vec;
	my_test(vec, "VECTOR", 50, 50);

	std::list<int> lst;
	my_test(lst, "LIST", 50, 50);

	std::deque<int> deq;
	my_test(deq, "DEQUE", 50, 50);


	std::vector<int> vec2;
	my_test(vec2, "VECTOR_2", 100000, 100000);

	std::list<int> lst2;
	my_test(lst2, "LIST_2", 100000, 100000);

	std::deque<int> deq2;
	my_test(deq2, "DEQUE_2", 100000, 100000);

	return 0;
}
