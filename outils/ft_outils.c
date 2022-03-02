/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_outils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samoreno <samoreno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 14:55:29 by samoreno          #+#    #+#             */
/*   Updated: 2022/01/25 09:23:05 by samoreno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	ft_newline(char *line)
{
	int	iter;

	iter = 0;
	while (line[iter] && line[iter] != '\n')
	{
		if (line[iter] != '0' && line[iter] != '1' && line[iter] != 'C'
			&& line[iter] != 'E' && line[iter] != 'P' && line[iter] != 'X')
		{
			free(line);
			ft_error(ERRMAP);
		}
		iter++;
	}
	return (iter);
}

void	ft_free(char **array, t_coord *rowcol)
{
	int	iter;

	iter = 0;
	while (iter < rowcol->y)
	{
		free(array[iter]);
		iter++;
	}
	free(array);
}

int	ft_red_cross(t_content *all)
{
	ft_free(all->array, &(all->size_map));
	ft_destroy_img(all->ptrs.mlx_ptr, &(all->images), 4);
	mlx_destroy_window(all->ptrs.mlx_ptr, all->ptrs.win_ptr);
	exit(0);
}

void	ft_destroy_img(void *mlx_ptr, t_stimages *images, int n_img)
{
	int	iter;

	iter = 0;
	while (iter <= n_img)
	{
		if (iter == 0)
			mlx_destroy_image(mlx_ptr, images->tile.img);
		if (iter == 1)
			mlx_destroy_image(mlx_ptr, images->wall.img);
		if (iter == 2)
			mlx_destroy_image(mlx_ptr, images->hero.img);
		if (iter == 3)
			mlx_destroy_image(mlx_ptr, images->coin.img);
		if (iter == 4)
			mlx_destroy_image(mlx_ptr, images->exit.img);
		if (iter == 5)
			mlx_destroy_image(mlx_ptr, images->enemy.img);
		iter++;
	}
}

void	ft_free_array(char **array, int words)
{
	int	iter;

	iter = 0;
	while (iter < words)
	{
		free(array[iter]);
		iter++;
	}
	free(array);
}
