/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gd-harco <gd-harco@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 10:25:32 by gd-harco          #+#    #+#             */
/*   Updated: 2023/11/09 16:25:56 by gd-harco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
#define ARRAY_HPP

template <typename T>
class Array{
private:
	T*				_array;
	unsigned int	_size;
public:
	Array<T>() :
			_array(new T[0]),
			_size(0)
	{}

	Array<T>(const unsigned int len) :
			_array(new T[len]),
			_size(len) {
		for (unsigned int i=0; i < len; i++)
			_array[i] = T();
	}

	Array<T>(const Array<T> &old) {
		*this = old;
	}

	Array<T> &operator=(const Array<T> &rhs) {
		if (this == &rhs){
			return *this;
		}
		delete[] this->_array;
		_size = rhs._size;
		_array = new T[_size];
		T* limit = _array + _size;
		T* rhsIt = rhs._array;
		for (T* it = _array; it != limit; ++it) {
			*it = *rhsIt;
			++rhsIt;
		}
	}

};


#endif //ARRAY_HPP
