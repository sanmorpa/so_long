/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_events.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samoreno <samoreno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 13:59:51 by samoreno          #+#    #+#             */
/*   Updated: 2022/01/28 15:12:47 by samoreno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	key_hook(int key, t_content *all)
{
	char	*count;

	if (key == ESC)
		ft_close(&(all->ptrs), &(all->size_map), all->array,
			&(all->images));
	if (key == W)
		ft_up(all);
	if (key == A)
		ft_left(all);
	if (key == S)
		ft_down(all);
	if (key == D)
		ft_right(all);
	ft_enemy(all);
	count = ft_itoa(all->hero.moves);
	mlx_string_put(all->ptrs.mlx_ptr, all->ptrs.win_ptr, 0, 0, 0, count);
	free(count);
	return (0);
}
