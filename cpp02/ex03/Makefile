# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lorbke <lorbke@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/17 16:37:03 by lorbke            #+#    #+#              #
#    Updated: 2023/04/17 21:56:07 by lorbke           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# __________________________________________________________________ VARIABLES #

SHELL		:= /bin/bash

NAME		:= bsp

CC			:= c++
CFLAGS		:= #-Wall -Wextra -Werror
CFLAGS		+= -std=c++98

SRCS		:= main.cpp Fixed.cpp Point.cpp bsp.cpp
OBJS		:= $(SRCS:.cpp=.o)

# __________________________________________________________________ LIBRARIES #

MLX_PATH	:= mlx42/
MLX_LIB		:= mlx42
MLX_LINK	:= -L$(MLX_PATH) -l$(MLX_LIB)
MLX_INC		:= -I$(MLX_PATH)/include/MLX42/

GL_PATH		:= /opt/homebrew/Cellar/glfw/3.3.8/lib/
GL_LIB		:= glfw
GL_LINK		:= -L$(GL_PATH) -l$(GL_LIB)

# _____________________________________________________________________ COLORS #

RED			:= \033[0;31m
GREEN		:= \033[0;32m

# ______________________________________________________________________ RULES #

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

%.o: %.cpp
	$(CC) $(CFLAGS) $(MLX_LINK) $(MLX_INC) $(GL_LINK) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

# ______________________________________________________________ TESTING RULES #

test:
	@$(SHELL) tester/tester.sh

run: all
	@./$(NAME) WARNING

rawrun:
	@$(CC) $(SRCS) -o $(NAME)
	@./$(NAME) WARNING

val: all
	@valgrind --leak-check=full ./$(NAME) WARNING

.PHONY: all clean fclean re test run rawrun val
