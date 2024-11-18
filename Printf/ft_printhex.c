/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printhex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nimorel <nimorel <marvin@42.fr> >          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 11:14:45 by nimorel           #+#    #+#             */
/*   Updated: 2024/11/18 11:30:26 by nimorel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_printhex(unsigned int n, char specifier)
{
	char	*base;
	int	len;

	len = 0;
	if (specifier = 'X')
		base = "0123456789ABCDEF";
	else
		base = "0123456789abcdef";
	if (n >= 16)
		len = len + ft_printhex(n / 16, specifier);
	len =  len + ft_printchar(base[n % 16]);
 return (len);
}
