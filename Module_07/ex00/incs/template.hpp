

#ifndef TEMPLATE_HPP
#define TEMPLATE_HPP

template <typename T>
void	swap(T &a, T &b){
	T c = a;
	a = b;
	b = c;
}

template <typename T>
T		min(T const &a, const T &b){
	return (a > b)? a: b;
}

template <typename T>
T	max(T const &a, T const  &b){
	return (a > b)? b: a;
}
#endif //TEMPLATE_HPP
