//
// Created by gd-harco on 24/12/23.
//

#include "BitcoinExchange.hpp"

 bool	ValidDay(int&year, int&month, int&day);

BitcoinExchange::BitcoinExchange()
	: _year(0), _month(0), _day(0) {}

BitcoinExchange::BitcoinExchange(std::string &date) {
	std::string	data[3];

	if (date.length() != 10 || (date[4] != '-' || date[7] != '-'))
		throw std::invalid_argument("Wrong date format");
	try {
		data[0] = date.substr(0, 4);
		data[1] = date.substr(4,2);
		data[2] = date.substr(8,2);
	} catch (std::exception & e){
		throw std::invalid_argument("Wrong date format");
	}
	char *end;
	int temp;
	_year = std::strtod(data[0].c_str(), &end);
	temp = _year;
	if (temp != _year || *end != '\0' || errno != 0 || _year < 0)
		throw std::invalid_argument("Invalid year");
	_month = std::strtod(data[1].c_str(), &end);
	temp = _month;
	if (temp != _month || *end != '\0' || errno != 0 || _month < 0 || _month > 12)
		throw std::invalid_argument("Invalid month");
	_day = std::strtod(data[2].c_str(), &end);
	temp = _day;
	if (temp != _day || !ValidDay(_year, _month, _day))
		throw std::invalid_argument("Invalid day");
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &obj)
	:_year(obj._year), _month(obj._month), _day(obj._day){}

BitcoinExchange::~BitcoinExchange() {}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &obj) {
	if (this == &obj)
		return *this;
	this->_day = obj._day;
	this->_month = obj._month;
	this->_year = obj._year;
	return *this;
}

int BitcoinExchange::year() const {
	return _year;
}

int BitcoinExchange::month() const {
	return _month;
}

int BitcoinExchange::day() const {
	return _day;
}

bool	ValidDay(const int& year, const int& month, const int& day) {
	if(day < 1)
		return false;
	if(month == 2) {
		if((year % 4 == 0 && year % 100 != 0) || year % 400 == 0) {
			if(day > 29)
				return false;
			}
		if(day > 28)
			return false;
		}
	else if(month == 4 || month == 6 || month == 9 || month == 11) {
		if(day > 30) {
			return false;
		}
	} else {
		if(day > 31) {
			return false;
		}
	}
	return true;
}
