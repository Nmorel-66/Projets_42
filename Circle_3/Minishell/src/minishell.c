#include "minishell.h"

void	ft_handle_sigint(int sig)
{
	(void)sig;
	write(1, "\n", 1);
	rl_on_new_line();
	//rl_replace_line("", 0);
	rl_redisplay(); 
}

int	main(int argc, char	**argv, char	**envp)
{
	char	*input;


	(void)argc;
	(void)argv;
	(void)envp;
	t_env	*g_env;
	signal(SIGINT, ft_handle_sigint);
	g_env = (t_env *)malloc(sizeof(t_env));
	if (!g_env)
	{
		perror("malloc");
		exit(1);
	}
	g_env->key = NULL;
	g_env->value = NULL;
	while (1)
	{
		input = readline("minishell$ ");
		if (!input)
			break ;
		if (*input)
		{
			add_history(input);
			//parse_input(input, envp);
		}
		free(input);
	}
	free(g_env);
	return (0);
}