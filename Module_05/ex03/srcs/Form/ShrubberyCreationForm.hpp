//
// Created by gd-harco on 11/24/23.
//


#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP
#include <iostream>
#include <fstream>
#include "AForm.hpp"

class ShrubberyCreationForm : public AForm {
public:
	//Canonical
	ShrubberyCreationForm(const std::string& _target);
	ShrubberyCreationForm(ShrubberyCreationForm const &obj);
	~ShrubberyCreationForm();
	ShrubberyCreationForm &operator= (const ShrubberyCreationForm &obj);

	//Exception Subclass
	class FileUnavailableException : public std::exception {
		virtual const char* what() const throw();
};
	//Member Function
	virtual void execute(const Bureaucrat &executor) const;

private:
		ShrubberyCreationForm();

		std::string	_target;
		mutable std::ofstream	_fileToWrite;
};



#endif //SHRUBBERYCREATIONFORM_HPP
