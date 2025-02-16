/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nimorel <nimorel <marvin@42.fr> >          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 11:07:34 by nimorel           #+#    #+#             */
/*   Updated: 2025/02/16 12:28:20 by nimorel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

t_color	ft_get_color_by_height(double z)
{
	t_color	color;
	double	min_z;
	double	max_z;
	double	normalized_z;

	min_z = -50.0;
	max_z = 3000.0;
	normalized_z = (z - min_z) / (max_z - min_z);
	normalized_z = fmax(0.0, fmin(1.0, normalized_z));

	if (normalized_z <= 0.25)
	{
		color.r = 0;
		color.g = 0;
		color.b = (int)(255 * (1 - 4 * normalized_z));
	}
	else if (normalized_z <= 0.5)
	{
		color.r = 0;
		color.g = (int)(255 * (4 * normalized_z - 1));
		color.b = 0;
	}
	else if (normalized_z <= 0.75)
	{
		color.r = (int)(255 * (4 * normalized_z - 2));
		color.g = (int)(200 * (4 * normalized_z - 2));
		color.b = 0;
	}
	else
	{
		color.r = 255;
		color.g = 255;
		color.b = (int)(255 * (4 * normalized_z - 3));
	}
	return (color);
}

int	ft_get_color(t_color color)
{
	return ((color.r << 16) | (color.g << 8) | color.b);
}