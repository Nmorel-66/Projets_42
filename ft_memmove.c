/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nimorel <nimorel <marvin@42.fr> >          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 15:20:25 by nimorel           #+#    #+#             */
/*   Updated: 2024/11/06 15:45:40 by nimorel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void    *ft_memmove(void *dest, const void *src, size_t n)
{
    unsigned char	*s;
	unsigned char   *d;
	size_t	        i;

	s = (unsigned char *)src;
	d = (unsigned char *)dest;
	i = 0;
    if (dest == src || n == 0)
        return (dest);
	if (d > s)
        while (n > 0)
		{
            n--;
            d[n] = s[n];
        }    
	else
		while (i < n)
		{
			d[i] = s[i];
			i++;
		}
	return (dest);
}
/* La fonction memmove() copie n octets depuis la zone mémoire src vers la
zone mémoire dest. Les deux zones  peuvent  se  chevaucher :  la  copie
s’effectue  comme  si  src  était  premièrement  copiée dans un tableau
temporaire ne chevauchant pas src ou dest puis il est copié vers  dest
premiere cond copie de l'arriere vers l'avant pour eviter chvauchement
2nd cond copie dvers l'avant
*/