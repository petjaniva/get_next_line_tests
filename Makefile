#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pniva <pniva@student.hive.fi>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/09 14:08:13 by pniva             #+#    #+#              #
#    Updated: 2021/12/15 10:46:43 by pniva            ###   ########.fr        #
#                                                                              #
#******************************************************************************#


SRCS = test_files.c \
		../get_next_line.c \
		munit.c 

NAME = test.out

CC = gcc

CFLAGS = -Wall -Werror -Wextra -I ../ -I ../libft/includes

all:	 $(NAME)

libft: 
		make -C ../libft/

$(NAME):
		@$(CC) $(CFLAGS) $(SRCS) -o $(NAME)

stdin:
		@$(CC) $(CFLAGS) stdin_test.c ../libft/libft.a ../get_next_line.c -o stdin.out

clean:
		@rm -f $(OBJS)

fclean: clean
		@rm -f $(NAME)

re: fclean all
