/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nimorel <nimorel <marvin@42.fr> >          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 15:26:40 by nimorel           #+#    #+#             */
/*   Updated: 2025/02/16 12:05:29 by nimorel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "../minilibx_macos/mlx.h"
# include "../Libft/libft.h"
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <math.h>
# include <errno.h>
# include <string.h>

# define SCREEN_WIDTH 1280
# define SCREEN_HEIGHT 720

typedef struct s_color
{
	int	r;
	int	g;
	int	b;
}		t_color;

typedef struct s_point
{
	double	x;
	double	y;
	double	z;
	t_color	color;
}			t_point;

typedef struct s_map
{
	t_point	**coordinates;
	void	*mlx_ptr;
	void	*win_ptr;
	int		map_width;
	int		map_height;
	int		scale;
	int		z_scale;
	int		x_offset;
	int		y_offset;
}			t_map;

/* fdf.c */
void	ft_error_handler(char *message, int exit_code);

 /* hook.c */
int		ft_key_events(int keycode, t_map *map);
int		ft_mouse_events(int button, int x, int y, t_map *map);
int		ft_close_window(t_map *map);

/* read.c */
void	free_split(char **split);
int		ft_read_map(char *file, t_map *map);
int		ft_map_dimensions(char *file, t_map *map);

/* draw.c */
void	ft_draw(t_map *map);
void	ft_draw_line(t_point p1, t_point p2, t_map *map);
t_point	ft_project_iso(t_point p, t_map *map);

/* init.c */
int		ft_init_coordinates(t_map *map);
void	ft_map_init(t_map *param);

/* events.c */
void	ft_exit(t_map *map);
void	ft_scale_up(t_map *map);
void	ft_scale_down(t_map *map);
void	ft_height_up(t_map *map);
void	ft_height_down(t_map *map);
void	ft_move_right(t_map *map);
void	ft_move_left(t_map *map);
void	ft_move_up(t_map *map);
void	ft_move_down(t_map *map);

/* color.c */
t_color	ft_get_color_by_height(double z);
int		ft_get_color(t_color color);

#endif