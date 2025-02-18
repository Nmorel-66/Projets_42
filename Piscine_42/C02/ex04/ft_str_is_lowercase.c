/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_lowercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nimorel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 10:13:08 by nimorel           #+#    #+#             */
/*   Updated: 2024/09/08 15:36:55 by nimorel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_lowercase(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (!(str[i] >= 'a' && str[i] <= 'z'))
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
	char str1[] = "abcd";
	char str2[] = "aBcd";
	
	
	printf("chaine abcd retur ; %d\n", ft_str_is_lowercase(str1));

	printf("chaine aBcd retur ; %d\n", ft_str_is_lowercase(str2));

}*/
