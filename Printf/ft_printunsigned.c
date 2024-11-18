/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printunsigned.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nimorel <nimorel <marvin@42.fr> >          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 11:24:44 by nimorel           #+#    #+#             */
/*   Updated: 2024/11/18 11:25:13 by nimorel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_printunsigned(unsigned n)
{
	long nb = n;
	int len = 0;

	if (nb < 0)
	{
		len = len + ft_printchar('-');
		nb = -nb;
	}
	if (nb >= 10)
		len = len + ft_printunsigned(nb / 10);
	len = len + ft_printchar(nb % 10 + '0');
	return (len);
}
