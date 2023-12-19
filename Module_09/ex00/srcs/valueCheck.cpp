#include "header.hpp"

bool	invalidDate(const std::string& date, myMap map) {
	if (!validDateFormat(date) || date < map.begin()->first){
		std::cout << "Error: invalid line => " + date << std::endl;
		return true;
	}
	return false;
}

bool invalidValue(float &value, const std::string &valueStr) {
	if (value != value || value < 0 || value > 1000){
		std::cout << "Error : invalid value =>" << valueStr <<std::endl;
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
