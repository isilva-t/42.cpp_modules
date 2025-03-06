#include "BitcoinExchange.hpp"

static const std::string COMMA		= ",";
static const std::string SPACES_PIPE	= " | ";
static const std::string ERROR		= "Error: ";
static const std::string NOT_POSITIVE	= "not a positive number.";
static const std::string DATA_READ	= "bad data => ";
static const std::string INPUT_READ	= "bad input => ";
static const std::string TOO_LARGE	= "too large a number.";
static const std::string TXT		= ".txt";
static const std::string CSV		= ".csv";
static const std::string FILE_ERR	= "could not open file.";

BitcoinExchange::BitcoinExchange() 
	: _db(), 
	_data_file("data.csv"), 
	_input_file(""),
	_date(""),
	_value(0),
	_value_str("")
{
	if(!_data_file.is_open())
	{
		_data_file.clear();
		_data_file.open(".data.csv");
		if(!_data_file.is_open())
			throw Error(ERROR + FILE_ERR);
	}
	_registerCsv();
	_data_file.close();
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& other) 
	: _db(other._db), 
	_data_file(""),
	_input_file(""),
	_date(""), 
	_value(0),
	_value_str("")

{	(void)other;	}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& other)
{	(void)other;
	return *this;	}

BitcoinExchange::~BitcoinExchange() {}

/////////////////////////////////////////////////////////////////////

void	BitcoinExchange::readUserFile(const std::string& input_txt)
{
	//if (!_isValidFile(TXT, input_txt) || !_isValidFile(CSV, input_txt))
	//	throw Error(ERROR + FILE_ERR);
	_input_file.clear();	
	_input_file.open(input_txt.c_str());
	if(!_input_file.is_open())
		throw Error(ERROR + FILE_ERR);
	_handleInputContent();
	_input_file.close();
}

void	BitcoinExchange::_handleInputContent()
{
	std::string line;
	int i = 0;
	std::map<std::string, double>::iterator it;
	std::map<std::string, double>::iterator ite = _db.end();

	while(std::getline(_input_file, line))
	{
		_resetVars();
		_clear_edge_spaces(line);
		if(i++ == 0 && _verifyHeader(line))
			continue ;
		if (!line.length())
			continue ;
		try
		{
			if(!_isValidDataHere(line, INPUT_READ))
				throw Error(ERROR + INPUT_READ + line);
			if(_value < 0)
				throw Error(ERROR + NOT_POSITIVE);
			if(_value > 1000 || _isTooHigh())
				throw Error(ERROR + TOO_LARGE);
			it = _db.begin();
			if (_date < it->first)
			{
				//std::cout << _date << " => "; 
				//_printN(_value);
				//std::cout << " = ";
				//_printN(_value * it->second);
				//continue ;
				throw Error(ERROR + "no BTC price found for " + _date);
			}
			while(it != ite && _date >= it->first)
			{
				it++;
				if (it != ite &&_date < it->first)
				{
					it--;
					break ;
				}
			}
			if (it == ite)
				it--;
			std::cout << _date << " => "; 
			_printN(_value);
			std::cout << " = ";
			_printN(_value * it->second);
			std::cout << std::endl;
		}
		catch (Error& e)
		{
			std::cout << e.what() << std::endl;
		}
	}
}

void	BitcoinExchange::_registerCsv()
{
	std::string line;
	if (!std::getline(_data_file, line))
		throw Error("Empty data.csv file!");
	while(std::getline(_data_file, line))
	{
		_clear_edge_spaces(line);
		if (!line.length())
			continue ;
		if(!_isValidDataHere(line, DATA_READ))
			throw Error(ERROR + DATA_READ + line);
		_db[_date] = _value;
		_resetVars();
	}
	if (_db.size() == 0)
		throw Error(ERROR + "empty database.");
}

//////// helpers

bool	BitcoinExchange::_verifyHeader(std::string& line) const
{
	for (int i = 0; line[i]; i++)
	{
		if(isalpha(line[i]))
			return true;
	}
	return false;
}

bool	BitcoinExchange::_isValidFile(const std::string& wanted, const std::string have)
{
	unsigned int	len = have.length();

	if (len <= wanted.length())
		return (false);
	if (have[len - wanted.length() - 1] == '/')
		return false;
	for(unsigned int i = 0; i < wanted.length(); i++)
	{
		if (have[len - wanted.length() + i] != wanted[i])
			return false;
	}
	return true ;
}

bool	BitcoinExchange::_isValidDataHere(std::string& line, const std::string& what_here)
{
	std::string separator;
	if(what_here == DATA_READ)
		separator = COMMA;
	else if(what_here == INPUT_READ)
		separator = SPACES_PIPE;
	else
		return false;

	size_t midle_text = line.find(separator);
	if(midle_text == std::string::npos)
		throw Error(ERROR + what_here + line);
	_date =  line.substr(0, midle_text);
	_value_str = line.substr(midle_text + separator.length());

	_value = 0;
	if(!_isValidValue(_value_str, &_value) || !_isValidDate(_date))
	{
		_resetVars();
		return false;
	}
	return true;
}

bool	BitcoinExchange::_isValidDate(const std::string& date)
{
	if(date.length() != 10)
		return false;
	for (int i = 0; i < 10; i++)
	{
		if((i == 4 || i == 7) && date[i] == '-')
			continue ;
		if(!isdigit(date[i]))
			return false;
	}
	std::string year_str = date.substr(0, 4);
	std::string month_str = date.substr(5, 2);
	std::string day_str = date.substr(8, 2);

	struct tm t_s = {};
	std::istringstream ss_year(year_str);
	std::istringstream ss_month(month_str);
	std::istringstream ss_day(day_str);
	
	if (!(ss_year >> t_s.tm_year))
		return false;
	if (!(ss_month >> t_s.tm_mon))
		return false;
	if (!(ss_day >> t_s.tm_mday))
		return false;

	if(!(t_s.tm_mon >= 1 && t_s.tm_mon <= 12)
		|| !(t_s.tm_mday >= 1 && t_s.tm_mday <= 31))
		return false;

	t_s.tm_year -= 1900;
	t_s.tm_mon -= 1;

	struct tm cache_t = t_s;
	if (mktime(&cache_t) == -1)
		return false;
	
	if (t_s.tm_year != cache_t.tm_year
		|| t_s.tm_mon != cache_t.tm_mon
		|| t_s.tm_mday != cache_t.tm_mday)
		return false;
	return true;
}

bool	BitcoinExchange::_isValidValue(const std::string& value_str, double *converted)
{
	if(!value_str.length())
		return false;

	std::istringstream iss(value_str);

	if (iss >> *converted && iss.eof())
		return true;
	return false;
}

void	BitcoinExchange::_resetVars()
{
	_date = "";
	_value = 0;
	_value_str = "";
}

void	BitcoinExchange::_clear_edge_spaces(std::string& input) 	
{
    input.erase(0, input.find_first_not_of("\t\n\v\f\r "));
    input.erase(input.find_last_not_of("\t\n\v\f\r ") + 1);
}

void	BitcoinExchange::_printDB()
{
	for (std::map<std::string, double>::iterator it = _db.begin(); 
		it != _db.end(); ++it) 
	{
        std::cout << "Key: " << it->first << " Value: " << it->second << std::endl;
	}
}

////// exceptions

BitcoinExchange::Error::Error(const std::string& in_msg) : _msg(in_msg) {}

BitcoinExchange::Error::~Error() throw() {}

const char* BitcoinExchange::Error::what() const throw() {
    return _msg.c_str();
}

/// more helpers
bool	BitcoinExchange::_isTooHigh() const
{
	std::istringstream ss(_value_str);

	int	test;
	if (_value >= 1000 && ss >> test && !ss.eof())
		return true;
	return false;
}

void	BitcoinExchange::_printN(double n)
{
	std::ostringstream stream;
	stream << std::fixed << std::setprecision(2) << n;

	std::string result = stream.str();

	size_t decimal_pos = result.find('.');
	if (decimal_pos != std::string::npos)
	{
		size_t last_non_zero = result.find_last_not_of('0');

		if (last_non_zero == decimal_pos)
		{
			result.erase(decimal_pos);
		}
		else
		{
			result.erase(last_non_zero + 1);
		}
	}
	std::cout << result;
}
