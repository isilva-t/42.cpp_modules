#include "Weapon.hpp"

Weapon::Weapon(const std::string &name_type) : type(name_type)
{} ;

Weapon::~Weapon(void) {}

void	Weapon::setType(const std::string new_type)
{
	this->type = new_type;
}

const std::string	&Weapon::getType()
{
	return(this->type);
}
