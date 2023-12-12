//
// Created by Guillaume on 08/12/2023.
//

#ifndef SPAN_HPP
#define SPAN_HPP

#include <vector>
#include <algorithm>
#include <stdexcept>

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
	unsigned int	longestSpan();
	unsigned int	shortestSpan();

	template<typename T>
	void			addRange(T begin, T end){
		if (std::distance(begin, end) + this->storage().size() >= this->_spanSize)
			throw SpanWillFullException();
		this->_storage.insert(this->_storage.end(), begin, end);
	}
private:
	unsigned int		_spanSize;
	std::vector<int>	_storage;
};



#endif //SPAN_HPP
