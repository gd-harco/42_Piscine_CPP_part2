//
// Created by gd-harco on 11/24/23.
//

#include "ShrubberyCreationForm.hpp"
#include "header.hpp"

ShrubberyCreationForm::ShrubberyCreationForm()
	: AForm("Shrubbery", 145, 137), _target("undefined") {}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& _target)
		: AForm("Shrubbery", 145, 137), _target(_target){
	std::cout << "ShrubberyCreationForm : Target Constructor Called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &obj)
		: AForm(obj), _target(obj._target){
	std::cout << "ShrubberyCreationForm : Copy Constructor Called" << std::endl;
	if (this != &obj)
		*this = obj;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {
	std::cout << "ShrubberyCreationForm : Destructor Called" << std::endl;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &obj) {
	if (this != &obj)
		this->_target = obj._target;
	return *this ;
}

void ShrubberyCreationForm::execute(const Bureaucrat &executor) {
	if (!this->isAllowed(executor))
		throw Bureaucrat::GradeTooLowException();
	else {
		std::string fileToOpen = this->_target + "_shrubbery";
		this->_fileToWrite.open(fileToOpen.c_str());
		if (!this->_fileToWrite)
			throw FileUnavailableException();
		this->_fileToWrite << TREE << std::endl;
		this->_fileToWrite.close();
	}
}

const char * ShrubberyCreationForm::FileUnavailableException::what() const throw() {
	return "Unable to open file";
}
