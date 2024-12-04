/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nimorel <nimorel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 11:35:48 by nimorel           #+#    #+#             */
/*   Updated: 2024/12/04 10:39:34 by nimorel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>

# ifdef BUFFER_SIZE
#  if BUFFER_SIZE < 1 || BUFFER_SIZE > 8192000
#   undef BUFFER_SIZE
#   define BUFFER_SIZE 10
#  endif
# endif
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

size_t	ft_strlen(const char *s);
char	*ft_strdup(const char *s);
char	*ft_strchr(const char *s, int c);
char	*ft_strjoin(char *s1, char *s2);
char	*get_next_line(int fd);

typedef struct s_fd_data
{
	char	*readed_data;
	size_t	index;
}			t_fd_data;

#endif
