//
// Created by gd-harco on 11/20/23.
//

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat()
		: _name("undefined"), _grade(150){
	std::cout << "Bureaucrat : Default Constructor Called" << std::endl;
}

Bureaucrat::Bureaucrat(const std::string& _name, int _grade)
			:_name(_name), _grade(_grade){
	if (this->_grade < 1)
		throw GradeTooHighException();
	else if (this->_grade > 150)
		throw GradeTooLowException();
	std::cout << "Bureaucrat: name & grade constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat &obj) {
	std::cout << "Bureaucrat : Copy Constructor Called" << std::endl;
	if (this != &obj)
		*this = obj;
}

Bureaucrat::~Bureaucrat() {
	std::cout << "Bureaucrat : Destructor Called" << std::endl;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &rhs) {
	if (this == &rhs)
		return *this ;
	this->_grade = rhs._grade;
	return *this;
}

const char *Bureaucrat::GradeTooHighException::what() const throw() {
	return "BureaucratException: GradeTooHigh";
}

const char *Bureaucrat::GradeTooLowException::what() const throw() {
	return "BureaucratException: GradeTooLow";
}

const std::string &Bureaucrat::getName() const {
	return _name;
}

int Bureaucrat::getGrade() const {
	return _grade;
}

void Bureaucrat::incrementGrade() {
	if (this->_grade == 1)
		throw GradeTooHighException();
	this->_grade--;
}

void Bureaucrat::decrementGrade() {
	if (this->_grade == 150)
		throw GradeTooLowException();
	this->_grade++;
}

std::ostream& operator<<(std::ostream &os, const Bureaucrat &Bureaucrat){
	os << Bureaucrat.getName() +",  bureaucrat grade " << Bureaucrat.getGrade() << ".";
	return os;
}
