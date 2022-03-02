/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unite.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samoreno <samoreno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 11:25:09 by samoreno          #+#    #+#             */
/*   Updated: 2022/01/25 09:23:25 by samoreno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

t_content	ft_unite(char **array, t_ptr *ptr, t_stimages *images,
			t_coord *size_map)
{
	t_hero		hero;
	t_content	all;

	hero = ft_hero(array, size_map);
	all.hero = hero;
	all.images = *images;
	all.ptrs = *ptr;
	all.size_map = *size_map;
	all.array = array;
	return (all);
}
