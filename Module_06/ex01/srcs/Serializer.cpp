//
// Created by gd-harco on 11/28/23.
//

#include "Serializer.hpp"


Serializer::Serializer() {
	std::cout << "Serializer : Default Constructor Called" << std::endl;
}

Serializer::Serializer(const Serializer &obj) {
	std::cout << "Serializer : Copy Constructor Called" << std::endl;
	if (this != &obj)
		*this = obj;
}

Serializer::~Serializer() {
	std::cout << "Serializer : Destructor Called" << std::endl;
}

Serializer &Serializer::operator=(const Serializer &obj) {
	(void)obj;
	return *this;
}

uintptr_t	Serializer::serialize(Data *ptr) {
	return reinterpret_cast<uintptr_t>(ptr);
}
Data		*Serializer::deserialize(uintptr_t raw) {
	return reinterpret_cast<Data *>(raw);
}
