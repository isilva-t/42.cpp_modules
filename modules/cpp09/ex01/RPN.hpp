#pragma once

#include <iostream>
#include <string>
#include <exception>
#include <cctype>
#include <climits>
#include <cstring>

#include <stack>

class RPN {

private:

	std::stack<float> _st;

	void	_preCheck(const std::string& in);
	float	_doOper(float l, float r, char op);

	RPN(const RPN& other);
	RPN& operator=(const RPN& other);

public:
	RPN();
	~RPN();

	void	calc(const std::string& in);
};
