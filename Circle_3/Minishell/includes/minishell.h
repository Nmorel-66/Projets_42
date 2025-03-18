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

typedef struct s_cmd 
{
	char	*cmd;
	char	**args;
}			t_cmd;

typedef struct s_env
{
	char	*key;
	char	*value;
}			t_env;

#endif