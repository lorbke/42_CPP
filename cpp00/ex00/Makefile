# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lorbke <lorbke@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/17 16:37:03 by lorbke            #+#    #+#              #
#    Updated: 2023/05/01 15:13:01 by lorbke           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# __________________________________________________________________ VARIABLES #

SHELL	:= /bin/bash

NAME	:= megaphone

CC		:= c++
CFLAGS	:= -Wall -Wextra -Werror
CFLAGS	+= -std=c++98

SRCS	:= megaphone.cpp
OBJS	:= $(SRCS:.cpp=.o)

# _____________________________________________________________________ COLORS #

RED		:= \033[0;31m
GREEN	:= \033[0;32m

# ______________________________________________________________________ RULES #

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
