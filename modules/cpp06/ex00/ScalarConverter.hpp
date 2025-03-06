#pragma once


#include <iostream>
#include <string>
#include <sstream>
#include <limits>
#include <exception>
#include <cctype>
#include <climits>



class ScalarConverter {

private:
	ScalarConverter();
	ScalarConverter(const ScalarConverter& other);
	ScalarConverter& operator=(const ScalarConverter& other);
	~ScalarConverter();

public:
	static void convert(std::string in);
};
