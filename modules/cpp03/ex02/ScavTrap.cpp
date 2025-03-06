#include "ScavTrap.hpp"

ScavTrap::ScavTrap( void ) : ClapTrap()
{	
	_name = "DEFAULT";
	_hit = 100; 
	_energy = 50; 
	_attack_damage = 20;
	_gate_keeper_mode = false;
	std::cout << "ScavTrap Default constructor called" << std::endl;	
}

ScavTrap::ScavTrap( const std::string to_name ) : ClapTrap(to_name)
{
	_hit = 100;
	_energy = 50;
	_attack_damage = 20;
	_gate_keeper_mode = false;
	std::cout << "ScavTrap Constructor with name "
		<< this->_name << " called" << std::endl;	
}

ScavTrap::ScavTrap( const ScavTrap& to_copy) : ClapTrap(to_copy)
{	*this = to_copy;	}

ScavTrap&	ScavTrap::operator=( const ScavTrap& to_copy)
{
	if (this != &to_copy)
	{
		this->_name = to_copy._name;
		this->_hit = to_copy._hit;
		this->_energy = to_copy._energy;
		this->_attack_damage = to_copy._attack_damage;
		this->_gate_keeper_mode = to_copy._gate_keeper_mode;
	}
	return *this;
}

ScavTrap::~ScavTrap(void)
{	std::cout << "ScavTrap Destructor called" << std::endl;	}

// subject requirements //////////////////////////////////////////////////////////////

void	ScavTrap::attack( const std::string& target )
{
	std::cout << YELLOW << "---------ScavTrap---attack----------" << RESET << std::endl;
	std::cout << GREEN "ScavTrap " << this->_name << RESET;
	if ( !canWork(1) && showStatus() )
		return ;
	this->_energy--;
	std::cout << " attacks " << target << ", causing 0 point(s) of damage!" << std::endl;
	showStatus();
}

void	ScavTrap::guardGate(void)
{
	std::cout << YELLOW << "---------ScavTrap---guardGate----------" << RESET << std::endl;
	if ( !canWork(1) && showStatus() )
		return ;
	else if (!this->_gate_keeper_mode)
	{
		this->_gate_keeper_mode = true;
		std::cout << "ScavTrap " << this->_name
			<< " guardGate keeper mode enabled" << std::endl;
	}
	else
	{
		std::cout << "ScavTrap " << this->_name
			<< " guardGate mode already enabled" << std::endl;
	}
	showStatus();
}
