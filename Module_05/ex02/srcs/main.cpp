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
	AForm *test;
	Bureaucrat Obelix("Obelix", 1);
	test = new ShrubberyCreationForm("test");

	try {
		test->execute(Obelix);

	}	catch (std::exception &e){
		std::cout << Obelix.getName() + "couldn't execute form because :" << e.what() <<std::endl;
	}

	delete test;
	return 0;
}
