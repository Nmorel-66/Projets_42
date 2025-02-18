/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nimorel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 11:33:43 by nimorel           #+#    #+#             */
/*   Updated: 2024/09/10 09:09:04 by nimorel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcat(char *dest, char *src)
{
	int	i;
	int	len;

	i = 0;
	while (dest[i] != '\0')
		i++;
	len = i;
	i = 0;
	while (src[i] != '\0')
	{
		dest[len] = src[i];
		i++;
		len++;
	}
	dest[len] = '\0';
	return (dest);
}

/*#include <string.h>
#include <stdio.h>
int	main(void)
{
	char	str1[] = "debut";
	char	str2[] = "fin";
	//printf("strcat:  %s\n",strcat(str1,str2)); 
	printf("ft_strcat:  %s\n", ft_strcat(str1, str2));
	return (0);
}*/
/* strcat ajoute la chaine src a la suite de la chaine dest et on la stock
dans dest aue l'omn renvoie*/
