/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printptr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nimorel <nimorel <marvin@42.fr> >          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 11:32:41 by nimorel           #+#    #+#             */
/*   Updated: 2024/11/18 15:44:38 by nimorel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_printptr(void *ptr)
{
	int	len = 0;

	if (!ptr)
		return (write(1, "(nil)", 5));
	len = len + write(1, "0x", 2);
	len = len + ft_printhex((unsigned long)ptr, 'x');
	return (len);
}
