/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nimorel <nimorel <marvin@42.fr> >          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 08:47:36 by nimorel           #+#    #+#             */
/*   Updated: 2025/03/19 09:11:52 by nimorel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"


void	free_tokens(t_token *tokens)
{
	while (tokens)
	{
		t_token	*tmp;

		tmp = tokens;
		tokens = tokens->next;
		free(tmp->value);
		free(tmp);
	}
}

t_token	*ft_create_token(char *value, t_token_type type)
{
	t_token	*token;

	token = malloc(sizeof(t_token));
	if (!token)
		return NULL;
	token->value = ft_strdup(value);
	token->type = type;
	token->next = NULL;
	return token;
}

void	ft_add_token(t_token **tokens, t_token *new_token)
{
	t_token	*current;
	
	if (!*tokens)
	{
		*tokens = new_token;
		return;
	}
	current = *tokens;
	while (current->next)
		current = current->next;
	current->next = new_token;
}

t_token_type	ft_get_operator_type(char c, char next_c)
{
	if (c == '|')
		return (PIPE);
	if (c == '<' && next_c == '<')
		return (HEREDOC);
	if (c == '>' && next_c == '>')
		return (APPEND);
	if (c == '<')
		return (REDIRECT_IN);
	if (c == '>')
		return (REDIRECT_OUT);
	return (WORD);
}

t_token	*ft_lexer(const char *input)
{
	t_token	*tokens;
	size_t	i;
	char	op[3];
	char	quote;
	char	*quoted_word;
	char	*word;
	int		start;

	tokens = NULL;
	i = 0;
	while (input[i])
	{
		if (ft_isspace(input[i]))
		{
			i++;
			continue ;
		}
		if (ft_strchr("|<>", input[i]))
		{
			op[0] = input[i];
			op[1] = '\0';
			op[2] = '\0';
			if ((input[i] == '<' || input[i] == '>') && input[i + 1] == input[i])
			{
				op[1] = input[i];
				i++;
			}
			ft_add_token(&tokens, ft_create_token(op, ft_get_operator_type(op[0], op[1])));
			i++;
			continue ;
		}
		if (input[i] == '\'' || input[i] == '"')
		{
			quote = input[i++];
			start = i;
			while (input[i] && input[i] != quote)
				i++;
			if (input[i] == quote)
			{
				quoted_word = ft_strndup(&input[start], i - start);
				ft_add_token(&tokens, ft_create_token(quoted_word, WORD));
				free(quoted_word);
				i++;
			}
			else
			{
				perror("Error : quote not closed.\n");
				break ;
			}
			continue ;
		}
		start = i;
		while (input[i] && !ft_isspace(input[i]) && !ft_strchr("|<>", input[i]))
			i++;
		word = ft_strndup(&input[start], i - start);
		ft_add_token(&tokens, ft_create_token(word, WORD));
		free(word);
	}
	return (tokens);
}
