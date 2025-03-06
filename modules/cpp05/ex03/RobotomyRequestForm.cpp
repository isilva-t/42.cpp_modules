#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm()  
: AForm("default", 72, 45)
{}

RobotomyRequestForm::~RobotomyRequestForm()
{}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other) 
	: AForm(other), 
	_target(other._target)
{
	*this = other;
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& other)
{
	if(this != &other)
		AForm::operator=(other);
	return (*this);
}

RobotomyRequestForm::RobotomyRequestForm(const std::string& target)  
: AForm("default", 72, 45), _target(target)
{}

void RobotomyRequestForm::action() const
{
	int number;

	number = rand();
	if(number % 2 == 0)
	{
		std::cout << "DRRR-DRRR-DRRR..... " << GREEN
			<< _target 
			<< " has been robotomized successfully 50% of the time."
			<< RESET << std::endl;
	}
	else
		throw RobotomyFailed();
}

const char* RobotomyRequestForm::RobotomyFailed::what() const throw()
{
	static const std::string msg = RED "Robotomy Failed!"  RESET;
	return msg.c_str();
}

