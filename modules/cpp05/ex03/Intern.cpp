#include "Intern.hpp"

Intern::Intern()
{}

Intern::Intern(const Intern& other)
{
	*this = other;
}

Intern&	Intern::operator=(const Intern& other)
{
	(void)other;
	return *this;
}

Intern::~Intern() {}

/////////////////////////////////////////////////////

AForm*	Intern::makeForm(const std::string& form, const std::string& target)
{
	try
	{
		FormType my_methods[] = {
			{"shrubbery creation", &createShrubbery},
			{"robotomy request", &createRobotomy},
	  		{"presidential pardon", &createPresidential}
		};
		const std::string message = "Intern created " + form + ", with " + target + ".\n";

		int i;
		for(i = 0; i < 3; i++)
		{
			if(form == my_methods[i].name)
				return my_methods[i].ft_to_create(target, message);
		}
		throw NotValidForm();
	}
	catch (std::exception& e)
	{
		std::cout << "Can't create form, because " << e.what() << std::endl;
		return NULL;
	}
}

const char* Intern::NotValidForm::what() const throw()
{
	static const std::string msg = RED "Invalid form name!"  RESET;
	return msg.c_str();
}

AForm* Intern::createShrubbery(const std::string& target, const std::string& message)
{
	std::cout << message;
	return new ShrubberyCreationForm(target);
}

AForm* Intern::createRobotomy(const std::string& target, const std::string& message)
{
	std::cout << message;
	return new RobotomyRequestForm(target);
}

AForm* Intern::createPresidential(const std::string& target, const std::string& message)
{
	std::cout << message;
	return new PresidentialPardonForm(target);
}
