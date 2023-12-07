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

#ifndef ITER_HPP
#define ITER_HPP

template <typename T, typename U, typename V>
void	iter(T *array, U len, V (*f)(T&)) {
	for (U i=0; i<len; ++i)
		f(array[i]);
}

template <typename T, typename U, typename V>
void	iter(const T *array, U len, V (*f)(const T&)) {
	for (U i=0; i<len; ++i)
		f(array[i]);
}

#endif //ITER_HPP
