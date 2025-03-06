#pragma once

#include <fstream>
#include <iostream>
#include <string>
#include <sstream>
#include <exception>
#include <ctime>
#include <cmath>
#include <iomanip>

#include <map>

class BitcoinExchange {

private:
	std::map<std::string, double> _db;

	std::ifstream _data_file;
	std::ifstream _input_file;
	std::string _date;
	double	_value;
	std::string	_value_str;

	void	_handleInputContent();
	bool	_verifyHeader(std::string& line) const;
	void	_resetVars();
	bool	_isValidDataHere(std::string& line, const std::string& what_here);
	void	_clear_edge_spaces(std::string& input);
	void	_registerCsv();
	void	_printDB();
	bool	_isValidDate(const std::string& date);
	bool	_isValidValue(const std::string& value_str, double *converted);
	bool	_isValidFile(const std::string& wanted, const std::string what_have);
	bool	_isTooHigh() const;
	void	_printN(double n);
	
	BitcoinExchange(const BitcoinExchange& other);
	BitcoinExchange& operator=(const BitcoinExchange& other);

public:
	BitcoinExchange();
	~BitcoinExchange();

	class Error : public std::exception {
	private:
		std::string _msg;
	public:
		Error(const std::string& in_msg);
		virtual const char* what() const throw();
		virtual ~Error() throw();
	};

	void	readUserFile(const std::string& input_txt);
};
