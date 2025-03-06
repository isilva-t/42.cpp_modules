#pragma once

#include <iostream>
#include "Weapon.hpp"

class HumanB {

private :

	std::string	name;
	Weapon		*weapon;

public :

	void	attack();
	void	setWeapon(class Weapon &received_weapon);

	HumanB(const std::string received_name);
	~HumanB(void);
} ;
