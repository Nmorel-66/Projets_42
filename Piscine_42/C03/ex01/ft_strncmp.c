/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nimorel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 10:40:46 by nimorel           #+#    #+#             */
/*   Updated: 2024/09/10 16:42:42 by nimorel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	unsigned int	i;

	i = 0;
	while ((s1[i] != '\0') && (s2[i] != '\0') && (i < n)
		&& (s1[i] == s2[i]))
	{
		i++;
	}
	if (n == i)
		return (0);
	return (s1[i] - s2[i]);
}
/*#include <stdio.h>
#include <string.h>
int	main(void)
{
	char str1[] = "bonjour";
	char str2[] = "bonsoir";
	
	printf("%d", strncmp(str1, str2, 0));
	printf("%d", ft_strncmp(str1, str2, 0));
}*/
/* meme chose que strcmp mais on determine une longueur n de recherche */
