//
// Created by gd-harco on 1/4/24.
//


#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <deque>
#include <vector>

class PmergeMe {
public:
	explicit PmergeMe(char **argv);
	PmergeMe(PmergeMe const &obj);
	~PmergeMe();
	PmergeMe &operator=(const PmergeMe &obj);
	bool	error;
	std::deque<int> deckContainer;
	std::vector<int> vectorContainer;
	PmergeMe();
};


#endif //PMERGEME_HPP
