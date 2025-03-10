/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nimorel <nimorel <marvin@42.fr> >          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 11:07:34 by nimorel           #+#    #+#             */
/*   Updated: 2025/03/09 18:01:15 by nimorel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

t_color	ft_get_color_by_height(float z, t_map *map)
{
	float	ratio;
	int		r;
	int		g;
	int		b;

	if (z < 0)
		return (0x0000FF);
	ratio = (z - map->z_min) / (map->z_max - map->z_min);
	r = (int)(128 * ratio);
	g = (int)(255 * (1 - ratio));
	b = (int)(128 * ratio);
	return ((r << 16) | (g << 8) | b);
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
		map->coordinates[i].color = ft_atoi_base(z_value, base);
		free(z_value);
	}
}
