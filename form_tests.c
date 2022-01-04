/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   form_tests.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pniva <pniva@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 14:55:24 by pniva             #+#    #+#             */
/*   Updated: 2022/01/03 14:29:49 by pniva            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <ctype.h>
#include <limits.h>
#include "get_next_line.h"
#include <fcntl.h>
#include <assert.h>
#include <stdio.h>


void	read_fd(int fd)
{
	char *line;
	
	while (get_next_line(fd, &line) == 1)
	{
		if (strlen(line) == 7)
			assert(strcmp(line, "1234567") == 0);
		else if (strlen(line) == 15)
			assert(strcmp(line, "abcdefghijklmno") == 0);
		else if(strlen(line) == 3)
			assert(strcmp(line, "123") == 0);
		else if(strlen(line) == 4)
			assert(strcmp(line, "1234") == 0);
		else if(strlen(line) == 8)
			assert(strcmp(line, "12345678") == 0);
		else if (strlen(line) == 16)
			assert(strcmp(line, "abcdefghijklmnop") == 0);
		else
			assert(0);
	}
	puts("OK");
}

int	main(int argc, char *argv[])
{
	if (argc == 1)
	{
		read_fd(STDIN_FILENO);
		return (0);
	}
	int fd;

	fd = open(argv[1], O_RDONLY);
	read_fd(fd);
}
