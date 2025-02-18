/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nimorel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 09:56:47 by nimorel           #+#    #+#             */
/*   Updated: 2024/09/09 13:09:48 by nimorel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strncpy(char *dest, char *src, unsigned int n)
{
	unsigned int	i;

	i = 0;
	while (src[i] != '\0' && i < n)
	{
		dest[i] = src[i];
		i++;
	}
	while (i < n)
	{
		dest[i] = '\0';
		i++;
	}
	return (dest);
}

/*#include<stdio.h>
#include<string.h>
int main()
{
	char			dest[50];
	char			src[] = "Hello world !";
	unsigned int	n = 10;

	ft_strncpy(dest, src, n);
	printf(" Chaine copie ;: %s\n", dest);
	strncpy(dest, src, n);
	printf(" Chaine copie ;: %s\n", dest);
	return (0);
}*/
