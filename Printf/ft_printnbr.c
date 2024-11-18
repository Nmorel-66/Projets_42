/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printnbr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nimorel <nimorel <marvin@42.fr> >          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 10:03:17 by nimorel           #+#    #+#             */
/*   Updated: 2024/11/18 11:19:43 by nimorel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_printnbr(int n)
{
	long nb = n;
	int len = 0;

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
