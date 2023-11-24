

#include "PresidentialPardonForm.hpp"
#include "header.hpp"
#include <cstdlib>
#include <ctime>

PresidentialPardonForm::PresidentialPardonForm()
	: AForm("Shrubbery", 25, 5), _target("undefined") {
	std::srand(std::time(0));
	std::cout << "PresidentialPardonForm : Default Constructor Called" << std::endl;}

PresidentialPardonForm::PresidentialPardonForm(const std::string& _target)
		: AForm("Shrubbery", 25, 5), _target(_target){
	std::srand(std::time(0));
	std::cout << "PresidentialPardonForm : Target Constructor Called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &obj)
		: AForm(obj), _target(obj._target){
	std::cout << "PresidentialPardonForm : Copy Constructor Called" << std::endl;
	if (this != &obj)
		*this = obj;
}

PresidentialPardonForm::~PresidentialPardonForm() {
	std::cout << "PresidentialPardonForm : Destructor Called" << std::endl;
}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &obj) {
	if (this != &obj)
		this->_target = obj._target;
	return *this ;
}

void PresidentialPardonForm::execute(const Bureaucrat &executor) {
	this->isAllowed(executor);
	std::cout << GREEN << this->_target + " has been pardoned by Zaphod Beeblebrox" << RESET << std::endl;
}
