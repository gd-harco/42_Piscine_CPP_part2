//
// Created by gd-harco on 24/12/23.
//

#include "BitcoinExchange.hpp"

 bool	ValidDay(int&year, int&month, int&day);

BitcoinExchange::BitcoinExchange(std::fstream &date) {
	std::string	data[3];

	std::getline(date, data[0], '-');
	std::getline(date, data[1], '-');
	std::getline(date, data[2]);
	if (data[0].length() != 4 || data[1].length() != 2 || data[2].length() != 2)
		throw std::invalid_argument("Wrong date format");
	_year = std::atof(data[0].c_str());
	if (_year != _year || _year < 0)
		throw std::invalid_argument("Invalid year");
	_month = std::atof(data[1].c_str());
	if (_month != _month || _month < 0 || _month > 12)
		throw std::invalid_argument("Invalid month");
	_day = std::atof(data[2].c_str());
	if (!ValidDay(_year, _month, _day))
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
