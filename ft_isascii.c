/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nimorel <nimorel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 13:43:22 by nimorel           #+#    #+#             */
/*   Updated: 2024/11/05 14:22:28 by nimorel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isascii(int c)
{
	if (c >= 0 && c <= 128)
		return (1);
	return (0);
}
/*#include <stdio.h>
int main(void)
{	
	int c = 2229;
	printf("%d\n",ft_isascii(c));
	return (0);
}*/
