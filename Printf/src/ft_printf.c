/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nimorel <nimorel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 09:47:54 by nimorel           #+#    #+#             */
/*   Updated: 2024/11/16 15:12:20 by nimorel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <stdio.h>
//#include <stdlib.h>
#include <unistd.h>


size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
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
	long	nb;

	nb = n;
	if (nb < 0)
	{
		ft_putchar_fd('-',fd);
		nb = nb * (-1);
	}
	if (nb > 9)
	{
		ft_putnbr_fd(nb / 10, fd);
		ft_putnbr_fd(nb % 10, fd);
	}
	else
		ft_putchar_fd(nb + 48, fd);
	return (1);
}

int ft_printf(const char *format, ...)
{
	va_list	args;
	int		len;  
	
	len = 0;
	va_start(args, format);
	 while (format[len]) {
        if (format[len] == '%')
		{
           	len++; 
            if (format[len] == 'd')
				len = len + ft_putnbr_fd(va_arg(args, int), 1);
			if (format[len] == 'c')
				len = len + ft_putchar_fd(va_arg(args, int), 1);
			if (format[len] == 's')
                len = len + ft_putstr_fd(va_arg(args, char *), 1);             
        }
		if (format[len] == '\n')
			ft_putchar_fd('\n', 1);
		else
			ft_putchar_fd(format[len], 1);
        len++;
    }
	
    va_end(args);
	return (len);
}
int main(void)
{
    int	c = 67;
	//int i = 42;
	int	len;
	
   	len = 0;
	//printf("Printf affiche %d\n", i);
	len = printf("Printf affiche %c\n", c);
	printf("len%d\n", len);
    len = ft_printf("printf affiche %c\n", c);
	printf("len%d\n", len);
	return (0);
}