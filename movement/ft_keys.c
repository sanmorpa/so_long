/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_keys.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samoreno <samoreno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 14:54:59 by samoreno          #+#    #+#             */
/*   Updated: 2022/01/28 15:17:12 by samoreno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	ft_up(t_content *all)
{
	char	up;

	up = all->array[all->hero.y - 1][all->hero.x];
	if (up != '1' && (up != 'E' || (up == 'E' && all->hero.coin == 0)))
	{
		if (up == 'C')
			all->hero.coin--;
		all->array[all->hero.y][all->hero.x] = '0';
		all->array[all->hero.y - 1][all->hero.x] = 'P';
		all->hero.y--;
		all->hero.moves++;
		if (up == 'E' || up == 'X')
		{
			if (up == 'E')
				printf("YOU WIN!\n");
			if (up == 'X')
				printf("TOUCHED AN ENEMY! YOU LOOSE!\n");
			ft_close(&(all->ptrs), &(all->size_map), all->array,
				&(all->images));
		}
		printf("Moves: %d\n", all->hero.moves);
		ft_fill_window(all->array, &(all->size_map), &(all->ptrs),
			&(all->images));
	}
}

void	ft_down(t_content *all)
{
	char	down;

	down = all->array[all->hero.y + 1][all->hero.x];
	if (down != '1' && (down != 'E' || (down == 'E' && all->hero.coin == 0)))
	{
		if (down == 'C')
			all->hero.coin--;
		all->array[all->hero.y][all->hero.x] = '0';
		all->array[all->hero.y + 1][all->hero.x] = 'P';
		all->hero.y++;
		all->hero.moves++;
		if (down == 'E' || down == 'X')
		{
			if (down == 'E')
				printf("YOU WIN!\n");
			if (down == 'X')
				printf("TOUCHED AN ENEMY! YOU LOOSE!\n");
			ft_close(&(all->ptrs), &(all->size_map), all->array,
				&(all->images));
		}
		printf("Moves: %d\n", all->hero.moves);
		ft_fill_window(all->array, &(all->size_map), &(all->ptrs),
			&(all->images));
	}
}

void	ft_right(t_content *all)
{
	char	right;

	right = all->array[all->hero.y][all->hero.x + 1];
	if (right != '1' && (right != 'E' || (right == 'E'
				&& all->hero.coin == 0)))
	{
		if (right == 'C')
			all->hero.coin--;
		all->array[all->hero.y][all->hero.x] = '0';
		all->array[all->hero.y][all->hero.x + 1] = 'P';
		all->hero.x++;
		all->hero.moves++;
		if (right == 'E' || right == 'X')
		{
			if (right == 'E')
				printf("YOU WIN!\n");
			if (right == 'X')
				printf("TOUCHED AN ENEMY! YOU LOOSE!\n");
			ft_close(&(all->ptrs), &(all->size_map), all->array,
				&(all->images));
		}
		printf("Moves: %d\n", all->hero.moves);
		ft_fill_window(all->array, &(all->size_map), &(all->ptrs),
			&(all->images));
	}
}

void	ft_left(t_content *all)
{
	char	left;

	left = all->array[all->hero.y][all->hero.x - 1];
	if (left != '1' && (left != 'E' || (left == 'E'
				&& all->hero.coin == 0)))
	{
		if (left == 'C')
			all->hero.coin--;
		all->array[all->hero.y][all->hero.x] = '0';
		all->array[all->hero.y][all->hero.x - 1] = 'P';
		all->hero.x--;
		all->hero.moves++;
		if (left == 'E' || left == 'X')
		{
			if (left == 'E')
				printf("YOU WIN!\n");
			if (left == 'X')
				printf("TOUCHED AN ENEMY! YOU LOOSE!\n");
			ft_close(&(all->ptrs), &(all->size_map), all->array,
				&(all->images));
		}
		printf("Moves: %d\n", all->hero.moves);
		ft_fill_window(all->array, &(all->size_map), &(all->ptrs),
			&(all->images));
	}
}

int	ft_close(t_ptr *ptrs, t_coord *size_map, char **array, t_stimages *images)
{
	ft_free(array, size_map);
	ft_destroy_img(ptrs->mlx_ptr, images, 5);
	mlx_destroy_window(ptrs->mlx_ptr, ptrs->win_ptr);
	exit(0);
}
