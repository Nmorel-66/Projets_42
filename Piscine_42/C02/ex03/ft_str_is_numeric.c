/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_numeric.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nimorel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 17:32:52 by nimorel           #+#    #+#             */
/*   Updated: 2024/09/08 15:29:05 by nimorel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_numeric(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '\0')
		return (1);
	while (str[i] != '\0')
	{
		if (str[i] < '0' || str[i] > '9')
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
	char	str1[] = "1234";
	char	str2[] = "12a";
	
	printf("chaine 1234 retur ; %d\n", ft_str_is_numeric(str1));

	printf("chaine 12a retur ; %d\n", ft_str_is_numeric(str2));

}*/
