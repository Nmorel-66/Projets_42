/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nimorel <nimorel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 11:07:34 by nimorel           #+#    #+#             */
/*   Updated: 2025/03/08 10:11:57 by nimorel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

t_color	ft_get_color_by_height(double z, t_map *map)
{
	double	z_min;
	double	z_max;
	double	pas;

	z_min = map->z_min;
	z_max = map->z_max;
	pas = (z_max - z_min) / 4.0;
	if (z >= z_min && z <= z_min + pas)
		return ((t_color){0, 0, 255});
	else if (z > z_min + pas && z <= z_min + (2 * pas))
		return ((t_color){0, 255, 0});
	else if (z > z_min + (2 * pas) && z <= z_min + (3 * pas))
		return ((t_color){139, 69, 19});
	else if (z > z_min + (3 * pas) && z <= z_max)
		return ((t_color){255, 255, 255});
	return ((t_color){0, 0, 0});
}

int	ft_get_color(t_color color)
{
	return ((color.r << 16) | (color.g << 8) | color.b);
}

void	ft_get_z(char *z_split, int row, int col, t_map *map)
{
	char	*iscolor;
	int		len;
	char	*z_value;
	char	*z_color;
	char	*base;

	iscolor = ft_strchr(z_split, ',');
	base = "0123456789ABCDEF";
	if (iscolor == NULL)
		map->coordinates[row][col].z = ft_atoi(z_split);
	else
	{
		len = iscolor - z_split;
		z_value = ft_substr(z_split, 0, len);
		map->coordinates[row][col].z = ft_atoi(z_value);
		free(z_value);
		len = len + 3;
		z_color = ft_substr(z_split, len, 6);
		map->coordinates[row][col].color.r = ft_atoi_base(z_color, base) & 0xFF;
		map->coordinates[row][col].color.g = ft_atoi_base(z_color + 2, base)
			& 0xFF;
		map->coordinates[row][col].color.b = ft_atoi_base(z_color + 4, base);
		free(z_color);
	}
}
