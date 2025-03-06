#include "FragTrap.hpp"

FragTrap::FragTrap( void ) : ClapTrap()
{	_name = "DEFAULT";
	_hit = 100; 
	_energy = 100; 
	_attack_damage = 30;
	std::cout << "FragTrap Default constructor called" << std::endl;	
}

FragTrap::FragTrap( const std::string to_name ) : ClapTrap(to_name)
{
	_hit = 100;
	_energy = 100;
	_attack_damage = 30;
	std::cout << "FragTrap Constructor with name "
		<< this->_name << " called" << std::endl;	
}

FragTrap::FragTrap( const FragTrap& to_copy) : ClapTrap(to_copy)
{	*this = to_copy;	}

FragTrap&	FragTrap::operator=( const FragTrap& to_copy)
{
	if (this != &to_copy)
	{
		this->_name = to_copy._name;
		this->_hit = to_copy._hit;
		this->_energy = to_copy._energy;
		this->_attack_damage = to_copy._attack_damage;
	}
	return *this;
}

FragTrap::~FragTrap(void)
{	std::cout << "FragTrap Destructor called" << std::endl;	}

// similar to ScavTrap... ////////////////////////////////////////////////////////

void	FragTrap::attack( const std::string& target )
{
	std::cout << YELLOW << "---------FragTrap---attack----------" << RESET << std::endl;
	std::cout << GREEN "FragTrap " << this->_name << RESET;
	if ( !canWork(1) && showStatus() )
		return ;
	this->_energy--;
	std::cout << " attacks " << target << ", causing 0 point(s) of damage!" << std::endl;
	showStatus();
}

void	FragTrap::guardGate(void)
{
	std::cout << YELLOW << "---------FragTrap---guardGate----------" << RESET << std::endl;
	if ( !canWork(1) && showStatus() )
		return ;
	else if (!this->_gate_keeper_mode)
	{
		this->_gate_keeper_mode = true;
		std::cout << "FragTrap " << this->_name
			<< " guardGate keeper mode enabled" << std::endl;
	}
	else
	{
		std::cout << "FragTrap " << this->_name
			<< " guardGate mode already enabled" << std::endl;
	}
	showStatus();
}

// subject requirements /////////////////////////////////////////////////////////////

void	FragTrap::highFivesGuys( void )
{
	std::cout << YELLOW << "---------FragTrap---highFiveGuys----------" << RESET << std::endl;
	if ( !canWork(1) && showStatus() )
		return ;
	std::cout << YELLOW << "FragTrap " << this->_name 
		<< " sends an Hi fives to you, and wishes you a nice day!!!!"
		<< RESET << std::endl << std::endl;
}
