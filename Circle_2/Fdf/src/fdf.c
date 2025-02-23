/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nimorel <nimorel <marvin@42.fr> >          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 15:30:38 by nimorel           #+#    #+#             */
/*   Updated: 2025/02/23 08:36:22 by nimorel          ###   ########.fr       */
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

int	main(int argc, char **argv)
{
	t_map	map;

	if (argc != 2)
		ft_error_handler("Usage: ./fdf <filename>\n", 1);
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
