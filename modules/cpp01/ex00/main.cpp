#include "Zombie.h"

int	main(void)
{
	Zombie *heap_zombie;

	heap_zombie = newZombie("heapzzzzz");

	heap_zombie->announce();

	randomChump("stackzzzzz");

	delete heap_zombie;

	return (0);
}
