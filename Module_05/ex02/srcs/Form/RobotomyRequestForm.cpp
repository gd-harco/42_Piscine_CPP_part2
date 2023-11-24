

#include "RobotomyRequestForm.hpp"
#include "header.hpp"
#include <cstdlib>
#include <ctime>

RobotomyRequestForm::RobotomyRequestForm()
	: AForm("Shrubbery", 72, 45), _target("undefined") {
	std::srand(std::time(0));
	std::cout << "RobotomyRequestForm : Default Constructor Called" << std::endl;}

RobotomyRequestForm::RobotomyRequestForm(const std::string& _target)
		: AForm("Shrubbery", 72, 45), _target(_target){
	std::srand(std::time(0));
	std::cout << "RobotomyRequestForm : Target Constructor Called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &obj)
		: AForm(obj), _target(obj._target){
	std::cout << "RobotomyRequestForm : Copy Constructor Called" << std::endl;
	if (this != &obj)
		*this = obj;
}

RobotomyRequestForm::~RobotomyRequestForm() {
	std::cout << "RobotomyRequestForm : Destructor Called" << std::endl;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &obj) {
	if (this != &obj)
		this->_target = obj._target;
	return *this ;
}

void RobotomyRequestForm::execute(const Bureaucrat &executor) const {
	this->isAllowed(executor);
	if (std::rand() % 2)
		std::cout << RED << "Robotomy failed" << RESET << std::endl;
	else
		std::cout << GREEN << "Bzzzzz... Bzzzz... Bzzzz\n" + this->_target + " has been Robotomized" << RESET << std::endl;
}
