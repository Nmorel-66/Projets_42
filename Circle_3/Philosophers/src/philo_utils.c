/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nimorel <nimorel <marvin@42.fr> >          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 10:03:01 by nimorel           #+#    #+#             */
/*   Updated: 2025/05/07 11:38:13 by nimorel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_error_handler(char *message, int exit_code)
{
	printf("\033[1;31m%s\033[0m\n", message);
	return (exit_code);
}

int	ft_atoi(const char *nptr)
{
	int	sign;
	int	i;
	int	res;

	i = 0;
	sign = 1;
	res = 0;
	while (nptr[i] == ' ' || nptr[i] == '\n' || nptr[i] == '\t'
		|| nptr[i] == '\v' || nptr[i] == '\f' || nptr[i] == '\r')
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			sign = -sign;
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		res = res * 10 + (nptr[i] - 48);
		i++;
	}
	return (res * sign);
}

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

long long	ft_gettime(void)
{
	struct timeval	tv;
	long long		ms;

	gettimeofday(&tv, NULL);
	ms = (tv.tv_sec * 1000LL) + (tv.tv_usec / 1000);
	return (ms);
}

int	ft_strcmp(const char	*s1, const char	*s2)
{
	size_t	i;

	i = 0;
	while (s1[i] != '\0' && s2[i] != '\0' && s1[i] == s2[i])
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}
