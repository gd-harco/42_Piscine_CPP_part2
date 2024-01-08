//
// Created by Guillaume on 07/01/2024.
//

#ifndef RPN_HPP
#define RPN_HPP
#include <iostream>
#include <stack>

class RPN {
public:
	RPN();
	RPN(const RPN &obj);
	~RPN();
	RPN &operator=(const RPN &rhs);
	std::stack<int>	stack;
	void	calculate(std::stack<int> &pStack, const char & sign);
};

#endif //RPN_HPP
