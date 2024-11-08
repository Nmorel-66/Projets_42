/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nimorel <nimorel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 14:46:33 by nimorel           #+#    #+#             */
/*   Updated: 2024/11/05 16:24:39 by nimorel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
/*int main(void)
{
	char *str = "Hello World";
	int c = 'a';
	char *ptr = ft_strrchr(str, c);
	
	if (ptr)
		printf("%s\n", ptr);
	else
		printf("Caratere non touve\n")	;
	return (0);
}*/
