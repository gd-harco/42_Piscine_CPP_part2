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
#include "Bureaucrat.hpp"
#include "Form.hpp"
int main() {
	{
		Bureaucrat	Good("Asterix", 75);
		Bureaucrat	Bad("Obelix", 150);
		std::cout << Good << std::endl;
		std::cout << Bad << std::endl;
		Form		HighLevel("A38", 80, 80);
		Form		LowLevel("B40", 149,149);
		std::cout << HighLevel << std::endl;
		std::cout << LowLevel << std::endl;

		try {
			Good.signForm(HighLevel);
			Bad.signForm(HighLevel);
		} catch (std::exception &e){
			std::cout << e.what() <<std::endl;
		}
		try {
			Bad.signForm(LowLevel);
		} catch (std::exception &e) {
			std::cout <<e.what() << std::endl;
		}
		try {
			Bad.incrementGrade();
			std::cout << Bad << std::endl;
			Bad.signForm(LowLevel);
		} catch (std::exception &e) {
			std::cout << e.what() << std::endl;
		}
	}
	return 0;
}
