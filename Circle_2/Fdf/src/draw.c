/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nimorel <nimorel <marvin@42.fr> >          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 10:13:43 by nimorel           #+#    #+#             */
/*   Updated: 2025/03/09 16:44:08 by nimorel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

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
	t_color		point_color;

	line_data.proj_p1 = ft_project_iso(p1, map);
	line_data.proj_p2 = ft_project_iso(p2, map);
	line_data.dx = line_data.proj_p2.x - line_data.proj_p1.x;
	line_data.dy = line_data.proj_p2.y - line_data.proj_p1.y;
	line_data.dz = p2.z - p1.z;
	line_data.step = fmax(abs(line_data.proj_p2.x - line_data.proj_p1.x),
			abs(line_data.proj_p2.y - line_data.proj_p1.y));
	line_data.inv_step = 1.0 / line_data.step;
	i = 0;
	while (i <= line_data.step)
	{
		line_data.current_x = line_data.proj_p1.x + line_data.dx * i
			* line_data.inv_step;
		line_data.current_y = line_data.proj_p1.y + line_data.dy * i
			* line_data.inv_step;
		line_data.current_z = p1.z + line_data.dz * i * line_data.inv_step;
		point_color = ft_get_color_by_height(line_data.current_z, map);
		mlx_pixel_put(map->mlx_ptr, map->win_ptr, (int)line_data.current_x,
			(int)line_data.current_y, ft_get_color(point_color));
		i++;
	}
}

static void	ft_adjust_offset(t_map *map)
{
	map->x_offset = (SCREEN_WIDTH - (map->map_width * map->scale)) / 2;
	map->y_offset = (SCREEN_HEIGHT - (map->map_height * map->scale)) / 2;
}

static void	ft_adjust_scale(t_map *map)
{
	int	maxi;

	maxi = fmax(map->map_width, map->map_height);
	while (maxi * map->scale > 1000)
		map->scale--;
	ft_adjust_offset(map);
}

void	ft_draw(t_map *map)
{
	int	row;
	int	col;
	int	index;

	row = 0;
	ft_adjust_scale(map);
	while (row < map->map_height)
	{
		col = 0;
		while (col < map->map_width)
		{
			index = row * map->map_width + col;
			if (col < map->map_width - 1)
				ft_draw_line(map->coordinates[index],
							map->coordinates[index + 1], map);
			if (row < map->map_height - 1)
				ft_draw_line(map->coordinates[index],
							map->coordinates[index + map->map_width], map);
			col++;
		}
		row++;
	}
}

/*void	ft_draw_point(t_line_data *line_data, t_map *map, int i)
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
}*/

/*void	ft_draw_line(t_point p1, t_point p2, t_map *map)
{
	t_line_data	line_data;
	int			i;

	line_data.proj_p1 = ft_project_iso(p1, map);
	line_data.proj_p2 = ft_project_iso(p2, map);
	line_data.p1 = p1;
	line_data.p2 = p2;
	line_data.dx = line_data.proj_p2.x - line_data.proj_p1.x;
	line_data.dy = line_data.proj_p2.y - line_data.proj_p1.y;
	line_data.dz = p2.z - p1.z;
	line_data.z1 = p1.z;
	line_data.step = fmax(fabs(line_data.dx), fabs(line_data.dy));
	i = 0;
	while (i <= line_data.step)
	{
		ft_draw_point(&line_data, map, i);
		i++;
	}
}*/
