/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nimorel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 15:54:52 by nimorel           #+#    #+#             */
/*   Updated: 2024/09/11 18:16:19 by nimorel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_power(int nb, int power)
{
	int	i;
	int	result;

	i = 0;
	result = 1;
	if (power < 0)
		return (0);
	if (power == 0 && nb == 0)
		return (1);
	while (power > i)
	{
		result = result * nb;
		i++;
	}
	return (result);
}
/*#include <stdio.h>
int	main(void)
{
	printf("%d\n",ft_iterative_power(3, 3));
}*/
