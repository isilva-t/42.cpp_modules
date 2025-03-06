#include "ScalarConverter.hpp"
#include "Helper.hpp"
#include <limits>

static const std::string CHAR = "char: ";
static const std::string INT = "int: ";
static const std::string FLOAT = "float: ";
static const std::string DOUBLE = "double: ";
static const std::string IMPOSSIBLE = "impossible";

ScalarConverter::ScalarConverter(){}

ScalarConverter::ScalarConverter(const ScalarConverter& other)
{	*this = other;	}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& other)
{	(void)other;
	return *this;	}

ScalarConverter::~ScalarConverter() {}

/////////////////////////////////////////////////////////////////////////

void ScalarConverter::convert(std::string in)
{
	std::string edge[7] = {"-inff", "+inff", "nanf","-inf", "+inf", "nan", IMPOSSIBLE};
	int	edge_v = 6;
	try
	{
		if(in.length() == 1 && !isdigit(in[0]))
		{
			char c = static_cast<char>(in[0]);
			Helper::displayChar(static_cast<char>(c));
			Helper::displayInt(static_cast<int>(c));
			Helper::displayFloat(static_cast<float>(c));
			Helper::displayDouble(static_cast<double>(c));
			return ;
		}
		else
		{
			Helper::clear_edge_spaces(in);
			for(int i = 0; i < 6 ; i++)
			{
				if(in == edge[i])
				{
					edge_v = i;
					throw (std::invalid_argument(in));
				}
			}
			bool point = false;
			for(int i = 0; in[i]; i++)
			{
				if(i == 0 && (in[0] == '+' || in[0] == '-') && in[1])
					continue ;
				if(in[i] == '.' && point == false)
	   			{
					point = true;
					if (!in[i + 1])
					{
						in.erase(in.length() - 1);
						break ;
					}
				}
				else if(in[i] == '.' && point == true)
					throw (std::invalid_argument("Has more than one point"));
				if(!in[i + 1] && in[i] == 'f')
				{
					if (!point)
						throw (std::invalid_argument(IMPOSSIBLE));
					in.erase(in.length() - 1);
					break ;
				}
				if(!isdigit(in[i]) && !in[i + 1])
					throw (std::invalid_argument("not digit"));
			}
			std::istringstream iss(in);
			double val;
			if (iss >> val && iss.eof())
			{
				if(val >= -128 && val <= 127)
					Helper::displayChar(static_cast<char>(val));
				else
					std::cout << CHAR << IMPOSSIBLE << std::endl;
				if (val >= INT_MIN && val <= INT_MAX)
					Helper::displayInt(static_cast<int>(val));
				else
					std::cout << INT << IMPOSSIBLE << std::endl;
				if (val >= -std::numeric_limits<float>::max()
					&& val <= std::numeric_limits<float>::max())
					Helper::displayFloat(static_cast<float>(val));
				else
					std::cout << FLOAT << IMPOSSIBLE << std::endl;
				Helper::displayDouble(val);
				return ;
			}
		}
		throw (std::invalid_argument(IMPOSSIBLE));
	}
	catch (std::exception& e)
	{
		//std::cout << "What happen? " << e.what() << std::endl;
		std::cout << CHAR << IMPOSSIBLE << std::endl;
		std::cout << INT << IMPOSSIBLE << std::endl;
		{
			std::cout << FLOAT;
			if(edge_v >= 3 && edge_v <= 5)
				std::cout << edge[edge_v - 3];
			else
				std::cout << edge[edge_v];
			std::cout << std::endl;
		}
		{
			std::cout << DOUBLE;
			if(edge_v >= 0 && edge_v <= 2)
				std::cout << edge[edge_v + 3];
			else
				std::cout << edge[edge_v];
			std::cout << std::endl;
		}
	}
}
