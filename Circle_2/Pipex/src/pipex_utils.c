/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nimorel <nimorel <marvin@42.fr> >          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 19:13:45 by nimorel           #+#    #+#             */
/*   Updated: 2025/02/07 18:54:54 by nimorel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static char	*ft_get_path_from_env(char **env)
{
	int	i;

	i = 0;
	while (env[i])
	{
		if (strncmp(env[i], "PATH=", 5) == 0)
			return (env[i] + 5);
		i++;
	}
	return (NULL);
}

static char	*ft_get_path(char *cmd, char **env)
{
	char	*path;
	char	**dirs;
	char	*cmd_path;
	int		i;

	path = ft_get_path_from_env(env);
	if (!path)
		return (NULL);
	dirs = ft_split(path, ':');
	cmd_path = NULL;
	i = 0;
	while (dirs[i])
	{
		cmd_path = ft_strjoin(dirs[i], "/");
		cmd_path = ft_strjoin(cmd_path, cmd);
		if (access(cmd_path, F_OK) == 0)
			return (cmd_path);
		i++;
	}
	return (NULL);
}

void	ft_exec_cmd(char *cmd, char **env)
{
	char	**cmd_args;
	char	*cmd_path;

	cmd_args = ft_split(cmd, ' ');
	cmd_path = ft_get_path(cmd_args[0], env);
	if (!cmd_path)
	{
		ft_error_handler("Command not found\n", 2);
		exit(127);
	}
	execve(cmd_path, cmd_args, env);
	ft_error_handler("Execute command failed\n", 2);
	exit(1);
}
