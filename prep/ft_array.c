/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_array.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samoreno <samoreno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 09:55:48 by samoreno          #+#    #+#             */
/*   Updated: 2022/01/25 09:23:09 by samoreno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static void	ft_fill_array(char **array, t_coord *rowcol, char **argv);
static void	ft_parse_fill(char *line, char **array, int iter_word);
static int	ft_check_map(char **array, t_coord *rowcol);

char	**ft_array(t_coord *rowcol, char **argv)
{
	char	**array;
	int		iter;

	array = malloc(sizeof(char *) * rowcol->y + 1);
	iter = 0;
	if (!array)
		ft_error(ERRMEM);
	while (iter < rowcol->y)
	{
		array[iter] = malloc(sizeof(char) * (rowcol->x + 1));
		if (!array[iter])
		{
			ft_free_array(array, iter);
			ft_error(ERRMEM);
		}
		iter++;
	}
	ft_fill_array(array, rowcol, argv);
	if (ft_check_map(array, rowcol) == 1)
		ft_error_free(array, rowcol, ERRMAP);
	return (array);
}

static int	ft_check_map(char **array, t_coord *rowcol)
{
	int		iter_word;
	int		iter_char;

	iter_word = 0;
	while (iter_word < rowcol->y)
	{
		iter_char = 0;
		while (array[iter_word][iter_char])
		{
			if (iter_word == 0 || iter_word == rowcol->y - 1)
			{
				if (array[iter_word][iter_char] != '1')
					return (1);
			}
			iter_char++;
		}
		if (iter_word > 0 && iter_word < rowcol->y - 1)
		{
			if (array[iter_word][0] != '1'
				|| array[iter_word][rowcol->x - 1] != '1')
				return (1);
		}
		iter_word++;
	}
	return (0);
}

static void	ft_fill_array(char **array, t_coord *rowcol, char **argv)
{
	int		fd;
	int		iter_word;
	char	*line;

	iter_word = 0;
	fd = open(argv[1], O_RDONLY);
	line = get_next_line(fd);
	if (!fd || !line)
	{
		ft_free(array, rowcol);
		ft_error(ERRFILE);
	}
	while (line)
	{
		ft_parse_fill(line, array, iter_word);
		iter_word++;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
}

static void	ft_parse_fill(char *line, char **array, int iter_word)
{
	int		iter_char;
	int		iter_line;

	iter_char = 0;
	iter_line = 0;
	while (line[iter_line] != '\n' && line[iter_line])
	{
		array[iter_word][iter_char] = line[iter_line];
		iter_char++;
		iter_line++;
	}
	array[iter_word][iter_char] = 0;
}
