/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nimorel <nimorel <marvin@42.fr> >          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 09:28:53 by nimorel           #+#    #+#             */
/*   Updated: 2025/01/20 09:54:53 by nimorel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_valid_int(char *str)
{
	int	i;
	int	value;

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
	int	i;

	i = 1;
	if (argc < 2)
		exit (0);
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

char	**ft_split_args(int argc, char **argv, int *new_argc)
{
	char	**split_args;
	char	**new_argv;
	int		i;
	int		j;

	if (argc == 2 && ft_strchr(argv[1], ' '))
	{
		split_args = ft_split(argv[1], ' ');
		*new_argc = 0;
		while (split_args[*new_argc])
			(*new_argc)++;
		new_argv = (char **)malloc(sizeof(char *) * (*new_argc + 1));
		if (!new_argv)
			return (NULL);
		i = 0;
		j = 0;
		while (i < *new_argc)
		{
			new_argv[i] = ft_strdup(split_args[i]);
			i++;
		}
		new_argv[i] = NULL;
		ft_free_split(split_args);
		return (new_argv);
	}
}

void ft_free_split(char **split)
{
	int	i;

	i = 0;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
}
