/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nimorel <nimorel <marvin@42.fr> >          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 15:30:38 by nimorel           #+#    #+#             */
/*   Updated: 2025/03/02 12:03:09 by nimorel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	ft_error_handler(char *message, int exit_code)
{
	ft_putstr_fd("\033[1;31m", 2);
	ft_putstr_fd(message, 2);
	if (errno)
		ft_putstr_fd(strerror(errno), 2);
	ft_putstr_fd("\033[0m", 2);
	exit(exit_code);
}

static int	ft_get_width(char *line)
{
	int		width;
	char	**split;

	width = 0;
	split = ft_split(line, ' ');
	while (split[width])
		width++;
	ft_free_split(split);
	return (width);
}

static void	ft_invalid_map_exit(char *line, int fd)
{
	free(line);
	close(fd);
	ft_error_handler("Invalid map\n", 1);
}

static void	ft_map_checker(char *file)
{
	int		fd;
	int		first_width;
	int		width;
	char	*line;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		ft_error_handler("Open file error.\n", 1);
	first_width = 0;
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		width = ft_get_width(line);
		if (first_width && width != first_width)
			ft_invalid_map_exit(line, fd);
		if (!first_width)
			first_width = width;
		free(line);
	}
	close(fd);
	if (!first_width)
		ft_error_handler("Invalid map: empty map.\n", 1);
}

int	main(int argc, char **argv)
{
	t_map	map;

	if (argc != 2)
		ft_error_handler("Usage: ./fdf <filename>\n", 1);
	ft_map_checker(argv[1]);
	ft_map_init(&map);
	ft_read_map(argv[1], &map);
	ft_draw(&map);
	map.img.img_ptr = mlx_new_image(map.mlx_ptr, 260, 130);
	map.img.data = (int *)mlx_get_data_addr(map.img.img_ptr, &map.img.bpp,
			&map.img.size_line, &map.img.endian);
	ft_menu(&map);
	mlx_key_hook(map.win_ptr, ft_key_events, &map);
	mlx_mouse_hook(map.win_ptr, ft_mouse_events, &map);
	mlx_hook(map.win_ptr, 17, 0, ft_exit, &map);
	mlx_loop(map.mlx_ptr);
	return (0);
}
