/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nimorel <nimorel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 16:04:56 by nimorel           #+#    #+#             */
/*   Updated: 2024/11/07 16:59:19 by nimorel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat( char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (dst[i] != '\0' && i < size)
		i++;
	j = 0;
	while (src[j] != '\0' && i < size - 1)
	{
		dst[i] = src[j];
		i++;
		j++;
	}
	if (j < size)
		dst[i] = '\0';
	return (j - 1 + ft_strlen(src));
}
/*int	main(void)
{
	char *src = " World";
	char dest[50] = "Hello";
	
	printf("%ld\n", ft_strlcat(dest, src, 12));
	printf("%s\n", dest);
	return(0);
}*/