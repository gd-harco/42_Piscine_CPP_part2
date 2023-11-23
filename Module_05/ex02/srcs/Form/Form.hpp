
#ifndef FORM_HPP
#define FORM_HPP
#include <iostream>
#include <string>

class Bureaucrat;

class Form {
public:
	Form(const std::string& name, int toSign, int toExec);
	Form(Form const &obj);
	~Form();
	Form &operator=(const Form &obj);

	//Getter
	const std::string &getName() const;
	bool isSigned() const;
	int getSignGrade() const;
	int getExecGrade() const;

	//Member Function
	void	beSigned(Bureaucrat &employee);

	//Exception subclass
	class GradeTooLowException : public std::exception {
		virtual const char* what() const throw();
	};

	class GradeTooHighException : public std::exception {
		virtual const char* what() const throw();
	};

	class AlreadySignedException : public std::exception {
	public:
		explicit AlreadySignedException(Form *form);
		std::string	whatNamed() const throw();
	private:
		Form *m_form;
	};
private:
	Form();
	const std::string	_name;
	bool				_signed;
	const int			_signGrade;
	const int			_execGrade;
};

std::ostream &operator<<(std::ostream &os, const Form &form);

#endif //FORM_HPP
