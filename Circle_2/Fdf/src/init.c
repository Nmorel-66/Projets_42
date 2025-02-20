/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nimorel <nimorel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 11:00:43 by nimorel           #+#    #+#             */
/*   Updated: 2025/02/20 15:09:55 by nimorel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	ft_map_init(t_map *new_map)
{
	new_map->mlx_ptr = mlx_init();
	new_map->win_ptr = mlx_new_window(new_map->mlx_ptr, SCREEN_WIDTH,
			SCREEN_HEIGHT, "Project_FDF");
	new_map->map_width = 0;
	new_map->map_height = 0;
	new_map->coordinates = NULL;
	new_map->scale = 20;
	new_map->z_scale = 1;
	new_map->x_offset = 0;
	new_map->y_offset = 0;
	new_map->z_min = -10;
	new_map->z_max = 10;
	new_map->radian = 0.523599;
}

int	ft_init_coordinates(t_map *map)
{
	int	y;

	map->coordinates = (t_point **)malloc(sizeof(t_point *) * map->map_height);
	if (map->coordinates == NULL)
		return (-1);
	y = 0;
	while (y < map->map_height)
	{
		map->coordinates[y] = (t_point *)malloc(sizeof(t_point)
				* map->map_width);
		if (map->coordinates[y] == NULL)
			return (-1);
		y++;
	}
	return (0);
}

void	ft_free_coordinates(t_map *map)
{
	int	y;

	if (map->coordinates == NULL)
		return ;
	y = 0;
	while (y < map->map_height)
	{
		free(map->coordinates[y]);
		y++;
	}
	free (map->coordinates);
}
