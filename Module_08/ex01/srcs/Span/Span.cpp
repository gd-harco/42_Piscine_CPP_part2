//
// Created by Guillaume on 08/12/2023.
//

#include "Span.hpp"

Span::Span()
		: _spanSize(0), _storage(std::vector<int>(0)){}

Span::Span(unsigned int spanSize)
		: _spanSize(spanSize), _storage(std::vector<int>(_spanSize)){}

Span::~Span() {}

Span& Span::operator=(const Span& rhs) {
	if (this == &rhs)
		return *this;
	this->_spanSize = rhs._spanSize;
	this->_storage = rhs._storage;
	return *this;
}

Span::Span(const Span& old) {
	*this = old;
}
