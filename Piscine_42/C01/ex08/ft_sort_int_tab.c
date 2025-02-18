/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nimorel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 10:13:40 by nimorel           #+#    #+#             */
/*   Updated: 2024/09/24 10:28:56 by nimorel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	ft_sort_int_tab(int *tab, int size)
{
	int	i;
	int	j;
	int	tmp;

	i = 0;
	while (i < size)
	{
		j = i + 1;
		while (j < size)
		{
			if (tab[i] > tab[j])
			{
				tmp = tab[j];
				tab[j] = tab[i];
				tab[i] = tmp;
			}
			j++;
		}
		i++;
	}
}
/*
int	main(void)
{
	int	t[5];
	int	s;

	s = 5;
	t[0] = 4;
	t[1] = 3;
	t[2] = 1;
	t[3] = 5;
	t[4] = 2;
	printf("%d %d %d %d %d\n", t[0], t[1], t[2], t[3], t[4]);
	ft_sort_int_tab(t, s);
	printf(" %d %d %d %d %d \n", t[0], t[1], t[2], t[3], t[4]);
	return (0);
}*/
