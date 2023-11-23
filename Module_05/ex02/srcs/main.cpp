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
		// Create a Bureaucrat object named 'Good' with the name 'Asterix' and an initial grade of 75
		Bureaucrat	Good("Asterix", 75);
		// Create another Bureaucrat object named 'Bad' with the name 'Obelix' and an initial grade of 150
		Bureaucrat	Bad("Obelix", 150);
		// Print details of 'Good' and 'Bad' to the console
		std::cout << Good << std::endl;
		std::cout << Bad << std::endl;
		// Create a Form object named 'HighLevel' with minimum grade 80 for signing and execution
		Form		HighLevel("A38", 80, 80);
		// Create another Form object named 'LowLevel' with minimum grade 149 for signing and execution
		Form		LowLevel("B40", 149,149);
		// Print details of 'HighLevel' and 'LowLevel' to the console
		std::cout << HighLevel << std::endl;
		std::cout << LowLevel << std::endl;

		// Handle exception arises from attempts to sign 'HighLevel' form by 'Good' and 'Bad'
		try {
			// 'Good' attempts to sign 'HighLevel' form
			Good.signForm(HighLevel);
			// 'Bad' attempts to sign 'HighLevel' form
			Bad.signForm(HighLevel);
		} catch (std::exception &e){
			// Print out the error message
			std::cout << e.what() <<std::endl;
		}

		// Handle exception arising from exceptions to sign 'LowLevel' form by 'Bad'
		try {
			// 'Bad' attempts to sign 'LowLevel' form
			Bad.signForm(LowLevel);
		} catch (std::exception &e) {
			// Print out the error message
			std::cout <<e.what() << std::endl;
		}
		// Handle exception arising from an attempt to increment grade of 'Bad' and signing 'LowLevel' form
		try {
			// Increment the grade of 'Bad'
			Bad.incrementGrade();
			// Print out updated details of 'Bad'
			std::cout << Bad << std::endl;
			// 'Bad' attempts to sign 'LowLevel' form
			Bad.signForm(LowLevel);
		} catch (std::exception &e) {
			// Print out the error message
			std::cout << e.what() << std::endl;
		}
	}
	// Program termination with return code 0
	return 0;
}
