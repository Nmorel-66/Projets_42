/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nimorel <nimorel <marvin@42.fr> >          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 18:02:04 by nimorel           #+#    #+#             */
/*   Updated: 2025/02/16 18:43:59 by nimorel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	ft_menu(t_map *map)
{
	mlx_put_image_to_window(map->mlx_ptr, map->win_ptr, map->img.img_ptr, 0, 0);
	mlx_string_put(map->mlx_ptr, map->win_ptr, 10, 10, 0x00FF00, "Controls:");
	mlx_string_put(map->mlx_ptr, map->win_ptr, 10, 30, 0x00FF00,
		"Zoom: Scroll");
	mlx_string_put(map->mlx_ptr, map->win_ptr, 10, 50, 0x00FF00,
		"Move: Arrows");
	mlx_string_put(map->mlx_ptr, map->win_ptr, 10, 70, 0x00FF00,
		"Change height: shift +/-");
	mlx_string_put(map->mlx_ptr, map->win_ptr, 10, 90, 0x00FF00, "Exit: ESC");
}
