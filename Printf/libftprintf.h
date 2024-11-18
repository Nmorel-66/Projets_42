/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nimorel <nimorel <marvin@42.fr> >          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 10:04:06 by nimorel           #+#    #+#             */
/*   Updated: 2024/11/18 11:36:05 by nimorel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdio.h>

int	ft_printchar(int c);
int	ft_printstr(char *str);
int	ft_printnbr(int n);
int	ft_printhex(unsigned int num, char specifier);
int	ft_printunsigned(unsigned n);
int	ft_printptr(void *ptr);

#endif
