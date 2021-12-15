/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stdin_test.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pniva <pniva@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 09:16:16 by pniva             #+#    #+#             */
/*   Updated: 2021/12/15 10:40:28 by pniva            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include "./libft/libft.h"
#include "get_next_line.h"
#include <stdio.h>


int		main(int argc, char **argv)
{
	int		fd;
	int		fd_output;
	char	*line;

	(void)	argc;
	(void)	argv;
	
	fd_output = open("stdin_output", O_WRONLY | O_CREAT);
	fd = STDIN_FILENO;
	while (get_next_line(fd, &line) == 1)
	{
		write(fd_output, line, ft_strlen(line));
//		write(fd_output, "\n", 1);
		free(line);
	}
	close(fd);
	close(fd_output);
	
	return (0);
}
