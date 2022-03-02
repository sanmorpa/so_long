/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_window.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samoreno <samoreno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 09:27:10 by samoreno          #+#    #+#             */
/*   Updated: 2022/01/25 09:23:36 by samoreno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	*ft_window(t_coord window, void *mlx_ptr, t_stimages *images,
			char **array)
{
	void		*win_ptr;

	win_ptr = mlx_new_window(mlx_ptr, window.x * TILE,
			window.y * TILE, "So_long");
	if (!win_ptr)
	{
		ft_destroy_img(mlx_ptr, images, 5);
		ft_error_free(array, &window, ERRMEM);
	}
	return (win_ptr);
}
