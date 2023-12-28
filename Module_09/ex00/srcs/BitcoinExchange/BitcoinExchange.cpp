//
// Created by gd-harco on 24/12/23.
//

#include "BitcoinExchange.hpp"
#include <fstream>

BitcoinExchange(std::fstream );



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
