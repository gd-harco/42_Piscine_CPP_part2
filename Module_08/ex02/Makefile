# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gd-harco <gd-harco@student.42lyon.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/07 20:23:57 by gd-harco          #+#    #+#              #
#    Updated: 2023/12/01 17:42:27 by gd-harco         ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

NAME =	ex02

SRC_PATH =	srcs/

SRC =	main.cpp

DIR_INCS =	incs/

INCLUDES =\
	$(addprefix -I , $(DIR_INCS))

DIR_BUILD	=	.build/
OBJS		=	$(patsubst %.cpp, $(DIR_BUILD)%.o, $(SRC))
DEPS		=	$(patsubst %.cpp, $(DIR_BUILD)%.d, $(SRC))
CPPFLAGS	=	-Wall -Wextra -Werror -std=c++98 -g3
DEBUGFLAGS	=	-fsanitize=address -g3
DEPSFLAGS	=	-MMD -MP
RM			=	rm -rf
AR			=	ar rcs
CXX			=	c++

.PHONY:		all
all:
			$(MAKE) $(NAME)

debug:
			$(MAKE) $(NAME) CPPFLAGS="$(CPPFLAGS) $(DEBUGFLAGS)"

$(NAME):	$(OBJS)
			$(CXX) $(CPPFLAGS) $(INCLUDES) $(OBJS) -o $(NAME)

.PHONY:	bonus
bonus:	all

.PHONY:	clean
clean:
		$(RM) $(DIR_BUILD)

.PHONY:	fclean
fclean:	clean
		$(RM) $(NAME)

.PHONY:	re
re:		fclean
		$(MAKE) all

-include $(DEPS)

$(DIR_BUILD)%.o : $(SRC_PATH)%.cpp
		@mkdir -p $(shell dirname $@)
		$(CXX) $(CPPFLAGS) $(DEPSFLAGS) $(INCLUDES) -c $< -o $@
