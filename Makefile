# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mmazzocc <mmazzocc@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/05 21:55:42 by mmazzocc          #+#    #+#              #
#    Updated: 2023/02/08 01:50:03 by mmazzocc         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC		= gcc
CFLAGS	= -Wall -Werror -Wextra
NAME	= push_swap
NAME_BONUS	=	checker

SRC_PATH = src/
SRC_BONUS_PATH = bonus/
OBJ_PATH = obj/
OBJ_BONUS_PATH = obj_bonus/

SRC1		=	main.c \
				sort.c

SRC2		=	input.c \
				moves.c \
				moves2.c \
				moves3.c \
				moves4.c \
				moves5.c \
				position.c \
				stack.c \
				utils.c \
				utils2.c \
				utils3.c

SRC_BONUS	=	bonus/checker.c \
				bonus/get_next_line.c \
				bonus/push.c \
				bonus/rev_rotate.c \
				bonus/rotate.c \
				bonus/swap.c \
				bonus/utils.c \

SRCS1		= $(addprefix $(SRC_PATH), $(SRC1))
OBJ1		= $(SRC1:.c=.o)
OBJS1		= $(addprefix $(OBJ_PATH), $(OBJ1))
SRCS2		= $(addprefix $(SRC_PATH), $(SRC2))
OBJ2		= $(SRC2:.c=.o)
OBJS2		= $(addprefix $(OBJ_PATH), $(OBJ2))
OBJ_BONUS	= $(SRC_BONUS:.c=.o)

INCS		= -I ./inc/

all: $(OBJ_PATH) $(NAME)

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	$(CC) $(CFLAGS) -c $< -o $@ $(INCS)

$(OBJ_PATH):
	mkdir $(OBJ_PATH)

$(NAME): $(OBJS1) $(OBJS2)
	$(CC) $(CFLAGS) $(OBJS1) $(OBJS2) -o $(NAME) $(INCS)

fclean:  clean
	$(RM) $(NAME) $(NAME_BONUS)

clean:
	$(RM) -f $(OBJS1) $(OBJS2) $(OBJ_BONUS)

re: fclean all

bonus:		$(NAME_BONUS)

.c.o:
	$(CC) $(CFLAGS) -c $< -o $@ $(INCS)

$(NAME_BONUS): $(OBJS2) $(OBJ_BONUS)
	$(CC) $(CFLAGS) $(OBJ_BONUS) $(OBJS2) -o $(NAME_BONUS) $(INCS)

.PHONY: all clean fclean re
