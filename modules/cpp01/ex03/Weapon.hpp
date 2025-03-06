#pragma once

#include <iostream>

class Weapon {

private :

	std::string type;

public :

	const std::string	&getType();
		void		setType(const std::string str);

	Weapon(const std::string &name_type);
	~Weapon(void);
} ;
