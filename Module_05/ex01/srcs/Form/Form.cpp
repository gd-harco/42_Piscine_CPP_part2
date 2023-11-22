#include "Form.hpp"


Form::Form()
		:_name("undefined"), _signed(false), _signGrade(150), _execGrade(150) {
	std::cout << "Form : Default Constructor Called" << std::endl;
}

Form::Form(const std::string& name, int toSign, int toExec)
		:_name(name), _signed(false), _signGrade(toSign), _execGrade(toExec){
	if (toSign > 150 || toExec > 150)
		throw Form::GradeTooLowException();
	if (toSign < 1 || toExec < 1)
		throw Form::GradeTooHighException();
	std::cout << "Form : Data Constructor Called" << std::endl;
}

Form::Form(const Form &obj)
		: _name(obj._name), _signed(obj._signed),_signGrade(obj._signGrade), _execGrade(obj._execGrade){
	std::cout << "Form : Copy Constructor Called" << std::endl;
}

Form::~Form() {
	std::cout << "Form : Destructor Called" << std::endl;
}

Form &Form::operator=(const Form &obj) {
	if (this == &obj)
		return *this;
	else
		this->_signed = obj._signed;
}

const std::string &Form::getName() const {
	return _name;
}

bool Form::isSigned() const {
	return _signed;
}

int Form::getSignGrade() const {
	return _signGrade;
}

int Form::getExecGrade() const {
	return _execGrade;
}



const char *Form::GradeTooLowException::what() const throw() {
	return "FormException: Grade too Low";
}

const char *Form::GradeTooHighException::what() const throw() {
	return "FormException: Grade too High";
}

Form::AlreadySignedException::AlreadySignedException(Form *form) : m_form(form){}

std::string	Form::AlreadySignedException::whatNamed() const throw() {
	return "FormException: form " + m_form->getName() + " already signed";
}
