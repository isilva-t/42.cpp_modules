#include "Bureaucrat.hpp"

int main()
{
    std::cout << CYAN << "\t\t\t============== Testing Constructors\n" << RESET;
    {
        try
		{
            Bureaucrat valid("John", 75);
            std::cout << valid << GREEN << "Created successfully\n" << RESET;
        } 
		catch (std::exception& e) 
		{
            std::cout << RED << "Error: " << e.what() << RESET;
        }

		std::cout << CYAN 
			<< "\n----too HIGH instance try:----\n" RESET;
        try 
		{
            Bureaucrat tooHigh("High", 0);
            std::cout << "Should not reach here!\n";
        } 
		catch (Bureaucrat::GradeTooHighException& e) 
		{
            std::cout << GREEN << "Caught: " << e.what() << "\n" RESET;
        }

		std::cout << CYAN 
			<< "\n----too LOW instance try:----\n" << RESET;
        try 
		{
            Bureaucrat tooLow("Low", 151);
            std::cout << "Should not reach here!\n";
        } 
		catch (Bureaucrat::GradeTooLowException& e) 
		{
            std::cout << GREEN << "Caught: " << e.what() << "\n" RESET;
        }
    }

    std::cout << CYAN << "\n\t\t\t============== Testing Grade Modifications\n" << RESET;
    {
		Bureaucrat worker("Worker", 75);
		std::cout << worker;

		std::cout << CYAN << "\n----INCrement test:----\n" << RESET;
		int val = 13;
		try 
		{
			worker.incGrade(val);
			std::cout << "Increment " << val << ": " << worker;
		}
		catch (std::exception& e) 
		{
			std::cout << RED << "Error: " << e.what() << "\n" RESET;
		}

		std::cout << CYAN << "\n----DECrement test:----\n" << RESET;
		try 
		{
			worker.decGrade(val);
			std::cout << "Decrement " << val << ": " << worker;
		}
		catch (std::exception& e) 
		{
			std::cout << RED << "Error: " << e.what() << "\n" RESET;
		}

		std::cout << CYAN << "\n----Non valid INCrement test:----\n" << RESET;
		int	val_two = 6;
		{
			Bureaucrat boss("Boss", 6);
			try 
			{
				std::cout << boss;
				std::cout << "try to increment....\n";
				boss.incGrade(val_two);
				std::cout << "Should not reach here!\n";
			}
			catch (Bureaucrat::GradeTooHighException& e) 
			{
				std::cout << GREEN << "Caught: " << e.what() << "\n" RESET;
				std::cout << boss;
			}
		}
		std::cout << CYAN << "\n----Non valid DECrement test:----\n" << RESET;
		{
			Bureaucrat intern("Intern", 145);
			try
			{
				std::cout << intern;
				std::cout << "try to decrement....\n";
				intern.decGrade(val_two);
				std::cout << "Should not reach here!\n";
			} 
			catch (Bureaucrat::GradeTooLowException& e)
			{
				std::cout << GREEN << "Caught: " << e.what() << "\n" RESET;
				std::cout << intern;
			}
		}
    }
    {
        std::cout << CYAN << "\n============== Testing Getters \n" << RESET;
        Bureaucrat employee("Employee", 42);
        std::cout << "Name: " << employee.getName() << std::endl;
        std::cout << "Grade: " << employee.getGrade() << std::endl;
    }
    return 0;
}
