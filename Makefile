#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pniva <pniva@student.hive.fi>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/09 14:08:13 by pniva             #+#    #+#              #
#    Updated: 2021/12/09 14:13:45 by pniva            ###   ########.fr        #
#                                                                              #
#******************************************************************************#


SRCS = test_files.c \
		get_next_line.c \
		munit.c \
		libft/libft.a

NAME = test.out

CC = gcc

CFLAGS = -Wall -Werror -Wextra

all: $(NAME)

$(NAME):
		@$(CC) $(CFLAGS) $(SRCS) -o $(NAME)

clean:
		@rm -f $(OBJS)

fclean: clean
		@rm -f $(NAME)

re: fclean all
