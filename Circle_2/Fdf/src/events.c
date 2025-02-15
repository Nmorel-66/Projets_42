/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nimorel <nimorel <marvin@42.fr> >          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 10:32:56 by nimorel           #+#    #+#             */
/*   Updated: 2025/02/15 21:31:31 by nimorel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	ft_exit(t_map *map)
{
	mlx_destroy_window(map->mlx_ptr, map->win_ptr);
	exit(0);
}

void	ft_scale_up(t_map *map)
{
	map->scale = map->scale + 2;
	mlx_clear_window(map->mlx_ptr, map->win_ptr);
	ft_draw(map);
}

void	ft_scale_down(t_map *map)
{
	map->scale = map->scale - 2;
	if (map->scale <= 1)
		map->scale = 1;
	mlx_clear_window(map->mlx_ptr, map->win_ptr);
	ft_draw(map);
}

void	ft_height_up(t_map *map)
{
	map->z_scale = map->z_scale * 2;
	mlx_clear_window(map->mlx_ptr, map->win_ptr);
	ft_draw(map);
}

void	ft_height_down(t_map *map)
{
	map->z_scale = map->z_scale / 2;
	if (map->z_scale <= 1)
		map->z_scale = 1;
	mlx_clear_window(map->mlx_ptr, map->win_ptr);
	ft_draw(map);
}
