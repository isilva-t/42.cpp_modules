#include "Bureaucrat.hpp"

int main()
{
    std::cout << CYAN << "\n\t\t\t============== Testing Form Signing\n" << RESET;
    {
        Form form("form", 50, 25);
        std::cout << form << "\n";

        Bureaucrat intern("Intern", 51);
        std::cout << CYAN << "\n----Testing with low rank bureaucrat:----\n" << RESET;
        intern.signForm(form);
        std::cout << form;

        Bureaucrat director("Director", 1);
        std::cout << CYAN << "\n----Testing with high rank bureaucrat:----\n" << RESET;
		std::cout << director << "\n";
        director.signForm(form);
        std::cout << form;
    }
    return 0;
}
