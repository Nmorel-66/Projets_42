/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nimorel <nimorel <marvin@42.fr> >          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 11:00:43 by nimorel           #+#    #+#             */
/*   Updated: 2025/03/12 21:34:28 by nimorel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	ft_error_handler(char *message, int exit_code)
{
	ft_putstr_fd("\033[1;31m", 2);
	ft_putstr_fd(message, 2);
	if (errno)
		ft_putstr_fd(strerror(errno), 2);
	ft_putstr_fd("\033[0m", 2);
	exit(exit_code);
}
/*void ft_init_img_ptr(t_map *map)
{
	map->img.img_ptr = mlx_new_image(map->mlx_ptr, SCREEN_WIDTH, SCREEN_HEIGHT);
	map->img.data = (int *)mlx_get_data_addr(map->img.img_ptr,
			&map->img.bpp, &map->img.size_line, &map->img.endian);
}*/

void	ft_refresh_window(t_map *map)
{
	mlx_clear_window(map->mlx_ptr, map->win_ptr);
	memset(map->img.data, 0, SCREEN_WIDTH * SCREEN_HEIGHT * sizeof(int));
}

void	ft_map_init(t_map *new_map)
{
	new_map->mlx_ptr = mlx_init();
	new_map->win_ptr = mlx_new_window(new_map->mlx_ptr, SCREEN_WIDTH,
			SCREEN_HEIGHT, "Project_FDF");
	new_map->img.img_ptr = mlx_new_image(new_map->mlx_ptr, SCREEN_WIDTH,
			SCREEN_HEIGHT);
	new_map->img.data = (int *)mlx_get_data_addr(new_map->img.img_ptr,
			&new_map->img.bpp, &new_map->img.size_line, &new_map->img.endian);
	new_map->map_width = 0;
	new_map->map_height = 0;
	new_map->coordinates = NULL;
	new_map->scale = 10;
	new_map->z_scale = 1;
	new_map->x_offset = 0;
	new_map->y_offset = 0;
	new_map->z_min = -10;
	new_map->z_max = 10;
	new_map->radian = 0.523599;
	new_map->is_def_col = 0;
}

int	ft_init_coordinates(t_map *map)
{
	map->coordinates = (t_point *)malloc(sizeof(t_point) * map->map_width
			* map->map_height);
	if (map->coordinates == NULL)
		return (-1);
	return (0);
}

void	ft_free_coordinates(t_map *map)
{
	if (map->coordinates != NULL)
	{
		free(map->coordinates);
		map->coordinates = NULL;
	}
}
