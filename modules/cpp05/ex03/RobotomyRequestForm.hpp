#include "AForm.hpp"
#include <cstdlib>

class RobotomyRequestForm : public AForm {

private:
	const std::string _target;
	RobotomyRequestForm();

	void	action() const;

public:
	RobotomyRequestForm(const std::string& target);
	RobotomyRequestForm(const RobotomyRequestForm& other);
	RobotomyRequestForm& operator=(const RobotomyRequestForm& other);
	~RobotomyRequestForm();


	class RobotomyFailed : public std::exception {
		public:
			virtual const char* what() const throw();
	};
};
