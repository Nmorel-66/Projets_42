/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nimorel <nimorel <marvin@42.fr> >          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 09:47:54 by nimorel           #+#    #+#             */
/*   Updated: 2024/11/18 10:56:44 by nimorel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "libftprintf.h"

int	ft_printchar(int c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_printstr(char *str)
{
	int	len = 0;

	while (str[len])
		len++;
	write(1, str, len);
	return (len);
}

int	ft_printnbr(int n)
{
	long nb = n;
	int len = 0;

	if (nb < 0)
	{
		len = len + ft_printchar('-');
		nb = -nb;
	}
	if (nb > 9)
		len = len + ft_printnbr(nb / 10);
	len = len + ft_printchar(nb % 10 + '0');
	return (len);
}

int ft_printptr(void *ptr)
{
	int	len = 0;

    len = len + write(1, "0x", 2);
    len += len + ft_printhexa((unsigned long)ptr);
    return (len);
}

static int	ft_printformat(char specifier, va_list args)
{
	if (specifier == 'c')
		return (ft_printchar(va_arg(args, int)));
	if (specifier == 's')
		return (ft_printstr(va_arg(args, char *)));
	//if (specifier == 'p')
	//	return (ft_printptr(va_arg(args, void *)));
	if (specifier == 'd' || specifier == 'i'|| specifier == 'u')
		return (ft_printnbr(va_arg(args, int)));
	//if (specifier == 'x' || specifier == 'X')
	//	return (ft_printhex(va_arg(args, int), specifier));
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
	unsigned int i = 4200000;
	//char	c = 'A';
	//char	*s = "Hello";
	int 	len;

	len = printf("Printf affiche %i\n", i);
	printf("len (Printf): %d\n", len);
	len = ft_printf("printf affiche %i\n", i);
	ft_printf("len (printf): %d\n", len);
	return (0);
}
