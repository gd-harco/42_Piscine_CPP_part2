#ifndef HEADER_HPP
#define HEADER_HPP

#include <iostream>
#include <string>
#include <cstdlib>
#include <fstream>
#include <map>
#include <cmath>
#include <sstream>
#include <algorithm>
#include "BitcoinExchange.hpp"

typedef std::map<BitcoinExchange, float> myMap;

bool	validDateFormat(const std::string& date);
bool	invalidDate(const std::string& date, myMap map);
bool	invalidValue(float &value, const std::string &valueStr);
#endif //HEADER_HPP
