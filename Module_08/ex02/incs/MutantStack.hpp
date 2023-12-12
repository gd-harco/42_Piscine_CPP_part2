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

#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP
#include <stack>
#include <deque>

//La Stack n'est rien d'autre q'un deque (par defaut)
//avec certaine regle pour opperer en LIFO

//c represente le conteneur chois

template<typename T>
class MutantStack : public std::stack<T>{
public:
	typedef typename std::deque<T>::iterator iterator;

	iterator begin(){return this->c.begin();}
	iterator end(){return this->c.end();}
};


#endif //MUTANTSTACK_HPP
