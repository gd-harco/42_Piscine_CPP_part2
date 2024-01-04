/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gd-harco <gd-harco@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 10:25:32 by gd-harco          #+#    #+#             */
/*   Updated: 2023/11/09 16:25:56 by gd-harco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_HPP
#define HEADER_HPP

#include <iostream>
#include <deque>
#include <vector>

#include "PmergeMe.hpp"
typedef std::string str;

void	fillDeck(char **argv, std::deque<int>& toFill);
void	fillVector(const std::deque<int>& deck, std::vector<int>& tofill);

void	deckMerge(std::deque<int>& toMerge);
void	vectorMerge(std::vector<int>& toMerge);
unsigned int	Jacobsthal(int n);

#endif //HEADER_HPP
