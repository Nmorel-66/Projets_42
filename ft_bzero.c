/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nimorel <nimorel <marvin@42.fr> >          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 14:43:17 by nimorel           #+#    #+#             */
/*   Updated: 2024/11/06 14:56:15 by nimorel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	fr_bzero(void *s, size_t n)
{
    unsigned char	*dest;
	size_t			i;

	dest = s;
	i = 0;
	while (i < n)
	{
		dest[i] = 0;
		i++;
	}
}
/*La  fonction bzero() met à 0 les n premiers octets du bloc pointé par s
       (octets contenant « \0 »)*/
int	main(void)
{
	char	str[10] = "Hello";
	printf("avant bzero : %s\n", str);
	printf("apres bzero : %s\n", bzero(str, 5));
	return (0);	
}