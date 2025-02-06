/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nimorel <nimorel <marvin@42.fr> >          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 19:13:45 by nimorel           #+#    #+#             */
/*   Updated: 2025/02/06 21:23:52 by nimorel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char *ft_get_path_env(char **env)
{
	int i = 0;
	while (env[i])
	{
		if (ft_strncmp(env[i], "PATH=", 5) == 0)
			return (env[i] + 5);
		i++;
	}
	return (NULL);
}

char *ft_get_full_path(char *path, char *cmd)
{
	char *full_path = ft_strjoin(path, "/");
	if (!full_path)
		return (NULL);
	char *tmp = ft_strjoin(full_path, cmd);
	free(full_path);
	return (tmp);
}

char *ft_get_path(char *cmd, char **env)
{
	char *path_env = ft_get_path_env(env);
	if (!path_env)
		return (NULL);

	char **paths = ft_split(path_env, ':');
	int i = 0;
	while (paths[i])
	{
		char *full_path = ft_get_full_path(paths[i], cmd);
		if (!full_path)
		{
			free(paths);
			return (NULL);
		}
		if (access(full_path, X_OK) == 0)
		{
			free(paths);
			return (full_path);
		}
		free(full_path);
		i++;
	}
	free(paths);
	return (NULL);
}

void	ft_exec(char *cmd, char **env)
{
	char	**cmd_args = ft_split(cmd, ' ');
	char	*cmd_path = ft_get_path(cmd_args[0], env);

	if (!cmd_path)
	{
		ft_putstr_fd("Command not found\n", 2);
		exit(127);
	}
	execve(cmd_path, cmd_args, env);
	ft_putstr_fd("Execute command failed\n", 2);
	exit(1);
}
