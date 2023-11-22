#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <string>
class Bureaucrat {
public:
	//canonical
	Bureaucrat(const std::string& _name, int _grade);
	Bureaucrat(Bureaucrat const &obj);
	~Bureaucrat();
	Bureaucrat &operator= (const Bureaucrat &obj);

	//getter & setter
	const std::string	&getName() const;
	int					getGrade() const;
	void				incrementGrade();
	void				decrementGrade();

	//exception subclass
	class GradeTooHighException : public std::exception {
		virtual const char* what() const throw();
	};
	class GradeTooLowException : public std::exception {
		virtual const char* what() const throw();
	};

private:
	Bureaucrat();
	const std::string	_name;
	int					_grade;
};

std::ostream &operator <<(std::ostream &output, const Bureaucrat &Bureaucrat);
#endif //BUREAUCRAT_HPP
