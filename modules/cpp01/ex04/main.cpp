#include <iostream>
#include <fstream>

int main(int ac, char **av)
{
	if (ac != 4)
		return (std::cerr << "Number of arguments incorrect!" << std::endl, 1);

	// open file with ifstream, like "open" function in C
	std::string source_file(av[1]);
	std::ifstream file(av[1]);
	if (!file.is_open())
		return (std::cerr << "Failed to open " << source_file << std::endl, 1);

	// make a string with name to new .replace file
	std::string origin(av[1]);
	std::string name_new = origin + ".replace";

	// open file with new name to output changes
	std::ofstream replace_file(name_new.c_str());
	if (!replace_file.is_open())
		return (std::cerr << "Failed to open destination " << name_new << std::endl, 1);
	
	// declaring vars for reading lines and change words
	std::string line;
	std::string s1(av[2]);
	std::string s2(av[3]);

	// reading each line with get line, and do replacements
	while (std::getline(file, line))
	{
		if (!s1.empty())
		{
			size_t position = line.find(s1);
			while (position != std::string::npos)
			{	
				std::string before = line.substr(0, position);
				std::string after = line.substr(position + s1.length());
				line = before + s2 + after;
				position = line.find(s1);
			}
		}
		replace_file << line << std::endl;
	}
	std::cout << "Replacements completed!" << std::endl
		<< "Output written to " << name_new << std::endl;
	return 0 ;
}
