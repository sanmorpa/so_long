/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_size_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samoreno <samoreno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 15:53:52 by samoreno          #+#    #+#             */
/*   Updated: 2022/01/28 15:27:06 by samoreno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static void	ft_format(char **argv);

t_coord	ft_size_map(char **argv)
{
	int			fd;
	char		*line;
	t_coord		coord;

	coord.y = 0;
	ft_format(argv);
	fd = open(argv[1], O_RDONLY);
	line = get_next_line(fd);
	if (!fd || !line)
		ft_error(ERRFILE);
	coord.x = ft_newline(line);
	while (line)
	{
		if (ft_newline(line) == coord.x)
			coord.y++;
		else
		{
			free(line);
			ft_error(ERRMAP);
		}
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (coord);
}

static void	ft_format(char **argv)
{
	int		str_n;
	int		iter;
	char	*point;

	iter = 1;
	str_n = ft_strlen(argv[1]);
	point = ft_strrchr(argv[1], '.');
	if (!point)
		ft_error(ERRMAP);
	if (ft_strncmp(point, ".ber", ft_strlen(point) + 1) != 0)
		ft_error(ERRMAP);
}
