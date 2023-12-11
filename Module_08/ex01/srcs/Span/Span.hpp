//
// Created by Guillaume on 08/12/2023.
//

#ifndef SPAN_HPP
#define SPAN_HPP

#include <vector>
#include <algorithm>

int ret(int a);

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

	class SpanWillFullException : public std::exception {
	public :
		const char* what() const throw();
	};

	class NoSpanToFindException : public std::exception {
	public :
		const char* what() const throw();
	};

	//Getter
	unsigned span_size() const;
	std::vector<int> storage() const;

	//Member Function
	void			addNumber(int n);
	void			addRange(int* array, unsigned int len);
	unsigned int	longestSpan();
private:
	unsigned int		_spanSize;
	std::vector<int>	_storage;
};



#endif //SPAN_HPP
