/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nimorel <nimorel <marvin@42.fr> >          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 15:26:40 by nimorel           #+#    #+#             */
/*   Updated: 2025/03/08 21:14:26 by nimorel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "../minilibx_macos/mlx.h"
//# include "../minilibx-linux/mlx.h"
# include "../Libft/libft.h"
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <math.h>
# include <errno.h>
# include <string.h>
# include <stdio.h>

# define SCREEN_WIDTH 1200
# define SCREEN_HEIGHT 800

typedef struct s_color
{
	int	r;
	int	g;
	int	b;
}		t_color;

typedef struct s_point
{
	float	x;
	float	y;
	float	z;
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
	t_point	**coordinates;
	void	*mlx_ptr;
	void	*win_ptr;
	t_img	img;
	int		map_width;
	int		map_height;
	int		scale;
	int		z_scale;
	int		x_offset;
	int		y_offset;
	float	z_min;
	float	z_max;
	float	radian;
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
	float	current_x;
	float	current_y;
	float	current_z;
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
void	ft_draw_point(t_line_data *line_data, t_map *map, int i);
//void	ft_draw_point(t_line_data *line_data, t_map *map, int i, float inv_step);

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
int		ft_get_color(t_color color);
void	ft_get_z(char *z_split, int row, int col, t_map *map);

/* menu.c */
void	ft_menu(t_map *map);

#endif