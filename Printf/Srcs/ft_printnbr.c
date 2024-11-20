/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printnbr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nimorel <nimorel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 10:03:17 by nimorel           #+#    #+#             */
/*   Updated: 2024/11/20 09:17:01 by nimorel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printnbr(int n)
{
	long	nb;
	int		len;

	nb = n;
	len = 0;
	if (nb < 0)
	{
		len = len + ft_printchar('-');
		nb = -nb;
	}
	if (nb >= 10)
		len = len + ft_printnbr(nb / 10);
	len = len + ft_printchar(nb % 10 + '0');
	return (len);
}
