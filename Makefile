#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pniva <pniva@student.hive.fi>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/09 14:08:13 by pniva             #+#    #+#              #
#    Updated: 2021/12/16 11:41:16 by pniva            ###   ########.fr        #
#                                                                              #
#******************************************************************************#


SRCS = 	../get_next_line.c \
		munit.c 

EXTRA = extra_test.out

LEAKS = leaks_test.out

STDIN = stdin_test.out

FORM = forms_test.out

CC = gcc

CFLAGS = -Wall -Werror -Wextra

INCLUDES = -I ../ -I ../libft/includes -L ../libft -lft

all:	 $(EXTRA) $(STDIN) $(LEAKS) $(FORM)

test_all: basic middle advanced error test_leaks test_stdin

$(EXTRA):
		make -C ../libft/ fclean && make -C ../libft/
		$(CC) $(CFLAGS) $(SRCS) test_files.c $(INCLUDES) -o $(EXTRA)

$(LEAKS):
		$(CC) $(CFLAGS) leaks_test.c $(SRCS) $(INCLUDES) -o $(LEAKS)

test_leaks:
		valgrind --leak-check=full ./$(LEAKS)

$(STDIN):
		$(CC) $(CFLAGS) stdin_test.c $(SRCS) $(INCLUDES) -o $(STDIN)

test_stdin:
		cat test_one_long_line | ./$(STDIN)
		@diff test_one_long_line stdin_output
		@cmp -s test_one_long_line stdin_output; \
		RETVAL=$$?; \
		if [ $$RETVAL -eq 0 ]; then \
            echo "OK"; \
		else \
            echo "ERROR in reading from stdin"; \
		fi

$(FORM):
		$(CC) $(CFLAGS) -g form_tests.c $(SRCS) $(INCLUDES) -o $(FORM)

basic:
		@bash change_buff_size.sh 8
		cat 1_8_char_line | ./forms_test.out
		cat 2_8_char_lines | ./forms_test.out
		cat 4_8_char_lines | ./forms_test.out
		./forms_test.out 1_8_char_line
		./forms_test.out 2_8_char_lines
		./forms_test.out 4_8_char_lines

middle:
		cat 1_16_char_line | ./forms_test.out
		cat 2_16_char_lines | ./forms_test.out
		cat 4_16_char_lines | ./forms_test.out
		./forms_test.out 1_16_char_line
		./forms_test.out 2_16_char_lines
		./forms_test.out 4_16_char_lines

advanced:
		cat 1_4_char_line | ./forms_test.out
		cat 2_4_char_lines | ./forms_test.out
		cat 4_4_char_lines | ./forms_test.out
		./forms_test.out 1_4_char_line
		./forms_test.out 2_4_char_lines
		./forms_test.out 4_4_char_lines
		./forms_test.out 4_chars_no_nl
		./forms_test.out 8_chars_no_nl
		./forms_test.out 16_chars_no_nl

error:
		@bash change_buff_size.sh 1
		@./$(EXTRA)
		@bash change_buff_size.sh 32
		@./$(EXTRA)
		@bash change_buff_size.sh 9999
		@./$(EXTRA)
		@bash change_buff_size.sh 10000000
		@./$(EXTRA)

clean:
		make -C ../libft clean
		rm -f stdin_output

fclean: clean
		rm -f $(EXTRA) $(LEAKS) $(STDIN) $(FORM)

re: fclean all
