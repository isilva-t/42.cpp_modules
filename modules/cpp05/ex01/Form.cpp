#include "Form.hpp"

Form::Form() 
: _name("default_form"), _sign(false), _gradeSign(100), _gradeExecute(100)
{}

Form::~Form()
{}

Form::Form(const Form& other)
	: _name(other._name), 
	_gradeSign(other._gradeSign), 
	_gradeExecute(other._gradeExecute)
{
	*this = other;
}

Form& Form::operator=(const Form& other)
{
	if (this != &other)
		_sign = other._sign;
	return (*this);
}

Form::Form(const std::string& name, const int gradeSign, const int gradeExecute)
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
		std::cout << GREEN << "Form successfull created!" << RESET << std::endl;
}

//////////////////////////////////////////////////////////////

const std::string&	Form::getName() const { return _name; }
bool			Form::getSign() const { return _sign; }
int 			Form::getGradeSign() const { return _gradeSign; }
int 			Form::getGradeExecute() const { return _gradeExecute; }

std::ostream&	operator<<(std::ostream& os, const Form& obj)
{	
	return (os
	<< obj.getName()
	<< (obj.getSign() == 1 ? GREEN" Signed" : RED" Not Signed") << std::endl
	<< "Form gradeSign " << obj.getGradeSign() << std::endl
	<< "Form gradeExecute " << obj.getGradeExecute() << RESET << std::endl);
} ;

//////////////////////////////////////////////////////////////

const char* Form::GradeTooHighException::what() const throw()
{
	static const std::string msg = YELLOW "Grade too HIGH!"  RESET;
	return msg.c_str();
}

const char* Form::GradeTooLowException::what() const throw()
{
	static const std::string msg = RED "Grade too LOW!"  RESET;
	return msg.c_str();
}

///////////////////////////////////////////////////////////////

void	Form::beSigned(const Bureaucrat& bur)
{
	if(bur.getGrade() > _gradeSign)
		throw GradeTooLowException();
	else
		_sign = true;
}
