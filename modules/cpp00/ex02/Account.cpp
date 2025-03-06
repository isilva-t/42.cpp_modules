#include "Account.hpp"

#include <iostream>
#include <ctime>
#include <iomanip>

int Account::_nbAccounts = 0 ;
int Account::_totalAmount = 0 ;
int Account::_totalNbDeposits = 0 ;
int Account::_totalNbWithdrawals = 0 ;

std::string t_wd = ";withdrawal:" ;
std::string t_wds = ";withdrawals:" ;
std::string t_index = "index:" ;
std::string t_amount = ";amount:" ;
std::string t_total = ";total:" ;
std::string t_deposits = ";deposits:" ;
std::string t_p_amount = ";p_amount:" ;

//************************************************************
//Default Constructor and Destructor//////////////////////////
//************************************************************
Account::Account( int initial_deposit )	 {

	this->_nbDeposits = 0;
	this->_nbWithdrawals = 0;
	this->_amount = initial_deposit ;
	this->_accountIndex = Account::getNbAccounts() ;
	Account::_nbAccounts += 1 ;
	Account::_totalAmount += initial_deposit ;

	Account::_displayTimestamp();
	std::cout 
		<< t_index << this->_accountIndex
		<< t_amount << initial_deposit << ";created"
		<< std::endl ;
}

Account::~Account( void )	{

	Account::_displayTimestamp();
	std::cout 
		<< t_index << this->_accountIndex
		<< t_amount << this->_amount
		<< ";closed" << std::endl ;
}

//************************************************************
//public ft's/////////////////////////////////////////////////
//************************************************************
int	Account::getNbAccounts( void )	{
	return Account::_nbAccounts	;
}

int	Account::getTotalAmount( void )	{
	return Account::_totalAmount ;
}

int	Account::getNbDeposits( void )	{	
	return Account::_totalNbDeposits ;
}

int	Account::getNbWithdrawals( void )	{
	return Account::_totalNbWithdrawals ;
}

void	Account::displayAccountsInfos( void )	{

	Account::_displayTimestamp() ;
	std::cout
		<< "accounts:" << Account::getNbAccounts()
		<< t_total << Account::getTotalAmount()
		<< t_deposits << Account::getNbDeposits()
		<< t_wds << Account::getNbWithdrawals()
		<< std::endl ;
}

void	Account::makeDeposit( int deposit )	{

	Account::_displayTimestamp() ;
	std::cout 
		<< t_index << this->_accountIndex 
		<< t_p_amount << this->_amount
		<< ";deposit:" << deposit ;

	this->_amount += deposit ;
	this->_nbDeposits++ ;
	Account::_totalNbDeposits++ ;
	Account::_totalAmount += deposit ;

	std::cout 
		<< t_amount << this->_amount
		<< ";nb_deposits:" << this->_nbDeposits
		<< std::endl ;
}

bool	Account::makeWithdrawal( int withdrawal )	{

	Account::_displayTimestamp() ;
	std::cout 
		<< t_index << this->_accountIndex
		<< t_p_amount << this->_amount;

	if ((this->_amount - withdrawal) < 0)
	{
		std::cout << t_wd << "refused" << std::endl ; 
		return false ;
	}
	else
	{
		this->_amount -= withdrawal ;
		Account::_totalAmount -= withdrawal ;

		this->_nbWithdrawals++ ;
		Account::_totalNbWithdrawals++;

		std::cout 
			<< t_wd << withdrawal
			<< t_amount << this->_amount
			<< ";nb_withdrawals:" << this->_nbWithdrawals
			<< std::endl ;
		return true ;
	}
}

int		Account::checkAmount( void ) const	{
	return this->_amount ;
}

void	Account::displayStatus( void ) const	{

	Account::_displayTimestamp();
	std::cout 
		<<  t_index << this->_accountIndex
		<< t_amount << this->_amount
		<< t_deposits << this->_nbDeposits
		<< t_wds << this->_nbWithdrawals
		<< std::endl ;
}

//************************************************************
//// private FT
//************************************************************
void	Account::_displayTimestamp( void )	{

	std::time_t	current_time_in_seconds = std::time(NULL);
	std::tm		*time_struct = std::localtime(&current_time_in_seconds);

	//std::cout << "[19920104_091532] " ;
	
	std::cout 
		<< "[" 
		<< time_struct->tm_year + 1900
		<< std::setfill('0') << std::setw(2) << time_struct->tm_mon + 1
		<< std::setfill('0') << std::setw(2) << time_struct->tm_mday
		<< "_"
		<< std::setfill('0') << std::setw(2) << time_struct->tm_hour
		<< std::setfill('0') << std::setw(2) << time_struct->tm_min
		<< std::setfill('0') << std::setw(2) << time_struct->tm_sec
		<< "] " ;
}
