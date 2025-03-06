#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name("default"), _grade(150)
{}

Bureaucrat::~Bureaucrat()
{}

Bureaucrat::Bureaucrat(const Bureaucrat& other) : _name(other._name)
{
	*this = other;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other)
{
	if (this != &other)
		_grade = other._grade;
	return (*this);
}

Bureaucrat::Bureaucrat(const std::string& name, const int grade)
	: _name(name)
{
	if(grade > 150)
		throw GradeTooLowException();
	if(grade < 1)
		throw GradeTooHighException();
	else
		_grade = grade;
}

//////////////////////////////////////////////////////////////

const std::string&	Bureaucrat::getName() const { return _name; }
int 			Bureaucrat::getGrade() const { return _grade; }

void	Bureaucrat::incGrade(int val)
{
	if(_grade - val < 1)
		throw GradeTooHighException();
	_grade -= val;
}

void	Bureaucrat::decGrade(int val)
{
	if(_grade + val > 150)
		throw GradeTooLowException();
	_grade += val;
}

std::ostream&	operator<<(std::ostream& os, const Bureaucrat& obj)
{	
	return (os << obj.getName() << ", bureaucrat grade " << obj.getGrade() << ".\n");	
} ;

//////////////////////////////////////////////////////////////

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
	static const std::string msg = YELLOW "Grade too HIGH!"  RESET;
	return msg.c_str();
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
	static const std::string msg = RED "Grade too LOW!"  RESET;
	return msg.c_str();
}

////////////////////////////////////////////////////////////////////

void	Bureaucrat::signForm(Form& form)
{
	try
	{
		form.beSigned(*this);
		std::cout << _name << " signed " << form.getName() << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << YELLOW 
			<< _name << " couldn’t sign "
			<< form.getName() << " because " << e.what() << ", "
			<< form.getGradeSign() << " minimum needed." 
			<< std::endl << *this 
			<< RESET << std::endl;
	}
}
