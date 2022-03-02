/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samoreno <samoreno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 11:51:42 by samoreno          #+#    #+#             */
/*   Updated: 2022/01/28 15:25:33 by samoreno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# define ESC  53
# define W  13
# define A  0
# define S  1
# define D  2
# define TILE 64
# define ERRARG "There must be a single map as an argument"
# define ERRMAP "Invalid map entry"
# define ERRFILE "Problem with file handling"
# define ERRMEM "Problem wiith memory allocation/usage"

# include "./gnl/get_next_line.h"
# include <mlx.h>
# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <errno.h>
# include <fcntl.h>
# include <string.h>

typedef struct s_ptr
{
	void	*mlx_ptr;
	void	*win_ptr;
}	t_ptr;

typedef struct s_image
{
	void	*img;
	char	*path;
	int		width;
	int		height;
}	t_image;

typedef struct s_stimages
{
	t_image	tile;
	t_image	wall;
	t_image	hero;
	t_image	coin;
	t_image	exit;
	t_image	enemy;
}	t_stimages;

typedef struct s_coord
{
	int	x;
	int	y;
}	t_coord;

typedef struct s_hero
{
	int	x;
	int	y;
	int	coin;
	int	moves;
}	t_hero;

typedef struct s_content
{
	char		**array;
	t_ptr		ptrs;
	t_stimages	images;
	t_hero		hero;
	t_coord		size_map;
}	t_content;

void		ft_error(char *error);
void		ft_error_free(char **array, t_coord *rowcol, char *error);
void		ft_free(char **array, t_coord *rowcol);
int			ft_newline(char *line);
int			key_hook(int key, t_content *all);
int			mouse_hook(int button, int x, int y, t_ptr *ptrs);
int			ft_close(t_ptr *ptrs, t_coord *size_map,
				char **array, t_stimages *images);
t_stimages	ft_images(void *mlx_ptr, t_coord *size_map, char **array);
void		*ft_window(t_coord window, void *mlx_ptr, t_stimages *images,
				char **array);
void		ft_fill_window(char **array, t_coord *size_map, t_ptr *ptr,
				t_stimages *images);
t_hero		ft_hero(char **array, t_coord *size_map);
t_coord		ft_size_map(char **argv);
char		**ft_array(t_coord *rowcol, char **argv);
t_content	ft_unite(char **array, t_ptr *ptr, t_stimages *images,
				t_coord *size_map);
void		ft_up(t_content *all);
void		ft_down(t_content *all);
void		ft_right(t_content *all);
void		ft_left(t_content *all);
void		ft_destroy_img(void *mlx_ptr, t_stimages *images, int n_img);
int			ft_red_cross(t_content *all);
void		ft_check_array(char **array, t_coord *size_map);
void		ft_enemy(t_content *all);
void		ft_free_array(char **array, int words);
char		*ft_itoa(int n);
int			ft_horizontal(int x, int y, char **copy, t_content *all);
void		ft_vertical(int x, int y, char **copy, t_content *all);
char		*ft_strrchr(const char *s, int c);
int			ft_strncmp(const char *s1, const char*s2, size_t n);
#endif