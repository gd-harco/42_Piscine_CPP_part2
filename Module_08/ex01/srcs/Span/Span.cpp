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

const char *Span::SpanFullException::what() const throw() {
	return "can't add number, Data Structure is already full";
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


unsigned int	Span::longestSpan() {
	if (this->_storage.size() <= 1)
		throw NoSpanToFindException();
	std::sort(this->_storage.begin(), this->_storage.end());
	return this->_storage.back() - this->_storage.front();
}

unsigned int	Span::shortestSpan() {
	if (this->_storage.size() <= 1)
		throw NoSpanToFindException();
	std::sort(this->_storage.begin(), this->_storage.end());
	std::vector<int>::iterator current = this->_storage.begin();
	std::vector<int>::iterator next = this->_storage.begin();
	std::advance(next, 1);
	unsigned int shortest = *next - *current ;
	while (next != this->_storage.end()){
		unsigned int currentSpan = *next - *current;
		if (currentSpan < shortest)
			shortest = currentSpan;
		current = next;
		std::advance(next, 1);
	}
	return (shortest);
}
