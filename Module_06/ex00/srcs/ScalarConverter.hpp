//
// Created by gd-harco on 11/27/23.
//


#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP
#include <iostream>
#include <string>

class ScalarConverter {
public:
	~ScalarConverter();
	static void convert(const std::string& litteral);
class NAN : public std::exception {};
private:
		ScalarConverter();
		ScalarConverter(ScalarConverter const &obj);
		ScalarConverter &operator= (const ScalarConverter &obj);
};



#endif //SCALARCONVERTER_HPP
