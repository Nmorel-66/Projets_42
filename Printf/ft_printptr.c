/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printptr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nimorel <nimorel <marvin@42.fr> >          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 11:32:41 by nimorel           #+#    #+#             */
/*   Updated: 2024/11/18 12:34:59 by nimorel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_printptr(void *ptr)
{
	int	len;

	len = 0;
	len = len + write(1, "0x", 2);
	while (ptr)
	{
		len = len + write(1, ptr, 1);
		ptr++;
	}
	return (len);
}
