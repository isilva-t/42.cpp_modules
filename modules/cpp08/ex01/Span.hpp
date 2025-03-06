#pragma once

#include <algorithm>
#include <vector>
#include <exception>
#include <string>
#include <climits>

class Span {

private:
	std::vector<int> _numbers;
	unsigned int	_N;
	
	Span();
public:
	Span(const unsigned int N);
	Span(const Span& other);
	Span& operator=(const Span& other);
	~Span();

	void addNumber(unsigned int N);
	
	class outOfSize : public std::exception {
		virtual const char* what() const throw();
	};

	void		addNumber(int to_add);
	unsigned int	shortestSpan();
	unsigned int	longestSpan();

	template <typename I>
	void	addMultipleNumbers(I begin, I end)
	{
		while (begin != end)
		{
			addNumber(*begin);
			begin++;
		}
	}

	class spanEmptyOrSizeOne : public std::exception {
	public:
		virtual const char* what() const throw();
	};
};
