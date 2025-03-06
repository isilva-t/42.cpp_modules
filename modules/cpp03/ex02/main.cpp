#include "FragTrap.hpp"

int main( void )
{
	std::cout << YELLOW << std::endl 
		<< "############################# TEST 1 #################################"
		<< RESET << std::endl;
	{
		FragTrap myself("myself");

		myself.showStatus();
		myself.attack("another_one");
		myself.attack("another_two");
		myself.takeDamage(70);
		myself.beRepaired(30);
	}




	std::cout << YELLOW << std::endl 
		<< "############################# TEST 2 #################################"
		<< RESET << std::endl;
	{
		FragTrap no_name;

		no_name.showStatus();
		no_name.attack("anybody");
		no_name.attack("another_one");
		no_name.attack("another_two");
		no_name.takeDamage(110);
		no_name.beRepaired(30);
		no_name.takeDamage(0);
	}




	std::cout << YELLOW << std::endl 
		<< "############################# TEST 3 #################################" 
		<< RESET << std::endl;
	{
		FragTrap mouse("mickey");

		mouse.showStatus();
		mouse.attack("anybody");
		mouse.attack("another_one");
		mouse.attack("another_two");
		mouse.takeDamage(90);
		mouse.beRepaired(30);
		mouse.beRepaired(30);
		mouse.beRepaired(30);
		mouse.beRepaired(30);

		mouse.takeDamage(200);
		mouse.beRepaired(30);
		mouse.takeDamage(200);
		mouse.attack("another_two");
	}          




	std::cout << YELLOW << std::endl 
		<< "############################# BASIC TEST #################################"
		<< RESET << std::endl;
	{
		FragTrap original("for_copy_test");
		FragTrap copied(original);  // Test copy constructor
		FragTrap assigned;

		assigned = original;    // Test assignment operator

		original.showStatus();
		copied.showStatus();	
		assigned.showStatus();

		original.takeDamage(10);
		copied.takeDamage(15);
		assigned.takeDamage(45);
		
		// Test if all three have the same state
		original.attack("target");
		copied.attack("target");
		assigned.attack("target");
	}





	std::cout << YELLOW << std::endl 
		<< "############################# GATE KEEPER TEST #################################"
		<< RESET << std::endl;
{
		FragTrap guard("guard");

		guard.guardGate();

		guard.guardGate();

		guard.takeDamage(150);
		guard.guardGate();
	}





	std::cout << YELLOW << std::endl 
		<< "############################# TEST ENERGY #################################" 
		<< RESET << std::endl;
	{
		FragTrap funny("mickey");

		funny.showStatus();
		funny.highFivesGuys();
		while(funny.canWork(0))
			funny.attack("oops");
		
		funny.attack("oops");
		funny.highFivesGuys();
	}
	return 0;

}
