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
int main() {
	{
		Bureaucrat *good = NULL;
		Bureaucrat *tooLow = NULL;

		try {
			good = new Bureaucrat("good", 5);
			std::cout << *good << std::endl;
			tooLow = new Bureaucrat("bad", 175);
			good->incrementGrade();
			std::cout << good << std::endl;
			tooLow->decrementGrade();
		} catch (std::exception &e) {
			std::cout << RED << EXC_CAUGHT << e.what() << RESET << std::endl;
		}
		std::cout << "Incrementing Bureaucrat\"good\"" << std::endl;
		good->incrementGrade();
		std::cout << *good << std::endl;
		std::cout << "decrementing Bureaucrat\"good\"" << std::endl;
		good->decrementGrade();
		std::cout << *good << std::endl;
		delete good;
	}
	{
		Bureaucrat *level1 = new Bureaucrat("level one", 1);
		Bureaucrat &level1Ref = *level1;
		std::cout << level1Ref << std::endl;
		try {
			level1Ref.decrementGrade();
			std::cout << level1Ref << std::endl;
			level1Ref.incrementGrade();
			std::cout << level1Ref << std::endl;
			level1Ref.incrementGrade();
			std::cout << level1Ref << std::endl;
		}
		catch (std::exception & e) {
			std::cout << RED << EXC_CAUGHT << e.what() << RESET << std::endl;
		}
		delete (level1);
	}
	return 0;
}
