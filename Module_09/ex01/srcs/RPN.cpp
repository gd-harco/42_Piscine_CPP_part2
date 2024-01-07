//
// Created by Guillaume on 07/01/2024.
//

#include "RPN.hpp"
RPN::RPN() {
	std::cout << "RPN : Default Constructor Called" << std::endl;
}

RPN::RPN(const RPN &obj) {
	std::cout << "RPN : Copy Constructor Called" << std::endl;
	if (this != &obj)
		*this = obj;
}

RPN::~RPN() {
	std::cout << "RPN : Destructor Called" << std::endl;
}

RPN &RPN::operator=(const RPN &rhs) {
	if (this != &rhs) {
		//copy code goes here
	}
	return *this ;
}
