/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nimorel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 11:33:34 by nimorel           #+#    #+#             */
/*   Updated: 2024/09/09 15:26:52 by nimorel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strlowcase(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (('A' <= str[i] && str[i] <= 'Z'))
			str[i] = str[i] + 32;
		i++;
	}
	return (str);
}

char	*ft_strcapitalize(char *str)
{
	int		i;
	char	flag;

	i = 0;
	flag = 1;
	ft_strlowcase(str);
	while (str[i] != '\0')
	{
		if (('a' <= str[i] && str[i] <= 'z') && flag == 1)
		{
			str[i] = str[i] - 32;
			flag = 0;
		}
		else
		{
			if (('a' <= str[i] && str[i] <= 'z')
				|| ('0' <= str[i] && str[i] <= '9'))
				flag = 0;
			else
				flag = 1;
		}
		i++;
	}
	return (str);
}

/*#include <stdio.h>
int	main(void)
{
	char str[] = "salut, comMment tu vas? 42mots quarante-deux; cin+et+un";
	printf("salut, comMment tu vas? 42mots quarante-deux; cin+et+un\n");
	printf("%s\n", ft_strcapitalize(str));
	return (0);
}*/
