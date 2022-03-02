/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_enemy_mood.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samoreno <samoreno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 09:31:59 by samoreno          #+#    #+#             */
/*   Updated: 2022/01/25 09:44:13 by samoreno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static int	ft_obstacle(char **array, int x, int y, int where)
{
	if (where == 'L')
	{
		if (array[y][x] != 'C' && array[y][x] != 'X' && array[y][x] != '1'
		&& array[y][x] != 'E' && array[y][x] != 'P' && array[y][x - 1] != 'X')
			return (0);
	}
	if (where == 'R')
	{
		if (array[y][x] != 'C' && array[y][x] != 'X' && array[y][x] != '1'
		&& array[y][x] != 'E' && array[y][x] != 'P' && array[y][x + 1] != 'X')
			return (0);
	}
	if (where == 'D')
	{
		if (array[y][x] != 'C' && array[y][x] != 'X' && array[y][x] != '1'
		&& array[y][x] != 'E' && array[y][x] != 'P' && array[y + 1][x] != 'X')
			return (0);
	}
	if (where == 'U')
	{
		if (array[y][x] != 'C' && array[y][x] != 'X' && array[y][x] != '1'
		&& array[y][x] != 'E' && array[y][x] != 'P' && array[y - 1][x] != 'X')
			return (0);
	}
	return (1);
}

int	ft_horizontal(int x, int y, char **copy, t_content *all)
{
	int	diff_x;
	int	diff_y;

	diff_x = x - all->hero.x;
	diff_y = y - all->hero.y;
	if (diff_x > 0)
	{
		if (ft_obstacle(copy, x - 1, y, 'L') == 0)
		{
			all->array[y][x - 1] = 'X';
			all->array[y][x] = '0';
			return (diff_y);
		}
		return (diff_y += diff_x);
	}
	else
	{
		if (ft_obstacle(copy, x + 1, y, 'R') == 0)
		{
			all->array[y][x + 1] = 'X';
			all->array[y][x] = '0';
			return (diff_y);
		}
		return (diff_y -= diff_x);
	}
}

void	ft_vertical(int x, int y, char **copy, t_content *all)
{
	int	diff_x;
	int	diff_y;

	diff_x = x - all->hero.x;
	diff_y = y - all->hero.y;
	if (diff_y > 0)
	{
		if (ft_obstacle(copy, x, y - 1, 'U') == 0)
		{
				all->array[y - 1][x] = 'X';
			all->array[y][x] = '0';
		}
	}
	if (diff_y <= 0)
	{
		if (ft_obstacle(copy, x, y + 1, 'D') == 0)
		{
			all->array[y + 1][x] = 'X';
			all->array[y][x] = '0';
		}
	}
}
