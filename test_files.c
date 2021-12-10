/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_files.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pniva <pniva@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 10:46:30 by pniva             #+#    #+#             */
/*   Updated: 2021/12/10 10:45:08 by pniva            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "munit.h"
#include "libft/libft.h"
#include <strings.h>
#include <ctype.h>
#include <limits.h>
#include "get_next_line.h"
#include <fcntl.h>



static MunitResult	test_empty_file(const MunitParameter params[], void *data)
{
	(void)	params;
	(void)	data;
	int		fd;
	char	*line;
	int		gnl_return;
	
	fd = open("test_file_empty_lines", O_RDONLY);
	gnl_return = get_next_line(fd, &line);
	munit_assert_int(1, ==, gnl_return);
	munit_assert_string_equal("", line);

	gnl_return = get_next_line(fd, &line);
	munit_assert_int(1, ==, gnl_return);
	munit_assert_string_equal("", line);

	gnl_return = get_next_line(fd, &line);
	munit_assert_int(1, ==, gnl_return);
	munit_assert_string_equal("", line);

	gnl_return = get_next_line(fd, &line);
	munit_assert_int(0, ==, gnl_return);
	close(fd);

	return MUNIT_OK;
}

static MunitResult	test_one_long_line(const MunitParameter params[], void *data)
{
	(void)	params;
	(void)	data;
	int		fd;
	char	*line;
	int		gnl_return;

	fd = open("test_one_long_line", O_RDONLY);
	gnl_return = get_next_line(fd, &line);
	munit_assert_int(gnl_return, ==, 1);
	munit_assert_char(line[0], ==, 'J');
	munit_assert_char(line[ft_strlen(line) - 1], ==, '.');
	free(line);

	gnl_return = get_next_line(fd, &line);
	munit_assert_int(gnl_return, ==, 0);

	close(fd);
	
	return MUNIT_OK;
}

static MunitResult	test_many_lines_variable_length(const MunitParameter params[], void *data)
{
	(void)	params;
	(void)	data;
	int		fd;
	char	*line;
	int		gnl_return;


	fd = open("test_many_lines_variable_length", O_RDONLY);

	gnl_return = get_next_line(fd, &line);
	munit_assert_int(gnl_return, ==, 1);
	munit_assert_char(line[2], ==, 'e');
	munit_assert_char(line[ft_strlen(line) - 1], ==,  ',');

	gnl_return = get_next_line(fd, &line);
	munit_assert_int(gnl_return, ==, 1);
	munit_assert_char(line[0], ==, 'f');
	munit_assert_char(line[ft_strlen(line) - 1], ==, 't');
	munit_assert_null(ft_strchr(line, '\n'));

	gnl_return = get_next_line(fd, &line);
	munit_assert_string_equal("King Aegon II’s behest.", line);
	munit_assert_null(ft_strchr(line, '\n'));

	gnl_return = get_next_line(fd, &line);
	munit_assert_null(ft_strchr(line, '\n'));

	gnl_return = get_next_line(fd, &line);
	munit_assert_null(ft_strchr(line, '\n'));

	gnl_return = get_next_line(fd, &line);
	munit_assert_null(ft_strchr(line, '\n'));

	gnl_return = get_next_line(fd, &line);
	munit_assert_null(ft_strchr(line, '\n'));

	gnl_return = get_next_line(fd, &line);
	munit_assert_null(ft_strchr(line, '\n'));

	gnl_return = get_next_line(fd, &line);
	munit_assert_null(ft_strchr(line, '\n'));
	munit_assert_char(line[0], ==, 'o');
	munit_assert_char(line[ft_strlen(line) - 1], ==,  '.');

	gnl_return = get_next_line(fd, &line);
	munit_assert_int(gnl_return, ==, 0);
	close(fd);
		
	return MUNIT_OK;
}

static MunitResult	test_open_another_file(const MunitParameter params[], void *data)
{
	(void)	params;
	(void)	data;
	int		fd;
	char	*line;
	int		gnl_return;

	fd = open("test_one_long_line", O_RDONLY);
	gnl_return = get_next_line(fd, &line);
	munit_assert_int(gnl_return, ==, 1);
	munit_assert_char(line[0], ==, 'J');
	munit_assert_char(line[ft_strlen(line) - 1], ==, '.');

	gnl_return = get_next_line(fd, &line);
	munit_assert_int(gnl_return, ==, 0);

	close(fd);

	fd = open("test_file_empty_lines", O_RDONLY);
	gnl_return = get_next_line(fd, &line);
	munit_assert_int(1, ==, gnl_return);
	munit_assert_string_equal("", line);

	gnl_return = get_next_line(fd, &line);
	munit_assert_int(1, ==, gnl_return);
	munit_assert_string_equal("", line);

	gnl_return = get_next_line(fd, &line);
	munit_assert_int(1, ==, gnl_return);
	munit_assert_string_equal("", line);

	gnl_return = get_next_line(fd, &line);
	munit_assert_int(0, ==, gnl_return);
	
	close(fd);
	
	return MUNIT_OK;
}

static MunitResult	test_error_handling(const MunitParameter params[], void *data)
{
	(void)	params;
	(void)	data;
	int		fd;
	char	*line;
	int		gnl_return;

	fd = -1;
	gnl_return = get_next_line(fd, &line);
	munit_assert_int(gnl_return, ==, -1);

	
	fd = open("test_file_empty_lines", O_RDONLY);
	gnl_return = get_next_line(fd, NULL);
	munit_assert_int(gnl_return, ==, -1);
	return MUNIT_OK;
}


static MunitTest test_suite_tests[] =
{
	{(char *) "/empty_file", test_empty_file, 0, 0, 0, 0},
	{(char *) "/test_one_long_line", test_one_long_line, 0, 0, 0, 0},
	{(char *) "/test_many_lines", test_many_lines_variable_length, 0, 0, 0, 0},
	{(char *) "/test_two_files", test_open_another_file, 0, 0, 0, 0},
	{(char *) "/test_error_handling", test_error_handling, 0, 0, 0, 0},
	{0, 0, 0, 0, 0, 0}
};

static const MunitSuite test_suite =
{
	(char *) "",
	test_suite_tests,
	0,
	1,
	0
};

int	main(int argc, char *argv[MUNIT_ARRAY_PARAM(argc + 1)])
{
	return munit_suite_main(&test_suite, (void *) "munit", argc, argv);
}
