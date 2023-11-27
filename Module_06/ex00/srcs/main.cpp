/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gd-harco <gd-harco@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 17:15:11 by gd-harco          #+#    #+#             */
/*   Updated: 2023/11/10 15:01:26 by gd-harco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.hpp"

//TODO:handle -inff +inff
int main(int argc, char **argv) {
	if (argc != 2)
		return (std::cout << "usage: ./convert <std::string>litteral" << std::endl, 1);
	else
		ScalarConverter::convert(argv[1]);
	return 0;
}
