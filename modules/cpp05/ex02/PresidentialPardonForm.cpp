#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm()  
: AForm("default", 25, 5)
{}

PresidentialPardonForm::~PresidentialPardonForm()
{}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& other) 
	: AForm(other), 
	_target(other._target)
{
	*this = other;
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& other)
{
	if(this != &other)
		AForm::operator=(other);
	return (*this);
}

PresidentialPardonForm::PresidentialPardonForm(const std::string& target)  
: AForm(target, 25, 5), _target(target)
{}

void PresidentialPardonForm::action() const
{
	std::cout << _target << " as been pardoned by Zaphod Beeblebrox" << std::endl;
}

