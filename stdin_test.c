/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stdin_test.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pniva <pniva@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 09:16:16 by pniva             #+#    #+#             */
/*   Updated: 2022/01/03 14:29:03 by pniva            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include "get_next_line.h"
#include <stdio.h>
#include <string.h>


int		main(int argc, char **argv)
{
	int		fd;
	int		fd_output;
	char	*line;

	(void)	argc;
	(void)	argv;
	
	fd_output = open("stdin_output", O_WRONLY | O_CREAT, 0777);
	fd = STDIN_FILENO;
	while (get_next_line(fd, &line) == 1)
	{
		write(fd_output, line, strlen(line));
		free(line);
	}
	close(fd);
	close(fd_output);
	
	return (0);
}
