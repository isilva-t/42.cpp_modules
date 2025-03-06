#include "header.hpp"

int	main()
{
	PhoneBook pb;
	std::string input;

	signal_mute();
	while (!ctrl_d())
	{
		prompt_msg(input, "Please try: ADD, SEARCH, or EXIT: ");
		if (!input.compare("ADD") && !ctrl_d())	
		{
			pb.add_contact();
		}
		else if (!input.compare("SEARCH") && !ctrl_d())	
		{
			if (pb.is_empty() && !ctrl_d())
			{
				std::cout << "There is no contacts to show. ADD first!" << std::endl;
				continue ;
			}
			else if (!ctrl_d())
			{
				pb.print_list_contacts();
				prompt_msg(input, "Give me an index: ");
				pb.handle_search(input);
			}
		}
		else if (!input.compare("EXIT") && !ctrl_d())	
		{
			std::cout << "PhoneBook destroyed. Goodbye!" << std::endl;
			return (0);
		}
		else if (!ctrl_d())
		{
			std::cout << "Invalid otion!" << std::endl;
		}
	}
	std::cout << std::endl << YELLOW << "CTRL + D pressed. Quiting program...";
	std::cout << RESET << std::endl;
	return (0);
}

void	signal_mute(void)
{
	signal(SIGINT, SIG_IGN);
	signal(SIGQUIT, SIG_IGN);
}

void	prompt_msg(std::string& input, std::string msg)	{

	input.clear();
	std::cout << std::endl << YELLOW << msg << RESET;
	std::getline(std::cin, input);
	clear_spaces(input);	
}
