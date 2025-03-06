#pragma once

#include "Bureaucrat.hpp"
#include <iostream>
#include <exception>

#define RED "\e[1;3;31m"
#define GREEN "\e[1;3;32m"
#define YELLOW "\e[1;3;93m"
#define RESET "\e[0m"

#include "Bureaucrat.hpp"
class Bureaucrat;

class Form {

private:
	const std::string _name;
	bool _sign;
	const int	_gradeSign;
	const int	_gradeExecute;
	
	Form();

public:
	Form(const std::string& name, const int gradeSign, const int gradeExecute);
	Form(const Form& to_cpy);
	Form& operator=(const Form& to_cpy);
	~Form();

	const std::string& getName() const;
	bool getSign() const;
	int getGradeSign() const;
	int getGradeExecute() const;

	void	beSigned(const Bureaucrat& B);

	class GradeTooHighException : public std::exception {
		public:
			virtual const char* what() const throw();
	};

	class GradeTooLowException : public std::exception {
		public:
			virtual const char* what() const throw();
	};

};

std::ostream& operator<<(std::ostream& os, const Form& obj);
