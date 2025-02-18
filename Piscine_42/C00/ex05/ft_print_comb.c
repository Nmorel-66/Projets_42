/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nimorel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 15:00:02 by nimorel           #+#    #+#             */
/*   Updated: 2024/09/05 08:00:50 by nimorel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char i, char j, char k)
{
	char	c;

	c = i;
	write(1, &i, 1);
	write(1, &j, 1);
	write(1, &k, 1);
	if (i < '7')
	{
		write(1, ", ", 2);
	}
}

void	ft_print_comb(void)
{
	char	i;
	char	j;
	char	k;

	i = '0';
	j = '1';
	k = '2';
	while (i <= '7')
	{
		while (j <= '8')
		{
			while (k <= '9')
			{
				ft_putchar(i, j, k);
				k++;
			}
			k = j + 2;
			j++;
		}
		j = i + 1;
		i++;
	}
}
