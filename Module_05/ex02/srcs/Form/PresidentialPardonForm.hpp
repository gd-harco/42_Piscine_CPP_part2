//
// Created by gd-harco on 11/24/23.
//


#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP
#include <iostream>
#include <fstream>
#include "AForm.hpp"

class PresidentialPardonForm : public AForm {
public:
	//Canonical
	PresidentialPardonForm(const std::string& _target);
	PresidentialPardonForm(PresidentialPardonForm const &obj);
	~PresidentialPardonForm();
	PresidentialPardonForm &operator= (const PresidentialPardonForm &obj);

	//Member Function
	virtual void execute(const Bureaucrat &executor) const;

private:
		PresidentialPardonForm();
		std::string	_target;
};



#endif //SHRUBBERYCREATIONFORM_HPP
