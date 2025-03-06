#include "ShrubberyCreationForm.hpp"
#include "AForm.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm()  
: AForm("default", 145, 137)
{}

ShrubberyCreationForm::~ShrubberyCreationForm()
{}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other) 
	: AForm(other), 
	_target(other._target)
{
	*this = other;
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other)
{
	if(this != &other)
		AForm::operator=(other);
	return (*this);
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target)  
: AForm(target, 145, 137), _target(target)
{}

void ShrubberyCreationForm::action() const
{
	std::string str_outfile = _target + "_shrubbery";
	std::ofstream outfile(str_outfile.c_str());

	if(outfile)
	{
		outfile << GREEN;
		outfile << "      ^" << std::endl;
		outfile << "     ^^^" << std::endl;
		outfile << "    ^^^^^" << std::endl;
		outfile << "   ^*^^^*^" << std::endl;
		outfile << "  ^^*^^^*^^" << std::endl;
		outfile << " ^^^*^^^*^^^" << std::endl;
		outfile << "^^^^^*^*^^^^^" << std::endl;
		outfile << "     ###" << std::endl;
		outfile << "     ###" << std::endl;
		outfile << "    #####" << RESET << std::endl;

		outfile.close();
	}
	else
		throw CantOpenFile();
}

const char* ShrubberyCreationForm::CantOpenFile::what() const throw()
{
	static const std::string msg = RED "Cant create file!"  RESET;
	return msg.c_str();
}

