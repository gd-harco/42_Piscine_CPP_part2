/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gd-harco <gd-harco@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 17:15:11 by gd-harco          #+#    #+#             */
/*   Updated: 2023/12/01 17:42:43 by gd-harco         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "header.hpp"

void	processLine(const myMap &map, const std::string& date, const float &value);
void	readAndFillDB(myMap & mapDB, std::ifstream& file);
double	getDouble(const std::string& doubleStr);
void	processFile(std::ifstream &file, const myMap &map);

int main(int argc, char **argv) {
 	if (argc != 2)
 		return (std::cout << "ERROR: bad number of argument" << std::endl, 1);

	std::ifstream database("data.csv");
	std::ifstream input(argv[1]);

	if (!database.is_open() || !input.is_open())
		return (std::cout << "Error opening database or input file" << std::endl, 0);

	myMap mapDatabase;
	try {
		readAndFillDB(mapDatabase, database);
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
		return 1;
	}
	processFile(input, mapDatabase);
}

void	readAndFillDB(myMap & mapDB, std::ifstream& file) {
	std::string	strDate;
	std::string	tmpDouble;
	int			i = 1;

	std::getline(file, strDate);
	if (strDate != "date,exchange_rate")
		throw std::invalid_argument("database wrongly formated");
	while (std::getline(file, strDate, ',') && std::getline(file, tmpDouble)) {
		i++;
		try {
			BitcoinExchange currDate(strDate);
		} catch (std::invalid_argument& e) {
			std::cout << e.what() << std::endl;
			continue;
		}
		const double value = getDouble(tmpDouble);
		if (value != value) {
			std::stringstream err;
			err << "invalid value detected at line ";
			err << i;
			throw std::invalid_argument(err.str());
		}
		mapDB.insert(std::make_pair(strDate, value));
	}
}

double	getDouble(const std::string& doubleStr) {
	for (int i=0; doubleStr[i]; ++i) {
		if (!isdigit(doubleStr[i]) && doubleStr[i] != '.')
			return NAN;
	}
	char	*check = NULL;
	double	rValue;
	rValue = std::strtod(doubleStr.c_str(), &check);
	if (*check == '\0')
		return rValue;
	return NAN;
}

void	processFile(std::ifstream &file, const myMap &map) {
	std::string tmp;
	char *check = NULL;

	std::getline(file, tmp);
	if (tmp != "date | value") {
		std::cout << "invalid input file" << std::endl;
		return;
	}

	std::string buff;
	std::getline(file, buff);
	while (!file.eof()) {
		if (buff.empty()) {
			std::cout << "Error: empty line"<< std::endl;
			std::getline(file, buff);
			continue;
		}

		std::string	currDate;
		std::stringstream	lineStream(buff);
		getline(lineStream, currDate, '|');
		if (*(currDate.end() - 1) == ' ') {
			currDate.resize(currDate.length() - 1);
		}
		if (lineStream.eof()){
			std::cout << "Error: invalid line => " + currDate << std::endl;
			std::getline(file, buff);
			continue;
		}
		try {
			BitcoinExchange test(currDate);
		} catch (std::exception &e) {
			std::cout << e.what() << ": " << currDate <<std::endl;
			std::getline(file, buff);
			continue;
		}
		getline(lineStream, tmp);
		float	currValue = std::strtof(tmp.c_str(), &check);
		if (*check != '\0') {
			std::cout << "Wrong data value =>" + tmp << std::endl;
			std::getline(file, buff);
			continue;
		}
		if (invalidDate(currDate, map) || invalidValue(currValue, tmp)) {
			std::getline(file, buff);
			continue;
		}
		processLine(map, currDate, currValue);
		std::getline(file, buff);
	}
}

void	processLine(const myMap &map, const std::string& date, const float &value) {
	myMap::const_iterator it = --(map.upper_bound(date));
	std::cout << date +" => " << value << " = " << value * it->second <<std::endl;
}
