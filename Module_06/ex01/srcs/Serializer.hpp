#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include <iostream>
#include <stdint.h>
#include "header.hpp"

class Serializer {
public:
	~Serializer();
	static uintptr_t	serialize(Data *ptr);
	static Data			*deserialize(uintptr_t raw);
private:
	Serializer(Serializer const &obj);
	Serializer();
	Serializer &operator=(const Serializer &obj);
};


#endif //SERIALIZER_HPP
