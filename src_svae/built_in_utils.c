/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   built_in_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nimorel <nimorel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/22 12:31:23 by nimorel           #+#    #+#             */
/*   Updated: 2025/03/22 15:08:26 by nimorel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int ft_env(t_env *env)
{
	while (env)
	{
		ft_putstr_fd(env->name, 1);
		write(1, "=",1);
		ft_putstr_fd(env->value, 1);
		write(1, "\n",1);
		env = env->next;
	}
	return (1);
}
void	ft_set_env(t_env **env, const char *name, const char *value)
{
	t_env   *current;
	t_env   *new_var;
	
	new_var = NULL;
	current = *env;
	while(current)
	{
		if (ft_strncmp(current->name, name, ft_strlen(name)) == 0)
		{
			free(current->value);
			current->value  = ft_strdup(value);
			return ;
		}
		current = current->next;
	}
	new_var = malloc(sizeof(t_env));
	if (!new_var)
		return (perror("export failed"));
	new_var->name = ft_strdup(name);
	new_var->value = ft_strdup(value);
	new_var->next = *env;
	*env = new_var;
}
int ft_export(t_token *tokens, t_env *env)
{
	char	*var;
	char	*equal_sign;
	
	if (!tokens->next)
		return(ft_env(env));
	if (tokens->next && tokens->next->type == WORD)
	 {
		  var = tokens->next->value;
		  equal_sign = ft_strchr(var, '=');
		  if (equal_sign)
		  {
			*equal_sign = '\0';
			ft_set_env(&env, var, equal_sign + 1);
		  }
		  else
			ft_set_env(&env, var, "");
	 }
	return (1);
} 
