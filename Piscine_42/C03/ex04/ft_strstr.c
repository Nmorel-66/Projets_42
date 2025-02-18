/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nimorel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 16:24:44 by nimorel           #+#    #+#             */
/*   Updated: 2024/09/22 10:37:24 by nimorel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strstr(char *str, char *to_find)
{
	int	i;
	int	j;

	if (!*str)
		return (0);
	if (ft_strlen(to_find) > ft_strlen(str))
		return (0);
	if (!*to_find)
		return (str);
	i = 0;
	while (str[i] != '\0')
	{
		j = 0;
		while (str[i + j] == to_find[j])
		{
			if (to_find[j + 1] == '\0')
				return (str + i);
			j++;
		}
		i++;
	}
	return (0);
}
/*
#include <string.h>
#include <stdio.h>
int	main(void)
{
	char str1[] = "une aiguille dans un botte de foin";
	char str2[] = "aiguille";
//	char str1[] = "";			
//	char str2[] = "";		
	printf("%s\n", strstr(str1, str2));
	printf("%s\n", ft_strstr(str1, str2));
	return (0);
}*/
/* strstr recherche premiere occurence de la sous chaine to_find dans la
chaine str. la fonction renvoie un pointer vers le debut d la sous chaine
localisee dans str. si to-find est vide ca renvoi str*, si str est vide 
renvoie 0*/
