/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samoreno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 10:50:20 by samoreno          #+#    #+#             */
/*   Updated: 2021/11/16 12:12:08 by samoreno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>

void	ft_copy(char *dst, const char *src);
void	ft_strjoin(char *s1, char *s2);
int		ft_strlen(const char *s);
char	*ft_strchr(const char *s, int c);
char	*get_next_line(int fd);
char	*ft_trunc(char *concat);

#endif
