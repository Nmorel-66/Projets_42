/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   built_in.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nimorel <nimorel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/22 09:30:21 by nimorel           #+#    #+#             */
/*   Updated: 2025/03/22 13:23:43 by nimorel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_pwd()
{
	char cwd[1024];
	
	if (getcwd(cwd, sizeof(cwd)) != NULL)
	{	
		write(1, cwd, ft_strlen(cwd));
		write(1, "\n", 1);
	}
	else
		perror("pwd");	
	return (1);
}
int ft_echo(t_token *tokens)
{
	int	newline;
	int i;
	
	newline = 1;
	i = 0;
	if (tokens->next == NULL)
	{
		write(1, "\n", 1);
		return (1);
	}
	if (tokens->next && ft_strncmp(tokens->next->value, "-n" , 2) == 0)
	{
		newline = 0;
		tokens =tokens->next;
	}
	else
		tokens =tokens->next;
	while (tokens && tokens->type == WORD)
	{
		write(1, tokens->value, ft_strlen(tokens->value));
		if (tokens->next  && tokens->next->type == WORD)
			write(1, " ", 1);
		tokens = tokens->next;
	}
	if (newline)
		write(1, "\n", 1);
	else 
		write(1, "%\n", 2);
	return (1);
}

int	ft_isbuilt_in(char *cmd, t_token *tokens, t_env *env)
{
	if (ft_strncmp(cmd, "echo", 4) == 0)
		return (ft_echo(tokens));
	else if (ft_strncmp(cmd, "pwd", 3) == 0)
		return(ft_pwd());
	//else if (ft_strncmp(cmd, "cd", 2) == 0)
	//	ft_cd(tokens);
	else if (ft_strncmp(cmd, "env", 3) == 0)	
		return(ft_env(env));
	else if (ft_strncmp(cmd, "export", 6) == 0)
		return(ft_export(tokens, env));
	/*else if (ft_strncmp(cmd, "unset", 5) == 0)
		ft_unset(token, env);\
	*/
	else if(ft_strncmp(cmd, "exit", 4) == 0)
		exit(0);
	return(0);	
}
