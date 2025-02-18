/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nimorel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 11:13:07 by nimorel           #+#    #+#             */
/*   Updated: 2024/09/24 09:22:29 by nimorel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	ft_strlen(char *s1)
{
	int	i;

	i = 0;
	while (s1[i] != '\0')
		i++;
	return (i);
}

int	ft_base_check(char *s1)
{
	int	i;
	int	j;
	int	len;

	i = 0;
	len = ft_strlen(s1);
	if (len < 2)
		return (0);
	while (s1[i] != '\0' && i < len - 1)
	{
		j = i + 1;
		while (j < len -1)
		{
			if (s1[i] == s1[j])
				return (0);
			j++;
		}
		if (s1[i] == '+' || s1[i] == '-')
			return (0);
		i++;
	}
	return (1);
}

void	ft_putnbr_base(int nbr, char *base)
{
	int			i;
	int			valid_base;
	int			len_base;
	long		nb;

	nb = nbr;
	len_base = ft_strlen(base);
	valid_base = ft_base_check(base);
	if (valid_base == 0)
		return ;
	i = 0;
	if (nb < 0)
	{
		ft_putchar('-');
		nb = -nb;
	}
	if (nb >= len_base)
		ft_putnbr_base((nb / len_base), base);
	ft_putchar(base[nb % len_base]);
}
/*
int	main(void)
{
//	char	base[10] = "0123456789";
	char	base[16] = "0123456789ABCDEF";
//	char	base[8] = "poneyvif";
//	char	base[2] = "01";

	ft_putnbr_base(66, base);
	return (0);
}*/
//long nb pour ne pas gerer int min ca rentre tranquille
