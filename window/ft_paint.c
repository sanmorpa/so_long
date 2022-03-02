/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_paint.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samoreno <samoreno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 11:20:29 by samoreno          #+#    #+#             */
/*   Updated: 2022/01/25 09:23:30 by samoreno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static void	ft_paint(char letter, t_stimages *images,
				t_ptr *ptr, t_coord *coord);

void	ft_fill_window(char **array, t_coord *size_map, t_ptr *ptr,
				t_stimages *images)
{
	int		iter_word;
	int		iter_char;
	t_coord	painted;

	iter_word = 0;
	painted.x = 0;
	painted.y = 0;
	while (iter_word < size_map->y)
	{
		iter_char = 0;
		painted.x = 0;
		while (array[iter_word][iter_char])
		{
			ft_paint(array[iter_word][iter_char], images, ptr, &painted);
			iter_char++;
			painted.x += TILE;
		}
		iter_word++;
		painted.y += TILE;
	}
}

static void	ft_paint(char letter, t_stimages *images,
t_ptr *ptr, t_coord *coord)
{
	if (letter == '0' || letter == 'C' || letter == 'E' || letter == 'P'
		|| letter == 'X')
		mlx_put_image_to_window(ptr->mlx_ptr, ptr->win_ptr,
			images->tile.img, coord->x, coord->y);
	if (letter == '1')
		mlx_put_image_to_window(ptr->mlx_ptr, ptr->win_ptr,
			images->wall.img, coord->x, coord->y);
	if (letter == 'C')
		mlx_put_image_to_window(ptr->mlx_ptr, ptr->win_ptr,
			images->coin.img, coord->x, coord->y);
	if (letter == 'E')
		mlx_put_image_to_window(ptr->mlx_ptr, ptr->win_ptr,
			images->exit.img, coord->x, coord->y);
	if (letter == 'P')
		mlx_put_image_to_window(ptr->mlx_ptr, ptr->win_ptr,
			images->hero.img, coord->x, coord->y);
	if (letter == 'X')
		mlx_put_image_to_window(ptr->mlx_ptr, ptr->win_ptr,
			images->enemy.img, coord->x, coord->y);
}
