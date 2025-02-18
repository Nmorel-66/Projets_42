/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_div_mod.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nimorel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 10:35:14 by nimorel           #+#    #+#             */
/*   Updated: 2024/09/05 12:49:53 by nimorel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>

void	ft_ultimate_div_mod(int *a, int *b)
{
	int	tmp;

	tmp = *a % *b;
	*a = *a / *b;
	*b = tmp;
}

/*int	main(void)
{
	int	a;
	int	b;

	a = 7;
	b = 3;
	printf(" a =%d\n", a);
	printf(" b =%d\n", b);
	ft_ultimate_div_mod(&a, &b);
	printf(" le reultat de la division est : %d\n", a);
	printf(" resultat modulo : %d\n", b);
	return (0);
}*/
