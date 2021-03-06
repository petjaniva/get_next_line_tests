#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pniva <pniva@student.hive.fi>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/09 14:08:13 by pniva             #+#    #+#              #
#    Updated: 2022/01/05 09:29:38 by pniva            ###   ########.fr        #
#                                                                              #
#******************************************************************************#


SRCS = 	../get_next_line.c \
		munit.c 

EXTRA = extra_test.out

LEAKS = leaks_test.out

STDIN = stdin_test.out

FORM = forms_test.out

MULTI_FD = multi_fd_test.out

CC = gcc

CFLAGS = -Wall -Werror -Wextra

INCLUDES = -I ../ -I ../libft/includes -L ../libft -lft

all:	 $(EXTRA) $(STDIN) $(LEAKS) $(FORM) $(MULTI_FD) $(ERROR)

test_all: basic middle advanced error leaks stdin multi_fd

$(EXTRA):
		make -C ../libft/ fclean && make -C ../libft/
		$(CC) $(CFLAGS) $(SRCS) test_files.c $(INCLUDES) -o $(EXTRA)

$(LEAKS):
		$(CC) $(CFLAGS) leaks_test.c $(SRCS) $(INCLUDES) -o $(LEAKS)

leaks:
		valgrind --leak-check=full ./$(LEAKS)

$(STDIN):
		$(CC) $(CFLAGS) stdin_test.c $(SRCS) $(INCLUDES) -o $(STDIN)

stdin:
		cat ./test_files/test_one_long_line | ./$(STDIN)
		@diff ./test_files/test_one_long_line stdin_output
		@cmp -s ./test_files/test_one_long_line stdin_output; \
		RETVAL=$$?; \
		if [ $$RETVAL -eq 0 ]; then \
            echo "OK"; \
		else \
            echo "ERROR in reading from stdin"; \
		fi

$(FORM):
		@bash change_buff_size.sh 8
		$(CC) $(CFLAGS) form_tests.c $(SRCS) $(INCLUDES) -o $(FORM)

$(MULTI_FD):
		$(CC) $(CFLAGS) multi_fd_test.c $(SRCS) $(INCLUDES) -o $(MULTI_FD)

multi_fd:
		./$(MULTI_FD)

basic:
		cat ./test_files/1_8_char_line | ./forms_test.out
		cat ./test_files/2_8_char_lines | ./forms_test.out
		cat ./test_files/4_8_char_lines | ./forms_test.out
		./forms_test.out ./test_files/1_8_char_line
		./forms_test.out ./test_files/2_8_char_lines
		./forms_test.out ./test_files/4_8_char_lines

middle:
		cat ./test_files/1_16_char_line | ./forms_test.out
		cat ./test_files/2_16_char_lines | ./forms_test.out
		cat ./test_files/4_16_char_lines | ./forms_test.out
		./forms_test.out ./test_files/1_16_char_line
		./forms_test.out ./test_files/2_16_char_lines
		./forms_test.out ./test_files/4_16_char_lines

advanced:
		cat ./test_files/1_4_char_line | ./forms_test.out
		cat ./test_files/2_4_char_lines | ./forms_test.out
		cat ./test_files/4_4_char_lines | ./forms_test.out
		./forms_test.out ./test_files/1_4_char_line
		./forms_test.out ./test_files/2_4_char_lines
		./forms_test.out ./test_files/4_4_char_lines
		./forms_test.out ./test_files/4_chars_no_nl
		./forms_test.out ./test_files/8_chars_no_nl
		./forms_test.out ./test_files/16_chars_no_nl

error:
		@bash change_buff_size.sh 1
		@$(CC) $(CFLAGS) $(SRCS) test_files.c $(INCLUDES) -o $(EXTRA)
		@./$(EXTRA)
		@bash change_buff_size.sh 32
		@$(CC) $(CFLAGS) $(SRCS) test_files.c $(INCLUDES) -o $(EXTRA)
		@./$(EXTRA)
		@bash change_buff_size.sh 9999
		@$(CC) $(CFLAGS) $(SRCS) test_files.c $(INCLUDES) -o $(EXTRA)
		@./$(EXTRA)
		@bash change_buff_size.sh 10000000
		@$(CC) $(CFLAGS) $(SRCS) test_files.c $(INCLUDES) -o $(EXTRA)
		@./$(EXTRA)

clean:
		make -C ../libft clean
		rm -f stdin_output

fclean: clean
		rm -f $(EXTRA) $(LEAKS) $(STDIN) $(FORM) $(MULTI_FD)

re: fclean all
