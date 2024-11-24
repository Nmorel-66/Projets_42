/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nimorel <nimorel <marvin@42.fr> >          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 13:07:57 by nimorel           #+#    #+#             */
/*   Updated: 2024/11/24 18:44:59 by nimorel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_char_pos(const char *str, char c)
{
	char	*pos;

	pos = ft_strchr(str, c);
	if (!pos)
		return (-1);
	return (pos - str);
}

static char	*ft_buffer_save(char *buffer_read)
{
	char	*new_buffer;
	int		pos;

	pos = ft_char_pos(buffer_read, '\n');
	if (pos == -1)
		return (NULL);
	new_buffer = ft_strdup(buffer_read + pos + 1);
	if (!new_buffer)
	{
		free (buffer_read);
		return (NULL);
	}
	return (new_buffer);
}

static char	*ft_createline(char *buffer_read)
{
	char	*line;
	int		pos;
	int		i;

	pos = ft_char_pos(buffer_read, '\n');
	if (pos == -1)
		pos = ft_strlen(buffer_read);
	i = 0;
	line = malloc(sizeof(char) * pos + 2);
	if (!line)
	{
		free (buffer_read);
		return (NULL);
	}
	while (i <= pos)
	{
		line[i] = buffer_read[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

static char	*ft_update_buffer(char *buffer_read, char *buffer)
{
	char	*temp;

	if (!buffer_read)
		return (ft_strdup(buffer));
	temp = ft_strjoin(buffer_read, buffer);
	if (!temp)
	{
		free(buffer_read);
		return (NULL);
	}
	free(buffer_read);
	return (temp);
}

char	*get_next_line(int fd)
{
	static char	*buffer_read = NULL;
	char		buffer[BUFFER_SIZE + 1];
	ssize_t		bytes_read;
	char		*line;


	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	bytes_read = 1;
	while (bytes_read > 0)
	{
		bytes_read = read(fd, buffer, sizeof(buffer) - 1);
		if (bytes_read < 0)
		{
			free(buffer_read);
			return (NULL);
		}
		buffer[bytes_read] = '\0';
		buffer_read = ft_update_buffer(buffer_read, buffer);
		if (ft_strchr(buffer_read, '\n'))
		{
			line = ft_createline(buffer_read);
			buffer_read = ft_buffer_save(buffer_read);
			return (line);
		}
	}
	free(buffer_read);
	return (NULL);
}
/*
#include <stdio.h>
int main(void)
{
	int fd;
	char *line;

	fd = open("test.txt", O_RDONLY);
	if (fd == -1) {
		printf("Erreur lors de l'ouverture du fichier");
		return (EXIT_FAILURE);
	}
	while ((line = get_next_line(fd)) != NULL)
	{
		printf("%s\n", line);
		free(line);
	}
	close(fd);
	return (EXIT_SUCCESS);
}*/
