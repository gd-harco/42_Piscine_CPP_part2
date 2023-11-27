
#include "ScalarConverter.hpp"
#include <cstdlib>
#include <iomanip>

ScalarConverter::ScalarConverter(){
	std::cout << "ScalarConverter : Default Constructor Called" << std::endl;
}
ScalarConverter::ScalarConverter(const ScalarConverter &obj) {
	std::cout << "ScalarConverter : Copy Constructor Called" << std::endl;
	if (this != &obj)
		*this = obj;
}

ScalarConverter::~ScalarConverter() {
	std::cout << "ScalarConverter : Destructor Called" << std::endl;
}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &obj) {
	(void)obj;
	return *this ;
}

static bool	ft_isprint(int c)
{
	if ((c >= 32 && c < 127))
		return (true);
	return (false);
}

static float	getFloat(const std::string &litteral) {
	char *end;
	float myFloat;
	myFloat = std::strtof(litteral.c_str(), &end);
	if (end == litteral.c_str() || myFloat != myFloat)
		throw ScalarConverter::NAN();
	return(myFloat);
}

static void	NanHandling(){
	std::cout << "char: impossible\n"
			<< "int: impossible\n"
			<< "float: nanf\n"
			<< "double: nan" <<std::endl;
}

void	ScalarConverter::convert(const std::string& litteral) {
	std::string		charConvert;
	int				intConvert;
	float			floatConvert;
	double			doubleConvert;

	try {
		floatConvert = getFloat(litteral);
	} catch (ScalarConverter::NAN &e){
		return NanHandling();
	}
//	doubleConvert = std::strtod(litteral.c_str(), NULL);
	doubleConvert = static_cast<double>(floatConvert);
	intConvert	= static_cast<int>(doubleConvert);

	if (!ft_isprint(intConvert))
		charConvert = "Non Printable";
	else
		charConvert = static_cast<char>(doubleConvert);
	std::cout << "char: " << charConvert << "\n"
	<< "int: " << intConvert << "\n"
	<< "float: " << std::fixed << std::setprecision(1) << floatConvert << "f\n"
	<< "double: " << doubleConvert << std::endl;
}
