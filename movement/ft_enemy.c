/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_enemy.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samoreno <samoreno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 09:32:49 by samoreno          #+#    #+#             */
/*   Updated: 2022/01/25 09:44:33 by samoreno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static char	**ft_copy_map(t_content *all);
static void	ft_fill_copy(char **copy, t_content *all);
static void	ft_mood(char **copy, t_content *all, int y, int x);

void	ft_enemy(t_content *all)
{
	int		iter_word;
	int		iter_char;
	char	**copy;

	iter_word = 0;
	copy = ft_copy_map(all);
	while (iter_word < all->size_map.y)
	{
		iter_char = 0;
		while (copy[iter_word][iter_char])
		{
			if (copy[iter_word][iter_char] == 'X')
				ft_mood(copy, all, iter_word, iter_char);
			iter_char++;
		}
		iter_word++;
	}
	ft_fill_window(all->array, &(all->size_map), &(all->ptrs),
		&(all->images));
	ft_free(copy, &(all->size_map));
}

static char	**ft_copy_map(t_content *all)
{
	char	**copy;
	int		iter;

	copy = malloc(sizeof(char *) * all->size_map.y + 1);
	iter = 0;
	if (!copy)
	{
		mlx_destroy_window(all->ptrs.mlx_ptr, all->ptrs.win_ptr);
		ft_destroy_img(all->ptrs.mlx_ptr, &(all->images), 5);
		ft_error_free(all->array, &(all->size_map), ERRMEM);
	}
	while (iter < all->size_map.y)
	{
		copy[iter] = malloc(sizeof(char) * (all->size_map.x + 1));
		if (!copy[iter])
		{
			ft_free_array(copy, iter);
			mlx_destroy_window(all->ptrs.mlx_ptr, all->ptrs.win_ptr);
			ft_destroy_img(all->ptrs.mlx_ptr, &(all->images), 5);
			ft_error_free(all->array, &(all->size_map), ERRMEM);
		}
		iter++;
	}
	ft_fill_copy(copy, all);
	return (copy);
}

static void	ft_fill_copy(char **copy, t_content *all)
{
	int		iter_word;
	int		iter_char;

	iter_word = 0;
	while (iter_word < all->size_map.y)
	{
		iter_char = 0;
		while (all->array[iter_word][iter_char])
		{
			copy[iter_word][iter_char] = all->array[iter_word][iter_char];
			iter_char++;
		}
		copy[iter_word][iter_char] = 0;
		iter_word++;
	}
}

static void	ft_mood(char **copy, t_content *all, int y, int x)
{
	int	diff_x;
	int	diff_y;

	diff_x = x - all->hero.x;
	diff_y = y - all->hero.y;
	if (diff_x > diff_y)
		diff_y = ft_horizontal(x, y, copy, all);
	if (diff_x <= diff_y)
		ft_vertical(x, y, copy, all);
}
