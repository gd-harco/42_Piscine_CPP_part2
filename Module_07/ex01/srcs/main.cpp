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

#include "iter.hpp"
#include <string>
#include <iostream>

void	print(const int& element);
int		printPostCast(const int&element);
void	addOne(int& element);

//create an array of 10 int, called iter 2 with 2 const function
//Then called iter with a non-const function to add 1
//then recalled the 2 first function.
int		main() {
	int array[10] = {64, 65, 66, 67, 68, 69, 70, 71, 72, 73};
	std::cout << "----------PRINT ARRAY----------" << std::endl;
	iter<int, int, void>(array, 10, &print);
	std::cout << "----------PRINT CASTED ARRAY----------" << std::endl;
	iter<int, size_t, int>(array, 10, &printPostCast);
	std::cout << "----------CALLED ADD ONE FUNC----------" << std::endl;
	iter<int, int, void>(array, 10, addOne);
	std::cout << "----------PRINT ARRAY----------" << std::endl;
	iter<int, int, void>(array, 10, &print);
	std::cout << "----------PRINT CASTED ARRAY----------" << std::endl;
	iter<int, size_t, int>(array, 10, &printPostCast);
}

void	print(const int& element){
	std::cout << element << std::endl;
}

int		printPostCast(const int& element) {
	std::cout << static_cast<char>(element) << std::endl;
	return 15;
}

void	addOne(int& element) {
	element = element + 1;
}
