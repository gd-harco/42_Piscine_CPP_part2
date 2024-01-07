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

typedef std::string::iterator itera;

bool	isInCharset(int c);

int main(int argc, char **argv) {
	if (argc != 2) {
		std::cout << "Error: invalid number of argument" << std::endl;
		return 1;
	}
	RPN	rpn;
	std::string	arg = argv[1];
	itera end = arg.end();
	for (itera	cur = arg.begin(); cur != end; ++cur) {
		if (std::isspace(*cur))
			continue;
		else if (std::isdigit(*cur)){
			int curInt = *cur - ASCII_OFFSET;
			rpn.stack.push(curInt);
		}
		else if (isInCharset(*cur)) {
			try {
				rpn.calculate(rpn.stack, *cur);
			}	catch (std::invalid_argument& e) {
				std::cout << "Error: " <<  e.what() << std::endl;
				return 1;
			}	catch (std::exception &e) {
				std::cout << "Error, probably too many sign and not enough value" << std::endl;
				return 1;
			}
		}
		else {
			std::cout << "Error, unrecognized token: " << *cur << std::endl;
			return 1;
		}
	}
	if (rpn.stack.empty()){
		std::cout << "Error: empty stack ?" << std::endl;
		return 1;
	}
	int result = rpn.stack.top();
	rpn.stack.pop();
	if (!rpn.stack.empty()){
		std::cout << "Error, probably not enough sign" << std::endl;
		return 1;
	}
	std::cout << result << std::endl;
	return 0;
}


bool	isInCharset(int c) {
	switch (c) {
		case '/':
		case '+':
		case '-':
		case '*':
			return true;
		default:
			return false;
	}
}
