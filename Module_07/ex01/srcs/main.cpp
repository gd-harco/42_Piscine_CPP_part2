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

int	incr(int i);
void printArray(int *array, int len);

int main(void) {
	int (*incFunc)(int);
	incFunc = incr;
	int array[8];
	for (int i=0; i<7; i++)
		array[i] = i+1;
	array[7] = 0;
	printArray(array, 8);
	iter(array, 8, incFunc);
	std::cout << "----------ITER----------" << std::endl;
	printArray(array, 8);
}

int	incr(int i){
	return i + 1;
}

void printArray(int *array, int len){
	for (int i=0; i<len; i++)
		std::cout << array[i] << std::endl;
}
