/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nimorel <nimorel <marvin@42.fr> >          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 10:13:43 by nimorel           #+#    #+#             */
/*   Updated: 2025/02/14 11:40:43 by nimorel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	ft_draw_line(t_point p1, t_point p2, t_map *map)
{
	t_point proj_p1;
	t_point proj_p2;
	double x;
	double y;
	double dx;
	double dy;
	double step;
	int i;
	
	proj_p1 = ft_project_iso(p1, map);;
	proj_p2 = ft_project_iso(p2, map);
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
		mlx_pixel_put(map->mlx_ptr, map->win_ptr, (int)x, (int)y, 0x00FF00);
		x = x + dx;
		y = y + dy;
		i++;
	}
}

void	ft_draw(t_map *map)
{
	int row;
	int col;

	map->x_offset = (SCREEN_WIDTH - (map->map_width * map->scale)) / 2;
	map->y_offset = (SCREEN_HEIGHT - (map->map_height * map->scale)) / 2;

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
	double	angle = 0.523599;

	p.z = p.z * map->z_scale;
	proj.x = (p.x - p.y) * cos(angle) * map->scale + map->x_offset;
	proj.y = (p.x + p.y) * sin(angle) * map->scale - (p.z * map->scale / 2)
		+ map->y_offset;
	return (proj);
}