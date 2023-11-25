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

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>

#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN    "\033[36m"
#define WHITE   "\033[37m"
#define EXC_CAUGHT "Exception caught: "

#define TREE "      .              +   .       .                 \n\
                  _                              \n\
  ,              /;- _,- ____        ,----- __\n\
 ((             (_:#::_ :::  `- _   /:, /- _, ` _,\n\
  `                 \\   _|`\"=:_:: ` );  \\ __/ /\n\
                      ,    ` /  \\:  `    )==-'   \n\
            , ,-=-   ,\\, +# /`   \\:   / /   .        \n\
         .  \\/:/`-' , ,\\ '` ` `   ): , /_  -o\n\
            /:+- - + +- : :- + + -:'  /(o-) \\)      \n\
         ,=':  \\    ` `/` ' , , ,:' `'--\" --\"--- _/`7\n\
   `    (    \\: \\,- _` ` + '\\, ,\"   _,-- _,---\": __/\n\
              \\:  `  X` _| _,\\/'    -'\n\
 .              \": _:`\\____  /:'  /          .        \n\
                    \\::   :\\/:'  /        .     +\n\
      .              ` :   /:'  }       \n\
           .           ):_(:;   \\            \n\
                      /:  _/ ,  |\n\
                     (|::      ,`                   \n\
                      |::     {\\\n\
          .           |:: \\  \\ ` \n\
                      |:::(\\    |\n\
              O       |:::/{ }  |                  (o\n\
               )  ___/#\\::`/ (O \"== _____   O, (O  /`\n\
          ~~~w/w~\"~~,\\` `:/,-(~`\"~~~~~~~~\"~o~\\~/~w|/~\n\
dew   ~~~~~~~~~~~~~~~~~~~~~~~\\W~~~~~~~~~~~~\\|/~~"

#endif //HEADER_HPP
