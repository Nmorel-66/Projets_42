/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   built_in.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nimorel <nimorel <marvin@42.fr> >          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/22 09:30:21 by nimorel           #+#    #+#             */
/*   Updated: 2025/03/27 11:52:43 by nimorel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_pwd(void)
{
	char	cwd[PATH_MAX];

	if (getcwd(cwd, sizeof(cwd)) != NULL)
	{
		write(1, cwd, ft_strlen(cwd));
		write(1, "\n", 1);
		return (SUCCESS);
	}
	perror("pwd");
	return (FAILURE);
}

int	ft_echo(t_token *tokens)
{
	int		newline;
	char	*env_value;
	int		i;

	newline = 1;
	tokens = tokens->next;
	while (tokens && tokens->type == WORD
		&& ft_strncmp(tokens->value, "-n", 2) == 0)
	{
		i = 1;
		while (tokens->value[i] == 'n')
			i++;
		if (tokens->value[i] != '\0')
			break ;
		newline = 0;
		tokens = tokens->next;
	}
	while (tokens && (tokens->type == WORD || tokens->type == ENV_VAR))
	{
		if (tokens->type == WORD)
			write(1, tokens->value, ft_strlen(tokens->value));
		else if (tokens->type == ENV_VAR)
		{
			env_value = getenv(tokens->value + 1);
			if (env_value)
				write(1, env_value, ft_strlen(env_value));
		}
		if (tokens->next && (tokens->next->type == WORD
				|| tokens->next->type == ENV_VAR))
			write(1, " ", 1);
		tokens = tokens->next;
	}
	if (newline)
		write(1, "\n", 1);
	return (SUCCESS);
}

int	ft_cd(t_token *tokens)
{
	char	*path;

	if (tokens->next == NULL)
	{
		path = getenv("HOME");
		if (path)
			chdir(path);
		else
		{
			perror("cd: HOME not set");
			return (FAILURE);
		}
	}
	if (strcmp(tokens->next->value, "~") == 0)
	{
		path = getenv("OLDPWD");
		if (path)
			chdir(path);
		else
		{
			perror("cd: OLDPWD not set");
			return (FAILURE);
		}
	}
	path = tokens->next->value;
	if (chdir(path) != 0)
	{
		perror("cd");
		return (FAILURE);
	}
	// mettre a jour OLDPWD et PWD
	
	return (SUCCESS);
}

int	ft_isbuilt_in(char *cmd, t_token *tokens, t_env *env)
{
	if (ft_strncmp(cmd, "echo", 4) == 0)
		return (ft_echo(tokens));
	else if (ft_strncmp(cmd, "pwd", 3) == 0)
		return (ft_pwd());
	else if (ft_strncmp(cmd, "cd", 2) == 0)
		return (ft_cd(tokens));
	else if (ft_strncmp(cmd, "export", 6) == 0)
		return (ft_export(tokens, &env));
	else if (ft_strncmp(cmd, "unset", 5) == 0)
		return (ft_unset(tokens, env));
	else if (ft_strncmp(cmd, "env", 3) == 0)
		return (ft_env(env));
	else if (ft_strncmp(cmd, "exit", 4) == 0)
		exit(0);
	return (FAILURE);
}
