/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nimorel <nimorel <marvin@42.fr> >          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 19:12:40 by nimorel           #+#    #+#             */
/*   Updated: 2025/02/06 21:16:07 by nimorel          ###   ########.fr       */
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

void	ft_child(int fd[2], char **av, int infile, char **env);
void	ft_parent(int fd[2], char **av, int outfile, int pid, char **env);
void	ft_error_handler(char *message, int exit_code);
void	ft_exec(char *cmd, char **env);
char	*ft_get_path(char *cmd, char **env);

#endif