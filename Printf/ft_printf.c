/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nimorel <nimorel <marvin@42.fr> >          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 09:47:54 by nimorel           #+#    #+#             */
/*   Updated: 2024/11/19 13:23:35 by nimorel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static int	ft_printformat(char specifier, va_list *args)
{
	if (specifier == 'c')
		return (ft_printchar(va_arg(*args, int)));
	else if (specifier == 's')
		return (ft_printstr(va_arg(*args, char *)));
	else if (specifier == 'p')
		return (ft_printptr(va_arg(*args, void *)));
	else if (specifier == 'd' || specifier == 'i')
		return (ft_printnbr(va_arg(*args, int)));
	else if (specifier == 'u')
		return (ft_printunsigned(va_arg(*args, unsigned int)));
	else if (specifier == 'x' || specifier == 'X')
		return (ft_printhex(va_arg(*args, unsigned int), specifier));
	else if (specifier == '%')
		return (ft_printchar(37));
	return (0);
}

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
		if (format[i] == '%' && format[i + 1])
		{
			i++;
			len = len + ft_printformat(format[i], &args);
		}
		else
			len = len + write(1, &format[i], 1);
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

	len = printf("   Printf %s %i %c %u %x %X %p\n", s, i, c, u, h, h, p);
	printf("len (Printf): %d\n", len);
	len = ft_printf("ft_printf  %s %i %c %u %x %X %p\n", s, i, c, u, h, h, p);
	ft_printf("len (printf): %d\n", len);
	return (0);
}*/
