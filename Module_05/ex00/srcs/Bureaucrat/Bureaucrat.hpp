//
// Created by gd-harco on 11/20/23.
//

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

	//exception class
	class GradeTooHighException : public std::exception {
		virtual const char* what();
	};
	class GradeTooLowException : public std::exception {
		virtual const char* what();
	};

	//getter & setter
	const std::string	&getName() const;
	int					getGrade() const;
	void				incrementGrade();
	void				decrementGrade();
private:
	Bureaucrat();
	const std::string	_name;
	int					_grade;
};

std::ostream &operator <<(std::ostream &output, const Bureaucrat &Bureaucrat);
#endif //BUREAUCRAT_HPP
