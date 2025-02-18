/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nimorel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 09:49:13 by nimorel           #+#    #+#             */
/*   Updated: 2024/09/06 08:30:06 by nimorel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>

void	ft_swap(int *a, int *b)
{
	int	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

/*int	main(void)
{
	int a;
	int b;

	a = 1;
	b = 2;
	printf("avant swap : a = %d b: %d\n", a, b);
	ft_swap(&a, &b);
	printf("apres swap : a = %d b = %d\n", a, b);
}*/
