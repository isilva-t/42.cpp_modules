#include "Zombie.h"

int	main(void)
{
	Zombie *heap_zombie;
	int n = 10;

	heap_zombie = zombieHorde(n, "my_name");

	for (int i = 0; i < n; i++)	{
		heap_zombie[i].announce();
	}

	delete[] heap_zombie;

	return (0);
}
