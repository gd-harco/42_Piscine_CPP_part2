//
// Created by Guillaume on 07/01/2024.
//

#include "RPN.hpp"

RPN::RPN() {
}

RPN::RPN(const RPN &obj) {
	if (this != &obj)
		*this = obj;
}

RPN::~RPN() {
}

RPN &RPN::operator=(const RPN &rhs) {
	if (this != &rhs) {
		this->stack = rhs.stack;
	}
	return *this ;
}

void	RPN::calculate(std::stack<int> &pStack, const char & sign) {
	if (pStack.empty())
		throw std::exception();
	int second = pStack.top();
	pStack.pop();
	if (pStack.empty())
		throw std::exception();
	int first = pStack.top();
	pStack.pop();
	switch (sign) {
		case '+':
			pStack.push(first + second);
			return;
		case '-':
			pStack.push(first - second);
			return;
		case '*':
			pStack.push(first * second);
			return;
		case '/':
			if (second == 0)
				throw std::invalid_argument("Division by 0");
			pStack.push(first / second);
			return;
	}
}
