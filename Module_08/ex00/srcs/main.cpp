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

/*
 * Write a function template easyfind that accepts a type T. It takes two parameters.
 * The first one has type T and the second one is an integer.
 * Assuming T is a container of integers, this function has to find the first occurrence
 * of the second parameter in the first parameter.
 * If no occurrence is found, you can either throw an exception or return an error value
 * of your choice. If you need some inspiration, analyze how standard containers behave.
 * Of course, implement and turn in your own tests to ensure everything works as expected.
 */

#include "easyfind.hpp"
#include <deque>


void	easyFind(std::deque<int> container, int toFind) {
	std::deque<int>::iterator found = std::find(container.begin(), container.end(), toFind);
	if (*found != toFind)
		throw std::exception();
	std::cout << "found " << toFind << " at position " << found - container.begin() << std::endl;
}

int main() {
	std::deque<int> deck;
	deck.push_back(5);
	deck.push_back(20);
	deck.push_back(30);
	deck.push_back(40);
	deck.push_back(20);
	deck.push_back(40);
	try
	{
	easyFind(deck, 50);
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << " - value toFind not in the given container" << std::endl;
	}
}
