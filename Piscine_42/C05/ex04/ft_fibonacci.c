/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fibonacci.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nimorel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 16:41:11 by nimorel           #+#    #+#             */
/*   Updated: 2024/09/14 13:24:24 by nimorel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_fibonacci(int index)
{
	if (index < 0)
		return (-1);
	if (index == 0)
		return (0);
	else if (index == 1)
		return (1);
	else
		return (ft_fibonacci(index - 1) + ft_fibonacci(index -2));
}
/*#include <stdio.h>
int	main(void)
{
	printf("le nieme elementt %d\n", ft_fibonacci(6));
	return (0);
}*/
/*
suite de fibonacci
si 10 : 0 1 1 2 3 5 8 13 21 34 55
f0 = 0
f1 = 1
f2 = f0 + f1 = 1
f3 = f1 + f2 = 2
f4 = f2 + f3 = 3
f5 = f4 + f3 = 5
f6 = f5 + f4 = 8
*/
