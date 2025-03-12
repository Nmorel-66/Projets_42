/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nimorel <nimorel <marvin@42.fr> >          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 10:32:56 by nimorel           #+#    #+#             */
/*   Updated: 2025/03/12 21:34:54 by nimorel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int	ft_exit(t_map *map)
{
	ft_free_coordinates(map);
	mlx_destroy_image(map->mlx_ptr, map->img.img_ptr);
	mlx_destroy_window(map->mlx_ptr, map->win_ptr);
	//mlx_destroy_display(map->mlx_ptr);
	free(map->mlx_ptr);
	exit(0);
	return (0);
}

void	ft_scale_up(t_map *map)
{
	ft_refresh_window(map);
	map->scale = map->scale + 2;
	ft_draw(map);
	ft_menu(map);
}

void	ft_scale_down(t_map *map)
{
	ft_refresh_window(map);
	map->scale = map->scale - 2;
	if (map->scale <= 1)
		map->scale = 1;
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
