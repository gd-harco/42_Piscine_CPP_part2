//
// Created by Guillaume on 08/12/2023.
//

#include "Span.hpp"

Span::Span()
		: _spanSize(0), _storage(std::vector<int>()){}

Span::Span(unsigned int spanSize)
		: _spanSize(spanSize), _storage(std::vector<int>()){}

Span::~Span() {}

Span::Span(const Span& old){
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

std::vector<int> Span::storage() const {
	return _storage;
}

void Span::addNumber(int n) {
	if (this->_storage.size() == _spanSize)
		throw SpanFullException();
	_storage.push_back(n);
}

//void	Span::addRange( int *array, const unsigned int len) {
//	unsigned int	vectorSize = this->_storage.size();
//	if (len + vectorSize >= this->_spanSize)
//		throw SpanWillFullException();
//	int* end = array + len;
//	for (int* current = array; current != end; current++)
//		this->addNumber(*current);
//}

//unsigned int	Span::longestSpan() {
//	if (this->_storage.size() <= 1)
//		throw NoSpanToFindException();
//	int first = *_storage.begin();
//	int
//}
