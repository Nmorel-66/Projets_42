/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nimorel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 14:46:33 by nimorel           #+#    #+#             */
/*   Updated: 2024/11/04 15:42:56 by nimorel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strrchr(const char *s, int c)
{
	int	i;
	int	lastocc;

	i = 0;
	lastocc = -1;
	while (s[i] != '\0')
	{
		if (s[i] == c)
			lastocc = i;
		i++;
	}
	if (lastocc != -1)
		return ((char *)(s + lastocc));
	return (NULL);
}
/*
#include <stdio.h>
int	main(void)
{
	char *str = "hello world";
	char c = 'o';
	printf("%s \n", ft_strrchr(str, c));
	return (0);
}*/