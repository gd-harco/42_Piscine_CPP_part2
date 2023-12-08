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

int main() {
	int a[] = { 5, 6, 1, 10, 2, 10};

	//test on deque with const container
	{
		const std::deque<int> dequeCont(a, a + 6);
		printContainer(dequeCont);
		try {
			easyFind(dequeCont, 5);
		}
		catch (std::exception &e) {
			std::cout << e.what() << " - value toFind not in the given container" << std::endl;
		}
	}
	std::cout << SEPARATOR << std::endl;
	//test on vector, try to modify iterators pointed value
	{
		std::vector<int> vectorCont(a, a + 6);
		printContainer(vectorCont);
		try {
			*easyFind(vectorCont, 6) = 5;
		}
		catch (std::exception &e) {
			std::cout << e.what() << " - value toFind not in the given container" << std::endl;
		}
		printContainer(vectorCont);
	}
	std::cout << SEPARATOR << std::endl;
	//test on list
	{
		std::list<int> listCont(a, a + 6);
		printContainer(listCont);
		try {
			easyFind(listCont, 10);
		}
		catch (std::exception &e) {
			std::cout << e.what() << " - value toFind not in the given container" << std::endl;
		}
	}
}
