//
// Created by gd-harco on 11/25/23.
//

#include "header.hpp"

Intern::Intern() {
	std::cout << "Intern : Default Constructor Called" << std::endl;
}

Intern::Intern(const Intern &obj) {
	std::cout << "Intern : Copy Constructor Called" << std::endl;
	if (this != &obj)
		*this = obj;
}

Intern::~Intern() {
	std::cout << "Intern : Destructor Called" << std::endl;
}

Intern &Intern::operator=(const Intern &obj) {
	(void)obj;
	return *this;
}

AForm *Intern::makeShrub(const std::string &target) {
	return (new ShrubberyCreationForm(target));
}

AForm *Intern::makeRobo(const std::string &target) {
	return (new RobotomyRequestForm(target));
}

AForm *Intern::makePardon(const std::string &target) {
	return (new PresidentialPardonForm(target));
}

AForm *Intern::makeForm(const std::string& formName, const std::string &formTarget) {
	s_table table[3] = {
			{"robotomy request", &Intern::makeRobo},
			{"presidential pardon", &Intern::makePardon},
			{"shrubbery creation", &Intern::makeShrub}};
	for (int i=0; i < 3; i++){
		if (formName == table[i].expected)
			return (this->*table[i].call)(formTarget);
	}
	std::cout << RED << "no form to create" << RESET << std::endl;
	return NULL;
}
