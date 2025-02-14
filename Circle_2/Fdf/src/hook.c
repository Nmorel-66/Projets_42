/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nimorel <nimorel <marvin@42.fr> >          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 10:25:02 by nimorel           #+#    #+#             */
/*   Updated: 2025/02/14 11:23:46 by nimorel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int	ft_hook_events(int keycode, t_map *map)
{
	if (keycode == 53)
		ft_exit(map);
	if (keycode == 124)
		ft_scale_up(map);
	if (keycode == 123)
		ft_scale_down(map);
	if (keycode == 126)
		ft_height_up(map);
	if (keycode == 125)
		ft_height_down(map);
	return (0);
}


int	ft_close_window(t_map *map)
{
	mlx_destroy_window(map->mlx_ptr, map->win_ptr);
	exit(0); 
	return (0);
}
