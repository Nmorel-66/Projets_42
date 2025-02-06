/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nimorel <nimorel <marvin@42.fr> >          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 19:12:27 by nimorel           #+#    #+#             */
/*   Updated: 2025/02/06 21:23:09 by nimorel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_error_handler(char *message, int exit_code)
{
	ft_putstr_fd("\033[1;31m", 2);
	ft_putstr_fd(message, 2);
	ft_putstr_fd("\033[0m", 2);
	exit(exit_code);
}

void	ft_child(int pipe_fd[2], char **av, int infile, char **env)
{
	infile = open(av[1], O_RDONLY);
	if (infile == -1)
		ft_error_handler("Can't open infile\n", 2);
	dup2(infile, STDIN_FILENO);
	dup2(pipe_fd[1], STDOUT_FILENO);
	close(pipe_fd[0]);
	close(pipe_fd[1]);
	close(infile);
	ft_exec(av[2], env);
}

void	ft_parent(int pipe_fd[2], char **av, int outfile, int pid, char **env)
{
	waitpid(pid, NULL, 0);
	outfile = open(av[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (outfile == -1)
		ft_error_handler("Can't open outfile\n", 2);
	dup2(pipe_fd[0], STDIN_FILENO);
	dup2(outfile, STDOUT_FILENO);
	close(pipe_fd[0]);
	close(pipe_fd[1]);
	close(outfile);
	ft_exec(av[3], env);
}

int	main(int ac, char **av, char **env)
{
	int	fd_pipe[2];
	int	pid;
	int	infile;
	int outfile;

	infile = 0;
	outfile = 0;

	if (ac != 5)
		ft_error_handler("Args error: ./pipex infile cmd1 cmd2 outfile\n", 2);
	if (pipe(fd_pipe) == -1)
		ft_error_handler("Pipe failed\n", 2);
	pid = fork();
	if (pid == -1)
		ft_error_handler("Fork failed\n", 2);
	if (pid == 0)
		ft_child(fd_pipe, av, infile, env);
	else
		ft_parent(fd_pipe, av, outfile, pid, env);
	return (0);
}