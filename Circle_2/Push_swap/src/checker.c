/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nimorel <nimorel <marvin@42.fr> >          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 09:28:53 by nimorel           #+#    #+#             */
/*   Updated: 2025/01/03 09:25:35 by nimorel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_valid_int(char *str)
{
	int	i = 0;
	long long value;

	i = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	if (str[i] == '\0')
		return (0);
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	value = ft_atoi(str);
	if (value > INT_MAX || value < INT_MIN)
		return (0);
		i++;
	return (1);
}

int	is_duplicate(int argc, char **argv)
{
	int	i;
	int	j ;
	i = 1;
	while (i < argc)
	{
		j = i + 1;
		while (j < argc)
		{
			if (ft_atoi(argv[i]) == ft_atoi(argv[j]))
				return (1);
			j++;
	}
		i++;
	}
	return (0);
}

int	ft_arg_checker(int argc, char **argv)
{
	int i = 1;

	if (argc < 2)
        return (0);
	while (i < argc)
    {
 		if (!is_valid_int(argv[i]))
    		return (0);
		i++;
	}
    if (is_duplicate(argc, argv))
        return (0);
    return (1);
}
