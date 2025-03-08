/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nimorel <nimorel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 10:13:43 by nimorel           #+#    #+#             */
/*   Updated: 2025/03/08 14:54:28 by nimorel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	ft_draw_point(t_line_data *line_data, t_map *map, int i)
{
	double	x;
	double	y;
	t_color	point_color;

	x = line_data->proj_p1.x + (line_data->proj_p2.x - line_data->proj_p1.x)
		* (i / line_data->step);
	y = line_data->proj_p1.y + (line_data->proj_p2.y - line_data->proj_p1.y)
		* (i / line_data->step);
	point_color = ft_get_color_by_height(((1 - (i / line_data->step))
				* line_data->p1.z + (i / line_data->step) * line_data->p2.z),
			map);
	mlx_pixel_put(map->mlx_ptr, map->win_ptr, (int)x, (int)y,
		ft_get_color(point_color));
}

t_point	ft_project_iso(t_point p, t_map *map)
{
	t_point	proj;

	p.z = p.z * map->z_scale;
	proj.x = (p.x - p.y) * cos(map->radian) * map->scale + map->x_offset;
	proj.y = (p.x + p.y) * sin(map->radian) * map->scale
		- (p.z * map->scale / 2) + map->y_offset;
	return (proj);
}

void	ft_draw_line(t_point p1, t_point p2, t_map *map)
{
	t_line_data	line_data;
	int			i;

	line_data.proj_p1 = ft_project_iso(p1, map);
	line_data.proj_p2 = ft_project_iso(p2, map);
	line_data.p1 = p1;
	line_data.p2 = p2;
	line_data.step = fmax(fabs(line_data.proj_p2.x - line_data.proj_p1.x),
			fabs(line_data.proj_p2.y - line_data.proj_p1.y));
	i = 0;
	while (i <= line_data.step)
	{
		ft_draw_point(&line_data, map, i);
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

