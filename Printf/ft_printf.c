/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nimorel <nimorel <marvin@42.fr> >          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 09:47:54 by nimorel           #+#    #+#             */
/*   Updated: 2024/11/18 15:55:45 by nimorel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		i;
	int		len;

	i = 0;
	len = 0;
	va_start(args, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			if (format[i] == 'c')
				len = len + ft_printchar(va_arg(args, int));
			else if (format[i] == 's')
				len = len + ft_printstr(va_arg(args, char *));
			else if (format[i] == 'p')
				len = len + ft_printptr(va_arg(args, void *));
			else if (format[i] == 'd' || format[i] == 'i')
				len = len + ft_printnbr(va_arg(args, int));
			else if (format[i] == 'u')
				len = len + ft_printunsigned(va_arg(args, unsigned int));
			else if (format[i] == 'x' || format[i] == 'X')
				len = len + ft_printhex(va_arg(args, unsigned long), format[i]);
		}
		else
		{
			len = len + write(1, &format[i], 1);
		}
		i++;
	}
	va_end(args);
	return (len);
}
/*
int	main(void)
{
	int 	i = -452;
	unsigned int u = 23;
	char	*s = "Hello";
	char	c = 'A';
	unsigned int h = 100;
	int 	len;
	int *p = &i;

	len = printf("Printf affiche %s %i %c %u %x %X %p\n", s, i, c, u, h, h, p);
	printf("len (Printf): %d\n", len);
	len = ft_printf("printf affiche %s %i %c
		%u %x %X %p\n", s, i, c, u, h, h, p);
	ft_printf("len (printf): %d\n", len);
	return (0);
}*/
