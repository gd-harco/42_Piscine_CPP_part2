#include "header.hpp"

bool	invalidDate(const std::string& date, myMap map) {
	if (!validDateFormat(date) || date < map.begin()->first){
		std::cout << "Error: invalid line => " + date << std::endl;
		return true;
	}
	return false;
}

bool	invalidValue(const std::string& value) {
	float conv = std::atof(value.c_str());
	if (conv != conv || conv < 0 || conv > 1000){
		std::cout << "Error : invalid value =>" + value <<std::endl;
		return true;
	}
	return false;
}

bool validDateFormat(const std::string& date) {
	if (date.length() != 10)
		return false;
	if (date[4] != '-' || date[7] != '-')
		return false;
	for (int i = 0; i < 10; ++i) {
		if (i == 4 || i == 7)
			continue;
		if (!isdigit(date[i]))
			return false;
	}
	return true;
}
