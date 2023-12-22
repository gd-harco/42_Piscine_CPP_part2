#include "header.hpp"
#include <algorithm>

typedef std::deque<std::pair<int, int> > pairDeck;
typedef std::deque<int>::iterator deckIt;
typedef std::deque<int>::const_iterator const_deckIt;
typedef std::deque<std::pair<int, int> >::iterator pairIt;

void	mergeSort(std::deque<std::pair<int, int> >& pair);
void	createPair(std::deque<int> &toMerge, std::deque<std::pair<int, int> > &pair);
void	insertRemaining(std::deque<int>& toMerge, pairDeck& pair);
void	placeInDeck(std::deque<int>& toMerge, pairDeck& pair, unsigned int i);
int		binarySearch(std::deque<int>& arr, int val, int low, int high);

void	deckMerge(std::deque<int>& toMerge) {
	std::deque<std::pair<int, int> > pair;
	createPair(toMerge, pair);
	mergeSort(pair);//le deque de pair est trie selon le first de chaque pair.
	toMerge.clear();
	pairIt end = pair.end();
	for (pairIt curr = pair.begin(); curr != end; ++curr)
		toMerge.push_back(curr->first);
	//faire la suite de Jacobsthal, placer l'element Ux de la suite second dans l'array trie. remonter la suite et placer les non place. puis refaire Ux+1
	insertRemaining(toMerge, pair);
	if (toMerge[0] == -1)
		toMerge.erase(toMerge.begin());
}

void	insertRemaining(std::deque<int>& toMerge, pairDeck& pair) {
	int	i= -1;
	while (42){
		i++;
		unsigned int toPlace = Jacobsthal(i);
		if (toPlace >= pair.size())
			break;
		if (pair[i].first == 0)
			continue;
		placeInDeck(toMerge, pair, i);
		if (i==0)
			continue;
		for (int curr = --i; pair[curr].first != 0; --curr)
			placeInDeck(toMerge, pair, curr);
	}
	for (unsigned int curr = pair.size(); pair[curr].first != 0; --curr)
		placeInDeck(toMerge, pair, curr);
}

void	placeInDeck(std::deque<int>& toMerge, pairDeck& pair, unsigned int i){
	int place = binarySearch(toMerge, pair[i].second, 0, toMerge.size());
	deckIt itPlace = toMerge.begin() + place;
	toMerge.insert(itPlace, pair[i].second);
	pair[i].first = 0;
}

int binarySearch(std::deque<int>& arr, int val, int low, int high) {
	if (high <= low)
		return (val > arr[low]) ? (low + 1) : low;

	int mid = (low + high) / 2;

	if (val == arr[mid])
		return mid + 1;

	if (val > arr[mid])
		return binarySearch(arr, val, mid + 1, high);
	return binarySearch(arr, val, low, mid - 1);
}

void createPair(std::deque<int> &toMerge, std::deque<std::pair<int, int> > &pair) {
	deckIt cur = toMerge.begin();
	deckIt end = toMerge.end();
	while (cur != end){
		int biggest;
		int lowest;
		if (cur + 1 == end){
			biggest = *cur++;
			lowest = -1;
		}
		else {
		biggest = *cur++;
		lowest = *cur++;
		}
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
