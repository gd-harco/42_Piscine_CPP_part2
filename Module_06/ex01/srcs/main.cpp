/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gd-harco <gd-harco@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 17:15:11 by gd-harco          #+#    #+#             */
/*   Updated: 2023/11/10 15:01:26 by gd-harco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.hpp"
#include "Serializer.hpp"

void	printData(Data *ptr){
	std::cout << "name: " + ptr->name << "\nage: " << ptr->age << std::endl;
	std::cout << "gender: ";
	switch (ptr->gender) {
		case male: std::cout << "male" << std::endl; break;
		case female: std::cout << "female" << std::endl; break;
	}
	std::cout << std::boolalpha << "is major: " << ptr->isMajor <<std::endl;
}

int main() {
	Data		*myData = new Data;
	uintptr_t	uintptr;

	myData->name = "Asterix";
	myData->age = 17;
	myData->isMajor = false;
	myData->gender = male;
	printData(myData);
	std::cout << "---------Serialize---------" <<std::endl;
	uintptr = Serializer::serialize(myData);
	std::cout << uintptr << std::endl;
	std::cout << "---------deSerialize---------" <<std::endl;
	printData(Serializer::deserialize(uintptr));
	delete myData;
}
