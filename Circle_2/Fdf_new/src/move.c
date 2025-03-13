/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nimorel <nimorel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 14:15:30 by nimorel           #+#    #+#             */
/*   Updated: 2025/03/13 10:52:57 by nimorel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	ft_move_right(t_map *map)
{
	mlx_clear_window(map->mlx_ptr, map->win_ptr);
	map->x_offset = map->x_offset + 10;
	ft_draw(map);
	ft_menu(map);
}

void	ft_move_left(t_map *map)
{
	mlx_clear_window(map->mlx_ptr, map->win_ptr);
	map->x_offset = map->x_offset - 10;
	ft_draw(map);
	ft_menu(map);
}

void	ft_move_up(t_map *map)
{
	mlx_clear_window(map->mlx_ptr, map->win_ptr);
	map->y_offset = map->y_offset + 10;
	ft_draw(map);
	ft_menu(map);
}

void	ft_move_down(t_map *map)
{
	mlx_clear_window(map->mlx_ptr, map->win_ptr);
	map->y_offset = map->y_offset - 10;
	ft_draw(map);
	ft_menu(map);
}
