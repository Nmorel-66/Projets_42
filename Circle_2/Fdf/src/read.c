/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nimorel <nimorel <marvin@42.fr> >          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 10:26:58 by nimorel           #+#    #+#             */
/*   Updated: 2025/02/10 11:18:26 by nimorel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	free_split(char **split)
{
	int i = 0;
	while (split[i])
		free(split[i++]);
	free(split);
}

int	ft_map_dimensions(char *file, t_map *map)
{
	int		fd;
	char	*line;
	char	**split;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		ft_error_handler("Error opening file\n", -1);
	map->map_height = 0;
	map->map_width = 0;
	while ((line = get_next_line(fd)) != NULL)
	{
		split = ft_split(line, ' ');
		if (map->map_width == 0)
			while (split[map->map_width])
				map->map_width++;
		map->map_height++;
		free_split(split);
		free(line);
	}
	close(fd);
	return (0);
}

int	ft_read_map(char *file, t_map *map)
{
	int		fd;
	int		y;
	int		x;
	char	*line;
	char	**split;

	if (ft_map_dimensions(file, map) == -1)
		return (-1);
	if (ft_init_coordinates(map) == -1)
		ft_error_handler("Error allocating memory\n", -1);
	fd = open(file, O_RDONLY);
	if (fd < 0)
		ft_error_handler("Error opening file\n", -1);
	y = 0;
	while ((line = get_next_line(fd)) != NULL)
	{
		split = ft_split(line, ' ');
		x = 0;
		while (split[x])
		{
			map->coordinates[y][x].x = x;
			map->coordinates[y][x].y = y;
			map->coordinates[y][x].z = ft_atoi(split[x]);
			free(split[x]);
			x++;
		}
		free(split);
		free(line);
		y++;
	}
	close(fd);
	return (0);
}
