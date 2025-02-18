/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   angle.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nimorel <nimorel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 15:16:29 by nimorel           #+#    #+#             */
/*   Updated: 2025/02/18 15:42:43 by nimorel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/fdf.h"

void	ft_increase_radian(t_map *map)
{
	map->radian = map->radian + 0.05;
	mlx_clear_window(map->mlx_ptr, map->win_ptr);
	ft_draw(map);
	ft_menu(map);
}
void	ft_decrease_radian(t_map *map)
{
	map->radian = map->radian - 0.05;
	mlx_clear_window(map->mlx_ptr, map->win_ptr);
	ft_draw(map);
	ft_menu(map);
}