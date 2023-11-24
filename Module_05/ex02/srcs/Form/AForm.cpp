#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm()
		:_name("undefined"), _signed(false), _signGrade(150), _execGrade(150) {
	std::cout << "Form : Default Constructor Called" << std::endl;
}

AForm::AForm(const std::string& name, int toSign, int toExec)
		:_name(name), _signed(false), _signGrade(toSign), _execGrade(toExec){
	if (toSign > 150 || toExec > 150)
		throw AForm::GradeTooLowException();
	if (toSign < 1 || toExec < 1)
		throw AForm::GradeTooHighException();
	std::cout << "Form : Data Constructor Called" << std::endl;
}

AForm::AForm(const AForm &obj)
		: _name(obj._name), _signed(obj._signed),_signGrade(obj._signGrade), _execGrade(obj._execGrade){
	std::cout << "Form : Copy Constructor Called" << std::endl;
}

AForm::~AForm() {
	std::cout << "Form : Destructor Called" << std::endl;
}

AForm &AForm::operator=(const AForm &obj) {
	if (this == &obj)
		return *this;
	else
		this->_signed = obj._signed;
	return *this;
}

const std::string &AForm::getName() const {
	return _name;
}

bool AForm::isSigned() const {
	return _signed;
}

int AForm::getSignGrade() const {
	return _signGrade;
}

int AForm::getExecGrade() const {
	return _execGrade;
}

void	AForm::beSigned(Bureaucrat &employee) {
	if (this->_signed)
		throw AForm::AlreadySignedException(this);
	else if (employee.getGrade() > this->_signGrade)
		throw AForm::GradeTooLowException();
	this->_signed = true;
}

const char *AForm::GradeTooLowException::what() const throw() {
	return "FormException: Grade too Low";
}

const char *AForm::GradeTooHighException::what() const throw() {
	return "FormException: Grade too High";
}

AForm::AlreadySignedException::AlreadySignedException(AForm *form) : m_form(form){}

std::string	AForm::AlreadySignedException::whatNamed() const throw() {
	return "FormException: form " + m_form->getName() + " already signed";
}

std::ostream &operator<<(std::ostream &os, const AForm &form) {
	os << std::boolalpha << "Form name: " << form.getName() << "\nIs signed: " << form.isSigned()
	<< "\n_signGrade: " << form.getSignGrade()
			<< "\n_execGrade: " << form.getExecGrade();
	return os;
}
