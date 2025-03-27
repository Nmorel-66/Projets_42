/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   built_in_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nimorel <nimorel <marvin@42.fr> >          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/22 12:31:23 by nimorel           #+#    #+#             */
/*   Updated: 2025/03/27 11:20:54 by nimorel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_env(t_env *env)
{
	t_env	*current;

	if (!env)
		return (FAILURE);
	current = env;
	while (current)
	{
		write(1, current->name, ft_strlen(current->name));
		write(1, "=", 1);
		write(1, current->value, ft_strlen(current->value));
		write(1, "\n", 1);
		current = current->next;
	}
	return (SUCCESS);
}

int	ft_unset(t_token *tokens, t_env *env)
{
	t_env	*current;
	t_env	*prev;

	if (!tokens->next)
	{
		perror("unset: not enough arguments");
		return (SUCCESS);
	}
	current = env;
	prev = NULL;
	while (current)
	{
		if (ft_strcmp(current->name, tokens->next->value) == 0)
		{
			if (prev)
				prev->next = current->next;
			else
				env = current->next;
			free(current->name);
			free(current->value);
			free(current);
			return (SUCCESS);
		}
		prev = current;
		current = current->next;
	}
	return (FAILURE);
}

char *ft_extract_name(char *str)
{
	char	*name;
	int		i;

	i = 0;
	while (str[i] && str[i] != '=')
		i++;
	name = malloc(i + 1);
	if (!name)
		return (NULL);
	ft_strlcpy(name, str, i + 1);
	return (name);
}

int	ft_export(t_token *tokens, t_env **env)
{
	t_env	*current;
	t_env	*new_node;
	char	*name;
	char	*value;
	
	if (!tokens->next)
	{
		ft_env(*env);
		return (SUCCESS);
	}
	tokens = tokens->next;
	name = ft_extract_name(tokens->value);
	if (!name)
		return (FAILURE);
	value = ft_strchr(tokens->value, '=');
	if (value)
		value = ft_strdup(value + 1);
	else
		value = NULL;
	current = *env;
	while (current)
	{
		if (ft_strcmp(current->name, name) == 0)
		{
			if (value)
			{
				free(current->value);
				current->value = value;
			}
			free(name);
			return (SUCCESS);
		}
		current = current->next;
	}
	if (value == NULL)
		value = ft_strdup("");
	new_node = ft_create_env_node(name, value);
	free(name);
	if (!new_node)
	{
		perror("Failed to create new env node");
		return (FAILURE);
	}
	if (*env)
	{
		current = *env;
		while (current->next)
			current = current->next;
		current->next = new_node;
	}
	else
		*env = new_node;
	return (SUCCESS);
}