/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nimorel <nimorel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 10:26:58 by nimorel           #+#    #+#             */
/*   Updated: 2025/03/12 09:45:06 by nimorel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	ft_free_split(char **split)
{
	int	i;

	if (split == NULL)
		return ;
	i = 0;
	while (split[i])
		free(split[i++]);
	free(split);
}

void	ft_map_dimensions_process(char *line, t_map *map)
{
	int	width;
	int	is_counting;

	width = 0;
	is_counting = 0;
	if (map->map_width == 0)
	{
		while (*line)
		{
			if (*line == ' ')
				is_counting = 0;
			else if (!is_counting)
			{
				is_counting = 1;
				width++;
			}
			line++;
		}
		map->map_width = width;
	}
	map->map_height++;
}

int	ft_map_dimensions(char *file, t_map *map)
{
	int		fd;
	char	*line;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		ft_error_handler("Error opening file\n", -1);
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		ft_map_dimensions_process(line, map);
		free(line);
	}
	close(fd);
	return (0);
}

static void	ft_read_map_process(char *line, t_map *map, int row)
{
	char	**split;
	int		col;
	int		index;

	col = 0;
	split = ft_split(line, ' ');
	while (split[col])
	{
		if (col >= map->map_width)
		{
			free(split[col]);
			break ;
		}
		index = row * map->map_width + col;
		map->coordinates[index].x = col;
		map->coordinates[index].y = row;
		ft_get_z(split[col], index, map);
		if (map->coordinates[index].z < map->z_min)
			map->z_min = map->coordinates[index].z;
		if (map->coordinates[index].z > map->z_max)
			map->z_max = map->coordinates[index].z;
		free(split[col]);
		col++;
	}
	free(split);
}

int	ft_read_map(char *file, t_map *map)
{
	int		fd;
	int		row;
	char	*line;

	if (ft_map_dimensions(file, map) == -1)
		return (-1);
	if (ft_init_coordinates(map) == -1)
		ft_error_handler("Error allocating memory\n", -1);
	fd = open(file, O_RDONLY);
	if (fd < 0)
		ft_error_handler("Error opening file\n", -1);
	row = 0;
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		ft_read_map_process(line, map, row);
		free(line);
		row++;
	}
	close(fd);
	return (0);
}
