#include <iostream>
#include <cstdlib>
#include "Array.hpp"

#define MAX_VAL 750
int main(int, char**) {
	//test on empty array
	{
		Array<int> emptyArray(0);
		try{
			std::cout << emptyArray[1] << std::endl;
		} catch (std::exception &e){
			std::cout << e.what() << std::endl;
		}
	}

}
