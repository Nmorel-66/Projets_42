/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nimorel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 16:02:27 by nimorel           #+#    #+#             */
/*   Updated: 2024/09/10 09:14:17 by nimorel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strncat(char *dest, char *src, unsigned int nb)
{
	unsigned int	i;
	unsigned int	len;

	i = 0;
	while (dest[i] != '\0')
	{
		i++;
	}
	len = i;
	i = 0;
	while (src[i] != '\0' && i < nb)
	{
		dest[len + i] = src[i];
		i++;
	}
	dest[len + i] = '\0';
	return (dest);
}

/*#include <string.h>
#include <stdio.h>
int	main(void)
{
	unsigned int	nb;
	char	str1[] = "debut";
	char	str2[] = "fin";
	
	nb = 2;
	//printf("strncat:  %s\n",strncat(str1,str2, nb)); 
	printf("ft_str cat:  %s\n", ft_strncat(str1, str2, nb));
	return (0);
}*/
/* meme chose que strcat sauf qu'om ne peut rajouter que n caratere
len + 1 cr il faut prevoir la place pour le caratere fin de chaine*/
