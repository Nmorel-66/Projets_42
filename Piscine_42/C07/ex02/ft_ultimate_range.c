/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nimorel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 11:20:23 by nimorel           #+#    #+#             */
/*   Updated: 2024/09/15 17:47:13 by nimorel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int	i;
	int	len;

	i = 0;
	len = max - min;
	if (min >= max)
	{
		*range = NULL;
		return (0);
	}
	*range = (int *)malloc(sizeof(int) * len);
	if (*range == NULL)
		return (-1);
	while (i < len)
	{
		(*range)[i] = min + i;
		i++;
	}
	return (i);
}
/*int	main(void)
{
	int	min;
	int max;
	int	*i_tab;
	int	taille;
	
	min = 30;
	max = 43;
	taille = ft_ultimate_range(&i_tab, min, max);
	printf("taille de i_tab: %d\n", taille);
	free(i_tab);
	return (0);
}*/
