#pragma once

#include <iostream>
#include <exception>

#define RED "\e[1;3;31m"
#define GREEN "\e[1;3;32m"
#define YELLOW "\e[1;3;93m"
#define CYAN "\e[1;3;36m"
#define RESET "\e[0m"

#include "Form.hpp"
class Form;


class Bureaucrat {

private:
	const std::string _name;
	int	_grade;

public:
	Bureaucrat();
	Bureaucrat(const std::string& name, const int grade);
	Bureaucrat(const Bureaucrat& to_cpy);
	Bureaucrat& operator=(const Bureaucrat& to_cpy);
	~Bureaucrat();

	const std::string& getName() const;
	int getGrade() const;

	void	incGrade(int val);
	void	decGrade(int val);

	class GradeTooHighException : public std::exception {
		public:
			virtual const char* what() const throw();
	};

	class GradeTooLowException : public std::exception {
		public:
			virtual const char* what() const throw();
	};

	void	signForm(Form& form);

};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& obj);
