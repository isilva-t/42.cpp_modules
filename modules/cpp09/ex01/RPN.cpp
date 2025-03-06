#include "RPN.hpp"

const std::string OPER = "+-*/";

RPN::RPN() : _st() {}

RPN::RPN(const RPN& other) : _st(other._st) {}

RPN& RPN::operator=(const RPN& other)
{
	if (this != &other)
	{
		_st = other._st;
	}
	return *this;
}

RPN::~RPN() {}

////////////////////////////////////////////////

void	RPN::calc(const std::string& in)
{
	_preCheck(in);
	for (int i = 0; in[i]; i++)
	{
		if(isspace(static_cast<int>(in[i])))
			continue ;
		else if (isdigit(static_cast<int>(in[i])))
			_st.push(static_cast<float>(in[i] - '0'));
		else if (OPER.find(in[i]) != std::string::npos
			&& _st.size() >= 2)
		{
			float r = _st.top();
			_st.pop();
			float l = _st.top();
			_st.pop();
			_st.push(_doOper(l, r, in[i]));
		}
		else
			throw std::exception();
	}
	if (_st.size() != 1)
		throw std::exception();
	std::cout << _st.top() << std::endl;
	_st.pop();
}

float	RPN::_doOper(float l, float r, char op)
{
	float result = INT_MIN;

	std::string option = OPER;

	int oper;
	for (oper = 0; oper < 4 && static_cast<char>(option[oper]) != op; oper++) {}

	switch(oper)
	{
		case 0 : result = l + r; 
			break ;	
		case 1 : result = l - r;
			break ;
		case 2 : result = l * r;
			break ;
		case 3 : result = l / r; 
			break ;
		default : throw std::exception();
	}	
	if (result == INT_MIN)
		throw std::exception();
	return result;
}

void	RPN::_preCheck(const std::string& in)
{
	int	digit = 0;
	int	oper = 0;
	bool	space = true;

	for (int i = 0; in[i]; i++)
	{
		if(isspace(static_cast<int>(in[i])))
		{
			space = true;
			continue ;
		}
		else if (space && isdigit(static_cast<int>(in[i])))
		{
			digit++;
		}
		else if (space && strchr(OPER.c_str(), static_cast<char>(in[i])))
		{
			oper++;
		}
		else
			throw std::exception();
		space = false;
	}
	if (digit - oper != 1)
		throw std::exception();
}
