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
	std::stack<int> stack;
	std::string	arg = argv[1];
	itera end = arg.end();
	for (itera	cur = arg.begin(); cur != end; ++cur) {
		if (std::isspace(*cur))
			continue;
		else if (std::isdigit(*cur)){
			int curInt = *cur - '0';
			stack.push(curInt);
		}
		else if (isInCharset(*cur))
			std::cout << "TODO" << std::endl;
		else {
			std::cout << "Error" <<std::endl;
			return 1;
		}
	}
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

void	calculate(std::stack<int> &stack, const char & sign) {

}
