#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <signal.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <termios.h>
# include <string.h>
# include "../Libft/libft.h"

/* lexer */
typedef enum	e_token_type
{
	WORD,
	PIPE,
	REDIRECT_IN,
	REDIRECT_OUT,
	HEREDOC,
	APPEND,
	SPACE
}	t_token_type;

typedef struct	s_token
{
	char			*value;
	t_token_type	type;
	struct s_token	*next;
}					t_token;

extern int rl_replace_line(const char *text, int i);

/* minishell.c */
void	ft_handle_sigint(int sig);

/* lexer.c */
t_token	*ft_lexer(const char *input);
void	free_tokens(t_token *tokens);
t_token	*ft_create_token(char *value, t_token_type type);
void	ft_add_token(t_token **tokens, t_token *new_token);
t_token_type	ft_get_operator_type(char c, char next_c);

/* lexer_utils.c */
int		ft_isspace(int c);
char	*ft_strndup(const char *s, size_t n);

#endif