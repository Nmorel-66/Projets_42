/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nimorel <nimorel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 11:18:15 by nimorel           #+#    #+#             */
/*   Updated: 2025/02/03 16:25:43 by nimorel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	is_valid_int(char *str)
{
	int	i;

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
	if (ft_atol(str) > INT_MAX || ft_atol(str) < INT_MIN)
		return (0);
	return (1);
}

static int	is_duplicate(int count, char **args)
{
	int	i;
	int	j;

	i = 0;
	while (i < count)
	{
		j = i + 1;
		while (j < count)
		{
			if (ft_atoi(args[i]) == ft_atoi(args[j]))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

static int	ft_validate_args(char **args, int argc)
{
	int	i;

	i = 0;
	while (args[i])
	{
		if (!is_valid_int(args[i]))
		{
			if (argc == 2)
				ft_free(args);
			return (0);
		}
		i++;
	}
	if (is_duplicate(i, args))
	{
		if (argc == 2)
			ft_free(args);
		return (0);
	}
	return (1);
}

int	ft_arg_checker(int argc, char **argv)
{
	char	**splitted_args;

	if (argc < 2)
		exit(0);
	if (argc == 2)
		splitted_args = ft_split(argv[1], ' ');
	else
		splitted_args = argv + 1;
	if (!ft_validate_args(splitted_args, argc))
		return (0);
	if (argc == 2)
		ft_free(splitted_args);
	return (1);
}
