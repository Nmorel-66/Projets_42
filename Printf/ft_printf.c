/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nimorel <nimorel <marvin@42.fr> >          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 09:47:54 by nimorel           #+#    #+#             */
/*   Updated: 2024/11/18 10:04:44 by nimorel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <unistd.h>
#include <stdio.h>
#include "libftprintf.h"

static int	ft_printformat(char specifier, va_list args)
{
	if (specifier == 's')
		return (ft_printstr(va_arg(args, char *)));
	if (specifier == 'd' || specifier == 'i')
		return (ft_printnbr(va_arg(args, int)));
	if (specifier == 'c')
		return (ft_printchar(va_arg(args, int)));
	return (0);
}

int	ft_printf(const char *format, ...)
{
	va_list args;
	int i = 0;
	int len = 0;

	va_start(args, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			len = len + ft_printformat(format[i + 1], args);
			i++;
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

int	main(void)
{
	int i = 4200000;
	//char	c = 'A';
	//char	*s = "Hello";
	int 	len;

	len = printf("Printf affiche %i\n", i);
	printf("len (Printf): %d\n", len);
	len = ft_printf("printf affiche %i\n", i);
	ft_printf("len (printf): %d\n", len);
	return (0);
}
