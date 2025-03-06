#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
	//AForm test("test", 1, 1);  // This will fail at compile time

	std::cout << CYAN << "\n\t\t\t\t============== Testing ShrubberyCreationForm\n" << RESET;
    {
        ShrubberyCreationForm shrub("home");
        Bureaucrat highGrade("Boss", 1);
        Bureaucrat lowGrade("Intern", 150);
        std::cout << CYAN << "\n----Testing with unsigned form:----\n" << RESET;
        highGrade.executeForm(shrub);
        std::cout << CYAN << "\n----Testing with low grade bureaucrat:----\n" << RESET;
        lowGrade.signAForm(shrub);
        std::cout << "\n";
        lowGrade.executeForm(shrub);
        std::cout << CYAN << "\n----Testing with high grade bureaucrat:----\n" << RESET;
        highGrade.signAForm(shrub);
        highGrade.executeForm(shrub);
    }


	std::cout << CYAN << "\n\n\t\t\t\t============== Testing RobotomyRequestForm\n" << RESET;
    {
        RobotomyRequestForm robot("Bender");
        Bureaucrat manager("Manager", 40);

        std::cout << CYAN << "\n----Testing robotomy multiple times:----\n" << RESET;
        manager.signAForm(robot);
        for (int i = 0; i < 4; i++)
        {
            std::cout << "\nAttempt " << i + 1 << ":\n";
            manager.executeForm(robot);
        }
    }


	std::cout << CYAN << "\n\n\t\t\t\t============== Testing PresidentialPardonForm\n" << RESET;
    {
        PresidentialPardonForm pardon("Arthur Dent");
        Bureaucrat president("President", 1);
        Bureaucrat secretary("Secretary", 30);
        std::cout << CYAN << "\n----Testing with insufficient execution grade:----\n" << RESET;
        secretary.signAForm(pardon);
		std::cout << "\n";
        secretary.executeForm(pardon);
        std::cout << CYAN << "\n----Testing with sufficient grades:----\n" << RESET;
        president.signAForm(pardon);
        president.executeForm(pardon);
    }

    return 0;
}
