/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nimorel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 09:57:49 by nimorel           #+#    #+#             */
/*   Updated: 2024/09/14 11:00:53 by nimorel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int	*ft_range(int min, int max)
{
	int	*i_tab;
	int	len;
	int	i;

	len = max - min;
	i = 0;
	if (min >= max)
		return (NULL);
	i_tab = (int *)malloc(sizeof(int) * len);
	if (i_tab == NULL)
		return (NULL);
	while (i < len)
	{
		i_tab[i] = min + i;
		i++;
	}
	return (i_tab);
}
/*int	main(void)
{
	int	min;
	int max;
	int	*tab;
	int	i;
	
	min = 30;
	max = 43;

	tab = ft_range(min, max);
	printf("tableau genere: ");
	i = 0;
	while (i < max - min)
	{
		printf("%d ", tab[i]);
		i++;
	}
	free(tab);
	return (0);
}*/
