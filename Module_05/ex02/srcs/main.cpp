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
int main() {
	AForm *test[10];
	Bureaucrat Obelix("Obelix", 1);
	test[0] = new ShrubberyCreationForm("test");
	test[1] = new RobotomyRequestForm("to robotomise");
	try {
		Obelix.signForm(*test[0]);
		Obelix.executeForm(*test[0]);
		Obelix.signForm(*test[0]);
	}	catch (std::exception &e){
		std::cout << Obelix.getName() + "couldn't execute form because :" << e.what() <<std::endl;
	}

	delete test[0];
	return 0;
}
