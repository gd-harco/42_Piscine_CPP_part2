
#ifndef AFORM_HPP
#define AFORM_HPP
#include <iostream>
#include <string>

class Bureaucrat;

class AForm {
public:
	AForm(const std::string& name, int toSign, int toExec);
	AForm(AForm const &obj);
	virtual ~AForm() = 0;
	AForm &operator=(const AForm &obj);

	//Getter
	const std::string &getName() const;
	bool isSigned() const;
	int getSignGrade() const;
	int getExecGrade() const;

	//Member Function
	void			beSigned(Bureaucrat &employee);
	bool			isAllowed(Bureaucrat const &employee);
	virtual void	execute(Bureaucrat const & executor) = 0;

	//Exception subclass
	class GradeTooLowException : public std::exception {
		virtual const char* what() const throw();
	};

	class GradeTooHighException : public std::exception {
		virtual const char* what() const throw();
	};

	class AlreadySignedException : public std::exception {
	public:
		explicit AlreadySignedException(AForm *form);
		std::string	whatNamed() const throw();
	private:
		AForm *m_form;
	};
private:
	AForm();
	const std::string	_name;
	bool				_signed;
	const int			_signGrade;
	const int			_execGrade;
};

std::ostream &operator<<(std::ostream &os, const AForm &form);

#endif //AFORM_HPP
