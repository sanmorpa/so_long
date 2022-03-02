/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samoreno <samoreno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 15:00:14 by samoreno          #+#    #+#             */
/*   Updated: 2022/01/25 09:22:55 by samoreno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	ft_error(char *error)
{
	printf("Error: %s\n", error);
	exit(1);
}

void	ft_error_free(char **array, t_coord *rowcol, char *error)
{
	ft_free(array, rowcol);
	printf("Error: %s\n", error);
	exit(1);
}
