/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nimorel <nimorel <marvin@42.fr> >          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 15:30:38 by nimorel           #+#    #+#             */
/*   Updated: 2025/03/09 16:40:45 by nimorel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static void	ft_map_checker(char *file)
{
	int		fd;
	char *ext;
	int	start;

	start = ft_strlen(file) - 3;
	ext = ft_substr(file, start, 4);
	if (ft_strncmp(ext,"fdf", 3) != 0)
	{
		free(ext);
		ft_error_handler("extension file error\n", 1);	
	}
	free(ext);
	fd = open(file, O_RDONLY);
	if (fd < 0)
		ft_error_handler("Open file error.\n", 1);
	close(fd);
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
