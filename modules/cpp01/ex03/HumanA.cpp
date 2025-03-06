#include "HumanA.hpp"

HumanA::HumanA(const std::string my_name, class Weapon &received_weapon) :
	name(my_name),
	weapon(received_weapon)
{};

HumanA::~HumanA(void) {};

void	HumanA::attack()
{
	std::cout << this->name
		<< " attacks with their "
		<< this->weapon.getType() << std::endl;
}
