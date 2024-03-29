#include <iostream>
#include "Array.hpp"

int main(int, char**) {
	//test on empty array
	{
		Array<int> emptyArray(0);
		try{
			std::cout << "emptyArry._size: " << emptyArray.size() <<std::endl;
			std::cout << emptyArray[1] << std::endl;
		} catch (std::exception &e){
			std::cout << e.what() << std::endl;
		}
	}
	//test on a small array
	{
		Array<int> smallArray(10);
		for(unsigned int i=0; i<smallArray.size(); ++i)
			std::cout << smallArray[i] << std::endl; //proving that the constructor set the value to default even with builtin type
	}
	//test on a big array
	{
		Array<std::string> bigArray(150);
		try {
			std::cout << bigArray[20] << std::endl;
			bigArray[20] = "Hello there";
			std::cout << bigArray[20] << std::endl;
			std::cout << bigArray[150] << std::endl; //will fail, array goes from 0 to 149
		} catch (std::exception &e){
			std::cout << e.what() << std::endl;
		}
	}
	//test on a const array
	{
		const Array<int> constArray(20);
		std::cout << constArray[10] <<std::endl;
//		constArray[10] = 125; // uncomment to test the Read-only aspect of the operator overload
		std::cout << constArray[10] <<std::endl;
	}
	return 0;
}
