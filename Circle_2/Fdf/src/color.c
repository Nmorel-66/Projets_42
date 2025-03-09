/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nimorel <nimorel <marvin@42.fr> >          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 11:07:34 by nimorel           #+#    #+#             */
/*   Updated: 2025/03/09 16:44:36 by nimorel          ###   ########.fr       */
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

/*void	ft_get_z(char *z_split, int row, int col, t_map *map)
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
}*/
void ft_get_z(char *z_split, int row, int col, t_map *map)
{
    int index = row * map->map_width + col;
    char *iscolor;
    int len;
    char *z_value;
    char *z_color;
    char *base;

    iscolor = ft_strchr(z_split, ',');
    base = "0123456789ABCDEF";
    if (iscolor == NULL)
	{
        map->coordinates[index].z = ft_atoi(z_split);
        map->coordinates[index].color = map->default_color;
    } 
	else
	{
		len = iscolor - z_split;
        z_value = ft_substr(z_split, 0, len);
        map->coordinates[index].z = ft_atoi(z_value);
        free(z_value);
        len = len + 3;
        z_color = ft_substr(z_split, len, 6);
        map->coordinates[index].color.r = ft_atoi_base(z_color, base) & 0xFF;
        map->coordinates[index].color.g = ft_atoi_base(z_color + 2, base) & 0xFF;
        map->coordinates[index].color.b = ft_atoi_base(z_color + 4, base);
        free(z_color);
    }
}