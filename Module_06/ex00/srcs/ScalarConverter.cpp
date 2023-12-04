
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

static void handlNan(const std::string &litteral, std::string &charConvert, const double doubleConvert) {
	if (litteral.size() == 1 && isprint(litteral[0]))
		charConvert = litteral;
	else
		charConvert = "impossible";
	const float floatConvert = static_cast<float>(doubleConvert);
	std::cout << "char: " << charConvert << std::endl;
	std::cout << "int: impossible" << std::endl;
	std::cout << "float: " << std::fixed << std::setprecision(1) << floatConvert << "f\n"
			<< "double: " << doubleConvert << std::endl;
}

void	ScalarConverter::convert(const std::string& litteral) {
	std::string		charConvert;

	const double doubleConvert = getDouble(litteral);
	if (std::isnan(doubleConvert) || std::isinf(doubleConvert))
		return handlNan(litteral, charConvert, doubleConvert);
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
