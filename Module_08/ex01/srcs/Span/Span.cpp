//
// Created by Guillaume on 08/12/2023.
//

#include "Span.hpp"
#include "algorithm"

Span::Span()
		: _spanSize(0), _storage(new int[_spanSize]){}

Span::Span(unsigned int spanSize)
		: _spanSize(spanSize), _storage(new int[_spanSize]){}

Span::~Span() {
	delete[] _storage;
}

Span& Span::operator=(const Span& rhs) {
	if (this == &rhs)
		return *this;
	if (this->_spanSize != rhs._spanSize) {
		std::cout << "Can't assign a Span to another one with different span size" << std::endl;
		return *this;
	}
	std::copy(rhs._storage, rhs._storage + _spanSize, this->_storage);
	return *this;
}

Span::Span(const Span& old)
		: _spanSize(old._spanSize), _storage(new int[_spanSize]) {
	*this = old;
}
