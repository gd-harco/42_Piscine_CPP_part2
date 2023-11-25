//
// Created by gd-harco on 11/25/23.
//


#ifndef INTERN_HPP
#define INTERN_HPP
#include <iostream>
#include <string>
#include "AForm.hpp"

class Intern {
public:
	//canonical
	Intern();
	Intern(Intern const &obj);
	~Intern();
	Intern &operator=(const Intern &obj);

	//member function
	AForm	*makeForm(const std::string& formName, const std::string & formTarget);
private:
	AForm	*makeShrub(const std::string &target);
	AForm	*makeRobo(const std::string &target);
	AForm	*makePardon(const std::string &target);
};

typedef AForm * (Intern::*ptr)(const std::string &);
struct s_table {
	std::string expected;
	ptr call;
};


#endif //INTERN_HPP
