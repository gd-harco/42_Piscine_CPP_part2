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
double	getFloat(const std::string& doubleStr);
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
		if (!validDateFormat(tmpStr)){
			std::stringstream err;
			err << "invalid date detected at line ";
			err << i;
			throw std::invalid_argument(err.str());
		}
		const double value = getFloat(tmpDouble);
		if (value != value){
			std::stringstream err;
			err << "invalid value detected at line ";
			err << i;
			throw std::invalid_argument(err.str());
		}
		mapDB.insert(std::make_pair(tmpStr, value));
	}
}

double	getFloat(const std::string& doubleStr) {
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
		std::stringstream	lineStream(buff);
		getline(lineStream, currDate, '|');
		if (*(currDate.end() - 1) == ' ')
			currDate.resize(currDate.length() - 1);
		if (lineStream.eof()){
			std::cout << "Error: invalid line => " + currDate << std::endl;
			std::getline(file, buff);
			continue;
		}
		getline(lineStream, tmp);
		float		currValue = std::atof(tmp.c_str());
		if (invalidDate(currDate, map) || invalidValue(currValue, tmp)){
			std::getline(file, buff);
			continue;
		}
		processLine(map, currDate, currValue);
		std::getline(file, buff);
	}
}

void	processLine(const myMap &map, const std::string& date, const float &value){
	myMap::const_iterator it = --(map.upper_bound(date));
	std::cout << date +" => " << value << " = " << value * it->second <<std::endl;
}
