#include "AForm.hpp"

class ShrubberyCreationForm : public AForm {

private:
	const std::string _target;
	ShrubberyCreationForm();

	void	action() const;

public:
	ShrubberyCreationForm(const std::string& target);
	ShrubberyCreationForm(const ShrubberyCreationForm& other);
	ShrubberyCreationForm& operator=(const ShrubberyCreationForm& other);
	~ShrubberyCreationForm();


	class CantOpenFile : public std::exception {
		public:
			virtual const char* what() const throw();
	};
};
