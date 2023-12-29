//
// Created by gd-harco on 24/12/23.
//

#include "BitcoinExchange.hpp"

 bool	invalidDay(int year, int month, int day);

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
	if (invalidDay(_year, _month, _day))
		throw std::invalid_argument("Invalid day");
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &obj) {
	std::cout << "BitcoinExchange : Copy Constructor Called" << std::endl;
	if (this != &obj)
		*this = obj;
}

BitcoinExchange::~BitcoinExchange() {
	std::cout << "BitcoinExchange : Destructor Called" << std::endl;
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &obj) {
	if (this == &obj)
		return *this;
	//this.elem =
}

// bool	invalidDay(int year, int month, int day) {
// 	if (day < 0 || day > 31)
// }
