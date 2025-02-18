/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nimorel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 15:02:31 by nimorel           #+#    #+#             */
/*   Updated: 2024/09/23 15:38:38 by nimorel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "ft_stock_str.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strdup(char *src)
{
	int		i;
	int		len;
	char	*dest;

	i = 0;
	len = 0;
	while (src[len] != '\0')
		len++;
	dest = (char *)malloc(sizeof(char) * (len + 1));
	if (dest == NULL)
		return (NULL);
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

struct s_stock_str	*ft_strs_to_tab(int ac, char **av)
{
	int			i;
	t_stock_str	*my_stock;

	i = 0;
	my_stock = (t_stock_str *)malloc(sizeof(t_stock_str) * (ac + 1));
	if (my_stock == NULL)
		return (NULL);
	while (i < ac)
	{
		my_stock[i].size = ft_strlen(av[i]);
		my_stock[i].str = av[i];
		my_stock[i].copy = ft_strdup(av[i]);
		i++;
	}
	my_stock[i].str = 0;
	return (my_stock);
}
/*
int main(void)
{
char *strs[4];
char *str1;
char *str2;
char *str3;
char *str4;
int size;

str1 = "Bonjour";
str2 = "les";
str3 = "chacaux";
str4 = "!";
size = 4;
strs[0] = str1;
strs[1] = str2;
strs[2] = str3;
strs[3] = str4;
ft_show_tab(ft_strs_to_tab(size, strs));
}*/
