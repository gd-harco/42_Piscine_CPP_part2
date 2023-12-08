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

#ifndef HEADER_HPP
#define HEADER_HPP

#include <iostream>
#include "template.hpp"

template <typename T>
void test(T& data1, T& data2){
	std::cout << "-----DATA BEFORE SWAP-----" << std::endl;
	std::cout << "data1 = " << data1 << ", data2 = " << data2 << std::endl;
	std::cout << "-----Calling Swap Template Function-----" << std::endl;
	swap(data1, data2);
	std::cout << "-----DATA AFTER SWAP-----" << std::endl;
	std::cout << "data1 = " << data1 << ", data2 = " << data2 << std::endl;
	std::cout << "min( data1, data2 ) = " << min(data1, data2) << std::endl;
	std::cout << "max( data1, data2 ) = " << max(data1, data2) << std::endl;
}

#endif //HEADER_HPP
