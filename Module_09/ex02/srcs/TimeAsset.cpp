//
// Created by gd-harco on 12/21/23.
//

#include "TimeAsset.hpp"


TimeAsset::TimeAsset() {
	gettimeofday(&timeStruct, NULL);
}

TimeAsset::TimeAsset(const TimeAsset &obj) {
	std::cout << "timeAsset : Copy Constructor Called" << std::endl;
	if (this != &obj)
		*this = obj;
}

TimeAsset::~TimeAsset() {}

TimeAsset &TimeAsset::operator=(const TimeAsset &obj) {
	if (this == &obj)
		return *this;
	else {
		this->timeStruct.tv_sec = obj.timeStruct.tv_sec;
		this->timeStruct.tv_usec = obj.timeStruct.tv_usec;
	}
	return *this;
}

TimeAsset *TimeAsset::operator-(const TimeAsset &obj) {
	time_t sec_diff = this->timeStruct.tv_sec - obj.timeStruct.tv_sec;
	suseconds_t usec_diff = this->timeStruct.tv_usec - obj.timeStruct.tv_usec;

	// Handle case where subtraction results in negative microseconds
	if (usec_diff < 0) {
		sec_diff -= 1;
		usec_diff += 1000000; // 1 second = 1,000,000 microseconds
	}

	TimeAsset *ret = new TimeAsset;
	ret->timeStruct.tv_usec = usec_diff;
	ret->timeStruct.tv_sec = sec_diff;
	return ret;
}

std::ostream &operator <<(std::ostream &output, const TimeAsset &toPrint) {
	if (toPrint.timeStruct.tv_sec == 0)
		output << toPrint.timeStruct.tv_usec << " useconde";
	else
		output << toPrint.timeStruct.tv_sec << " second and " << toPrint.timeStruct.tv_usec << " useconde";
	return (output);
}
