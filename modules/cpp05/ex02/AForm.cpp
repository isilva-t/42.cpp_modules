#include "AForm.hpp"

AForm::AForm() 
: _name("default_form"), _sign(false), _gradeSign(100), _gradeExecute(100)
{}

AForm::~AForm()
{}

AForm::AForm(const AForm& other)
	: _name(other._name), 
	_gradeSign(other._gradeSign), 
	_gradeExecute(other._gradeExecute)
{
	*this = other;
}

AForm& AForm::operator=(const AForm& other)
{
	if (this != &other)
		_sign = other._sign;
	return (*this);
}

AForm::AForm(const std::string& name, const int gradeSign, const int gradeExecute)
	: _name(name), 
	_sign(false), 
	_gradeSign(gradeSign), 
	_gradeExecute(gradeExecute)
{
	if(_gradeSign > 150 || _gradeExecute > 150)
		throw GradeTooLowException();
	if(_gradeSign < 1 || _gradeExecute < 1)
		throw GradeTooHighException();
	else
		std::cout << GREEN << "AForm successfull created!" << RESET << std::endl;
}

//////////////////////////////////////////////////////////////

const std::string&	AForm::getName() const { return _name; }
bool			AForm::getSign() const { return _sign; }
int 			AForm::getGradeSign() const { return _gradeSign; }
int 			AForm::getGradeExecute() const { return _gradeExecute; }

std::ostream&	operator<<(std::ostream& os, const AForm& obj)
{	
	return (os
	<< obj.getName()
	<< (obj.getSign() == 1 ? GREEN" Signed" : RED" Not Signed") << std::endl
	<< "AForm gradeSign " << obj.getGradeSign() << std::endl
	<< "AForm gradeExecute " << obj.getGradeExecute() << RESET << std::endl);
} ;

//////////////////////////////////////////////////////////////

const char* AForm::GradeTooHighException::what() const throw()
{
	static const std::string msg = YELLOW "Grade too HIGH!"  RESET;
	return msg.c_str();
}

const char* AForm::GradeTooLowException::what() const throw()
{
	static const std::string msg = RED "Grade too LOW!"  RESET;
	return msg.c_str();
}

const char* AForm::NotSignedException::what() const throw()
{
	static const std::string msg = RED "Form not signed!"  RESET;
	return msg.c_str();
}

///////////////////////////////////////////////////////////////

void	AForm::beSigned(const Bureaucrat& bur)
{
	if(bur.getGrade() > _gradeSign)
		throw GradeTooLowException();
	else
		_sign = true;
}

void	AForm::execute(const Bureaucrat& executor) const
{
	if(_sign == false)
		throw NotSignedException();
	else if(executor.getGrade() > _gradeExecute)
		throw GradeTooLowException();
	else
		action();
}
