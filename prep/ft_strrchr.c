/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samoreno <samoreno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 09:56:46 by samoreno          #+#    #+#             */
/*   Updated: 2022/01/28 13:37:58 by samoreno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

char	*ft_strrchr(const char *s, int c)
{
	int	len_s;

	len_s = ft_strlen(s);
	while (s[len_s] != (char)c && len_s)
	{
		if (s[len_s] == (char)c)
			return ((char *)&s[len_s]);
		len_s--;
	}
	if (s[len_s] != (char)c)
		return (0);
	return ((char *)&s[len_s]);
}
