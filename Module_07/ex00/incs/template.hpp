

#ifndef TEMPLATE_HPP
#define TEMPLATE_HPP

//swap: Swaps the values of two given arguments. Does not return anything.
//• min: Compares the two values passed in its arguments and returns the smallest
//		one. If the two of them are equal, then it returns the second one.
//• max: Compares the two values passed in its arguments and returns the greatest one.
//If the two of them are equal, then it returns the second one.
//These functions can be called with any type of argument. The only requirement is
//that the two arguments must have the same type and must support all the comparison
//operators.

template <class T>
void	swap(T &a, T &b){
	T c = a;
	a = b;
	b = c;
}

template <class T>
T		min(T a, T b){
	return (a > b)? a: b;
}

template <class T> T max(T a, T b){
	return (a > b)? b: a;
}
#endif //TEMPLATE_HPP
