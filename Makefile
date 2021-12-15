#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pniva <pniva@student.hive.fi>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/09 14:08:13 by pniva             #+#    #+#              #
#    Updated: 2021/12/15 11:06:50 by pniva            ###   ########.fr        #
#                                                                              #
#******************************************************************************#


SRCS = test_files.c \
		../get_next_line.c \
		munit.c \
		../libft/libft.a

NAME = test.out

CC = gcc

CFLAGS = -Wall -Werror -Wextra -I ../ -I ../libft/includes

all:	 $(NAME)

libft: 
		make -C ../libft/

$(NAME):
		@$(CC) $(CFLAGS) $(SRCS) -o $(NAME)

stdin:
		@$(CC) $(CFLAGS) stdin_test.c ../get_next_line.c ../libft/libft.a -o stdin.out

clean:
		@rm -f $(OBJS)

fclean: clean
		@rm -f $(NAME)

re: fclean all
