/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nimorel <nimorel <marvin@42.fr> >          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 10:26:58 by nimorel           #+#    #+#             */
/*   Updated: 2025/02/16 15:55:39 by nimorel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	free_split(char **split)
{
	int	i;

	i = 0;
	while (split[i])
		free(split[i++]);
	free(split);
}

void	ft_map_dimensions_process(char *line, t_map *map)
{
	char	**split;
	int		width;

	width = 0;
	split = ft_split(line, ' ');
	if (map->map_width == 0)
	{
		while (split[width])
		{
			width++;
		}
		map->map_width = width;
	}
	map->map_height++;
	free_split(split);
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
	map->x_offset = (SCREEN_WIDTH - ((map->map_width - map->map_height)
				* map->scale)) / 2;
	map->y_offset = (SCREEN_HEIGHT - ((map->map_width + map->map_height)
				* map->scale) / 2) / 2;
	close(fd);
	return (0);
}

static void	ft_read_map_process(char *line, t_map *map, int row)
{
	char	**split;
	int		col;

	col = 0;
	split = ft_split(line, ' ');
	while (split[col])
	{
		map->coordinates[row][col].x = col;
		map->coordinates[row][col].y = row;
		map->coordinates[row][col].z = ft_atoi(split[col]);
		if (map->coordinates[row][col].z < map->z_min)
			map->z_min = map->coordinates[row][col].z;
		if (map->coordinates[row][col].z > map->z_max)
			map->z_max = map->coordinates[row][col].z;
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
