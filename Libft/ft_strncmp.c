/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nimorel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 15:35:16 by nimorel           #+#    #+#             */
/*   Updated: 2024/11/04 15:40:44 by nimorel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

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
	
	printf("%d", strncmp(str1, str2, 4));
	printf("%d", ft_strncmp(str1, str2, 4));
}*/
