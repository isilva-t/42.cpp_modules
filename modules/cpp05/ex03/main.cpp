#include "Bureaucrat.hpp"
#include "Intern.hpp"

int main()
{
	std::cout << YELLOW << "\n============== Testing Intern ==============" << RESET << "\n";
	
	Intern trainee;

	AForm* shur;
	AForm* robo;
	AForm* pres;
	AForm* invalid;

	std::cout << CYAN << "\n----Testing valid form creation:----\n" << RESET;
	
	shur = trainee.makeForm("shrubbery creation", "target-shur");
	robo = trainee.makeForm("robotomy request", "target-robo");
	pres = trainee.makeForm("presidential pardon", "target-president");

	std::cout << CYAN << "\n----Testing invalid form creation:----\n" << RESET;
	invalid = trainee.makeForm("invalid form", "Nobody");

	delete shur;
	delete robo;
	delete pres;

	return 0;
}
