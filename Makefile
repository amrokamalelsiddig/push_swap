# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aelsiddi <aelsiddi@student.42abudhabi.a    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/27 18:04:30 by aelsiddi          #+#    #+#              #
#    Updated: 2022/10/29 17:18:02 by aelsiddi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LIBFT_PATH		=	./libft
LIBFT			=	$(LIBFT_PATH)/libft.a

SRCS			= 	helpers.c indexing.c operation.c parsing.c push_swap.c \
					sorting_A.c sorting_B.c linked_list.c validation.c

OBJES 		= ${SRCS:.c=.o}
OBJES_B 	= ${SRCS_B:.c=.o}

NAME 		= push_swap
NAME_B		= checker
CC 			= cc
CFLAGS 		= -Wall -Wextra -Werror -g
RM 			= rm -rf


%.o			:	%.c
				$(CC) ${CFLAGS} -c $< -o $@
	

all			:	$(NAME)

$(NAME)		:	$(LIBFT) $(OBJES) push_swap.h
				$(CC) $(OBJES) ${LIBFT} -o $(NAME)
				
$(NAME_B)	:   $(LIBFT) $(OBJES_B) push_swap.h
				$(CC) $(OBJES_B) ${LIBFT} -o $(NAME_B)

$(LIBFT)	:
				$(MAKE) -C $(LIBFT_PATH)

bonus		: $(NAME_B)

clean		:
				$(MAKE) -C $(LIBFT_PATH) clean
				$(RM) $(OBJES)
				$(RM) $(OBJES_B)

fclean		:	clean
				$(MAKE) -C $(LIBFT_PATH) fclean
				$(RM) $(NAME)
				$(RM) $(NAME_B)

re			:	clean all

norm :
	norminette $(shell find *.c *.h)

.PHONY		:	all clean fclean re ${LIBFT}