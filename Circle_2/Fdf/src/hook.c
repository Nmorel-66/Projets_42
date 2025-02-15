/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nimorel <nimorel <marvin@42.fr> >          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 10:25:02 by nimorel           #+#    #+#             */
/*   Updated: 2025/02/15 16:00:52 by nimorel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int ft_mouse_events(int button, int x, int y, t_map *map)
{
	(void)x;
	(void)y;
	printf("Mouse button: %d\n", button);
	if (button == 4)
		ft_scale_down(map);
	if (button == 5)
		ft_scale_up(map);
	return (0);
}

int	ft_key_events(int keycode, t_map *map)
{
	printf("Key pressed: %d\n", keycode);
	if (keycode == 53)
		ft_exit(map);
	if (keycode == 124)
		ft_move_right(map);
	if (keycode == 123)
		ft_move_left(map);
	if (keycode == 125)
		ft_move_up(map);
	if (keycode == 126)
		ft_move_down(map);
	if (keycode == 44)
		ft_scale_up(map);
	if (keycode == 47)
		ft_scale_down(map);
	return (0);
}


int	ft_close_window(t_map *map)
{
	mlx_destroy_window(map->mlx_ptr, map->win_ptr);
	exit(0); 
	return (0);
}
/*************************************/
/*        keycode for linux          */
/************************************** 
int	ft_keycode(int keycode, t_map *map)
{
	if (keycode == 65307)
		ft_exit(map);
	if (keycode == 65363)
		ft_move_right(map);
	if (keycode == 65361)
		ft_move_left(map);
	if (keycode == 65362)
		ft_move_up(map);
	if (keycode == 65364)
		ft_move_down(map);
	return (0);
}
**************************************/