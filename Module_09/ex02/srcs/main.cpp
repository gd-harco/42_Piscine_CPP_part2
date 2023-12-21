/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gd-harco <gd-harco@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 17:15:11 by gd-harco          #+#    #+#             */
/*   Updated: 2023/12/01 17:42:43 by gd-harco         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <algorithm>
#include <ctime>
#include <sys/time.h>
#include "TimeAsset.hpp"
#include "header.hpp"

void print(int n){
	std::cout << n << " ";
}

template <typename T>
void	printSequence(T& seq, bool sorted){
	if (sorted)
		std::cout << "Unsorted Sequence : ";
	else
		std::cout << "Sorted Sequence : ";
	std::for_each(seq.begin(), seq.end(), print);
	std::cout << std::endl;
};

int main(int argc, char **argv) {
	if (argc == 1 || argv[1][0] == '\0') {
		std::cout << "No integer sequence given" << std::endl;
		return 1;
	}
	std::deque<int> deckContainer;
	std::vector<int> vectorContainer;
	try {
		fillDeck(&argv[1], deckContainer);
		fillVector(deckContainer, vectorContainer);
	} catch (std::exception& e){
		std::cout << e.what() << std::endl;
		return 0;
	}
	printSequence(vectorContainer, false);
	TimeAsset deckStart;
	deckMerge(deckContainer);
	TimeAsset deckEnd;
	TimeAsset *durationDeck = deckEnd - deckStart;
	TimeAsset vecStart;
	vectorMerge(vectorContainer);
	TimeAsset vecEnd;
	TimeAsset *durationVector = vecEnd - vecStart;
	printSequence(vectorContainer, true);
	std::cout << "Time to sort " << deckContainer.size() << " element using deque container: "  << *durationDeck << std::endl;
	std::cout << "Time to sort " << deckContainer.size() << " element using vector container: "  << *durationVector << std::endl;
	delete durationDeck;
	delete durationVector;
}
