/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nimorel <nimorel <marvin@42.fr> >          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 10:13:43 by nimorel           #+#    #+#             */
/*   Updated: 2025/02/16 12:24:43 by nimorel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	ft_draw_line(t_point p1, t_point p2, t_map *map)
{
	t_point	proj_p1;
	t_point	proj_p2;
	double	x;
	double	y;
	double	dx;
	double	dy;
	double	step;
	int		i;
	t_color	color1;
	t_color	color2;
	t_color interpolated_color;

	color1 = ft_get_color_by_height(p1.z);
    color2 = ft_get_color_by_height(p2.z);
	proj_p1 = ft_project_iso(p1, map);
	proj_p2 = ft_project_iso(p2, map);
	p1.color = (t_color){0, 255, 0};
	p2.color = (t_color){0, 255, 0};
	x = proj_p1.x;
	y = proj_p1.y;
	dx = proj_p2.x - proj_p1.x;
	dy = proj_p2.y - proj_p1.y;
	step = fmax(fabs(dx), fabs(dy));
	i = 0;
	dx = dx / step;
	dy = dy / step;
	while (i <= step)
	{
        interpolated_color.r = (int)((1 - (i / step)) * color1.r + (i / step) * color2.r);
        interpolated_color.g = (int)((1 - (i / step)) * color1.g + (i / step) * color2.g);
        interpolated_color.b = (int)((1 - (i / step)) * color1.b + (i / step) * color2.b);
        interpolated_color.r = fmin(fmax(interpolated_color.r, 0), 255);
        interpolated_color.g = fmin(fmax(interpolated_color.g, 0), 255);
        interpolated_color.b = fmin(fmax(interpolated_color.b, 0), 255);
        mlx_pixel_put(map->mlx_ptr, map->win_ptr, (int)x, (int)y, ft_get_color(interpolated_color));
		x = x + dx;
		y = y + dy;
		i++;
	}
}

void	ft_draw(t_map *map)
{
	int	row;
	int	col;

	row = 0;
	while (row < map->map_height)
	{
		col = 0;
		while (col < map->map_width)
		{
			if (col < map->map_width - 1)
				ft_draw_line(map->coordinates[row][col],
					map->coordinates[row][col + 1], map);
			if (row < map->map_height - 1)
				ft_draw_line(map->coordinates[row][col],
					map->coordinates[row + 1][col], map);
			col++;
		}
		row++;
	}
}

t_point	ft_project_iso(t_point p, t_map *map)
{
	t_point	proj;
	double	radian;

	radian = 0.523599;
	p.z = p.z * map->z_scale;
	proj.x = (p.x - p.y) * cos(radian) * map->scale + map->x_offset;
	proj.y = (p.x + p.y) * sin(radian) * map->scale - (p.z * map->scale / 2)
		+ map->y_offset;
	return (proj);
}

//angle = 0.523599 radians = 30°