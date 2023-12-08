//
// Created by Guillaume on 08/12/2023.
//

#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <vector>

class Span {
public:
	Span();
	explicit Span(unsigned int spanSize);
	~Span();
	Span &operator=(const Span &rhs);

	Span(const Span& old);
private:
	unsigned int		_spanSize;
	std::vector<int>	_storage;
};



#endif //SPAN_HPP
