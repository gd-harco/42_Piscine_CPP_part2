#include "header.hpp"
#include <sstream>
#include <cstdlib>

void	fillDeck(char **argv, std::deque<int>& toFill) {
	for (int i = 0; argv[i]; ++i) {
		char *buff = NULL;
		int tmpInt = strtol(argv[i], &buff, 10);
		if (*buff != '\0')
			throw std::invalid_argument("Unauthorized character detected");
		toFill.push_back(tmpInt);
	}
}

void	fillVector(const std::deque<int>& deck, std::vector<int>& tofill){
	std::deque<int>::const_iterator begin = deck.begin();
	std::deque<int>::const_iterator end = deck.end();
	while (begin != end){
		tofill.push_back(*begin);
		begin++;
	}
}

unsigned int	Jacobsthal(int n)
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
