/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nimorel <nimorel <marvin@42.fr> >          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 19:12:40 by nimorel           #+#    #+#             */
/*   Updated: 2025/02/07 17:40:00 by nimorel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "../Libft/libft.h"
# include <unistd.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>  
# include <stdlib.h>
# include <string.h>
# include <errno.h>

void	ft_child_process(int pipefd[2], char **av, char **env);
void	ft_parent_process(int pipefd[2], char **av, int pid, char **env);
void	ft_error_handler(char *message, int exit_code);
void	ft_exec_cmd(char *cmd, char **env);
char	*ft_get_path(char *cmd, char **env);

#endif