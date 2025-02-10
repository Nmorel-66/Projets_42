/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nimorel <nimorel <marvin@42.fr> >          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 10:13:43 by nimorel           #+#    #+#             */
/*   Updated: 2025/02/10 10:53:48 by nimorel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	ft_draw_line(t_point p1, t_point p2, t_map *map)
{
	double x;
	double y;
	double dx;
	double dy;
	double step;
	int i;

	dx = (p2.x - p1.x) * map->scale;
	dy = (p2.y - p1.y) * map->scale;
	if (fabs(dx) > fabs(dy))
		step = fabs(dx);
	else
		step = fabs(dy);
	dx = dx / step;
	dy = dy / step;
	x = p1.x * map->scale;
	y = p1.y * map->scale;
	i = 0;
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
	int x;
	int y;
	
	y = 0;
	while (y < map->map_height)
	{
		x = 0;
		while (x < map->map_width)
		{
			if (x < map->map_width - 1)
				ft_draw_line(map->coordinates[y][x], map->coordinates[y][x + 1], map);
			if (y < map->map_height - 1)
				ft_draw_line(map->coordinates[y][x], map->coordinates[y + 1][x], map);
			x++;
		}
		y++;
	}
}