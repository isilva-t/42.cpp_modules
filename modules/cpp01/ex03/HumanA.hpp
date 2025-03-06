#pragma once

#include <iostream>

#include "Weapon.hpp"

class HumanA {

private :

	std::string	name;
	Weapon		&weapon;

public :

	void	attack();

	HumanA(const std::string received_name, class Weapon &received_weapon);
	~HumanA(void);
} ;
