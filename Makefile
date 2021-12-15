#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pniva <pniva@student.hive.fi>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/09 14:08:13 by pniva             #+#    #+#              #
#    Updated: 2021/12/15 12:36:07 by pniva            ###   ########.fr        #
#                                                                              #
#******************************************************************************#


SRCS = test_files.c \
		../get_next_line.c \
		munit.c \

NAME = test.out

CC = gcc

CFLAGS = -Wall -Werror -Wextra

INCLUDES = -I ../ -I ../libft/includes -L ../libft -lft

all:	 $(NAME) stdin

$(NAME):
		make -C ../libft/ fclean && make -C ../libft/
		@$(CC) $(CFLAGS) $(SRCS) $(INCLUDES) -o $(NAME)
		./$(NAME)

leaks:
		$(CC) $(CFLAGS) leaks_test.c ../get_next_line.c $(INCLUDES) -o leaks_test.out

test_leaks:
		valgrind --leak-check=full -v ./leaks_test.out

stdin:
		@$(CC) $(CFLAGS) stdin_test.c ../get_next_line.c ../libft/libft.a \
		$(INCLUDES) -o stdin.out
		cat test_one_long_line | ./stdin.out
		diff test_one_long_line stdin_output

clean:
		make -C ../libft clean
		rm -f stdin_output

fclean: clean
		@rm -f $(NAME)
		@rm -f stdin.out

re: fclean all
