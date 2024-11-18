/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printptr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nimorel <nimorel <marvin@42.fr> >          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 11:32:41 by nimorel           #+#    #+#             */
/*   Updated: 2024/11/18 11:38:07 by nimorel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_printptr(void *ptr)
{
	int	len;

	len = len + write(1, "0x", 2);
	len = len + ft_printhexa((unsigned long)ptr);
	return (len);
}
