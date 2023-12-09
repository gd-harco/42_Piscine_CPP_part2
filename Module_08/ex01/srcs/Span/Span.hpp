//
// Created by Guillaume on 08/12/2023.
//

#ifndef SPAN_HPP
#define SPAN_HPP

#include <vector>

class Span {
public:
	//Canonical
	Span();
	explicit Span(unsigned int spanSize);
	~Span();
	Span(const Span& old);
	Span &operator=(const Span &rhs);

	//Exception Subclass
	class SpanFullException : public std::exception {
	public :
		const char* what() const throw();
	};

	//Getter
	unsigned span_size() const;
	std::vector<int> storage() const;

	//Member Function
	void	addNumber(int n);
private:
	unsigned int		_spanSize;
	std::vector<int>	_storage;
};



#endif //SPAN_HPP
