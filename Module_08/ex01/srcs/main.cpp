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

//TODO: Add Number
//TODO: failure when span already full
//TODO: batch add number in span
//TODO: failure if the resulting span would be bigger than authorized
//TODO: test shortestPast
//TODO: test longestSpan;
//TODO: exception is empty span or of size 1;
//TODO: big span.
int main(){
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

	}
}
