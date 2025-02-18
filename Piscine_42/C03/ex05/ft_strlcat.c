/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nimorel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 18:33:31 by nimorel           #+#    #+#             */
/*   Updated: 2024/09/19 11:19:31 by nimorel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlen(char *str)
{
	unsigned int	i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	i;
	unsigned int	len;

	i = 0;
	while (dest[i] != '\0' && i <= size)
	{
		if (i == size)
			return (size);
		i++;
	}
	len = ft_strlen(dest);
	if (len == size - 1)
		return (size);
	i = 0;
	while (src[i] != '\0' && i < size -1)
	{
		dest[len + i] = src[i];
		i++;
	}
	dest[len + i] = '\0';
	return (len + i);
}
/*
#include <string.h>
#include <stdio.h>

int	main(void)
{
	unsigned int	size;
	char	str1[] = "debut";
	char	str2[] = "fin";
//	char	str2[] = "debut";
//	char	str1[] = "";
	
	size = 20;
//	printf(": strlcat  %zu\n", strlcat(str1,str2, size)); 
	printf("ft_strlcat:  %u\n", ft_strlcat(str1, str2, size));
	return (0);
}*/
