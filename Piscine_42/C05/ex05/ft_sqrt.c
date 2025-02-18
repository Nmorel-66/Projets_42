/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nimorel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 17:41:31 by nimorel           #+#    #+#             */
/*   Updated: 2024/09/14 12:57:26 by nimorel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_sqrt(int nb)
{
	int	i;

	i = 0;
	while ((i * i) != nb)
	{
		if (i > nb)
			return (0);
		i++;
	}
	return (i);
}
/*#include <stdio.h>

int	main(void)
{
	printf("la raine carre est ; %d\n", ft_sqrt(14));
	return (0);
}*/
