/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   leaks_test.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pniva <pniva@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 12:14:18 by pniva             #+#    #+#             */
/*   Updated: 2021/12/15 12:30:03 by pniva            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include "get_next_line.h"
#include <stdio.h>
#include <string.h>


int		main(int argc, char **argv)
{
	int		fd;
	char	*line;

	(void)	argc;
	(void)	argv;
	
	fd = open("test_many_lines_variable_length", O_RDONLY);
	while (get_next_line(fd, &line) == 1)
	{
		free(line);
	}
	close(fd);
	
	return (0);
}
