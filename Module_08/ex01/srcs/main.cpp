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

#include "Span.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>

int main(){
	std::srand(std::time(NULL));
//testing small Span
	{
		Span smallSpan(5);
		try {
			smallSpan.addNumber(5);
			smallSpan.addNumber(10);
			smallSpan.addNumber(15);
			smallSpan.addNumber(20);
			smallSpan.addNumber(22);
			smallSpan.addNumber(23); //will throw an exception
		} catch (std::exception &e){
			std::cout << e.what() << std::endl;
		}
		std::cout << "Shortest Span in given data: " << smallSpan.shortestSpan() << std::endl;
		std::cout << "Longest Span in given data: " << smallSpan.longestSpan() << std::endl;
	}
//test on big Span
	{
		Span bigSpan(20000);
		std::vector<int> big(19999) ;
		std::generate(big.begin(), big.end(), std::rand);
		try {
			bigSpan.addRange(big.begin(), big.end()); //prove batch add on range iterator for std::vector
		} catch (std::exception &e){
			std::cout << e.what() << std::endl;
		}
		std::cout << "Shortest Span in given data: " << bigSpan.shortestSpan() << std::endl;
		std::cout << "Longest Span in given data: " << bigSpan.longestSpan() << std::endl;
	}
//proving that batchAdd also throw an exception
	{
		int array[20];
		Span tooSmall(10);
		std::generate(array, array + 20, std::rand);
		try {
			tooSmall.addRange(array, array + 20);
		} catch (std::exception &e) {
			std::cout << e.what() << std::endl;
		}
	}
}
