/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_images.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samoreno <samoreno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 15:18:35 by samoreno          #+#    #+#             */
/*   Updated: 2022/01/25 09:23:19 by samoreno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static void	ft_fill_images(void *mlx_ptr, t_stimages *images, int iter);

t_stimages	ft_images(void *mlx_ptr, t_coord *size_map, char **array)
{
	t_stimages	images;
	t_image		image;
	int			iter;

	iter = 0;
	image.path = "./sprites/tile.xpm";
	image.img = mlx_xpm_file_to_image(mlx_ptr, image.path, &image.width,
			&image.height);
	images.tile = image;
	while (iter != 5)
	{
		ft_fill_images(mlx_ptr, &images, iter);
		if (!image.img)
		{
			ft_destroy_img(mlx_ptr, &images, iter);
			ft_error_free(array, size_map, ERRMEM);
		}
		iter++;
	}
	return (images);
}

static void	ft_fill_images(void *mlx_ptr, t_stimages *images, int iter)
{
	t_image		image;

	if (iter == 0)
		image.path = "./sprites/wall.xpm";
	if (iter == 1)
		image.path = "./sprites/hero.xpm";
	if (iter == 2)
		image.path = "./sprites/coin.xpm";
	if (iter == 3)
		image.path = "./sprites/exit.xpm";
	if (iter == 4)
		image.path = "./sprites/enemy.xpm";
	image.img = mlx_xpm_file_to_image(mlx_ptr, image.path,
			&image.width, &image.height);
	if (iter == 0)
		images->wall = image;
	if (iter == 1)
		images->hero = image;
	if (iter == 2)
		images->coin = image;
	if (iter == 3)
		images->exit = image;
	if (iter == 4)
		images->enemy = image;
}
