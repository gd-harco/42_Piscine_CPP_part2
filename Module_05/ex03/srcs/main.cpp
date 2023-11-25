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

#define PRES "presidential pardon"
#define SHRUB "shrubbery creation"
#define ROBO "robotomy request"

int main() {
	Intern gaston;
	Bureaucrat fantasio("Fantasio", 1);

	AForm *formList[10] = {NULL};
	formList[0] = gaston.makeForm(PRES, "Dupont de Ligonnes");
	formList[1] = gaston.makeForm(SHRUB, "The Garden of Eden");
	formList[2] = gaston.makeForm(ROBO, "Hal 9000");

	fantasio.signForm(*formList[0]);
	fantasio.executeForm(*formList[0]);

	fantasio.signForm(*formList[1]);
	fantasio.executeForm(*formList[1]);

	fantasio.signForm(*formList[2]);
	fantasio.executeForm(*formList[2]);

	// Test a scenario where the bureaucrat doesn't have enough grade to execute the form
	Bureaucrat prunelle("Prunelle", 70);

	prunelle.signForm(*formList[0]);
	prunelle.executeForm(*formList[0]);

	for (int i=0; formList[i]; i++)
		delete formList[i];
}
