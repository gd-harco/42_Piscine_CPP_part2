/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gd-harco <gd-harco@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 17:15:11 by gd-harco          #+#    #+#             */
/*   Updated: 2023/11/29 16:32:22 by gd-harco         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "header.hpp"

void				setSeed();
Base				*generate();
static std::string	getInput();
void				identify(Base* p);
void				identify(Base& p);

int main() {
	setSeed();

	std::string		input;
	int				temp;

	std::cout << "number of test to Generate?" << std::endl;
	temp = std::atoi(getInput().c_str());
	while (temp <= 0) {
		std::cout << "Please enter a positive value" << std::endl;
		temp = std::atoi(getInput().c_str());
	}

	//generate the array of class
	Base *testArray[temp];
	for (int i=0; i<temp; i++)
		testArray[i] = generate();
	//Execute both identify function on every member of the array;
	for (int i=0; i<temp; i++){
		identify(testArray[i]);
		identify(*testArray[i]);
	}
	//Properly free the array.
	for (int i=0; i<temp; i++)
		delete testArray[i];
}

void setSeed() {
	const std::time_t time = std::time(0);
	std::tm *tm = std::localtime(&time);
	std::srand((tm->tm_hour + tm->tm_mon) / (tm->tm_sec + 1));
}

Base *generate() {
	switch (std::rand() % 3)
	{
		case(1): return new B;
		case(2): return new C;
		default: return new A;
	}
	return (NULL);
}

static std::string	getInput() {
	std::string input;

	std::getline(std::cin, input);
	if (!std::cin)
	{
		std::cout << "STOP CLOSIN CIN YOU IDIOT!" << std::endl;
		exit (1);
	}
	return (input);
}

void	identify(Base* p) {
	const A *ATest = dynamic_cast<A*>(p);
	const B *BTest = dynamic_cast<B*>(p);
	const C *CTest = dynamic_cast<C*>(p);

	if (ATest)
		std::cout << "Pointer to " << p << " is of type A" << std::endl;
	else if (BTest)
		std::cout << "Pointer to " << p << " is of type B" << std::endl;
	else if (CTest)
		std::cout << "Pointer to " << p << " is of type C" << std::endl;
	else
		std::cout << "Strange Situation" << std::endl;
}

void	identify(Base& p) {
	try {
		static_cast<void>(dynamic_cast<A&>(p));
		std::cout << "Ref to " << &p << " is of type A" << std::endl;
		return;
	} catch (std::exception &a) {}
	try {
		static_cast<void>(dynamic_cast<B&>(p));
		std::cout << "Ref to " << &p << " is of type B" << std::endl;
		return;
	} catch (std::exception &b){}
	try {
		static_cast<void>(dynamic_cast<C&>(p));
		std::cout << "Ref to " << &p << " is of type C" << std::endl;
	} catch (std::exception &c) {
		std::cout << "Strange Situation" << std::endl;
	}
}
