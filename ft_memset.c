/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nimorel <nimorel <marvin@42.fr> >          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 14:19:21 by nimorel           #+#    #+#             */
/*   Updated: 2024/11/06 14:56:04 by nimorel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*ptr;

	ptr = s;
    i = 0;
	while (i < n)
	{
		ptr[i] = (unsigned char)c;
		i++;
	}
	return (s);
}
/*La  fonction  memset() remplit les n premiers octets de la zone mémoire
       pointée par s avec l’octet c.*/
int main(void)
{
    char *str = "Hello";
    
    ft_memset(str, 'c', sizeof(str));
    printf("%s\n", str);
    return (0);
}