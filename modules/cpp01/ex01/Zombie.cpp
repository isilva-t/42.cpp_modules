#include "Zombie.hpp"

Zombie::Zombie ( void ) {}

Zombie::Zombie(const std::string& def ) : name(def) {
}

Zombie::~Zombie( void ) {

	std::cout << this->name << std::endl;
}

void	Zombie::announce( void )	{

	std::cout << this->name
		<< ": BraiiiiiiinnnzzzZ..." << std::endl;
}
