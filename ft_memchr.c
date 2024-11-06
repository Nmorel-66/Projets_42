/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nimorel <nimorel <marvin@42.fr> >          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 15:49:13 by nimorel           #+#    #+#             */
/*   Updated: 2024/11/06 16:00:01 by nimorel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
    unsigned char 	*str;
	size_t			i;

	str = (unsigned char *)s;
	i = 0;
	while (i < n)
    {
        if (str[i] == (unsigned char)c)
            return (&str[i]);
        i++;
    }
    return (NULL);
}
/*La  fonction  memchr() examine les n premiers octets de la zone mémoire
pointée par  s  à  la  recherche  du  caractère  c.  Le  premier  octet
correspondant   à   c   (interprété  comme  un  unsigned  char)  arrête
l’opération.*/