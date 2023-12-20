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

#include <algorithm>
#include "header.hpp"

typedef std::string str;

void checkValidArg(std::vector<std::string>& vec, char **argList);

int main(int argc, char **argv) {
	std::vector<str> stringVec;
	if (argc == 1) {
		std::cout << "No integer sequence given" << std::endl;
		return 1;
	}
	checkValidArg(stringVec, &argv[1]);
	std::deque<int> deckContainer = fillDeck(&argv[1]);
	// std::vector<int> vectorContainer = fillVector(argv);
}

void checkValidArg(std::vector<std::string>& vec, char **argList) {
	for (int i=0; argList[i]; ++i) {
		str tmp(argList[i]);

	}
}
