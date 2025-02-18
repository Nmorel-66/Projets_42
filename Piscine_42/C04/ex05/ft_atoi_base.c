/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nimorel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 08:39:00 by nimorel           #+#    #+#             */
/*   Updated: 2024/09/24 09:32:47 by nimorel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_strlen(char *base)
{
	int	len;

	len = 0;
	while (base[len] != '\0')
		len++;
	return (len);
}

int	ft_base_check(char *s1)
{
	int	i;
	int	j;
	int	len;

	i = 0;
	if (!*s1)
		return (0);
	len = ft_strlen(s1);
	if (len == 1)
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
		if (s1[i] == '+' || s1[i] == '-'
			|| ('\t' <= s1[i] && s1[i] <= '\r') || s1[i] == ' ')
			return (0);
		i++;
	}
	return (1);
}

int	ft_base_val(char c, char *base)
{
	int	i;

	i = 0;
	while (base[i] != '\0')
	{
		if (base[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

int	ft_atoi_base(char *str, char *base)
{
	int	i;
	int	sign;
	int	res;
	int	len_base;

	i = 0;
	sign = 1;
	res = 0;
	if (!ft_base_check(base))
		return (0);
	len_base = ft_strlen(base);
	while ((9 <= str[i] && str[i] <= 13) || str[i] == 32)
		i++;
	while (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -sign;
		i++;
	}
	while (str[i] != '\0' && ft_base_val(str[i], base) != -1)
	{
		res = (res * len_base) + ft_base_val(str[i], base);
		i++;
	}
	return (res * sign);
}
/*
int	main(void)
{
//	char	base[10] = "0123456789";
	char	base[16] = "0123456789ABCDEF";
//	char	base[8] = "poneyvif";
//	char	base[2] = "01";

	printf(" %d\n", ft_atoi_base("	 +10", base));
	return (0);
}*/
