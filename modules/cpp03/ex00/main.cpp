#include "ClapTrap.hpp"

int main( void )
{
	std::cout << YELLOW
		<< "############################# TEST 1 #################################" 
		<< RESET << std::endl;
	{
		ClapTrap myself("myself");
		myself.showStatus();

		myself.attack("another_one");
		myself.attack("another_two");
		myself.takeDamage(7);
		myself.beRepaired(3);
	}




	std::cout << YELLOW << std::endl 
		<< "############################# TEST 2 #################################"
		<< RESET << std::endl;
	{
		ClapTrap no_name;
		no_name.showStatus();

		no_name.attack("anybody");
		no_name.attack("another_one");
		no_name.attack("another_two");
		no_name.takeDamage(11);
		no_name.beRepaired(3);
		no_name.takeDamage(0);
		no_name.attack("another_two");
	}




	std::cout << YELLOW << std::endl 
		<< "############################# TEST 3 #################################"
		<< RESET << std::endl;
	{
		ClapTrap mouse("mickey");
		mouse.showStatus();

		mouse.attack("anybody");
		mouse.attack("another_one");
		mouse.attack("another_two");
		mouse.takeDamage(9);
		
		while (mouse.canWork(0))
			mouse.beRepaired(3);
	
		mouse.takeDamage(3);
		mouse.beRepaired(3);
		mouse.attack("another_two");
	}




	std::cout << YELLOW << std::endl 
		<< "############################# BASIC TEST #################################"
		<< RESET << std::endl;
	{
		ClapTrap no_name;
		ClapTrap original("my_name");
		ClapTrap copied_no_name(no_name);  // Test copy constructor
		ClapTrap copied(original);  // Test copy constructor
		ClapTrap assigned;

		assigned = original;    // Test assignment operator

		no_name.showStatus();
		original.showStatus();

		// Test if all three have the same state
		original.attack("target");
		copied_no_name.attack("target");
		copied.attack("target");
		assigned.attack("target");
	}
	return 0;
}
