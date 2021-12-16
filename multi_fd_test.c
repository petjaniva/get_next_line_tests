/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   multi_fd_test.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pniva <pniva@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 11:45:17 by pniva             #+#    #+#             */
/*   Updated: 2021/12/16 12:50:05 by pniva            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <strings.h>
#include <ctype.h>
#include <limits.h>
#include "get_next_line.h"
#include <fcntl.h>
#include <assert.h>
#include <stdio.h>

void	read_fd(int fd, int fd2, int fd3)
{
	char *line;
	
	if (get_next_line(fd, &line) == 1)
		assert(strcmp(line, "abcdefghijklmno") == 0);
	else
		assert(0);
	if (get_next_line(fd2, &line) == 1)
		assert(strcmp(line, "1234567") == 0);
	else
		assert(0);
	if (get_next_line(fd3, &line) == 1)
		assert(strcmp(line, "123") == 0);
	else
		assert(0);
	puts("OK");
}

int	main(void)
{
	int fd;
	int fd2;
	int fd3;

	fd = open("./test_files/2_16_char_lines", O_RDONLY);
	fd2 = open("./test_files/2_8_char_lines", O_RDONLY);
	fd3 = open("./test_files/2_4_char_lines", O_RDONLY);
	read_fd(fd, fd2, fd3);
}
