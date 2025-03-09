/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nimorel <nimorel <marvin@42.fr> >          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 11:07:34 by nimorel           #+#    #+#             */
/*   Updated: 2025/03/09 17:20:02 by nimorel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

t_color	ft_get_color_by_height(float z, t_map *map)
{
	t_color	color;
	float	ratio;

	if (z < 0)
		return ((t_color){.r = 0, .g = 0, .b = 255});
	ratio = (z - map->z_min) / (map->z_max - map->z_min);
	color.r = (int)(128 * ratio);
	color.g = (int)(255 * (1 - ratio));
	color.b = (int)(128 * ratio);
	return (color);
}

int	ft_get_color(t_color color)
{
	return ((color.r << 16) | (color.g << 8) | color.b);
}

void	ft_get_z(char *z_split, int i, t_map *map)
{
	char	*iscolor;
	int		len;
	char	*z_value;
	char	*base;

	iscolor = ft_strchr(z_split, ',');
	base = "0123456789ABCDEF";
	if (iscolor == NULL)
	{
		map->coordinates[i].z = ft_atoi(z_split);
		map->coordinates[i].color = map->default_color;
	}
	else
	{
		len = iscolor - z_split;
		z_value = ft_substr(z_split, 0, len);
		map->coordinates[i].z = ft_atoi(z_value);
		free(z_value);
		len = len + 3;
		z_value = ft_substr(z_split, len, 6);
		map->coordinates[i].color.r = ft_atoi_base(z_value, base) & 0xFF;
		map->coordinates[i].color.g = ft_atoi_base(z_value + 2, base) & 0xFF;
		map->coordinates[i].color.b = ft_atoi_base(z_value + 4, base);
		free(z_value);
	}
}
