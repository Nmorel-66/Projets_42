/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nimorel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 08:39:17 by nimorel           #+#    #+#             */
/*   Updated: 2024/09/15 15:29:35 by nimorel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_prime(int nb)
{
	int	i;

	i = 2;
	while (nb % i != 0)
	{
		if ((nb / i == 1))
			return (1);
		i++;
	}
	return (0);
}

int	ft_find_next_prime(int nb)
{
	int	i;

	if (nb <= 1)
		return (2);
	i = nb;
	while (!(ft_is_prime(i)))
		i++;
	return (i);
}
/*#include <stdio.h>
int	main(void)
{
	int	num;
	
	num = 5;
	printf("le prochaine premier est %d\n ",ft_find_next_prime(num));
	return (0);
}*/
//premier nbre premier est 2
