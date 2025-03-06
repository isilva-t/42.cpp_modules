#include "easyfind.hpp"
#include <vector>
#include <list>
#include <deque>

int main()
{
	std::cout << "\n==== <vector> ====\n";
	{
		std::vector<int> my_vec;

		my_vec.push_back(1);
		my_vec.push_back(2);
		my_vec.push_back(3);
		my_vec.push_back(4);
		my_vec.push_back(5);

		try {

			easyfind(my_vec, 3);
			easyfind(my_vec, 5);
			easyfind(my_vec, 2);
			easyfind(my_vec, 6); // will not find
			easyfind(my_vec, 1); // not achieved
		}
		catch(std::exception& e)
		{
			(void)e;
			std::cout << "Not found!" << std::endl;
		}
	}
	std::cout << "\n==== <list> ====\n";
	{
		std::list<int> my_list;

		my_list.push_back(1);
		my_list.push_back(2);
		my_list.push_back(3);
		my_list.push_back(4);
		my_list.push_back(5);

		try {

			easyfind(my_list, 3);
			easyfind(my_list, 5);
			easyfind(my_list, 2);
			easyfind(my_list, 6); // will not find
			easyfind(my_list, 1); // not achieved
		}
		catch(std::exception& e)
		{
			(void)e;
			std::cout << "Not found!" << std::endl;
		}
	}
	std::cout << "\n==== <deque> ====\n";
	{
		std::deque<int> my_deque;

		my_deque.push_back(1);
		my_deque.push_back(2);
		my_deque.push_back(3);
		my_deque.push_back(4);
		my_deque.push_back(5);

		try {

			easyfind(my_deque, 3);
			easyfind(my_deque, 5);
			easyfind(my_deque, 2);
			easyfind(my_deque, 6); // will not find
			easyfind(my_deque, 1); // not achieved
		}
		catch(std::exception& e)
		{
			(void)e;
			std::cout << "Not found!" << std::endl;
		}
	}

	return 0;
}
