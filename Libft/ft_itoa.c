/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nimorel <nimorel <marvin@42.fr> >          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 17:59:51 by nimorel           #+#    #+#             */
/*   Updated: 2024/11/10 18:54:15 by nimorel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include <stdlib.h>

static int	ft_nblen(int n)
{
	int i;

	i = 0;
	if (n < 0)
		n = -n;
	while (n != 0)
	{
		n /= 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	long	nb;
	int		len;
	char	*res;
	int		i;

	nb = n;
	i = 0;
	len = ft_nblen(nb);
	if (nb <= 0)
		len = len + 1;
	res = (char *)malloc(sizeof(char) * (len + 1));
	if (!res)
		return (NULL);
	if (nb == 0)
	{
		res[0] = '0';
		i++;
	}
	if (nb < 0)
	{
		res[0] = '-';
		nb = -nb;
		i++;
	}
	while (len > i)
	{
		len--;
		res[len] = (nb % 10) + '0';
		nb = nb /10;
	}
	return (res);
}

int	main(void)
{
	printf("%s\n", ft_itoa(120));
	return (0);
}
