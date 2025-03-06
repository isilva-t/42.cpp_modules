#ifndef ZOMBIE_H
# define ZOMBIE_H

#include <iostream>
#include "Zombie.hpp"

Zombie* newZombie( std::string name );
Zombie* zombieHorde(const int N, const std::string name );

#endif

