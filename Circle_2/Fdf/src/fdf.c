/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nimorel <nimorel <marvin@42.fr> >          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 15:30:38 by nimorel           #+#    #+#             */
/*   Updated: 2025/02/08 16:32:04 by nimorel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../includes/fdf.h"

int	main(int argc, char **argv)
{
	void	*mlx;
	void	*mlx_win;
	(void)argc;
	(void)argv;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 1000, 800, "FDF Project");
	mlx_loop(mlx);
}