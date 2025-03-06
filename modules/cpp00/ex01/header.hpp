#ifndef HEADER_HPP
# define HEADER_HPP

#include <iostream>
#include <csignal>

#define YELLOW "\e[1;3;93m"
#define RESET "\e[0m"

#include "PhoneBook.hpp"

void	prompt_msg(std::string& input, std::string msg);
void	signal_mute(void);

#endif
