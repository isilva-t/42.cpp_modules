#pragma once

template <typename Whatever>
void swap(Whatever& a, Whatever& b)
{
	Whatever temp = a;
	a = b;
	b = temp;
}

template <typename Whatever>
Whatever	min(Whatever& a, Whatever& b)
{
	return a < b ? a : b;
}

template <typename Whatever>
Whatever	max(Whatever& a, Whatever& b)
{
	return a > b ? a : b;
}
