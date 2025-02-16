/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nimorel <nimorel <marvin@42.fr> >          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 11:07:34 by nimorel           #+#    #+#             */
/*   Updated: 2025/02/16 15:20:06 by nimorel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"


t_color	ft_get_color_by_height(double z, t_map *map)
{
t_color color;
double z_min = map->z_min;
double z_max = map->z_max;
double pas = (z_max - z_min) / 4.0; 
int r = 0, g = 0, b = 0;

if (z >= z_min && z <= z_min + pas)
{
    b = 255;
    g = 0;
    r = 0;
}
else if (z > z_min + pas && z <= z_min + (2 * pas)) 
{
    b = 0;
    g = 255;
    r = 0;
}
else if (z > z_min + (2 * pas) && z <= z_min + (3 * pas))
{
	b = 0;
	g = 100;
	r = 139;
}
else if (z > z_min + (3 * pas) && z <= z_max)
{
	b = 255;
	g = 255;
	r = 255;
}

color.r = r;
color.g = g;
color.b = b;

return color;
}

int	ft_get_color(t_color color)
{
	return ((color.r << 16) | (color.g << 8) | color.b);
}