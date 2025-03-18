/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nimorel <nimorel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 13:47:56 by nimorel           #+#    #+#             */
/*   Updated: 2025/03/18 15:37:05 by nimorel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"


static void	ft_free_split(const char **split)
{
	int	i = 0;
	while (split[i])
	{
		free((void *)split[i]);
		i++;
	}
	free(split);
}

static void	ft_free_cmd(t_cmd *cmd)
{
	if (cmd)
	{
		free(cmd->cmd);
		free(cmd->option);
		free(cmd->input_file);
		free(cmd->output_file);
		free(cmd);
	}
}

t_cmd	*ft_parse(const char *input)
{
	t_cmd		*cmd;
	const char	**split;
	int			i;

	split = ft_split(input, " ");
	cmd = malloc(sizeof(t_cmd));
	if (cmd == NULL)
	{
		perror("cmd allocation failed");
		return (NULL);
	}

	cmd->cmd = ft_strdup(split[0]);
	cmd->option = ft_strdup(split[1]);
	cmd->input_file = NULL;
	cmd->output_file = NULL;
	cmd->append = 0;
	cmd->next = NULL;

	i = 0;
	while (split[i])
	{
		if (ft_strncmp(split[i], ">", 1) == 0)
		{
			cmd->output_file = ft_strdup(split[i + 1]);
			split[i] = NULL;
			break;
		}
		else if (ft_strncmp(split[i], ">>", 2) == 0)
		{
			cmd->output_file = ft_strdup(split[i + 1]);
			cmd->append = 1;
			split[i] = NULL;
			break;
		}
		else if (ft_strncmp(split[i], "<", 1) == 0)
		{
			cmd->input_file = ft_strdup(split[i + 1]);
			split[i] = NULL;
			break;
		}
		i++;
	}

	ft_free_split(split);
	return (cmd);
}
