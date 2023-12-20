#include "header.hpp"
#include <algorithm>

typedef std::deque<int>::iterator deckIt;
typedef std::deque<std::pair<int, int> >::iterator pairIt;

void mergeSort(std::deque<std::pair<int, int> >& pair);

void createPair(std::deque<int> &toMerge, std::deque<std::pair<int, int> > &pair);

void	deckMerge(std::deque<int>& toMerge) {
	std::deque<std::pair<int, int> > pair;
	createPair(toMerge, pair);
	mergeSort(pair);//le deque de pair est trie selon le first de chaque pair.
	toMerge.clear();
	pairIt end = pair.end();
	for (pairIt curr = pair.begin(); curr != end; ++curr)
		toMerge.push_back(curr->first);
	//faire la suite de Jacobsthal, placer l'element Ux de la suite second dans l'array trie. remonter la suite et placer les non place. puis refaire Ux+1
	insertRemaining(toMerge, pair.begin())

}

int Jacobsthal(int n)
{
	// base case
	if (n == 0)
		return 0;
	// base case
	if (n == 1)
		return 1;
	// recursive step.
	return Jacobsthal(n - 1) + 2 * Jacobsthal(n - 2);
}

void	insertRemaining(std::deque<int>& toMerge, pairIt begin) {
	int	i=0;
	
}

void createPair(std::deque<int> &toMerge, std::deque<std::pair<int, int> > &pair) {
	deckIt cur = toMerge.begin();
	deckIt end = toMerge.end();
	while (cur != end){
		if (cur + 1 == end)
			void;
			//todo;
		int	biggest = *cur++;
		int lowest = *cur++;
		if (biggest < lowest)
			std::swap(biggest, lowest);
		std::pair<int, int> tmp(biggest, lowest);
		pair.push_back(tmp);
	}
}

void mergeSort(std::deque<std::pair<int, int> >& pair){
	std::deque<std::pair<int, int> >::size_type size = pair.size();
	if (size >2){
		std::deque<std::pair<int, int> > firstHalf(pair.begin(), pair.begin() + (size /2));
		std::deque<std::pair<int, int> > secondHalf(pair.begin() + (size /2), pair.end());
		mergeSort(firstHalf);
		mergeSort(secondHalf);
		std::merge(firstHalf.begin(), firstHalf.end(), secondHalf.begin(), secondHalf.end(), pair.begin());
		return ;
	}
	if (size == 1)
		return ;
	if (pair[0].first > pair[1].first)
		std::swap(pair[0], pair[1]);
}
