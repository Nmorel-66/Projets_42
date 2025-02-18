/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nimorel <nimorel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 10:25:02 by nimorel           #+#    #+#             */
/*   Updated: 2025/02/18 15:42:38 by nimorel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
#include <stdio.h>

int	ft_mouse_events(int button, int x, int y, t_map *map)
{
	(void)x;
	(void)y;
	if (button == 4)
		ft_scale_down(map);
	if (button == 5)
		ft_scale_up(map);
	return (0);
}

int	ft_key_events(int keycode, t_map *map)
{
	printf("keycode = %d\n", keycode);
	if (keycode == 65307)//53)
		ft_exit(map);
	if (keycode == 65363) //124
		ft_move_right(map);
	if (keycode == 65361) //123
		ft_move_left(map);
	if (keycode == 65364) //125
		ft_move_up(map);
	if (keycode == 65362) //126
		ft_move_down(map);
	if (keycode == 61) //44
		ft_height_up(map);
	if (keycode == 45) //24
		ft_height_down(map);
	if (keycode == 97) //a
		ft_increase_radian(map);
	if (keycode == 113) //q
		ft_decrease_radian(map);
	return (0);
}

int	ft_close_window(t_map *map)
{
	mlx_destroy_image(map->mlx_ptr, map->img.img_ptr);
	mlx_destroy_window(map->mlx_ptr, map->win_ptr);
	exit(0);
	return (0);
}
/*************************************/
/*        keycode for linux          */
/************************************** 
int	ft_keycode(int keycode, t_map *map)
{
	if (keycode == 65307) ESC
		ft_exit(map);
	if (keycode == 65363) right arrow
		ft_move_right(map);
	if (keycode == 65361) left arrow
		ft_move_left(map);
	if (keycode == 65362) up arrow
		ft_move_up(map);
	if (keycode == 65364) down arrow
		ft_move_down(map);
	if (keycode == 65451) shift +
		ft_height_up(map);
	if (keycode == 65453) - (without shift)
		ft_height_down(map); 
	return (0);
}*/
/*************************************/
/*        keycode for MacOS          */
/************************************** 
int	ft_keycode(int keycode, t_map *map)
{
	if (keycode == 53) ESC
		ft_exit(map);
	if (keycode == 124) right arrow
		ft_move_right(map);
	if (keycode == 125) left arrow
		ft_move_left(map);
	if (keycode == 65362) up arrow
		ft_move_up(map);
	if (keycode == 65364) down arrow
		ft_move_down(map);
	if (keycode == 44) shift +
		ft_height_up(map);
	if (keycode == 24) shif -
		ft_height_down(map);
	return (0);
}*/
/**************************************
	printf("Mouse button: %d\n", button);
	printf("Key pressed: %d\n", keycode);
**************************************/