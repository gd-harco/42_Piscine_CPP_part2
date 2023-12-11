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

const char* Span::SpanWillFullException::what() const throw() {
	return "Span would be greater than authorised";
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

void Span::addRange(const int *array) {
	unsigned int	arraySize = sizeof(array);
	unsigned int	setSize = this->_storage.size();
	if (arraySize + setSize >= this->_spanSize)
		throw	SpanWillFullException();
	storage().insert(array, array + arraySize);
}
