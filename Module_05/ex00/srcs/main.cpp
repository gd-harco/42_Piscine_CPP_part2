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

#include "Bureaucrat.hpp"
int main() {
	Bureaucrat *good;
	Bureaucrat *tooLow;

	try {
		good = new Bureaucrat("good", 5);
		std::cout << *good << std::endl;
		tooLow = new Bureaucrat("bad", 175);
		good->incrementGrade();
		std::cout << good << std::endl;
		tooLow->decrementGrade();
	}
	catch (std::exception & e) {
		std::cout << "coucou Benoit " << e.what() << std::endl;
	}
	return 0;
}
