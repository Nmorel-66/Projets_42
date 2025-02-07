/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nimorel <nimorel <marvin@42.fr> >          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 19:12:27 by nimorel           #+#    #+#             */
/*   Updated: 2025/02/07 18:54:08 by nimorel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_error_handler(char *message, int exit_code)
{
	ft_putstr_fd("\033[1;31m", 2);
	ft_putstr_fd(message, 2);
	if (errno)
		ft_putstr_fd(strerror(errno), 2);
	ft_putstr_fd("\033[0m", 2);
	exit(exit_code);
}

void	ft_child_process(int pipefd[2], char **av, char **env)
{
	int	infile;

	infile = open(av[1], O_RDONLY);
	if (infile == -1)
		ft_error_handler("Can't open infile\n", 2);
	dup2(infile, STDIN_FILENO);
	dup2(pipefd[1], STDOUT_FILENO);
	close(pipefd[0]);
	close(pipefd[1]);
	close(infile);
	ft_exec_cmd(av[2], env);
}

void	ft_parent_process(int pipefd[2], char **av, pid_t cpid, char **env)
{
	int	outfile;

	waitpid(cpid, NULL, 0);
	outfile = open(av[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (outfile == -1)
		ft_error_handler("Can't open outfile\n", 2);
	dup2(pipefd[0], STDIN_FILENO);
	dup2(outfile, STDOUT_FILENO);
	close(pipefd[0]);
	close(pipefd[1]);
	close(outfile);
	ft_exec_cmd(av[3], env);
}

int	main(int ac, char **av, char **env)
{
	int		pipefd[2];
	pid_t	cpid;

	if (ac != 5)
		ft_error_handler("Args error: ./pipex infile cmd1 cmd2 outfile\n", 2);
	if (pipe(pipefd) == -1)
		ft_error_handler("Pipe failed\n", 2);
	cpid = fork();
	if (cpid == -1)
		ft_error_handler("Fork failed\n", 2);
	if (cpid == 0)
		ft_child_process(pipefd, av, env);
	else
		ft_parent_process(pipefd, av, cpid, env);
	return (0);
}
