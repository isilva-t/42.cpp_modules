#include "Zombie.hpp"

Zombie* zombieHorde( int N,  std::string my_name )
{
	Zombie*	heap_horde;

	heap_horde = new Zombie[N];

	for (int i = 0; i < N; i++)	{

		heap_horde[i] = Zombie(my_name);
	}

	return (heap_horde);
}
