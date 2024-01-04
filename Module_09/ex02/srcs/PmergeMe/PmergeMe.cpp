//
// Created by gd-harco on 1/4/24.
//

#include "PmergeMe.hpp"
void	fillDeck(char **argv, std::deque<int>& toFill);
void	fillVector(const std::deque<int>& deck, std::vector<int>& tofill);


PmergeMe::PmergeMe(char **argv) {
	error = false;
	try {
		fillDeck(argv, this->deckContainer);
		fillVector(this->deckContainer, this->vectorContainer);
	} catch (std::exception& e){
		std::cout << e.what() << std::endl;
		error = true;
	}
}

PmergeMe::PmergeMe() {
		error = true;
}

PmergeMe::PmergeMe(const PmergeMe &obj) {
	std::cout << "PmergeMe : Copy Constructor Called" << std::endl;
	if (this != &obj)
		*this = obj;
}

PmergeMe::~PmergeMe() {
	std::cout << "PmergeMe : Destructor Called" << std::endl;
}

PmergeMe &PmergeMe::operator=(const PmergeMe &obj) {
	if (this == &obj)
		return *this;
	else
	//copy instruction for the class

}
