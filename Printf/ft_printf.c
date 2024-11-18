/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nimorel <nimorel <marvin@42.fr> >          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 09:47:54 by nimorel           #+#    #+#             */
/*   Updated: 2024/11/18 15:49:33 by nimorel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "libftprintf.h"

int	ft_printchar(int c)
{
	write(1, &c, 1);
	return (1);
}
int	ft_printunsigned(unsigned int n)
{
	int		len;

	len = 0;
	if (n < 0)
	{
		len = len + ft_printchar('-');
		n = -n;
	}
	if (n >= 10)
		len = len + ft_printunsigned(n / 10);
	len = len + ft_printchar(n % 10 + '0');
	return (len);
}
int	ft_printnbr(int n)
{
	long	nb;
	int		len;

	nb = n;
	len = 0;
	if (nb < 0)
	{
		len = len + ft_printchar('-');
		nb = -nb;
	}
	if (nb >= 10)
		len = len + ft_printnbr(nb / 10);
	len = len + ft_printchar(nb % 10 + '0');
	return (len);
}

int	ft_printhex(unsigned long n, char specifier)
{
	char	*base;
	int		len;

	len = 0;
	if (specifier == 'X')
		base = "0123456789ABCDEF";
	else
		base = "0123456789abcdef";
	if (n >= 16)
		len = len + ft_printhex(n / 16, specifier);
	len = len + ft_printchar(base[n % 16]);
	return (len);
}
int	ft_printptr(void *ptr)
{
	int	len = 0;

	if (!ptr)
		return (write(1, "0x0", 3));
	len = len + write(1, "0x", 2);
	len = len + ft_printhex((unsigned long)ptr, 'x');
	return (len);
}
int	ft_printstr(char *str)
{
	int	len;

	len = 0;
	while (str[len])
		len++;
	write (1, str, len);
	return (len);
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
	len = ft_printf("printf affiche %s %i %c %u %x %X %p\n", s, i, c, u, h, h, p);
	ft_printf("len (printf): %d\n", len);
	return (0);
}
