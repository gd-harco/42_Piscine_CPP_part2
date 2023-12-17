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

int main(/*int argc, char **argv*/) {
// 	if (argc != 2)
// 		return (std::cout << "ERROR: bad number of argument" << std::endl, 1);
	// static_cast<void>(argv);
	std::ifstream database("data.csv");
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
		const double value = std::atof(tmpDouble.c_str());
		if (value != value)
			throw std::invalid_argument("invalid value detected");
		mapDB.insert(std::make_pair(tmpStr, value));
	}
}
