/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nimorel <nimorel <marvin@42.fr> >          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 15:26:40 by nimorel           #+#    #+#             */
/*   Updated: 2025/02/10 11:02:57 by nimorel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "../minilibx_macos/mlx.h"
# include "../Libft/libft.h"
# include "../Printf/Includes/ft_printf.h"
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <math.h>
# include <errno.h>
# include <string.h>

# define SCREEN_WIDTH 800
# define SCREEN_HEIGHT 600

typedef struct s_point
{
	double	x;
	double	y;
	double	z;
	int		color;
}			t_point;

typedef struct s_map
{
	t_point	**coordinates;
	void	*mlx_ptr;
	void	*win_ptr;
	void	*img_ptr;
	char	*data_addr;
	int		bits_per_pixel;
	int		size_line;
	int		endian;
	int		map_width;
	int		map_height;
	int		scale;
	int		x_offset;
	int		y_offset;
}			t_map;

/* fdf.c */
void	ft_error_handler(char *message, int exit_code);

 /* hook.c */
int		ft_key_hook(int keycode, t_map *map);
int		ft_close_window(t_map *map);

/* read.c */
void	free_split(char **split);
int		ft_read_map(char *file, t_map *map);
int		ft_map_dimensions(char *file, t_map *map);

/* draw.c */
void	ft_draw(t_map *map);
void	ft_draw_line(t_point p1, t_point p2, t_map *map);

/* init.c */
int		ft_init_coordinates(t_map *map);
void	ft_map_init(t_map *param);


#endif