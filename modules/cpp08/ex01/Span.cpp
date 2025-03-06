#include "Span.hpp"

Span::Span() : _numbers(0), _N(0) {}

Span::Span(const unsigned int N) 
	: _numbers(0), _N(N)
{
	_numbers.reserve(N);
}

Span::Span(const Span& other) 
	: _numbers(other._numbers), _N(other._N)
{}

Span& Span::operator=(const Span& other)
{  
	if(this != &other)
		_numbers = other._numbers;
	return *this;
}

Span::~Span() {}

/////////////////////////////////////////////////////////

void		Span::addNumber(int to_add)
{
	if (_numbers.size() < _N)
		_numbers.push_back(to_add);
	else
		throw outOfSize();
}

const char* Span::outOfSize::what() const throw()
{
	static const std::string msg = "Container cant receive number!";
	return msg.c_str();
}

//////////////////////////////////////////

unsigned int	Span::shortestSpan()
{
	if(_numbers.size() < 2)
		throw spanEmptyOrSizeOne();

	std::vector<int> sorted_numbers(_numbers);
	std::sort(sorted_numbers.begin(), sorted_numbers.end());

	int min_span = INT_MAX;
	unsigned int i = 1;
	for(; i < sorted_numbers.size(); i++)
		min_span = std::min(
			min_span, 
			sorted_numbers[i] - sorted_numbers[i - 1]);

	return static_cast<unsigned int>(min_span);
}

unsigned int	Span::longestSpan()
{
	if(_numbers.size() < 2)
		throw spanEmptyOrSizeOne();

	int min_value;
	int max_value;

	min_value = *std::min_element(_numbers.begin(), _numbers.end());
	max_value = *std::max_element(_numbers.begin(), _numbers.end());

	return static_cast<unsigned int>(max_value - min_value);
}

const char* Span::spanEmptyOrSizeOne::what() const throw()
{
	static const std::string msg = "Container empty, or siz == one!";
	return msg.c_str();
}

///////////////////////////////////////////////////////////




