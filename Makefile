# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mmazzocc <mmazzocc@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/05 21:55:42 by mmazzocc          #+#    #+#              #
#    Updated: 2023/02/06 20:22:56 by mmazzocc         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC		= gcc
CFLAGS	= -Wall -Werror -Wextra
NAME	= push_swap

SRC_PATH = src/
OBJ_PATH = obj/

SRC		= main.c \
		input.c \
		moves.c \
		moves2.c \
		moves3.c \
		moves4.c \
		moves5.c \
		position.c \
		sort.c \
		stack.c \
		utils.c \
		utils2.c \
		utils3.c
SRCS	= $(addprefix $(SRC_PATH), $(SRC))
OBJ		= $(SRC:.c=.o)
OBJS	= $(addprefix $(OBJ_PATH), $(OBJ))
INCS	= -I ./inc/

all: $(OBJ_PATH) $(NAME)

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	$(CC) $(CFLAGS) -c $< -o $@ $(INCS)

$(OBJ_PATH):
	mkdir $(OBJ_PATH)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

fclean:  clean
	$(RM) $(NAME)

clean:
	$(RM) -f $(OBJS)

re: fclean all

.PHONY: all clean fclean re
