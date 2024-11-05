/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nimorel <nimorel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 14:25:17 by nimorel           #+#    #+#             */
/*   Updated: 2024/11/05 16:21:41 by nimorel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{	
		if (s[i] == c)
			return ((char *)s + i);
		i++;
	}
	return (NULL);
}
/*int main(void)
{
	char *str = "Hello World";
	int c = 'o';
	char *ptr = ft_strchr(str, c);
	
	if (ptr)
		printf("%s\n", ptr);
	else
		printf("Caratere non touve\n")	;
	return (0);
}*/
