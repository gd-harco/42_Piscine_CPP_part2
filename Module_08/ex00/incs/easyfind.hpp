//
// Created by Guillaume on 07/12/2023.
//

#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <iostream>
#include <algorithm>

template <typename T>
void	printElement(T elem){
	std::cout << elem << "\t";
}

template <typename T>
void	printContainer(const T& toPrint){
	std::cout << "Container content : \t";
	std::for_each(toPrint.begin(), toPrint.end(), printElement<typename T::value_type>);
	std::cout << std::endl;
}

template <typename T>
typename T::const_iterator	easyFind(const T &container, int toFind) {
	typename T::const_iterator begin = container.begin();
	typename T::const_iterator end = container.end();
	typename T::const_iterator found = std::find(begin, end, toFind);
	if (*found != toFind)
		throw std::exception();
	std::cout << "found " << toFind << " at position " << std::distance(begin, found) << std::endl;
	return (found);
}

template <typename T>
typename T::iterator	easyFind(T &container, int toFind) {
	typename T::iterator begin = container.begin();
	typename T::iterator end = container.end();
	typename T::iterator found = std::find(begin, end, toFind);
	if (*found != toFind)
		throw std::exception();
	std::cout << "found " << toFind << " at position " << std::distance(begin, found) << std::endl;
	return (found);
}

#endif //EASYFIND_HPP
