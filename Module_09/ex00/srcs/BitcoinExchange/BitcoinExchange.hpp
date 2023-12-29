//
// Created by gd-harco on 24/12/23.
//

#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <fstream>
#include <cstdlib>

class BitcoinExchange {
public:
	explicit BitcoinExchange(std::fstream &date);
	BitcoinExchange(BitcoinExchange const &obj);
	~BitcoinExchange();
	BitcoinExchange &operator=(const BitcoinExchange &obj);
private:
	int	_year;
	int	_month;
	int	_day;
};


#endif //BITCOINEXCHANGE_HPP
