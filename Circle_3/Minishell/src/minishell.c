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
	t_cmd	*cmd;


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
			cmd = ft_parse_input(input);
            if (cmd) {
                printf("cmd = %s\n", cmd->cmd);
                free(cmd->cmd);
                free(cmd);
            }
        }
        free(input);
    }

    return 0;
}