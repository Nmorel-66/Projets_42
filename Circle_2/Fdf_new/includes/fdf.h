/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nimorel <nimorel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 15:26:40 by nimorel           #+#    #+#             */
/*   Updated: 2025/03/13 11:23:38 by nimorel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

//# include "../minilibx_macos/mlx.h"
# include "../minilibx-linux/mlx.h"
# include "../Libft/libft.h"
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <math.h>
# include <errno.h>
# include <string.h>
# include <stdio.h>

# define SCREEN_WIDTH 1200
# define SCREEN_HEIGHT 900

typedef int	t_color;

typedef struct s_point
{
	short	x;
	short	y;
	short	z;
	t_color	color;
}			t_point;

typedef struct s_img
{
	void	*img_ptr;
	int		*data;
	int		bpp;
	int		size_line;
	int		endian;
}			t_img;

typedef struct s_map
{
	t_point	*coordinates;
	void	*mlx_ptr;
	void	*win_ptr;
	t_img	img;
	short	map_width;
	short	map_height;
	short	scale;
	short	z_scale;
	short	x_offset;
	short	y_offset;
	short	z_min;
	short	z_max;
	short	left;
	short	right;
	short	top;
	short	bottom;
	float	radian;
	int		is_def_col;
}			t_map;

typedef struct s_line_data
{
	t_point	proj_p1;
	t_point	proj_p2;
	float	step;
	float	dx;
	float	dy;
	float	dz;
	float	inv_step;
	short	current_x;
	short	current_y;
	short	current_z;
}			t_line_data;

/* hook.c */
int		ft_key_events(int keycode, t_map *map);
int		ft_mouse_events(int button, int x, int y, t_map *map);
void	ft_increase_radian(t_map *map);
void	ft_decrease_radian(t_map *map);

/* read.c */
void	ft_free_split(char **split);
int		ft_read_map(char *file, t_map *map);
int		ft_map_dimensions(char *file, t_map *map);

/* draw.c */
void	ft_draw(t_map *map);
void	ft_draw_line(t_point p1, t_point p2, t_map *map);
t_point	ft_project_iso(t_point p, t_map *map);
void	ft_adjust_scale(t_map *map);

/* init.c */
void	ft_error_handler(char *message, int exit_code);
int		ft_init_coordinates(t_map *map);
void	ft_map_init(t_map *param);
void	ft_free_coordinates(t_map *map);

/* events.c */
int		ft_exit(t_map *map);
void	ft_scale_up(t_map *map);
void	ft_scale_down(t_map *map);
void	ft_height_up(t_map *map);
void	ft_height_down(t_map *map);

/* move.c */
void	ft_move_right(t_map *map);
void	ft_move_left(t_map *map);
void	ft_move_up(t_map *map);
void	ft_move_down(t_map *map);

/* color.c */
t_color	ft_get_color_by_height(float z, t_map *map);
void	ft_get_z(char *z_split, int index, t_map *map);
t_color	ft_get_point_color(int z, t_map *map, t_point p1);

/* menu.c */
void	ft_menu(t_map *map);

#endif