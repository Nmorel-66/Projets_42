/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_prime.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nimorel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 17:52:37 by nimorel           #+#    #+#             */
/*   Updated: 2024/09/15 09:21:32 by nimorel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_prime(int nb)
{
	int	i;

	if (nb == 0 || nb == 1)
		return (0);
	if (nb == 2)
		return (1);
	i = 2;
	while (nb % i != 0)
	{
		if ((nb / i == 1))
			return (1);
		i++;
	}
	return (0);
}
/*#include <stdio.h>
int	main(void)
{
	int	num;
	
	num = 43;
	if (ft_is_prime(num) == 0)
		printf("%d  n'est pas premier\n ",num);
	else
		printf("%d  est premier \n ",num);
	return (0);
}*/
