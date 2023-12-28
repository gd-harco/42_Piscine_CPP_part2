//
// Created by gd-harco on 24/12/23.
//

#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <fstream>

class BitcoinExchange {
public:
	BitcoinExchange(std::fstream const &date);
	BitcoinExchange(BitcoinExchange const &obj);
	~BitcoinExchange();
	BitcoinExchange &operator=(const BitcoinExchange &obj);
private:
	int	year;
	int	month;
	int	day;
};


#endif //BITCOINEXCHANGE_HPP
