/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nimorel <nimorel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 10:25:02 by nimorel           #+#    #+#             */
/*   Updated: 2025/03/04 14:09:15 by nimorel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

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
	if (keycode == 65307)
		ft_exit(map);
	if (keycode == 65363)
		ft_move_right(map);
	if (keycode == 65361)
		ft_move_left(map);
	if (keycode == 65364)
		ft_move_up(map);
	if (keycode == 65362)
		ft_move_down(map);
	if (keycode == 61)
		ft_height_up(map);
	if (keycode == 45)
		ft_height_down(map);
	if (keycode == 97)
		ft_increase_radian(map);
	if (keycode == 113)
		ft_decrease_radian(map);
	return (0);
}

void	ft_increase_radian(t_map *map)
{
	map->radian = map->radian + 0.1;
	mlx_clear_window(map->mlx_ptr, map->win_ptr);
	ft_draw(map);
	ft_menu(map);
}

void	ft_decrease_radian(t_map *map)
{
	map->radian = map->radian - 0.1;
	mlx_clear_window(map->mlx_ptr, map->win_ptr);
	ft_draw(map);
	ft_menu(map);
}

/*int	ft_key_events(int keycode, t_map *map)
{
	#ifdef __APPLE__
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
		ft_height_up(map);
	if (keycode == 24)
		ft_height_down(map);
	#elif __linux__
	if (keycode == 65307)
		ft_exit(map);
	if (keycode == 65363)
		ft_move_right(map);
	if (keycode == 65361)
		ft_move_left(map);
	if (keycode == 65364)
		ft_move_up(map);
	if (keycode == 65362)
		ft_move_down(map);
	if (keycode == 61)
		ft_height_up(map);
	if (keycode == 45)
		ft_height_down(map);
	#endif	
	return (0);
}*/
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
	printf("Mouse button: %d\n", button);
	printf("Key pressed: %d\n", keycode);
**************************************/