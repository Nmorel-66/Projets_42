/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nimorel <nimorel <marvin@42.fr> >          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 19:13:45 by nimorel           #+#    #+#             */
/*   Updated: 2025/02/07 18:03:48 by nimorel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*ft_get_path_env(char **env)
{
	int	i;

	i = 0;
	while (env[i])
	{
		if (ft_strncmp(env[i], "PATH=", 5) == 0)
			return (env[i] + 5);
		i++;
	}
	return (NULL);
}

char	*ft_get_full_path(char *path, char *cmd)
{
	char	*full_path;
	char	*tmp;

	tmp = ft_strjoin(path, "/");
	if (!tmp)
		return (NULL);
	full_path = ft_strjoin(tmp, cmd);
	free(tmp);
	return (full_path);
}

char	*ft_free_and_return(char **to_free, char *ret_value)
{
	if (to_free && *to_free)
	{
		free(*to_free);
		*to_free = NULL;	
	}
	return (ret_value);
}

char	*ft_get_path(char *cmd, char **env)
{
	char	**paths;
	char	*full_path;
	int		i;

	paths = ft_split(ft_get_path_env(env), ':');
	if (!paths)
		return (NULL);
	i = 0;
	while (paths[i])
	{
		full_path = ft_get_full_path(paths[i], cmd);
		if (!full_path)
			return (ft_free_and_return(paths, NULL));
		if (access(full_path, X_OK) == 0)
			return (ft_free_and_return(paths, full_path));
		free(full_path);
		i++;
	}
	return (ft_free_and_return(paths, NULL));
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
