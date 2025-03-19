#include "minishell.h"

void	ft_handle_sigint(int sig)
{
	(void)sig;
	write(1, "\n", 1);
	rl_on_new_line();
	rl_replace_line("", 0);
	rl_redisplay(); 
}

int	main(int argc, char	**argv, char	**envp)
{
	char	*input;
	//t_cmd	*cmd;
	t_token	*lexer;


	(void)argc;
	(void)argv;
	(void)envp;
	
	signal(SIGINT, ft_handle_sigint);

	while (1)
	{
		input = readline("minishell$ ");
		if (!input)
			break ;
		if (*input)
		{
			add_history(input);
			lexer = ft_lexer(input);
			while (lexer) // test of lexer
			{
				printf("Token: %-10s Type: %d\n", lexer->value, lexer->type);
				lexer = lexer->next;
			}
        }
        free(input);
    }

    return 0;
}
