//
// Created by gd-harco on 11/24/23.
//


#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP
#include <iostream>
#include <fstream>
#include "AForm.hpp"

class RobotomyRequestForm : public AForm {
public:
	//Canonical
	RobotomyRequestForm(const std::string& _target);
	RobotomyRequestForm(RobotomyRequestForm const &obj);
	~RobotomyRequestForm();
	RobotomyRequestForm &operator= (const RobotomyRequestForm &obj);

	//Member Function
	virtual void execute(const Bureaucrat &executor) const;

private:
		RobotomyRequestForm();
		std::string	_target;
};



#endif //SHRUBBERYCREATIONFORM_HPP
