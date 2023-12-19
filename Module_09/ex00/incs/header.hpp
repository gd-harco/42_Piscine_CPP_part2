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

typedef std::map<std::string, double> myMap;

bool	validDateFormat(const std::string& date);
bool	invalidDate(const std::string& date, myMap map);
bool	invalidValue(const std::string& value);
#endif //HEADER_HPP
