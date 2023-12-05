

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
	return (a > b)? b: a;
}

template <typename T>
T	max(T const &a, T const  &b){
	return (a > b)? a: b;
}
#endif //TEMPLATE_HPP
