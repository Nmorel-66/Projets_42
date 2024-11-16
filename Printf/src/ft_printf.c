/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nimorel <nimorel <marvin@42.fr> >          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 09:47:54 by nimorel           #+#    #+#             */
/*   Updated: 2024/11/16 20:39:37 by nimorel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <unistd.h>
#include <stdio.h>

size_t	ft_strlen(const char *s)
{
	size_t i = 0;

	 while (s[i] != '\0')
		i++;
	return (i);
}

int	ft_putstr_fd(char *s, int fd)
{
	write(fd, s, ft_strlen(s));
	return (ft_strlen(s));
}

int	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
	return (1);
}

int	ft_putnbr_fd(int n, int fd)
{
	long nb = n;
	int len = 0;

	if (nb < 0)
	{
		len = len + ft_putchar_fd('-', fd);
		nb = -nb;
	}
	if (nb > 9)
	{
		len = len + ft_putnbr_fd(nb / 10, fd);
		len = len + ft_putnbr_fd(nb % 10, fd);
	}
	else
		len = len + ft_putchar_fd(nb + '0', fd);
	return (len);
}

int ft_printf(const char *format, ...)
{
	va_list args;
	int len = 0;
	int i = 0;

	va_start(args, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			if (format[i] == 'd')
				len = len + ft_putnbr_fd(va_arg(args, int), 1);
			else if (format[i] == 'c')
				len = len + ft_putchar_fd(va_arg(args, int), 1);
			else if (format[i] == 's')
				len = len + ft_putstr_fd(va_arg(args, char *), 1);
			else
				len = len + ft_putchar_fd(format[i], 1);
		}
		else
			len = len + ft_putchar_fd('%', 1);
		i++;
	}
	va_end(args);
	return (len);
}

int main(void)
{
   	int i = 42;
	char c = 'A';
	char *s = "Hello";
	int len;

	len = printf("Printf affiche %d, %c, %s\n", i, c, s);
	printf("len (printf): %d\n", len);

	len = ft_printf("ft_printf affiche %d, %c, %s\n", i, c, s);
	printf("len (ft_printf): %d\n", len);
    return (0);
}
