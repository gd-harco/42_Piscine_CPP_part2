//
// Created by Guillaume on 08/12/2023.
//

#include "Span.hpp"

Span::Span()
		: _spanSize(0), _storage(std::multiset<int>()){}

Span::Span(unsigned int spanSize)
		: _spanSize(spanSize), _storage(std::multiset<int>()){}

Span::~Span() {}

Span::Span(const Span& old) {
	*this = old;
}

Span& Span::operator=(const Span& rhs) {
	if (this == &rhs)
		return *this;
	this->_spanSize = rhs._spanSize;
	this->_storage = rhs._storage;
	return *this;
}

const char* Span::SpanFullException::what() const throw() {
	return "Span Already Full";
}

const char* Span::NoSpanToFindException::what() const throw() {
	return "No Span to be found here";
}


unsigned Span::span_size() const {
	return _spanSize;
}

std::multiset<int> Span::storage() const {
	return _storage;
}

void Span::addNumber(int n) {
	if (this->_storage.size() == _spanSize)
		throw SpanFullException();
	_storage.insert(n);
}
