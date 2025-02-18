/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nimorel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 08:33:10 by nimorel           #+#    #+#             */
/*   Updated: 2024/09/10 08:53:52 by nimorel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while ((s1[i] != '\0' || s2[i] != '\0') && s1[i] == s2[i])
	{
		i++;
	}
	return (s1[i] - s2[i]);
}

/*#include<stdio.h>
int	main(void)
{
	char	str1[] = "coupercou";
	char	str2[] = "coucou";

	printf("%d", ft_strcmp(str1, str2));
	return (0);
}*/
/* strcmp compare les deux chaines, 
si on arrive a la fin de deux chaines elles sont egale la soustraction
de leur index egale 0 sinon elle sera positive ou negative suivant
suivant la position de l'index le chiffre est different*/
