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


typedef struct s_cmd 
{
	char			*cmd; //command ex : ls
	char			*option; //optio ex -l
	char			*input_file; // <
	char			*output_file; // >
	int				append; // >>
	struct	t_cmd	*next;
}				t_cmd;

/* minishell.c */
void	ft_handle_sigint(int sig);

/* parse.c */
t_cmd	*ft_parse(const char *input);

#endif