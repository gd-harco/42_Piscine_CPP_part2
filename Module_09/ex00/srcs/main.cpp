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

void	readAndFillDB(std::map<std::string, double>& mapDB, std::ifstream& file);
bool	validDate(const std::string& date);
double	getDouble(const std::string& doubleStr);

int main(int argc, char **argv) {
 	if (argc != 2)
 		return (std::cout << "ERROR: bad number of argument" << std::endl, 1);
	std::ifstream database("data.csv");
	std::ifstream input(argv[1]);
	if (!database.is_open() || !input.is_open())
		return (std::cout << "Error opening database or input file" << std::endl, 0);
	std::map<std::string, double> mapDatabase;
	try {
		readAndFillDB(mapDatabase, database);
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
		return 1;
	}
}

void	readAndFillDB(std::map<std::string, double>& mapDB, std::ifstream& file) {
	std::string tmpStr;
	std::string tmpDouble;

	std::getline(file, tmpStr);
	if (tmpStr != "date,exchange_rate") {
		throw std::invalid_argument("database wrongly formated");
	}
	while (std::getline(file, tmpStr, ',') && std::getline(file, tmpDouble)) {
		if (!validDate(tmpStr))
			throw std::invalid_argument("invalid date detected");
		const double value = getDouble(tmpDouble);
		if (value != value)
			throw std::invalid_argument("invalid value detected");
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
