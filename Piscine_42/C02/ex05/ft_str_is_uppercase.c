/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_uppercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nimorel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 10:14:50 by nimorel           #+#    #+#             */
/*   Updated: 2024/09/08 15:42:29 by nimorel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_uppercase(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (!(str[i] >= 'A' && str[i] <= 'Z'))
		{
			return (0);
		}
		i++;
	}
	return (1);
}

/*#include <stdio.h>
int	main(void)
{
	char str1[] = "ABCD";
	char str2[] = "ABCd";
	
	printf("ABCD return : %d\n", ft_str_is_uppercase(str1));
			
	printf("ABCd return : %d\n", ft_str_is_uppercase(str2));
}*/	
