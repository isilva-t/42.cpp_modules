#pragma once

#include <iostream>
#include <exception>
#include <algorithm>

template <typename T>
void	easyfind(T container, int to_find)
{
	typename T::iterator iter;

	iter =  std::find(container.begin(), container.end(), to_find);
	if(iter == container.end())
		throw (std::exception());
	std::cout << "Found value: " << *iter << std::endl;

}
