#pragma once

#include <exception>
#include <iostream>

#define PRINT 1

#define RED "\e[1;3;31m"
#define GRE "\e[1;3;32m"
#define YEL "\e[1;3;93m"
#define CYA "\e[1;3;36m"
#define RST "\e[0m"

template <typename  T>
class Array {

private:
	T* _array;
	unsigned int	_size;

public:
	Array() : _array(NULL), _size(0)
	{
		if(PRINT)
			std::cout << YEL"\nConstructor DEFAULT\n" << RST;
	}

	Array(unsigned int size_array) : 
		_array(new T[size_array]), 
		_size(size_array)	
	{
		if(PRINT)
			std::cout << GRE"\nConstructor with PARAMETER\n" << RST;
	}

	Array<T>(const Array& other) : _array(NULL), _size(0)
	{
		if(other.size() > 0)
		{
			_size = other.size();
			_array = new T[_size]; 
			unsigned int i = 0;
			for(; i < other.size(); i++)
				_array[i] = other._array[i];
		}
		if(PRINT)
			std::cout << CYA"\nCOPY Constructor\n" << RST;
	}

	Array<T>& operator=(const Array<T>& other)
	{
		if(this != &other)
		{
			T* temp_array = new T[other.size()];
			unsigned int i = 0;
			for(; i < other.size(); i++)
				temp_array[i] = other._array[i];
			if(_size > 0 || _array != NULL)
				delete[] _array;
			_array = temp_array;
			_size = other.size();
		}
		if(PRINT)
			std::cout << CYA"\nOperator =\n" << RST;
		return *this;
	}

	~Array() {	
		delete[] _array;
		if(PRINT)
			std::cout << RED"\nDESTRUCTOR\n" << RST;
	}

	T&	operator[](unsigned int index)
	{
		if (index >= _size || _array == NULL)
			throw std::exception();
		return _array[index];
	}

	unsigned int	size() const
	{
		return _size;
	}
};
