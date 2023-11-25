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

/*
 * Shrubbery, 145, 137
 * Robotomy Request, 72, 45
 * PresidentialPardon, 25, 5
 */
int main() {
	// Create an array of pointers to AForm objects.
	// Set all pointers to NULL.
	AForm* test[10] = {NULL};

	// Create two Bureaucrat objects named Obelix and Asterix.
	Bureaucrat obelix("Obelix", 1);
	Bureaucrat asterix("asterix", 138);

	// Allocate memory for three AForm objects and assign their addresses
	// to the first three positions in the test array.
	test[0] = new ShrubberyCreationForm("test");
	test[1] = new RobotomyRequestForm("to robotomise");
	test[2] = new PresidentialPardonForm("Dupont de Ligones");

	// Create references to the three AForm objects for easier access.
	AForm &tree = *test[0];
	AForm &roboto = *test[1];
	AForm &pardon = *test[2];

	// Asterix will try to signs and executes the 'tree' form.
	// Obelix executes the 'tree' form.
	// Obelix signs 'roboto' and 'pardon' forms.
	// No need to catch exceptions here, they
	// are handled in the Bureaucrat class.
	asterix.signForm(tree);
	asterix.executeForm(tree);
	obelix.executeForm(tree);
	obelix.signForm(roboto);
	obelix.signForm(pardon);

	// Obelix executes 'roboto' form five times
	// to prove the randomness of the execution.
	for (int i = 0; i < 5; i++)
		obelix.executeForm(roboto);

	// Obelix signs the 'pardon' form.
	// It should fail because it is already signed.
	obelix.signForm(pardon);

	// Deallocate memory from all AForm
	// objects that were created on the heap.
	for (int i = 0;  test[i]; i++)
		delete test[i];
	return 0;
}
