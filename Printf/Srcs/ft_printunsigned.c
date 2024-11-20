/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printunsigned.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nimorel <nimorel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 11:24:44 by nimorel           #+#    #+#             */
/*   Updated: 2024/11/20 09:21:31 by nimorel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printunsigned(unsigned int n)
{
	int		len;

	len = 0;
	if (n >= 10)
		len = len + ft_printunsigned(n / 10);
	len = len + ft_printchar(n % 10 + '0');
	return (len);
}
