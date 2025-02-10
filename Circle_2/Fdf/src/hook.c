/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nimorel <nimorel <marvin@42.fr> >          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 10:25:02 by nimorel           #+#    #+#             */
/*   Updated: 2025/02/10 11:29:31 by nimorel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int		ft_hook_events(int keycode, t_map *map)
{
	if (keycode == 53)
	{
		mlx_destroy_window(map->mlx_ptr, map->win_ptr);
		exit(0);
	}
	if (keycode == 124)
	{	
		map->scale = map->scale + 2;
		mlx_clear_window(map->mlx_ptr, map->win_ptr);
		ft_draw(map);
	}
	if (keycode == 123)
	{	
		mlx_clear_window(map->mlx_ptr, map->win_ptr);
		map->scale = map->scale - 2;
		ft_draw(map);
	}
	return (0);
}

int	ft_close_window(t_map *map)
{
	mlx_destroy_window(map->mlx_ptr, map->win_ptr);
	exit(0); 
	return (0);
}
