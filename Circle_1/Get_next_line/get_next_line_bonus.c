/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nimorel <nimorel <marvin@42.fr> >          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 11:35:43 by nimorel           #+#    #+#             */
/*   Updated: 2024/12/03 10:27:06 by nimorel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static char	*ft_createline(char *readed_data)
{
	char	*line;
	char	*pos;
	int		len;
	int		i;

	pos = ft_strchr(readed_data, '\n');
	if (pos)
		len = pos - readed_data;
	else
		len = ft_strlen(readed_data);
	line = malloc(sizeof(char) * (len + 2));
	if (!line)
		return (NULL);
	i = 0;
	while (i <= len)
	{
		line[i] = readed_data[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

static char	*ft_buffer_save(char *readed_data)
{
	char	*temp;
	char	*pos;

	pos = ft_strchr(readed_data, '\n');
	if (!pos)
	{
		free(readed_data);
		return (NULL);
	}
	temp = ft_strdup(pos + 1);
	if (!temp)
		return (NULL);
	free(readed_data);
	return (temp);
}

static int	ft_read(int fd, char **readed_data, char *buffer)
{
	ssize_t	bytes_read;
	char	*temp;

	bytes_read = 1;
	while (bytes_read > 0)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read <= 0)
			break ;
		buffer[bytes_read] = '\0';
		temp = ft_strjoin(*readed_data, buffer);
		if (!temp)
		{
			free(*readed_data);
			return (-1);
		}
		free(*readed_data);
		*readed_data = temp;
		if (ft_strchr(*readed_data, '\n'))
			break ;
	}
	return (bytes_read);
}

char	*get_next_line(int fd)
{
	static t_fd_data	fd_data[4096];
	char				buffer[BUFFER_SIZE + 1];
	ssize_t				bytes_read;
	char				*line;

	if (fd < 0 || fd >= 4096 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!fd_data[fd].readed_data)
		fd_data[fd].readed_data = ft_strdup("");
	bytes_read = ft_read(fd, &fd_data[fd].readed_data, buffer);
	if (bytes_read == -1)
		return (free(fd_data[fd].readed_data),
			fd_data[fd].readed_data = NULL, NULL);
	if (ft_strchr(fd_data[fd].readed_data, '\n')
		|| (bytes_read == 0 && *fd_data[fd].readed_data))
	{
		line = ft_createline(fd_data[fd].readed_data);
		fd_data[fd].readed_data = ft_buffer_save(fd_data[fd].readed_data);
		return (line);
	}
	return (free(fd_data[fd].readed_data), fd_data[fd].readed_data = NULL,
		NULL);
}
/*
int main(void)
{
	int fd1 = open("test1.txt", O_RDONLY);
	int fd2 = open("test2.txt", O_RDONLY);
	int fd3 = open("test3.txt", O_RDONLY);
	char *line;

	if (fd1 == -1 || fd2 == -1 || fd3 == -1)
	{
		printf("Erreur lors de l'ouverture des fichiers\n");
		return (EXIT_FAILURE);
	}
	while ((line = get_next_line(fd1)) != NULL)
	{
		printf("FD1: %s", line);
		free(line);
	}
	while ((line = get_next_line(fd2)) != NULL)
    {
		printf("FD2: %s", line);
		free(line);
	}
	while ((line = get_next_line(fd3)) != NULL)
	{
		printf("FD3: %s", line);
		free(line);
	}
	close(fd1);
	close(fd2);
	close(fd3);
*/
