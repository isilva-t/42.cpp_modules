#include "ClapTrap.hpp"

ClapTrap::ClapTrap( void )
	: _name("DEFAULT"),
	_hit(10),
	_energy(10),
	_attack_damage(0)
{	std::cout << "ClapTrap Default constructor called" << std::endl;	}

ClapTrap::ClapTrap( const std::string to_name )
	: _name(to_name),
	_hit(10), 
	_energy(10), 
	_attack_damage(0)
{	std::cout << "ClapTrap Constructor with name "
		<< this->_name << " called" << std::endl;	}

ClapTrap::ClapTrap( const ClapTrap& to_copy)
{	*this = to_copy;	}

ClapTrap&	ClapTrap::operator=( const ClapTrap& to_copy)
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

ClapTrap::~ClapTrap(void)
{	std::cout << "ClapTrap Destructor called" << std::endl;	}

// custom helpers //////////////////////////////////////////////////////////////

bool	ClapTrap::canWork(int print) const
{
	if (!this->_energy || !this->_hit)
	{
		if (print)
			std::cout << RED 
				<<" don't have enough resources to do anything!" 
				<< RESET << std::endl;
		return (false);
	}
	return(true);
}

bool	ClapTrap::showStatus(void) const
{
	std::cout << std::right
		<< std::setw(15) << "Hit points: " << this->_hit << std::endl
		<< std::setw(15) << "Energy points: " << this->_energy 
		<< std::endl << std::endl;
	return (true);
}

// subject requirements //////////////////////////////////////////////////////////////

void	ClapTrap::attack( const std::string& target )
{
	std::cout << YELLOW << "---------ClapTrap---attack----------" << RESET << std::endl;
	std::cout << GREEN "ClapTrap " << this->_name << RESET;
	if ( !canWork(1) && showStatus() )
		return ;
	this->_energy--;
	std::cout << " attacks " << target << ", causing 0 point(s) of damage!" << std::endl;
	showStatus();
}

void	ClapTrap::takeDamage( unsigned int amount)
{
	std::cout << RED << "----------ClapTrap---takeDamage----------" << RESET << std::endl;
	std::cout << GREEN "ClapTrap " << this->_name << RESET;
	if ( !canWork(1) && showStatus() )
		return ;
	if (amount >= this->_hit)
		this->_hit = 0;
	else
		this->_hit -= amount;
	std::cout << " suffered damage of " << amount << std::endl;
	showStatus();
}

void	ClapTrap::beRepaired( unsigned int amount )
{
	std::cout << GREEN << "--------ClapTrap---beRepaired---------" << RESET << std::endl;
	std::cout << GREEN "ClapTrap " << this->_name << RESET;
	if ( !canWork(1) && showStatus() )
		return ;
	this->_energy--;
	this->_hit += amount;
	std::cout << " received " << amount << " hit points." << std::endl;
	showStatus();
}
