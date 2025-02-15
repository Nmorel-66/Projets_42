/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nimorel <nimorel <marvin@42.fr> >          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 14:15:30 by nimorel           #+#    #+#             */
/*   Updated: 2025/02/15 16:39:09 by nimorel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	ft_move_right(t_map *map)
{
	map->x_offset = map->x_offset + 10;
	mlx_clear_window(map->mlx_ptr, map->win_ptr);
	ft_draw(map);
}

void	ft_move_left(t_map *map)
{
	map->x_offset = map->x_offset - 10;
	mlx_clear_window(map->mlx_ptr, map->win_ptr);
	ft_draw(map);
}

void	ft_move_up(t_map *map)
{
	map->y_offset = map->y_offset + 10;
	mlx_clear_window(map->mlx_ptr, map->win_ptr);
	ft_draw(map);
}

void	ft_move_down(t_map *map)
{
	map->y_offset = map->y_offset - 10;
	mlx_clear_window(map->mlx_ptr, map->win_ptr);
	ft_draw(map);
}
