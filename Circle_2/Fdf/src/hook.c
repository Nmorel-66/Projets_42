/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nimorel <nimorel <marvin@42.fr> >          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 10:25:02 by nimorel           #+#    #+#             */
/*   Updated: 2025/02/10 10:12:12 by nimorel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int		ft_key_hook(int keycode, t_map *map)
{
	if (keycode == 53)
	{
		mlx_destroy_window(map->mlx_ptr, map->win_ptr);
		exit(0);
	}
	return (0);
}

int	ft_close_window(t_map *map)
{
	mlx_destroy_window(map->mlx_ptr, map->win_ptr);
	exit(0); 
	return (0);
}
