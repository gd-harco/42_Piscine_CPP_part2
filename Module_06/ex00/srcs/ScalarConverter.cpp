
#include "ScalarConverter.hpp"
#include <cstdlib>
#include <iomanip>
#include <cmath>
#include <cctype>

ScalarConverter::ScalarConverter(){}

ScalarConverter::ScalarConverter(const ScalarConverter &obj) {
	*this = obj;
}

ScalarConverter::~ScalarConverter() {}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &obj) {
	(void)obj;
	return *this ;
}

static double	getDouble(const std::string &litteral) {
	char *end;

	double myDouble = std::strtod(litteral.c_str(), &end);
	if (*end != litteral[litteral.size()])
		myDouble = NAN;
	return myDouble;
}

void	ScalarConverter::convert(const std::string& litteral) {
	std::string		charConvert;

	const double doubleConvert = getDouble(litteral);
	if (std::isnan(doubleConvert))	{
		if (litteral.size() == 1 && std::isprint(litteral[0]))
			charConvert = litteral;
		else
			charConvert = "impossible";
	}
	else
		charConvert = static_cast<char>(doubleConvert);
	const float floatConvert = static_cast<float>(doubleConvert);
	const int intConvert = static_cast<int>(doubleConvert);
	if (!isprint(intConvert))
		charConvert = "impossible";
	std::cout << "char: " << charConvert << std::endl;
	if (std::isnan(doubleConvert))
		std::cout << "int: impossible" << std::endl;
	else
		std::cout << "int: " << intConvert << std::endl;
	std::cout << "float: " << std::fixed << std::setprecision(1) << floatConvert << "f\n"
	<< "double: " << doubleConvert << std::endl;
}
