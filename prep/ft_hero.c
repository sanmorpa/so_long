/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hero.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samoreno <samoreno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 14:34:17 by samoreno          #+#    #+#             */
/*   Updated: 2022/01/25 09:23:16 by samoreno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

t_hero	ft_hero(char **array, t_coord *size_map)
{
	t_hero	hero;
	int		iter_word;
	int		iter_char;

	iter_word = 0;
	hero.coin = 0;
	hero.moves = 0;
	while (iter_word < size_map->y)
	{
		iter_char = 0;
		while (array[iter_word][iter_char])
		{
			if (array[iter_word][iter_char] == 'P')
			{
				hero.x = iter_char;
				hero.y = iter_word;
			}
			if (array[iter_word][iter_char] == 'C')
				hero.coin++;
			iter_char++;
		}
		iter_word++;
	}
	return (hero);
}
