/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stdin_test.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pniva <pniva@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 09:16:16 by pniva             #+#    #+#             */
/*   Updated: 2021/12/14 09:26:41 by pniva            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include "./libft/libft.h"
#include "get_next_line.h"
#include <stdio.h>


int		main(int argc, char **argv)
{
	int		fd;
	char	*line;

	(void)	argc;
	(void)	argv;
	
	fd = STDIN_FILENO;
	while (get_next_line(fd, &line) == 1)
	{
		printf("%s\n", line);
		free(line);
	}
	close(fd);
	
	return (0);
}
