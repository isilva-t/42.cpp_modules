#pragma once

#include <iostream>
#include <exception>

#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

class Intern {

public:
	Intern();
	Intern(const Intern& other);
	Intern& operator=(const Intern& other);
	~Intern();

	AForm*	makeForm(const std::string& form, const std::string& target);

	class NotValidForm : public std::exception {
		public:
			virtual const char* what() const throw();
	};

	struct FormType {
		std::string name;
		AForm* (*ft_to_create)(const std::string& target, const std::string& message);
	};
	static AForm *createShrubbery(const std::string& target, const std::string& message);
	static AForm *createRobotomy(const std::string& target, const std::string& message);
	static AForm *createPresidential(const std::string& target, const std::string& message);
};
