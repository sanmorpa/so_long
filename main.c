/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samoreno <samoreno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 11:29:56 by samoreno          #+#    #+#             */
/*   Updated: 2022/01/31 14:30:52 by samoreno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_ptr		ptr;
	t_stimages	images;
	t_coord		size_map;
	t_content	all;
	char		**array;

	if (argc != 2)
		ft_error(ERRARG);
	ptr.mlx_ptr = mlx_init();
	if (!ptr.mlx_ptr)
		ft_error(ERRMEM);
	size_map = ft_size_map(argv);
	array = ft_array(&size_map, argv);
	ft_check_array(array, &size_map);
	images = ft_images(ptr.mlx_ptr, &size_map, array);
	ptr.win_ptr = ft_window(size_map, ptr.mlx_ptr, &images, array);
	ft_fill_window(array, &size_map, &ptr, &images);
	all = ft_unite(array, &ptr, &images, &size_map);
	mlx_key_hook(ptr.win_ptr, key_hook, &all);
	mlx_hook(ptr.win_ptr, 17, 0, ft_red_cross, &all);
	mlx_loop(ptr.mlx_ptr);
	mlx_destroy_window(ptr.mlx_ptr, ptr.win_ptr);
	ft_free(array, &size_map);
	ft_destroy_img(&ptr.mlx_ptr, &images, 5);
	return (0);
}
