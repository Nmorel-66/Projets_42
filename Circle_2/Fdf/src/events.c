/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nimorel <nimorel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 10:32:56 by nimorel           #+#    #+#             */
/*   Updated: 2025/02/18 17:34:01 by nimorel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void ft_free_coordinates(t_map *map)
{
	int y;

	if (map->coordinates != NULL)
	{
		y = 0;
		while (y < map->map_height)
		{
			if (map->coordinates[y] != NULL)
				free(map->coordinates[y]);
			y++;
		}
		free(map->coordinates);
		map->coordinates = NULL;
	}
}

void	ft_exit(t_map *map)
{
	//ft_free_coordinates(map);
	mlx_destroy_image(map->mlx_ptr, map->img.img_ptr);
	mlx_destroy_window(map->mlx_ptr, map->win_ptr);
	
	exit(0);
}

void	ft_scale_up(t_map *map)
{
	map->scale = map->scale + 2;
	mlx_clear_window(map->mlx_ptr, map->win_ptr);
	ft_draw(map);
	ft_menu(map);
}

void	ft_scale_down(t_map *map)
{
	map->scale = map->scale - 2;
	if (map->scale <= 1)
		map->scale = 1;
	mlx_clear_window(map->mlx_ptr, map->win_ptr);
	ft_draw(map);
	ft_menu(map);
}

void	ft_height_up(t_map *map)
{
	map->z_scale = map->z_scale * 2;
	mlx_clear_window(map->mlx_ptr, map->win_ptr);
	ft_draw(map);
	ft_menu(map);
}

void	ft_height_down(t_map *map)
{
	map->z_scale = map->z_scale / 2;
	if (map->z_scale <= 1)
		map->z_scale = 1;
	mlx_clear_window(map->mlx_ptr, map->win_ptr);
	ft_draw(map);
	ft_menu(map);
}
