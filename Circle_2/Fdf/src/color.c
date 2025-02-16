/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nimorel <nimorel <marvin@42.fr> >          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 11:07:34 by nimorel           #+#    #+#             */
/*   Updated: 2025/02/16 15:36:39 by nimorel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

t_color	ft_get_color_by_height(double z, t_map *map)
{
	double z_min;
	double z_max;
	double pas;

	z_min = map->z_min;
	z_max = map->z_max;
	pas = (z_max - z_min) / 4.0; 
	if (z >= z_min && z <= z_min + pas)
		return (t_color){0, 0, 255};
	else if (z > z_min + pas && z <= z_min + (2 * pas)) 
		return (t_color){0, 255, 0};
	else if (z > z_min + (2 * pas) && z <= z_min + (3 * pas))
		return (t_color){139, 69, 19};
	else if (z > z_min + (3 * pas) && z <= z_max)
		return (t_color){255, 255, 255};
	return (t_color){0, 0, 0};
}

int	ft_get_color(t_color color)
{
	return ((color.r << 16) | (color.g << 8) | color.b);
}