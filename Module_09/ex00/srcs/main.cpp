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

#include <iostream>
#include <string>
#include <cstdlib>
#include <fstream>
#include <map>
#include <cmath>
#include <sstream>
#include <algorithm>

typedef std::map<std::string, double> myMap;

void	readAndFillDB(myMap & mapDB, std::ifstream& file);
bool	validDate(const std::string& date);
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
	std::string	tmpStr;
	std::string	tmpDouble;
	int			i = 1;
	std::getline(file, tmpStr);
	if (tmpStr != "date,exchange_rate") {
		throw std::invalid_argument("database wrongly formated");
	}
	while (std::getline(file, tmpStr, ',') && std::getline(file, tmpDouble)) {
		i++;
		if (!validDate(tmpStr)){
			std::stringstream err;
			err << "invalid date detected at line ";
			err << i;
			throw std::invalid_argument(err.str());
		}
		const double value = getDouble(tmpDouble);
		if (value != value){
			std::stringstream err;
			err << "invalid value detected at line ";
			err << i;
			throw std::invalid_argument(err.str());
		}
		mapDB.insert(std::make_pair(tmpStr, value));
	}
}

bool validDate(const std::string& date) {
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

double	getDouble(const std::string& doubleStr) {
	for (int i=0; doubleStr[i]; ++i) {
		if (!isdigit(doubleStr[i]) && doubleStr[i] != '.')
			return NAN;
	}
	return std::atof(doubleStr.c_str());
}

void	processFile(std::ifstream &file, const myMap &map) {
	std::string tmp;
	std::getline(file, tmp);
	if (tmp != "date | value") {
		std::cout << "invalid input file" << std::endl;
		return;
	}
	std::string buff;
	std::getline(file, buff);
	while (!buff.empty()){
		std::string	currDate;
		std::string	currValue;
		std::stringstream	lineStream(buff);
		getline(lineStream, currDate, '|');
		if (lineStream.eof()){
			std::cout << "Error: invalid line : " + currDate << std::endl;
			std::getline(file, buff);
			continue;
		}
		getline(lineStream, currValue);
		myMap::const_iterator	iterator = map.upper_bound(currDate);
		--iterator;
		std::cout << iterator->first << std::endl;
		std::getline(file, buff);
	}
}