#include "HumanB.hpp"

HumanB::HumanB(const std::string received_name) : 
	name(received_name), 
	weapon(NULL)
{} ;

HumanB::~HumanB(void) {};

void	HumanB::attack()
{
	if (this->weapon)
	{
		std::cout << this->name
		<< " attacks with their "
		<< this->weapon->getType() << std::endl;
	}
	else
	{
		std::cout << this->name
		<< " has no weapon to attack!" << std::endl;
	}
}

void	HumanB::setWeapon(class Weapon &received_weapon)
{
	this->weapon = &received_weapon;
}
