//
// Created by gd-harco on 12/21/23.
//


#ifndef TIMEASSET_HPP
#define TIMEASSET_HPP

#include <iostream>
#include <sys/time.h>

class TimeAsset {
public:
	TimeAsset();
	TimeAsset(TimeAsset const &obj);
	~TimeAsset();
	TimeAsset &operator=(const TimeAsset &obj);
	TimeAsset *operator-(const TimeAsset &obj);
	struct timeval timeStruct;
};

std::ostream &operator <<(std::ostream &output, const TimeAsset &toPrint);


#endif //TIMEASSET_HPP
