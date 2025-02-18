/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nimorel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 14:21:08 by nimorel           #+#    #+#             */
/*   Updated: 2024/09/17 13:01:29 by nimorel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_malloc(int size, char *strs, char *sep)
{
	int		i;
	int		len;
	char	*dest;

	i = 0;
	len = 0;
	while (i < size)
	{
		len = len + ft_strlen(&strs[i]);
		i++;
	}
	len = len + (ft_strlen(sep) * (size -1));
	dest = (char *)malloc(sizeof(char) * (len + 1));
	if (dest == NULL)
		return (NULL);
	dest[i] = '\0';
	return (dest);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	int		i;
	int		j;
	int		k;
	char	*dest;

	i = 0;
	k = 0;
	if (size == 0)
		return (dest = NULL);
	dest = ft_malloc(size, *strs, sep);
	while (i < size)
	{
		j = 0;
		while (strs[i][j] != '\0')
			dest[k++] = strs[i][j++];
		j = 0;
		while (sep[j] != '\0' && i < size - 1)
			dest[k++] = sep[j++];
		i++;
	}
	dest[k] = '\0';
	return (dest);
}
/*
int	main(void)
{
	char	*str[] = {"Bonjour", "Hello", "Ciao"};
	char	*sep = " , ";

	char *res = ft_strjoin(3, str, sep);
	if (res != NULL)
		printf("%s\n", res);
	else
	{
	printf("erreur allocation\n");
		free(res);
	}
	return (0);
}*/
