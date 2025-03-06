#pragma once

#include <iostream>

template <typename Whatever, typename Function>
void iter(Whatever& array, size_t len, Function& f)
{
	for (size_t i = 0; i < len; i++)
	{
		f(array[i]);
	}
}

