/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samoreno <samoreno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 08:44:51 by samoreno          #+#    #+#             */
/*   Updated: 2022/01/31 14:20:26 by samoreno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	ft_check_array(char **array, t_coord *size_map)
{
	int	iter_word;
	int	iter_char;
	int	flags[3];

	iter_word = 0;
	flags[0] = 0;
	flags[1] = 0;
	flags[2] = 0;
	while (iter_word < size_map->y)
	{
		iter_char = 0;
		while (array[iter_word][iter_char])
		{
			if (array[iter_word][iter_char] == 'P')
				flags[0]++;
			if (array[iter_word][iter_char] == 'C')
				flags[1]++;
			if (array[iter_word][iter_char] == 'E')
				flags[2]++;
			iter_char++;
		}
		iter_word++;
	}
	if (flags[0] != 1 || flags[1] == 0 || flags[2] == 0)
		ft_error_free(array, size_map, ERRMAP);
}
