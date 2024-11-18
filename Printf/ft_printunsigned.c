/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printunsigned.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nimorel <nimorel <marvin@42.fr> >          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 11:24:44 by nimorel           #+#    #+#             */
/*   Updated: 2024/11/18 12:40:04 by nimorel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_printunsigned(unsigned int n)
{
	int		len;

	len = 0;
	if (n < 0)
	{
		len = len + ft_printchar('-');
		n = -n;
	}
	if (n >= 10)
		len = len + ft_printunsigned(n / 10);
	len = len + ft_printchar(n % 10 + '0');
	return (len);
}
