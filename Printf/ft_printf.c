/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nimorel <nimorel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 09:47:54 by nimorel           #+#    #+#             */
/*   Updated: 2024/11/16 13:15:56 by nimorel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <stdio.h>
#include <stdlib.h>

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}
int ft_printf(const char *format, ...)
{
	va_list	args;
	int		i;
	int		size;
   
 
	i = 0;
	size = 0;
	va_start(args, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			
		}	
			
	}
	i++;
	var_end(args);
	return (size);
}
int main(void)
{
    char c = c;

    
    printf("Printf affiche %c\n", c);
    ft_printf("ft_printf affiche %c\n", c);
	return (0);
}