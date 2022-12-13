# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aelsiddi <aelsiddi@student.42abudhabi.a    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/27 18:04:30 by aelsiddi          #+#    #+#              #
#    Updated: 2022/12/13 16:06:10 by aelsiddi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LIBFT_PATH		=	./libft
LIBFT			=	$(LIBFT_PATH)/libft.a

SRCS			= 	helpers.c indexing.c operation.c parsing.c push_swap.c sort_5.c\
					sorting_A.c sorting_B.c linked_list.c validation.c ft_split.c\

OBJES 		= ${SRCS:.c=.o}

NAME 		= push_swap
CC 			= cc
CFLAGS 		= -g -Wall -Wextra -Werror -g
RM 			= rm -rf


%.o			:	%.c
				$(CC) ${CFLAGS} -c $< -o $@
	

all			:	$(NAME)

$(NAME)		:	$(OBJES) push_swap.h
				$(CC) $(OBJES) -o $(NAME)
				
clean		:
				$(RM) $(OBJES)

fclean		:	clean
				$(RM) $(NAME)

re			:	clean all

norm :
	norminette $(shell find *.c *.h)

.PHONY		:	all clean fclean re ${LIBFT}