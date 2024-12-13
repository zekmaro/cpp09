# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: anarama <anarama@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/19 11:54:40 by anarama           #+#    #+#              #
#    Updated: 2024/12/13 15:00:15 by anarama          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC		:= c++

NAME	:= PmergeMe

CFLAGS	:= -Wall -Wextra -Werror -std=c++98

OBJDIR	:= obj

HEADERS	:=	PmergeMe.hpp

SRC		:=	main.cpp PmergeMe.cpp

OBJ		:= $(SRC:%.cpp=$(OBJDIR)/%.o)

$(shell mkdir -p $(OBJDIR))

all: $(NAME)

$(NAME): $(OBJ) $(HEADERS)
	$(CC) $(OBJ) $(CFLAGS) -o $(NAME)

clean:
	rm -f $(OBJ)

fclean:
	rm -f $(OBJ) $(NAME)

re: fclean all

$(OBJDIR)/%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

.PHONY	: all clean fclean re