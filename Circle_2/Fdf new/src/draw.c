/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nimorel <nimorel <marvin@42.fr> >          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 10:13:43 by nimorel           #+#    #+#             */
/*   Updated: 2025/03/12 21:26:56 by nimorel          ###   ########.fr       */
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
		map->img.data[(int)line_data.current_x + (int)line_data.current_y
			* SCREEN_WIDTH] = ft_get_point_color(line_data.current_z, map, p1);
		i++;
	}
}

void	ft_adjust_scale(t_map *map)
{
	int	max;

	max = fmax(map->map_width, map->map_height);
	map->scale = fmin((SCREEN_WIDTH / (max + 2)), (SCREEN_HEIGHT / (max + 2)));
	map->x_offset = (SCREEN_WIDTH - (map->map_width * map->scale));
	map->y_offset = (SCREEN_HEIGHT - (map->map_height * map->scale)) / 2;
}

void	ft_draw(t_map *map)
{
	int	row;
	int	col;
	int	index;

	row = 0;
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
	mlx_put_image_to_window(map->mlx_ptr, map->win_ptr, map->img.img_ptr, 0, 0);
}
